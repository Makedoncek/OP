#include  <iostream>
using namespace std;



int main() {
	setlocale(LC_ALL, "Russian");
	int saveriforCount, amountnumbseq = 0;
	int firstnumber = 10000; 
	int lastnumber = 1000000;
	
	for (int i = firstnumber; i <= lastnumber; i++) {
		saveriforCount = i;
		int counterofdigits = 0;
		while (saveriforCount > 0) {
			counterofdigits++;
				saveriforCount = saveriforCount / 10;
		}
		
		    if (counterofdigits == 5 && i % 11111 == 0) {
				amountnumbseq++;
				cout << i << "\n";
		}
			else if (counterofdigits == 6) {
				
				 if (i % 1000 == i / 1000) {
					 amountnumbseq++;
					 cout << i<<"\n";
				 }
				 
				 else if (i / 10000 == (i % 10000) / 100 && i / 10000 == (i % 10000) % 100 && (i % 10000) / 100 == (i % 10000) % 100) {
					 amountnumbseq++;
					 cout << i << "\n";
				 }
				 

				 

			}
	}
	cout << "Количество чисел, которые состоят из последовательности цифр " << amountnumbseq;
	return 0;
}
