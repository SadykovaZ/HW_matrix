#include "Matrix.h"
using namespace std;

void main() {
	/*Matrix m(2,3,1);
	cin >> m;
	cout << m;*/
	Matrix m(2, 3, 1);
	/*m[1][1] = 4;
	cout << m;
	Matrix n(2, 3, 1);
	if (m == n)
		cout << true;
	else
		cout << false;

	m.print();
	cout << endl;
	m[1][1] = 7;
	m.print();
	cout << endl;*/
	m.transp();
	m.print();
	system("pause");

}