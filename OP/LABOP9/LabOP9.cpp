#include <iostream>
#include <string>
using namespace std;

void input_str(string&);
int split(string);
int sumofnumbers(string);


int main() {
    string str;
    cout << "Enter your string ";
    input_str(str);
    int sumofnum = split(str);
    cout << endl <<"The sum of strings that numbers is: " << sumofnum;
    return 0;
}


void input_str(string& str) {
    getline(cin, str);

}

int split(string str) {
    int symb = 0; //Початок нової підстроки 

    str += ' ';
    int length = str.length();//Вимірювання довжини загальної строки 
    int sum = 0;
    string stp; //Змінна для підстрок 
    int count;
    const int length1 = length; // Змінна константа яка буде використовуватись у циклі для знаходження місця наступного пробілу
    while (length > 0) {
        int pos;
        count = 0; // Показник знайдення пробілу, який анулюється кожної ітерації циклу
        stp = ""; //Опустошення підстроки 
        //пошук пробілу, який буде розділяти початок нової підстроки та кінець 
       
        for (int i = symb; i < length1; i++) {
            if (count != 1) {
                if (str[i] == ' ') {
                    pos = i;
                    count = 1;
                }
            }
        }
        //Створення підстроки з pos - j елементів 
        for (int j = symb; j < pos; j++) {
            stp += str[j];
        }
        


        length -= pos - symb + 1; // Віднімання довжини підстроки та пробілу що їх розділяє 
        symb = pos + 1; //Пропуск пробілу перенесення до першого символу нової підстроки 
        sum += sumofnumbers(stp); //Сума рядків які є числами 
        


    }
    return sum; //Повернення результату сумми
}

int sumofnumbers(string stp) {

    int eror;   //Змінна для перевірки кожного символа підстроки на відношення до цифри

    eror = 0; 
    for (int i = 0; i < stp.length(); i++) {
        if (isdigit(stp[i]) == 0) {
            eror = 1;

        }

    }
    if (eror != 1) {
        cout << "String " << stp << " is  number" << endl;
        return stoi(stp);//Повернення до функції перетворенної строки на число   
    }
    else {
        cout << "String " << stp << " is not number" << endl;
        return 0; // У випадку неналежності строки до числа 
    }


}
