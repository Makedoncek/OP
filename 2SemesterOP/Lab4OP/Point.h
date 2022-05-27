#pragma once
#include <iostream>
using namespace std;

class Point {
	//�������� ����� ����� �� �����
private:
	double X;
	double Y;

public:
	//������ �� ������
	void SetX(double);


	double GetX();

	void SetY(double);
		
	double GetY();

	int GetQuadrant();
	//����������� �� �������������
	Point();
	//� �����������
	Point(double, double);
	//����������� �� ������
	Point(int);
	

	//������� �������������� ���������
	friend double operator - (Point, Point);
	Point& operator++();
	Point operator++(int);

};


void Show(Point[]); //��������� ������ ����� �����



