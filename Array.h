#ifndef Programmka
#define Programmka
#include <iosfwd>
#include <string>

struct Array
{
public:
	Array() = default; // Конструктор по умолчанию

	~Array(); // Переопределяем деструктор

	Array(const int& q1); // Создание массива с заданным размером

	int& operator[] (const ptrdiff_t q1); // Получение значения i-ного элемента

	int Size() const; // Получение значения поля size

	void insert(const int& q1, const int& q2); // Вставка числа в массив

	//void insert_massiv(const int q1[], const int q2); // Добавление массива в массив

	void write_to(); // Вывод массива на экран
private:
	ptrdiff_t capacity{ 0 }; // Вместимость массива

	ptrdiff_t size{ 0 }; // Текущий размер массива

	int* massiv{ nullptr }; // Сам массив

	void add(); // Добавляет пустой элемент в конец массива
};


#endif // !Programmka
