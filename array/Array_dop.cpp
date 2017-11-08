#include "Array.h"
#include <iostream>
using namespace std;

Array::~Array() // Конструктор
{
	delete[] massiv;
	massiv = nullptr;
	capacity = 0;
	size = 0;
}

Array::Array(const int & q1) // Создание массива
{
	massiv = new int[q1];
	for (int i = 0; i < q1; i++)
	{
		massiv[i] = 0;
	}
	size = q1;
	capacity = q1;
}

int & Array::operator[](const ptrdiff_t q1) // Вызов элемента массива
{
	if (q1 < 0 || q1 >= size)
	{
		throw new std::exception;
	}
	else
	{
		return massiv[q1];
	}
}

int Array::Size() const // Получение размера массива
{
	return size;
}

void Array::add() // Добавление пустого элемента в массив
{
	if (size < capacity)
	{
		size++;
	}
	else
	{
		int* new_massiv = new int[capacity * 2];
		for (int i = 0; i < size; i++)
		{
			new_massiv[i] = massiv[i];
		}
		size++;
		capacity = capacity * 2;
		std::swap(massiv, new_massiv);
	}
}

void Array::insert(const int & q1, const int & q2) // Вставка элемента в массив
{
	if (q2 < 0 || q2 >= size)
	{
		throw new std::exception;
	}
	else
	{
		add();
		for (int i = size - 1; i > q2; i--)
		{
			massiv[i + 1] = massiv[i];
		}
		massiv[q2] = q1;
	}
}

//void Array::insert_massiv(const int q1[], const int q2)
//{
//	int a = sizeof(q1);
//	int m = 0;
//	if (q2 < 0 || q2 >= size)
//	{
//		throw new exception;
//	}
//	else
//	{
//		for (int i = 0; i < a; i++)
//		{
//			add();
//		}
//		for (int i = size - 1; i < q2; i--)
//		{
//			massiv[size + 1] = massiv[size - a];
//		}
//		for (int i = q2; i < q2 + a; i++)
//		{
//			massiv[i] = q1[m];
//			m++;
//		}
//	}
//}

void Array::write_to() // Вывод масива на экран
{
	for (int i = 0; i < size; i++)
	{
		cout << massiv[i] << " ";
	}
	cout << endl;
}

