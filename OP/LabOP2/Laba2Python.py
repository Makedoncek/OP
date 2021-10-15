#Варіант 27  Числа a і b виражають довжини катетів одного прямокутного трикутника, а с і d - іншого. З'ясувати, чи є ці трикутники подібними.

#Введення змінних катетів першого та другого прямокутних трикутників, а також змінних коефіцієнтів пропорційності їхніх сторін
a=float(input("Enter the length of the first leg of the first right triangle: "))
b=float(input("Enter the length of the second leg of the first right triangle: " ))
c=float(input("Enter the length of the first leg of the second right triangle: " ))
d=float(input("Enter the length of the second leg of the second right triangle: "))
k1=float(a/c)
k2=float(b/d)
k3=float(a/d)
k4=float(b/c)
#Застосування операторів умови для визначення результату завдання
if k1 == k2 or k3 == k4:
  print("Triangles are proportional")
else:
 print("Triangles aren`t proportional")
