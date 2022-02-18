#ifndef Programka
#define Programka

class Matrix
{
public:
	int **matrix{ nullptr };

	~Matrix();

	Matrix() = default;

	Matrix(const Matrix& q);

	Matrix(int n_Rows, int n_Columns);

	Matrix(int **mat, int n_Rows, int n_Columns);

	void Add(int mass[], ptrdiff_t n_Columns);

	const int& N_Rows() const { return n_Rows; };

	const int& N_Columns() const { return n_Columns; };

	Matrix& operator+=(const Matrix& q1);
	Matrix& operator-=(const Matrix& q1);
	Matrix& operator*=(const Matrix& q1);
	double Opredelitel(const Matrix& q1);
	//std::ostream& Write_to(std::ostream& ost) const;
	//std::iostream& Read_from(std::iostream& ios);
private:
	ptrdiff_t n_Rows{ 0 };

	ptrdiff_t n_Columns{ 0 };
};

Matrix& operator+(const Matrix& q1, const Matrix& q2);
Matrix& operator-(const Matrix& q1, const Matrix& q2);
Matrix& operator*(const Matrix& q1, const Matrix& q2);

//inline std::ostream& operator<<(std::ostream& ost, Matrix q1)
//{
//	return q1.Write_to(ost);
//}
//
//inline std::iostream& operator >> (std::iostream& ios, Matrix q1)
//{
//	return q1.Read_from(ios);
//}

#endif // !Programka
