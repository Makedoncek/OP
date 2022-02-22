#include <iostream>
#include <fstream>
#include <string>
using namespace std;



string inputText() {
    string initial = "Initial.txt";
    cout << "Input your text (press  Ctrl-Q combinination to stop entering your text):\n";
    ofstream fout(initial); //Створення та відкриття об'єкту класса для запису даних у нього 
    string str; //Рядок для заповнення начального файлу
    int count = 0;//Номер відповідного рядка, який вводиться користувачем
    while (str.find(17) == string::npos) { //перевірка на наявність комбінації(Ctrl-Q) в потоці 
        getline(cin, str);
        if (count == 0 && str.find(17) == string::npos)
            fout << str;
        else if (str.find(17) == string::npos)
            fout << endl << str;
        count++;
    }
    fout.close();
    return initial;
}

void chooseFile(string init, string even, string odd) {
    ifstream filein(init); //Створення та відкриття об'єкту класса для читання даних з нього 
    ofstream even1(even); //..для запису в перший файл (для парних)
    ofstream odd2(odd); //..для запису в другий файл(для непарних)
    string str;
    int count = 1; //  Лічильник номеру відповідної строки
    while (!filein.eof()) { //перевірка на кінець текстового файла
        getline(filein, str);
        if (count % 2 == 0) {
            if (count == 2) even1 << str;
            else even1 << endl << str;
        }
        else {
            if (count == 1) odd2 << str;
            else odd2 << endl << str;
        }
        count++;
    }
    filein.close();
    even1.close();
    odd2.close();
}

void addText(string adress) {
    ofstream fileout(adress, ios::app); //app (append) використовується для дозапису даних у кінець файлу
    cout << "You can add some text,to end entering the text press Ctrl-Q:\n";
    string str;
    int count = 0;
    while (str.find(17) == string::npos) {
        getline(cin, str);
        if (count == 0 && str.find(17) == string::npos)
            fileout << str;
        else if (str.find(17) == string::npos)
            fileout << endl << str;
        count++;
    }
    fileout.close();
}

void outputFile(string adress) {
    ifstream filein(adress); //Обьект класса файла для читання інформації з нього
    string str;
    while (!filein.eof()) {
        getline(filein, str);
        cout << str << endl;
    }
    cout << endl;
}

void alphabetSort(string adress) {
    fstream filein(adress); //об'єкт універсального класу (i/o)(як читання, так і запис)
    int cntLines = 0;
    string str;
    while (!filein.eof()) { //Обрахування кількості рядків у файлі
        getline(filein, str);
        cntLines++;
    }
    filein.close();
    filein.open(adress, ios::in); //відкриття файла у режимі зчитування інформації
    string* lines = new string[cntLines]; //масив для запису рядків тексту з файла 
    for (int i = 0; i < cntLines; i++) {
        getline(filein, lines[i]);
    }
    filein.close();
    for (int i = 0; i < cntLines; i++) {
        int cntSpace = 0;
        string nStr = "";
        for (int j = 0; j < lines[i].length(); j++) { //Видалення надлишкових пробілів між словами відповідного рядка
            if (lines[i][j] == ' ') {
                cntSpace++;
            }
            else {
                if (cntSpace != 0) {
                    cntSpace = 0;
                    nStr += ' ';
                }
                nStr += lines[i][j];
            }
        }
        if (nStr[0] == ' ') nStr.erase(0, 1); //Видалення пробіла у випадку першого символу рядка 
        if (nStr[nStr.length() - 1] != ' ') nStr.push_back(' ');
        int cntWords = 0;
        lines[i] = nStr;   //Переназначення вже відредактованої строки замість відповідного елементу у масиві строк 
        while (nStr.length() > 0) { //обрахування к-сті слів  у рядку
            cntWords++;
            nStr.erase(0, nStr.find(' ') + 1);
        }
        string* words = new string[cntWords]; //перезапис рядка в масив слів
        nStr = lines[i];
        for (int j = 0; j < cntWords; j++) {
            words[j] = nStr.substr(0, nStr.find(' '));
            nStr.erase(0, nStr.find(' ') + 1);
        }
        for (int j = 0; j < cntWords - 1; j++) { //сортування слів за алфавітом
            for (int g = 1; g < cntWords; g++) {
                if (words[g - 1].length() > words[g].length()) {
                    for (int k = 0; k < words[g].length(); k++) {
                        if (words[g - 1][k] > words[g][k]) { //перевірка букв сусідніх слів з однаковими індексами
                            string t = words[g];
                            words[g] = words[g - 1];
                            words[g - 1] = t;
                            break;
                        }
                        else if (words[g - 1][k] < words[g][k]) break;
                    }
                }
                else {
                    for (int k = 0; k < words[g - 1].length(); k++) {
                        if (words[g - 1][k] > words[g][k]) {
                            string t = words[g];
                            words[g] = words[g - 1];
                            words[g - 1] = t;
                            break;
                        }
                        else if (words[g - 1][k] < words[g][k]) break;
                    }
                }
            }
        }
        lines[i] = "";
        for (int j = 0; j < cntWords; j++) { //запис відсортованих слів у відповідний рядок
            lines[i] += words[j] + ' ';
        }
        lines[i].pop_back();
    }
    filein.open(adress, fstream::in | fstream::out | fstream::trunc); //запис відповідного рядка масиву до файлу (trunc - для очистки файлу)
    for (int i = 0; i < cntLines; i++) {
        filein << lines[i] << endl;
    }
    filein.close();
}