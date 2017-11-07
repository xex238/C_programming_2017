#ifndef Programmka
#define Programmka
#include <iosfwd>
#include <string>

struct Array
{
public:
	Array() = default; // Êîíñòðóêòîð ïî óìîë÷àíèþ

	~Array(); // Ïåðåîïðåäåëÿåì äåñòðóêòîð

	Array(const int& q1); // Ñîçäàíèå ìàññèâà ñ çàäàííûì ðàçìåðîì

	int& operator[] (const ptrdiff_t q1); // Ïîëó÷åíèå çíà÷åíèÿ i-íîãî ýëåìåíòà

	int Size() const; // Ïîëó÷åíèå çíà÷åíèÿ ïîëÿ size

	void insert(const int& q1, const int& q2); // Âñòàâêà ÷èñëà â ìàññèâ

	//void insert_massiv(const int q1[], const int q2); // Äîáàâëåíèå ìàññèâà â ìàññèâ

	void write_to(); // Âûâîä ìàññèâà íà ýêðàí
private:
	ptrdiff_t capacity{ 0 }; // Âìåñòèìîñòü ìàññèâà

	ptrdiff_t size{ 0 }; // Òåêóùèé ðàçìåð ìàññèâà

	int* massiv{ nullptr }; // Ñàì ìàññèâ

	void add(); // Äîáàâëÿåò ïóñòîé ýëåìåíò â êîíåö ìàññèâà
};


#endif // !Programmka
