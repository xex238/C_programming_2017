#include "Array.h"
#include <iostream>
#include <sstream>
using namespace std;

Array::~Array() // Äåñòðóêòîð
{
	delete[] massiv;
	massiv = nullptr;
	capacity = 0;
	size = 0;
}

Array::Array(const int & q1) // Ñîçäàíèå ìàññèâà
{
	massiv = new int[q1];
	for (int i = 0; i < q1; i++)
	{
		massiv[i] = 0;
	}
	size = q1;
	capacity = q1;
}

int & Array::operator[](const ptrdiff_t q1) // Âûçîâ ýëåìåíòà ìàññèâà
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

int Array::Size() const // Ïîëó÷åíèå ðàçìåðà ìàññèâà
{
	return size;
}

void Array::add() // Äîáàâëåíèå ïóñòîãî ýëåìåíòà â ìàññèâ
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

void Array::insert(const int & q1, const int & q2) // Âñòàâêà ýëåìåíòà â ìàññèâ
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

void Array::write_to()
{
	for (int i = 0; i < size; i++)
	{
		cout << massiv[i] << " ";
	}
	cout << endl;
}

