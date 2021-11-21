#include <iostream>
using namespace std;
#define M_PI 3.14159265358979323846


double Ugiver(double first, double second);
double Vgiver(double first, double second);
double Wgiver(double first, double second);



int main() {
    double a, b;
    cout << "Enter your a: ";
    cin >> a;
    cout << "Enter your b: ";
    cin >> b;
    double U = Ugiver(a, b);
    cout << "Function Ugiver return: " << U << "\n";
    double V = Vgiver(a * b, a + b);
    cout << "Function Vgiver return: " << V << "\n";
    double W = Wgiver(U + (pow(V, 2)), M_PI);
    cout << "Function Wgiver return: " << W << "\n";

    return 0;

}
double   Ugiver(double first, double second) {
    if (first > second) {
        return second;
    }
    else if (first < second) {
        return first;
    }
    else return first;
}
double Vgiver(double first, double second) {
    if (first > second) {
        return second;
    }
    else if (first < second) {
        return first;
    }
    else return first;
}

double Wgiver(double first, double second) {
    if (first > second) {
        return second;
    }
    else if (first < second) {
        return first;
    }
    else return first;
}

