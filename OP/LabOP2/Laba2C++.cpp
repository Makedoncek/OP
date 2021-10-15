//Варіант 27  Числа a і b виражають довжини катетів одного прямокутного трикутника, а с і d - іншого. З'ясувати, чи є ці трикутники подібними.
#include <iostream>
using namespace std;

int main()
{
	float a, b, c, d; //Введення змінних катетів першого та другого прямокутних трикутників, а також змінних коефіцієнтів пропорційності їхніх сторін
	cout << "Enter the length of the first leg of the first right triangle: ";
	cin >> a;
	cout << "Enter the length of the second leg of the first right triangle: ";
	cin >> b;
	cout << "Enter the length of the first leg of the second right triangle: ";
	cin >> c;
	cout << "Enter the length of the second leg of the second right triangle: ";
	cin >> d;
	float k1 = a / c;
	float k2 = b / d;
	float k3 = a / d;
	float k4 = b / c;
	//Застосування операторів умови для визначення результату завдання
	if (k1 == k2 || k3 == k4) {
		cout << "Triangles are proportional";
	}
	else {
		cout << "Triangles aren`t proportional";
	}
	return 0;
}
