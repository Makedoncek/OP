#include  <iostream>
using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	int sfc, amnseq = 0;
	int firstnumber = 10000;
	int lastnumber = 1000000;

	for (int i = firstnumber; i <= lastnumber; i++) {
		sfc = i;
		int cofdig = 0;
		while (sfc > 0) {
			cofdig++;
			sfc = sfc / 10;
		}


		if (cofdig == 5 && i % 11111 == 0) {
			amnseq++;
			cout << i << "\n";
		}
		else if (cofdig == 6 && i % 1000 == i / 1000 || cofdig == 6 && i / 10000 == (i % 10000) / 100 && i / 10000 == (i % 10000) % 100 && (i % 10000) / 100 == (i % 10000) % 100) {
			amnseq++;
			cout << i << "\n";
		}
	}
		cout << "Количество чисел, которые состоят из последовательности цифр " << amnseq;
		return 0;
	}
	
