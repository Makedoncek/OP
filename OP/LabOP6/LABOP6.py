import math


def ugiver(first, second):
    if first > second:
        return second
    elif first < second:
        return first
    else:
        return first


def vgiver(first, second):
    if first > second:
        return second
    elif first < second:
        return first
    else:
        return first


def wgiver(first, second):
    if first > second:
        return second
    elif first < second:
        return first
    else:
        return first


a = float(input("Enter your a: "))
b = float(input("Enter your b: "))
U = ugiver(a, b)
print("Function ugiver return: " + (str(U)))
V = vgiver(a * b, a + b)
print("Function vgiver return: " + (str(V)))
W = wgiver(U + V * V, math.pi)
print("Function wgiver return: " + (str(W)))
