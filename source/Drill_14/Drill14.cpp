#include<iostream>

using namespace::std;

class B1 
{

public:
	virtual void vf() const { cout << "B1::vf()" << endl; }
	void f() const { cout << "B1::f()" << endl; }
	virtual void pvf() const { cout << "B1::pvf()" << endl; }
};

class D1 : public B1
{

	void vf() const override { cout << "D1::vf()" << endl; }
	void f() const { cout << "D1::f()" << endl; }
	void pvf() const { cout << "D1::pvf()" << endl; }
};

void call(const B1& b){
	b.vf();
	b.f();
	b.pvf();
}

class D2 : public D1
{

	void pvf() const override { cout << "D2::pvf()" << endl; }

};

class B2
{

public:
	virtual void pvf() const = 0; 

};

class D21 : public B2
{

	string s = "whatever";
	void pvf() const { cout << s << endl; }

};

class D22 : public B2
{

	int i = 0;
	void pvf() const { cout << i << endl; } 

};

void f( B2& b2)
{

	b2.pvf();

}

int main(){
	
	B1 b1;
	D1 d1;

	call(b1);
	call(d1);

	cout << "End call." << endl << endl;

	B1& r {d1};
	call(r);

	cout << "End ref call." << endl << endl;

	D2 d2;
	call(d2);
	cout << "End D2 call." << endl << endl;

	D21 d21;
	D22 d22;
	f(d21);
	f(d22);
	cout << "End of whatever this was." << endl << endl;

return 0;
}