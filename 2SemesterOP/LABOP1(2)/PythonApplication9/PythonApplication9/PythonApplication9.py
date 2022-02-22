import os

def inputText(): #заповнення стартового файлу
    print("Input your text for initial file(to end the entering double press Enter):")
    initial = 'initial.txt'
    file = open(initial, 'w'); #відкриття файлу для запису
    text = " " #temp 
    c = 0
    while(text): #isEmpty  когда в строке не пусто
        text=input()
        if c == 0: file.write(text) 
        else: file.write('\n'+text)
        c+=1
    file.close()
    return initial

def chooseFiles(a,b,c): #перепис рядків по файлах
    initial = open(a, 'r') #стартовий файл, для зчитування
    even = open(b, 'w') #для запису парних рядків
    odd = open(c, 'w') #для запису  непарних рядків 
    c = 1 #Фіксування відповідного номеру рядка
    text = " " #рядок для запису введенного користувачем тексту
    while(text):
        text = initial.readline() #зчитуємо порядково
        if text:
            if(c%2==0):even.write(text)
            else: odd.write(text)  #Перенесення на нову строку
            c+=1
    initial.close()
    even.close()
    odd.close()

def addText(a): #дозаповнення файлу
    print("Input your text:")
    f = open(a, 'a'); #відкриваємо файл для дозапису
    text = " "
    c = 0
    while(text):
        text=input()
        if c == 0: f.write(text) 
        else: f.write("\n"+text)
        c+=1
    f.close()

def outputFile(a): #виведення вмісту файлів
    f = open(a, 'r')
    text = f.read()
    print(text)
    f.close()

def alphabet(adress): #сортування за алфавітом
    file = open(adress, 'r') 
    text = file.read() #записуємо весь текст файлу  
    arr = text.split('\n') #розділяємо текст по рядках в список
    arr.pop(len(arr)-1) #видалення зайвого рядка (пустого)
    file.close()
    numb = 0 #Індекс відповідного рядка файлу
    for i in arr:
        tArr = i.split(' ') #розділяємо рядок на слова
        for j in range(0, len(tArr)-1): #сортування алфавітом(за основу взято бульбашку)
            for g in range(0, len(tArr)-1):
                if len(tArr[g])>len(tArr[g+1]): 
                    for k in range(0, len(tArr[g+1])):
                        if tArr[g][k] > tArr[g+1][k]:
                            save = tArr[g+1]
                            tArr[g+1] = tArr[g]
                            tArr[g] = save
                            break
                        elif tArr[g][k] < tArr[g+1][k]:
                            break
                else:
                    for k in range(0, len(tArr[g])):
                        if tArr[g][k] > tArr[g+1][k]:
                            save = tArr[g+1]
                            tArr[g+1] = tArr[g]
                            tArr[g] = save
                            break
                        elif tArr[g][k] > tArr[g+1][k]:
                            break
        arr[numb] = tArr #запис у масив рядків відсортований ряд слів
        numb+=1
    file = open(adress, 'w') #запис зміненого тексту в файл
    for i in arr:
        file.write(' '.join(i)+'\n') 
    file.close()

if __name__=="__main__":
    intialFile = inputText() #стартовий файл, ф-ція повертає назву файлу
    os.system('cls||clear') #очищення консолі
    print("Text of the initial file:")
    outputFile(intialFile)
    choice = int(input("Do you want to add some text?\n1 - Yes\n2 - No\nType here: "))
    if choice == 1:
        addText(intialFile)
    os.system('cls||clear')
    print("Initial file:")
    outputFile(intialFile)
    even = 'even.txt' #перший файл (для парних)
    odd = 'odd.txt' #другий файл (для непарних)
    chooseFiles(intialFile, even, odd)
    print("Text of the first file (even, unsorted):")
    outputFile(even)
    alphabet(even)
    print("Text of the first file (even, sorted):")
    outputFile(even)
    print("Text of the second file (odd):")
    outputFile(odd)
