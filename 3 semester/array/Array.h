#ifndef Programmka
#define Programmka

#include <iosfwd>

struct Array
{
public:
	Array();

	~Array();

	Array(const int& q1);

	int& operator[] (const ptrdiff_t q1);

	int Size() const;

	void insert(const int& q1, const int& q2);

	void insert_massiv(const int q1[], const int q2);

	void write_to();

	void add();

private:

	ptrdiff_t capacity{ 0 };

	ptrdiff_t size{ 0 };

	int* massiv{ nullptr };
};

#endif // !Programmka
