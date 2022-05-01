#include "std_lib_facilities.h"
#include <complex>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

int main(){
try{

	cout << "Sizes: " << endl;
	cout << "char: " << "\t\t" << sizeof(char) << endl;
	cout << "short: " << "\t\t" << sizeof(short) << endl;
	cout << "int: " << "\t\t" << sizeof(int) << endl;
	cout << "long: " << "\t\t" << sizeof(long) << endl;
	cout << "float: " << "\t\t" << sizeof(float) << endl;
	cout << "double: " << "\t" << sizeof(double) << endl;
	cout << "int*: " << "\t\t" << sizeof(int*) << endl;
	cout << "double*: " << "\t" << sizeof(double*) << endl;


	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10, 10);
	Matrix<int, 3> e(10, 10, 10);

	cout << "Matrix sizes: " << endl;
	cout << "1D, 10 ints: " << "\t\t" << sizeof(a) << endl;
	cout << "1D, 100 ints: " << "\t\t" << sizeof(b) << endl;
	cout << "1D, 10 doubles: " << '\t' << sizeof(c) << endl;
	cout << "2D, 100 ints: " << "\t\t" << sizeof(d) << endl;
	cout << "2D, 1000 ints: " << "\t\t" << sizeof(e) << endl;

	cout << "Number of elements: " << endl;
	cout << "a: " << '\t' << a.size() << endl;
	cout << "b: " << '\t' << b.size() << endl;
	cout << "c: " << '\t' << c.size() << endl;
	cout << "d: " << '\t' << d.size() << endl;
	cout << "e: " << '\t' << e.size() << endl;


	cout << "Please enter 6 positive integers: " << endl;
	int sq = 0;
	for (int i = 0; i < 6; ++i)

	{
		cin >> sq;
		if(sq < 0)
			cout << "Invalid number" << endl;
		else
		cout << "sqrt(" << sq << ")=" << sqrt(sq) << endl;
	}


	Matrix<double> md(10);
	double im;
	cout << "Enter 10 floating-point values: " << endl;
	for (int i = 0; i < md.size(); ++i)
	{
		cin >> im;
		if(!cin) { throw runtime_error("Invalid number!");}
		md[i] = im;
	}
	cout << "Matrix: " << md << endl;


	cout << "Enter n: ";
	int n;
	cin >> n;
	cout << "Enter m: ";
	int m;
	cin >> m;
	Matrix<int, 2> intm(n, m);

	for (int i = 0; i < intm.dim1(); ++i)
	{
		for (int j = 0; j < intm.dim2(); ++j)
		{
			intm(i, j) = (i+1)*(j+1);
			cout << setw(5) << intm(i, j);
		}
		cout << endl;
	}


	Matrix<complex<double>> cm(10);
	cout << "Enter 10 complex numbers (real, imaginary): ";
	complex<double> cn;
	for (int i = 0; i < 10; ++i)
	{
		cin >> cn;
		if (!cin) { throw runtime_error("Invalid complex numbers!"); }
		cm [i] = cn;
	}
	cout << "complex matrix: " << cm << endl;
	complex<double> sum;
	for (Index i = 0; i < cm.size(); ++i)
	{
		sum += cm[i];
	}
	cout << "sum: " << sum << endl;


	Matrix<int, 2> m2(2, 3);
	cout << "Enter 6 integers: " << endl;
	for (int i = 0; i < m2.dim1(); ++i)
	{
		for (int j = 0; j < m2.dim2(); ++j)
		{
			cin >> m2(i, j);
		}
	}
	cout << m2 << endl;


	return 0;
}
catch(exception& e)
{
	cerr << e.what() << endl;
	return 1;
}
catch(...)
{
	cerr << "Unknown error!" << endl;
	return 2;
}
}