amnseq=0


for i in range(10000,1000000):
    sfc=i
    cofdig=0
    while sfc>0:
        cofdig=cofdig+1
        sfc=sfc//10
    if cofdig==5 and i%11111==0:
        amnseq+=1
        print(i)
    elif cofdig == 6 and  i % 1000 == i // 1000 or cofdig == 6 and i // 10000 == (i % 10000) // 100 and i // 10000 == (i % 10000) % 100 and (i % 10000)//100 == (i % 10000) % 100:
        amnseq+=1
        print(i)
print("Количество чисел, которые состоят из последовательности цифр "+ str(amnseq))

