amountnumbseq=0



for i in range(10000,1000000):
    saveriforCount=i
    counterofdigits=0
    while saveriforCount>0:
        counterofdigits+=1
        saveriforCount=saveriforCount//10
     
    if counterofdigits == 5 and i%11111 == 0 :
        amountnumbseq+=1
        print(i)

    elif counterofdigits == 6:
  
        if i % 1000 == i // 1000 :
            amountnumbseq+=1
            print(i)
            

        elif i // 10000 == (i % 10000) // 100 and i // 10000 == (i % 10000) % 100 and (i % 10000) // 100 == (i % 10000) % 100:
            amountnumbseq+=1
            print(i)
            
  
print("Количество чисел,которые состоят из последовательности цифр " + str(amountnumbseq))
