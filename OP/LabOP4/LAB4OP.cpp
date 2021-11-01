
/*Варіант №27   Нехай задані дійсне число x та ціле число k.Послідовність a1, a2, ..., an  утворена за законом
ai = pow(x, 2) * sin(pow(x, i)) / pow(i, 2), n=1,2,... Отримати суму k - членів даної послідовності. */
#include<cmath>
#include <iostream>
using namespace std;

int main()
{  //Ініціалізація змінних та введення відповідних значень 
    double x;  
    cout << "The x is : ";
    cin >> x;
    int k;
    cout << "The k is : ";
    cin >> k;
    
  if (k >= 1) {    //Перевірка значення k      
      double Ai;
      int i;
      double  S = 0;
      for (i = 1; i <= k; i++) {   // Арифметичний цикл для обчислення суми k членів послідовності 
          Ai = pow(x, 2) * sin(pow(x, i)) / pow(i, 2);
          cout << "The value of a is " << Ai << "\n";
          S = S + Ai;
          cout << "The sum is " << S << "\n";
      }
  }
    else {
       cout << "The sum is 0, error";  //Видання помилки у разі невиконання умови 
   }
  return 0;
    }
    
 


