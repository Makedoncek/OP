#include <iostream>
#include <fstream>
#include <string>
#include"Functions.h"
using namespace std;


int main() {
    string initial = inputText(); //Cтворення початкового файла з поверненням його адреси з функції
    system("CLS"); //очищення консолі 
    string even = "even.txt"; //Файл для парних рядків
    string odd = "odd.txt"; //Файл для непарних рядків
    cout << "Initial file:\n";
    outputFile(initial);
    cout << "If you want add some information to your file, press:\n1 - Agree\n2 - Deny\nType your answer here: ";
    int choice;
    cin >> choice;
    if (choice == 1) addText(initial);
    system("CLS");
    chooseFile(initial, even, odd);
    cout << "Initial file:\n";
    outputFile(initial);
    cout << "File with even lines (unalphabet):\n";
    outputFile(even);
    alphabetSort(even);
    cout << "File with even lines (alphabet):\n";
    outputFile(even);
    cout << "File with odd lines:\n";
    outputFile(odd);
}

