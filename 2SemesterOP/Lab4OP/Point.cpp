#include "Point.h"
#include <cmath>


//������ � ������ ��������� �������� ����� �����
void Point::SetX(double X) {
	this->X = X;
}

double Point::GetX() {
	return this->X;
}

void Point::SetY(double Y) {
	this->Y = Y;
}

double Point::GetY() {
	return Y;
}


//������� ��� ����������� ��������� �������� �����
int Point::GetQuadrant() {
	if (X > 0 && Y > 0) return 1;
	else if (X < 0 && Y > 0) return 2;
	else if (X < 0 && Y < 0) return 3;
	else if (X > 0 && Y < 0) return 4;
	else return 0;
	
}
//����������� � ��������� �����
Point::Point() {
	cout << "Enter T3 Point x coordinate: ";
	cin >> this->X;
	cout << "Enter T3 Point y coordinate: ";
	cin >> this->Y;
}
//����������� � ������������ ��������� ��� ����� �� ����������� �������� ��'���� � ��������� ������
Point::Point(double X,double Y) {
	SetX(X);
	SetY(Y);
}



//�������� ��������� ����� � ��������� �� ��������� ��������� ������������
Point::Point(int quadrant) {
	
	srand(time(NULL));
	switch (quadrant) {
	case 1:
		SetX(round((double)rand() / RAND_MAX * 10 * 10) / 10);
		SetY(round((double)rand() / RAND_MAX * 10 * 10) / 10);
		break;
	case 2:
		SetX(round(((double)rand() / RAND_MAX * 10 - 10) * 10) / 10);
		SetY(round((double)rand() / RAND_MAX * 10 * 10) / 10);
		break;
	case 3:
		SetX(round(((double)rand() / RAND_MAX * 10 - 10) * 10) / 10);
		SetY(round(((double)rand() / RAND_MAX * 10 - 10) * 10) / 10);
		break;
	case 4:
		SetX(round((double)rand() / RAND_MAX * 10 * 10) / 10);
		SetY(round(((double)rand() / RAND_MAX * 10 - 10) * 10) / 10);
		break;
	default:
		cout << "Incorrect quadrant in constructor!\nSetted an default zero values"<<endl;
		SetX(0);
		SetY(0);
	}
	}

//�������������� ��������� - ��� ��������� ������� �� ����� �������
double operator - (Point T1, Point T2) {

	return sqrt(pow(T2.GetX()-T1.GetX(),2)+pow((T2.GetY()-T1.GetY()),2));

}
//�������������� ����������� ���������� ��� ��������� X �� 1
Point& Point::operator++() {
	++this->X;
	return (*this);
}

Point Point::operator++(int) {
	return{ this->X, this->Y++ };
}
// ��������� ������ � ����� ����������� ��'���� ����� �����
void Show(Point points[]) {
	for (int i = 0; i < 3; i++) {
		cout << "Point T" << i + 1 << " X:" << points[i].GetX() << " Y:" << points[i].GetY() << endl;
	}

}