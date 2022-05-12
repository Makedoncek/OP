
from worker import *
import os

if __name__ == "__main__":
    #адреси бінарних файлів для створення та їх обробки
    path = "Calls.dat"
    path2 = "Bills.dat"

    print("Welcome to Get Tax app\nThanks for using us")
    create_phonebook(path)
    print("File creating\n-------------------------------------")
    Calls = get_calls()
    append_file(path, phonebook_to_str(Calls))
    print("Calls info added  to your program\n")
    print("File with your calls")
    printfile(path)
    os.system('cls||clear')
    create_phonebook(path2)
    append_file(path2, add_tax(Calls))
    print("File with tax of your calls")
    printfile(path2)
    os.system('cls||clear')
    append_or_create(path, path2)

    print("Thanks for using our GetTax Service")
