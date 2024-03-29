#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

#define eps 0.001
#define e 2.718281828

double Func(double x)  // начальная функция
{
	return ((1 - x)*(1 - x) + pow(e, x));
}
double F(int n)   // возрат числа Фибоначчи по порядковому номеру
{
	double f, f1 = 1, f2 = 1, m = 0;
	while (m < n - 1)
	{
		f = f1 + f2;
		f1 = f2;
		f2 = f;
		++m;
	}
	return f1;
}
void Fib(double a, double b)
{
	cout << "\n\n\n\tМетод Фибоначчи:\n\n";
	double x1, x2, _x, xf1, xf2;
	int k = 0, N = 0;
	double fn1 = 1, fn2 = 1, fn, f = (b - a) / eps;
	while (fn1 < f)  // ищем N - число итераций
	{
		fn = fn1 + fn2;
		fn1 = fn2;
		fn2 = fn;
		++N;
	}
	x1 = a + F(N - 2) / F(N) * (b - a);  // формула для 
	x2 = a + F(N - 1) / F(N) * (b - a);
	xf1 = Func(x1);
	xf2 = Func(x2);
P:
	++k;  // k - число прошедших итераций
	if (xf1 >= xf2)
	{
		a = x1;
		x1 = x2;
		xf1 = xf2;
		x2 = a + F(N - k - 1) / F(N - k) * (b - a);
		xf2 = Func(x2);
	}
	else
	{
		b = x2;
		x2 = x1;
		xf2 = xf1;
		x1 = a + F(N - k - 2) / F(N - k) * (b - a);
		xf1 = Func(x1);
	}
	cout << "Итерация № " << k << '\n' // промежуточная печать
		<< "x1 = " << x1 << "\t\tF(x1) = " << xf1
		<< "\nx2 = " << x2 << "\t\tF(x2) = " << xf2
		<< '\n' << std::endl;
	if (fabs(b - a) <= eps)  // уменьшаем расстояние пока не станет меньше eps
	{
		_x = (a + b) / 2;  // ответ
		cout << "Результат:\nx = " << _x << "\t\tF(x) = " << Func(_x) <<
			"\nКоличество итераций: " << k;
	}
	else
		goto P;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	double a = -5, b = 2;
	Fib(a, b);
	system("pause");
    return 0;
}

