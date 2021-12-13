#include <iostream>
#include <ctime>
using namespace std;

//Прототипізація функцій
void Generation(int**, int);
void Input(int**, int);
void Output(int**, int);
void Changer(int**, int);
void Creator(int**, int**, int**, int);

int main() {
    srand(time(NULL));

    int n;
    cout << "Enter amount of Matrix: "; cin >> n; //Введення розмірності матриці
    int** A = new int* [n];                //Створення динамічного масиву, введення елементів у нього та їх виведення
    Generation(A, n);
    Input(A, n);
    cout << "Matrix A" << endl; Output(A, n);

    int** B = new int* [n];             //Створення динамічного масиву, введення елементів у нього та їх виведення
    Generation(B, n); Input(B, n);
    cout << endl << "Matrix B" << endl; Output(B, n);

    Changer(A, n); Changer(B, n);           //Видозмінення матриці зміна діагонального елементу на мінімальний та навпаки
    cout << endl << "Matrix A after changes" << endl; Output(A, n);
    cout << endl << "Matrix B after changes" << endl; Output(B, n);

    int** Q = new int* [n];  //Створення динамічного масиву, введення елементів на основі більшого елементу з двох матриць у нього та їх виведення
    Generation(Q, n);
    Creator(A, B, Q, n);
    cout << endl << "Matrix Q" << endl; Output(Q, n);
    //Видалення ініціалізованої пам'яті для  Динамічних Масивів
    delete[] A;
    delete[] B;
    delete[] Q;
    return 0;
}
//Генерація динамічних одновимірних масивів,які стануть рядками двовимірного масива
void Generation(int** Matrix, int size) {
    for (int i = 0; i < size; i++) {
        Matrix[i] = new int[size];
    }
}
//Заповненя масива елементами
void Input(int** Matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Matrix[i][j] = rand() % 101;
        }

    }

}
//Виведення масиву
void Output(int** Matrix, int size) {

    for (int i = 0; i < size; i++) {
        cout << endl;
        for (int j = 0; j < size; j++) {
            cout << "\t" << Matrix[i][j];
        }
    }

}
//Зміна елементів місцями у масиві - зміна діагонального елементу на мінімальний та навпаки
void Changer(int** Matrix, int size) {
    int min, pos, diag;
    for (int i = 0; i < size; i++) {
        min = 1000;
        diag = Matrix[i][i];
        for (int j = 0; j < size; j++) {
            if (Matrix[i][j] < min) {
                min = Matrix[i][j];
                pos = j;               //Запам'ятовування позиції мінімального елемента
            }
        }
        Matrix[i][i] = min;
        Matrix[i][pos] = diag;
    }
}
//Створення масиву Q на основі двох перших масивів за допомогою порівняння та віднайдення відповідного більшого елемента
void Creator(int** A, int** B, int** Q, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (A[i][j] >= B[i][j]) {
                Q[i][j] = A[i][j];
            }
            else {
                Q[i][j] = B[i][j];
            }
        }
    }
}