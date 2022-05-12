
from phonebook import *


def create_phonebook(path): #створення бінарного файлу
    file = open(path, "wb")
    file.close()


def append_file(path, text: str): #запис тексту у бінарний файл
    text+='\n'
    with open(path, "ab") as file:
        calls = str.encode(text)
        file.write(calls)


def read_file(path) -> str: #читання з бінарного файлу
    calls = []
    with open(path, "rb") as file:
        calls = file.read()
    return calls.decode()  # из байтів у строку


def printfile(path):    #виведення данних бінарного файлу
    print(read_file(path))


def get_calls() -> list[PhoneBook]: #отримання дзвінків від користувача

    Calls = []

    while True: #отримання від користувача за допомогою вводу даних та подальше утворення об'єкта класу з додаванням до списку об'єктів дзвінків
        call = PhoneBook(
            datetime.datetime.strptime(input("Enter date of call  in format dd.mm.yy\n"), "%d.%m.%Y").date(),
            datetime.datetime.strptime(input("Enter call start time in format hh:mm\n"), "%H:%M").time(),
            datetime.datetime.strptime(input("Enter call end time in format hh:mm\n"), "%H:%M").time()
        )
        answer = input("Do you want to add more calls?\nEnter Yes or No\n")
        Calls.append(call)
        if (answer == "No"):
            break

    return Calls


def phonebook_to_str(Calls: list):  #переведення отриманих дзвінків у рядок для подальшого запису у бінарний файл
    call_str = []
    for call in Calls:
        call_str.append(str(call))
    return '\n'.join(call_str)


def add_tax(Calls:list): #утворення рядка з розрахованою вартістю для кожного дзвінка
    tax_calls = []
    for call in Calls:   #перевірка на тариф дзвінка для подальшого обрахування його вартості
        if call.time_start.hour>=9 and call.time_start.hour < 18 :
            tax_calls.append(f"{str(call)} - {get_tax(call)}")
        elif (call.time_start.hour>=7 and call.time_start.hour<9) or (call.time_start.hour >=18 and call.time_start.hour <22):
            tax_calls.append(f"{str(call)} - {get_tax(call)*0.7}")
        elif (call.time_start.hour>=22 and call.time_start.hour <24) or (call.time_start.hour>=0 and call.time_start.hour<7):
            tax_calls.append(f"{str(call)} - {0}")

    return '\n'.join(tax_calls)





def get_tax(call:PhoneBook): #Розрахування вартості дзвінка
    if call.time_end.hour>=call.time_start.hour:
        return((call.time_end.hour-call.time_start.hour)*
               60+(call.time_end.minute-call.time_start.minute))*1.7
    elif 22-call.time_start.hour< 22-call.time_end.hour:
        return((22-call.time_start.hour)*60+(0-call.time_start.minute))*1.7
    else:
        return 0


def append_or_create(path,path2): #можливий перезапис або додавання дзвінків у файл
    answer = input("Do you want to add or recreate your PhoneBook\nEnter Append or Recreate,else print No\n")
    if answer == "Append":
        Calls = get_calls()
        append_file(path,phonebook_to_str(Calls))
        print("File with your  added  calls")
        printfile(path)
        append_file(path2,add_tax(Calls))
        print("File with your  added  calls with tax")
        printfile(path2)

    elif answer == "Recreate":
        create_phonebook(path)
        Calls = get_calls()
        append_file(path,phonebook_to_str(Calls))
        print("File with your calls")
        printfile(path)
        print("File with tax of your calls")
        create_phonebook(path2)
        append_file(path2,add_tax(Calls))
        printfile(path2)
