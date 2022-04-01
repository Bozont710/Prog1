#include "std_lib_facilities.h"

template<typename T> 

struct S 
{ 

private:
	T val; 

public:
	S(T t):val{t} {}
	
	S& operator=(const T& t) { val=t; return *this; }
	T& get() { return val; }
	const T& get_const() const { return val; }
	
};

template<typename T>

void read_val(T& v) {cin>>v;}

int main()
{
	S<int>S_int(710);
	cout << S_int.get() << endl;
	
	S<char>S_char('$');
	cout << S_char.get() << endl;
	
	S<double>S_double(0.7734);
	cout << S_double.get() << endl;
	
	S<string>S_string("I live in your walls");
	cout << S_string.get() << endl;
	
	S<vector<int>>S_vector({1, 2, 3});
	vector<int>A=S_vector.get();
	for (auto x : A) 
        cout << x << " "<<endl;
	
	cout << "Enter an int: ";
	read_val(S_int.get());
	cout << S_int.get() << endl;
	
	cout << "Enter a char: ";
	read_val(S_char.get());
	cout << S_char.get() << endl;
	
	cout << "Enter a double: ";
	read_val(S_double.get());
	cout << S_double.get() << endl;
	
	cout << "Enter a string: ";
	read_val(S_string.get());
	cout << S_string.get() << endl;

	return 0;
}