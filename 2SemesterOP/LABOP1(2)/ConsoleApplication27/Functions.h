#pragma once
#include <string>
using namespace std;
string inputText(); //заповнення текстом стартового файлу
void addText(string); //Доповнення файла текстом у разі потреби користувача
void chooseFile(string, string, string); //Розподілення тексту по відповідним файлам
void outputFile(string); //Виведення інформації з відповідного файла
void alphabetSort(string); //Відсортування слів у рядках файла за алфавітом