#ifndef Arraystack_H
#define Arraystack_H
#include "Array_stack.h"

template <typename T>
struct Array_stack
{
public:

	Array_stack() = default;

	~Array_stack() = default;

	Array_stack& operator=(const Array_stack& q1);

	void insert(const T& q1);

	const T& top() const;

	const int Size() const;

	void pop();

	const bool isEmpty() const;

	T& operator[] (const ptrdiff_t q1);
private:
	Array<T> p_data;
	ptrdiff_t size{ 0 };
};

template <typename T>
void Array_stack<T>::insert(const T& q1)
{
	if (size < p_data.Size())
	{
		p_data[size] = q1;
	}
	else
	{
		p_data.insert(q1);
	}
	size++;
}

template <typename T>
const T& Array_stack<T>::top() const
{
	return p_data[size - 1];
}

template<typename T>
const int Array_stack<T>::Size() const
{
	return p_data.Size();
}

template <typename T>
void Array_stack<T>::pop()
{
	if (size > 0)
	{
		size--;
	}
	else
	{
		throw std::exception("You are not allowed to delete this item. Stack is hollow");
	}
}

template <typename T>
const bool Array_stack<T>::isEmpty() const
{
	return (size == 0);
}

template<typename T>
T& Array_stack<T>::operator[](const ptrdiff_t q1)
{
	if (q1 >= 0 && q1 < size)
	{
		return p_data[q1];
	}
	else
	{
		throw std::out_of_range("index out of range");
	}
}

template <typename T>
Array_stack<T>& Array_stack<T>::operator=(const Array_stack& q1)
{
	Array<T> newData_(q1.size);
	for (ptrdiff_t i = 0; i < q1.size; i++)
	{
		newData_[i] = q1.p_data[i];
	}
	size = q1.size;
	p_data = newData_;
	return *this;
}
#endif
