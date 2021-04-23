def trapezoidal(f, a, b, n):
    integral = 0
    for i in range(n):
        x_i = a + (b - a) * i / n
        x_j = a + (b - a) * (i + 1) / n
        integral += (f((x_i + x_j) / 2) * (x_j - x_i))
    return integral

def trapezoidalauto(f, a, b, eps):
    integral = 0
    n = 1
    for i in range(n):
        x_i = a + (b - a) * i / n
        x_j = a + (b - a) * (i + 1) / n
        integral += (f((x_i + x_j) / 2) * (x_j - x_i))
    return integral

def main():
    print(trapezoidal('x^2', 0, 2, 1))