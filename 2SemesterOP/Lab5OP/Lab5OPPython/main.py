

import func


if __name__ == '__main__':
    n = int(input("How many triangles you want to create?\n"))
    pArr = [] # список об'єктів класу PTriangle
    eArr = [] # ...ETriangle
    iArr = [] # ...ITriangle
    sumP = 0 # сума площ прямокутних трикутників
    sumE = 0 # сума площ рівносторонніх трикутників
    sumI = 0 # сума площ рівнобедренних трикутників
    for i in range(0, n):
        # генеруємо вершини прямокутного трикутника
        pointRT = func.GetRtPoint()
        temp = func.PTriangle(pointRT[0], pointRT[1], pointRT[2])
        pArr.append(temp)

        #генеруємо вершини рівнобедренного трикутника
        pointIT = func.GetItPoint()
        temp = func.ITriangle(pointIT[0], pointIT[1], pointIT[2])
        iArr.append(temp)

        # генеруємо вершини рівностороннього трикутника
        pointET = func.GetEtPoint()
        temp = func.ETriangle(pointET[0], pointET[1], pointET[2])
        eArr.append(temp)

    for i in range(0, n):
        pArr[i].print()
    print("-------------------")
    for i in range(0, n):
        eArr[i].print()
    print("-------------------")
    for i in range(0, n):
        iArr[i].print()
        sumP = sumP + pArr[i].getSquare()
        sumI = sumI + eArr[i].getSquare()
        sumE = sumE + iArr[i].getPerimeter()
    print("-------------------")

    print("Sum of squares of right triangles: " + str(round(sumP, 2)) + ";\nSum of squares of equilateral triangles: " + str(round(sumE, 2)) + ";\nSum of perimeters of isosceles triangles: " + str(round(sumI, 2)) + ".")

