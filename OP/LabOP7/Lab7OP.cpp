#include <iostream>
#include<iomanip>
#include <ctime>
using namespace  std;

int Generation(int*);
void Output(int*, int);
int Min(int*, int);
int Max(int*, int);
float GetMark(int*, int, int);


int main() {
    int size, Marks[10], minimal, maximum, summinmax;
    size = Generation(Marks);
    cout << "The number of marks is " << size << endl;
    Output(Marks, size);

    minimal = Min(Marks, size);  cout << endl << "Minimum mark is: " << minimal << endl;

    maximum = Max(Marks, size); cout << "Maximum mark is: " << maximum << endl;

    summinmax = minimal + maximum; cout << "The sum of minimal and maximal marks is: " << summinmax << endl;


    cout << "Mark for sportsman is " << GetMark(Marks, size, summinmax);
}


//Функція заповнення масиву

int Generation(int array[]) {
    srand(time(NULL));
    int num; cout << "Enter amount of marks "; cin >> num;

    for (int i = 0; i < num; i++) {
        array[i] = rand() % 11;

    }
    return  num;
}


//Функція виводу елементів масиву

void Output(int array[], int size) {
    cout << "Marks of arbiters:";
    for (int i = 0; i < size; i++) {
        cout << setw(3) << array[i];

    }

}

//Функція знаходження мінімального елементу 

int Min(int* array, int size) {
    int min = *array;

    array++;
    for (int i = 1; i < size; i++) {
        if (*array < min)
            min = *array;

        array++;
    }
    return min;
}

//Функція знаходження максимального елементу 

int Max(int* array, int size) {
    int max = *array;
    array++;

    for (int i = 1; i < size; i++) {
        if (*array > max) 
            max = *array;

        array++;
    }


    return  max;

}


//Функція знаходження результату за виступ

float GetMark(int array[], int size, int minmax) {   
    int sum = 0; float mark;

    for (int i = 0; i < size; i++) {
        sum += array[i];

    }
    size -= 2;
    mark = float(sum - minmax) / size;

    return mark;
}
