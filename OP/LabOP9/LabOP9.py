


def input_string():
    string=(input("Enter your string  "))
    return string


def  detach(string):
    symb=0
    string+=' '
    length=len(string)
    sum=0
    length1=length

    while (length>0) :

        count=0
        stp=''
        for i in range(symb,length1):
            if (count!=1):
                if(string[i]==' '):
                    pos=i
                    count=1
                    i+=1

        for j in range(symb,pos):
            stp+=string[j]
            j+=1

        length-=pos-symb+1
        symb=pos+1
        sum+=sumofnumbers(stp)
    return sum


def sumofnumbers(stp):

    if stp.isdigit()==1:
        print("String  ", stp  ,"  is number")
        return int(stp)
    else:
        print("String  ", stp, "  is not number")
        return 0







if __name__=="__main__":
    string=input_string()
    sumofnum=detach(string)
    print("The sum of strings that numbers is: ",sumofnum)

