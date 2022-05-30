import math
import random

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def getX(self):
        return self.x

    def getY(self):
        return self.y

    def setX(self, x):
        self.x = x

    def setY(self, y):
        self.y = y

    def __str__(self): # перетворюємо інформацію про точку в рядок
        return f"({self.x},{self.y})"


class TTriangle:
    def __init__(self, P1, P2, P3): # використовуємо об'єкти класу точки як атрибути класу трикутника (вершини)
        self.P1 = P1
        self.P2 = P2
        self.P3 = P3

    def getA(self): # знаходимо сторони трикутника
        return round(math.sqrt(pow(self.P2.getX() - self.P1.getX(), 2) + pow(self.P2.getY() - self.P1.getY(), 2)), 2)

    def getB(self):
        return round(math.sqrt(pow(self.P3.getX() - self.P1.getX(), 2) + pow(self.P3.getY() - self.P1.getY(), 2)), 2)

    def getC(self):
        return round(math.sqrt(pow(self.P3.getX() - self.P2.getX(), 2) + pow(self.P3.getY() - self.P2.getY(), 2)), 2)

    def getPerimeter(self):  # знаходимо периметр трикутника
        return self.getA() + self.getB() + self.getC()
    def getSquare(self):
        pass

    def print(self):
        pass

class PTriangle(TTriangle): # прямокутний трикутник
    def __init__(self, P1, P2, P3): # наслідуємо від класу TTriangle атрибути (об'єкти класу точки)
        super().__init__(P1, P2, P3)

    def print(self):
        print(f"PTriangle:\n A:{self.P1}, B:{self.P2}, C:{self.P3}\nLength of AB:{self.getA()}, BC:{self.getB()}, AC:{self.getC()}" )

    def getSquare(self): # знаходимо площу трикутника
        if self.getA() > self.getB():
            if self.getA() > self.getC():
                return 0.5 * self.getB() * self.getC()
            elif self.getB() > self.getC():
                return 0.5 * self.getC() * self.getA()
            else:
                return 0.5 * self.getA() * self.getB()


class ETriangle(TTriangle): # рівносторонній трикутник
    def __init__(self, P1, P2, P3): # наслідуємо від класу TTriangle атрибути (об'єкти класу точки)
        super().__init__(P1, P2, P3)

    def print(self):
        print(f"ETriangle:\nA:{self.P1}, B:{self.P2}, C:{self.P3}\nLength of AB:{self.getA()}, BC:{self.getB()}, AC:{self.getC()}")

    def getSquare(self): # знаходимо площу трикутника
        return self.getA()*self.getA()*math.sqrt(3)/4


class ITriangle(TTriangle): # рівнобедренний трикутник
    def __init__(self, P1, P2, P3): # наслідуємо від класу TTriangle атрибути (об'єкти класу точки)
        super().__init__(P1, P2, P3)

    def print(self):
        print(f"ITriangle:\nA:{self.P1}, B:{self.P2}, C:{self.P3}\nLength of AB:{self.getA()}, BC:{self.getB()}, AC:{self.getC()}")


def GetEtPoint():
    p1 = Point(round(random.uniform(-10, 10), 2), round(random.uniform(-10, 10), 2))
    p2 = Point(round(random.uniform(-10, 10), 2), round(random.uniform(-10, 10), 2))
    p3 = Point(0, 0)
    p3.setX(round((p2.getX() - p1.getX()) * 0.5 - (p2.getY() - p1.getY()) * math.sqrt(3) / 2 + p1.getX(), 2))
    p3.setY(round((p2.getX() - p1.getX()) * math.sqrt(3) / 2 + (p2.getY() - p1.getY()) * 0.5 + p1.getY(), 2))
    return [p1, p2, p3]


def GetItPoint():
    p1 = Point(round(random.uniform(-10, 10), 2), round(random.uniform(-10, 10), 2))
    p2 = Point(round(random.uniform(-10, 10), 2), round(random.uniform(-10, 10), 2))
    p3 = Point(0, 0)
    if p1.getX() > p2.getX():
        p3.setX(round(p2.getX() - abs(p1.getX() - p2.getX()), 2))
    else:
        p3.setX(round(abs(p1.getX() - p2.getX()) + p2.getX(), 2))
    p3.setY(p1.getY())
    return [p1, p2, p3]

def GetRtPoint():
    p1 = Point(round(random.uniform(-10, 10), 2), round(random.uniform(-10, 10), 2))
    p2 = Point(round(random.uniform(-10, 10), 2), round(random.uniform(-10, 10), 2))
    p3 = Point(p1.getX(), p2.getY())
    return [p1, p2, p3]










