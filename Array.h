#ifndef Programmka
#define Programmka
#include <iosfwd>
#include <string>

struct Array
{
public:
	Array() = default; // ����������� �� ���������

	~Array(); // �������������� ����������

	Array(const int& q1); // �������� ������� � �������� ��������

	int& operator[] (const ptrdiff_t q1); // ��������� �������� i-���� ��������

	int Size() const; // ��������� �������� ���� size

	void insert(const int& q1, const int& q2); // ������� ����� � ������

	//void insert_massiv(const int q1[], const int q2); // ���������� ������� � ������

	void write_to(); // ����� ������� �� �����
private:
	ptrdiff_t capacity{ 0 }; // ����������� �������

	ptrdiff_t size{ 0 }; // ������� ������ �������

	int* massiv{ nullptr }; // ��� ������

	void add(); // ��������� ������ ������� � ����� �������
};


#endif // !Programmka
