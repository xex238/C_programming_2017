#ifndef Programka
#define Programka
#include <iostream>

template <typename T>
struct Array
{
public:

	Array();

	Array(const int& q1);

	~Array();

	bool IsEmpty();

	void Add();

	void insert(const T& q1);

	void insert(const T& q1, const T& q2);

	const int Size() const;

	Array& operator= (const Array& q1);

	T& operator[] (const ptrdiff_t q1);

	const T& operator[] (const ptrdiff_t q1) const;

private:
	ptrdiff_t capacity{ 0 };
	ptrdiff_t size{ 0 };
	T* p_data{ nullptr };
};

template <typename T>
Array<T>::Array()
{
	capacity = 2;
	p_data = new T[capacity];
	size = 0;
}

template <typename T>
Array<T>::~Array()
{
	capacity = 0;
	size = 0;
	p_data = nullptr;
	delete[] p_data;
}

template <typename T>
Array<T>::Array(const int& q1)
{
	if (q1 > 0)
	{
		p_data = new T[q1];
		capacity = q1;
		size = q1;
	}
	else
	{
		throw std::out_of_range("index out of range");
	}
}

template <typename T>
bool Array<T>::IsEmpty()
{
	return p_data == nullptr;
}

template <typename T>
void Array<T>::insert(const T& q1)
{
	Add();
	p_data[size - 1] = q1;
}

template <typename T>
void Array<T>::insert(const T& q1, const T& q2)
{
	if (q2 >= 0 || q2 < size)
	{
		insert(q1);
		for (ptrdiff_t i = size - 1; i > q2; i--)
		{
			std::swap(p_data[i], p_data[i - 1]);
		}
	}
	else
	{
		throw std::out_of_range("index out of range");
	}
}

template <typename T>
void Array<T>::Add()
{
	if (size == capacity)
	{
		T* p_data_2 = new T[size * 2];
		for (ptrdiff_t i = 0; i < size; i++)
		{
			p_data_2[i] = p_data[i];
		}
		std::swap(p_data_2, p_data);
		delete[] p_data_2;
		capacity *= 2;
	}
	size++;
}

template <typename T>
const int Array<T>::Size() const
{
	return size;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array & q1)
{
	p_data = new T[q1.Size()];
	for (ptrdiff_t i = 0; i < q1.Size(); i++)
	{
		*(p_data + i) = q1[i];
	}
	size = q1.Size();
	capacity = q1.Size();
	return *this;
}

template <typename T>
T& Array<T>::operator[](const ptrdiff_t q1)
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
const T& Array<T>::operator[](const ptrdiff_t q1) const
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
#endif // !Programka

