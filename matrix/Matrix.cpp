#include "Matrix.h"
Matrix::Matrix()
{
	this->i = 0;
	this->j = 0;
	this->Matr = nullptr;
}
Matrix::Matrix(int a, int b, int num)
{
	if (a <= 0 || b <= 0) return;

	this->Matr = new int*[a];

	this->i = a;
	this->j = b;

	for (size_t i = 0; i < this->i; i++)
	{
		Matr[i] = new int[b];
		for (size_t j = 0; j < this->j; j++)
		{
			Matr[i][j] = num;
		}
	}
}
void Matrix::print() const
{
	if (Matr == nullptr) return;
	for (size_t a = 0; a < this->i; a++)
	{
		for (size_t b = 0; b < this->j; b++)
		{
			cout << Matr[a][b] << ' ';
		}
		cout << endl;
	}
}
void Matrix::transp()
{
	int** t;
	int a = this->i;
	int b = this->j;
	t = new int*[a];
	for (size_t j = 0; j < b; j++)
	{
		t[j] = new int[a];
	}
	for (size_t j = 0; j < b; j++)
	{
		for (size_t i = 0; i < a; i++)
		{
			t[j][i] = Matr[i][j];
		}
	}
	this->~Matrix();
	this->Matr = t;
	this->i = b;
	this->j = a;

}
void Matrix::operator*=(int num)
{
	for (size_t i = 0; i < this->i; i++)
	{
		for (size_t j = 0; j < this->j; j++)
		{
			Matr[i][j] *= num;
		}
	}
}
void Matrix::operator+=(int num)
{
	for (size_t i = 0; i < this->i; i++)
	{
		for (size_t j = 0; j < this->j; j++)
		{
			Matr[i][j] += num;
		}
	}
}
void Matrix::operator/=(int num)
{
	for (size_t i = 0; i < this->i; i++)
	{
		for (size_t j = 0; j < this->j; j++)
		{
			Matr[i][j] /= num;
		}
	}
}
void Matrix::operator-=(int num)
{
	for (size_t i = 0; i < this->i; i++)
	{
		for (size_t j = 0; j < this->j; j++)
		{
			Matr[i][j] -= num;
		}
	}
}
int * Matrix::operator[](int i) const
{
	return this->Matr[i];
}
Matrix::Matrix(const Matrix & m)
{
	if (m.Matr == nullptr) {
		this->i = this->j = 0;
		this->Matr = nullptr;
		return;
	}
	this->i = m.i;
	this->j = m.j;
	this->Matr = new int*[m.i];
	for (int a = 0; a < m.i; a++)
	{
		this->Matr[a] = new int[m.j];

		for (int b = 0; b < m.j; b++)
		{
			this->Matr[a][b] = m.Matr[a][b];
		}
	}
}
Matrix & Matrix::operator=(const Matrix & m)
{

	if (this == &m) return *this;

	if (this->i == m.i && this->j == m.j)
	{
		for (int a = 0; a < m.i; a++)
		{
			for (int b = 0; b < m.j; b++)
			{
				this->Matr[a][b] = m.Matr[a][b];
			}
		}
		return *this;
	}
	this->~Matrix();
	if (m.Matr == nullptr) return *this;

	this->i = m.i;
	this->j = m.j;
	this->Matr = new int*[m.i];
	for (int a = 0; a < m.i; a++)
	{
		this->Matr[a] = new int[m.j];
		for (int b = 0; b < m.j; b++)
		{
			this->Matr[a][b] = m.Matr[a][b];
		}
	}
	return *this;
}
Matrix::Matrix(Matrix && m)
{
	this->i = m.i;
	this->j = m.j;
	this->Matr = m.Matr;
	m.i = 0;
	m.j = 0;
	m.Matr = nullptr;
}
Matrix & Matrix::operator=(Matrix && m)
{
	this->~Matrix();
	this->i = m.i;
	this->j = m.j;
	this->Matr = m.Matr;
	m.i = 0;
	m.j = 0;
	m.Matr = nullptr;
	return *this;
}
Matrix::~Matrix()
{
	for (int i = 0; i < this->i; i++)
	{
		delete[]Matr[i];
	}
	delete[]Matr;
	this->i = 0;
	this->j = 0;
	this->Matr = nullptr;
}
bool operator==( const Matrix & m1, const Matrix & m2)
{
	if (m1.getI() != m2.getI() || m1.getJ() != m2.getJ())
		return false;	
	int a = m1.getI();
	int b = m1.getJ();
	for (int i = 0; i <a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (m1[i][j] != m2[i][j])
				return false;
		}
	}
	return true;	
}
ostream & operator<<(ostream & os, const Matrix & m)
{
	for (int i = 0; i < m.getI(); i++)
	{
		for (int j = 0; j < m.getJ(); j++)
		{
			os << m[i][j] << " ";
		}
		cout << endl;
	}
	return os;
}

istream & operator>>(istream & is, Matrix & m)
{
	cout << "Enter new matrix: ";
	for (int i = 0; i < m.getI(); i++)
	{
		for (int j = 0; j <m.getJ(); j++)
		{
			is >> m[i][j] ;
		}		
	}
	return is;
}
