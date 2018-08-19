//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include<math.h>
#include<string>
#include<ctime>

using namespace std;

//1.	Напишите шаблон функции, которая вычисляет корень линейного уравнения.
template<class type>
type root(type a, type b) {
	type x;
	if (a != 0)
		x = -b / a;
	return x;
}

//2.	Написать функцию, определяющую среднее арифметическое элементов передаваемого ей массива.
template<typename t>
double aver_arr(t arr[], int size) {
	t sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return (double)sum / size;
}

//3.	Написать шаблонную функцию, определяющую количество положительных,
//отрицательных и нулевых элементов передаваемого ей массива.
template<typename type>
void plusminus(type arr[], int size) {
	int k1 = 0, k2 = 0, k3 = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
			k1++;
		else if (arr[i] > 0)
			k2++;
		else if (arr[i] == 0)
			k3++;
	}
	cout << "- elements: " << k1 << endl;
	cout << "+ elements: " << k2 << endl;
	cout << "zeros: " << k3 << endl << endl;
}

//4.	Написать шаблонную функцию, определяющую минимум и максимум(значение и номер)
//элементов передаваемого ей массива.
template<typename type>
void minmax(type arr[], int size) {
	type min = arr[0], max = arr[0];
	int min_pos = 0, max_pos = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_pos = i;
		}

		if (arr[i] > max)
		{
			max = arr[i];
			max_pos = i;
		}
	}
	cout << min << "; " << min_pos << endl;
	cout << max << "; " << max_pos << endl << endl;
}

//5.	Написать шаблонную функцию, меняющую порядок следования элементов
//передаваемого ей массива на противоположный.
template<typename type>
void reverse_arr(type arr[], int size) {
	for (int i = 0; i < size / 2; i++)
		swap(arr[i], arr[size - i - 1]);

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl << endl;
}

//6.	Написать функцию, возвращающую количество простых чисел в передаваемом ей массиве.
void count_prime(int arr[], int size) {
	int count = 0;
	
	for (int i = 0; i < size; i++)
	{
		bool prime = true;
		if (arr[i] < 2) prime = false;
		for (int j = 2; j < arr[i]; j++)
		{
			if (arr[i] % j == 0)
			{
				prime = false;
				break;
			}
		}
		if (prime == true)
		{
			count++;
			cout << arr[i] << " ";
		}
	}
	cout << endl << count << " prime numbers" << endl << endl;
	}



int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		{
			double a = 2;
			double b = -2.6;

			cout << root(a, b) << endl << endl;
		}
		break;
		case 2:
		{
			double a[7] = { 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5 };
			int b[] = { 1, 2, 3, 4, 5, 6 };

			cout << aver_arr(a, 7) << endl << endl;
			cout << aver_arr(b, 6) << endl << endl;
		}
		break;
		case 3:
		{
			double a[7] = { 1.5, -2.5, -3.5, 4.5, 0, 6.5, 7.5 };
			int b[] = { -1, 0, 3, 0, 5, 6, 0 };

			plusminus(a, 7);
			plusminus(b, 7);
		}
		break;
		case 4:
		{
			double a[7] = { 1.5, -2.5, -3.5, 4.5, 0, 6.5, 7.5 };
			int b[] = { -1, 0, 3, 0, 5, 6, 0 };

			minmax(a, 7);
			minmax(b, 7);
		}
		break;
		case 5:
		{
			double a[7] = { 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5 };
			int b[] = { 1, 2, 3, 4, 5, 6 };

			reverse_arr(a, 7);
			reverse_arr(b, 6);
		}
		break;
		case 6:
		{
			int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

			count_prime(a, 21);
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}