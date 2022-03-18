#include "std_lib_facilities.h"

struct Person
{
public:
	Person() { };
	Person(string nn, int aa)
	{
		const vector<char> bad = {';','?',':','[',']','*','&','^','%','$','#','@','!','.','"','\''};
		if(aa < 0 || aa > 150) { error("Invalid age!"); }

		if(nn == " ") { error("Name must not be empty!"); }

		for(int i = 0; i < bad.size(); ++i)
		{
			if(nn.find(bad[i]) != string::npos) { error("Invalid char in name!"); }
		}
		constructinit(nn, aa);
	};

	void constructinit(string nn, int aa)
	{
		name = nn;
		age = aa;
	}

	string get_name() { return name; }
	int get_age() { return age; }

private:
	string name;
	int age;
};

ostream& operator<<(ostream& os, Person& p)
{
	os << p.get_name() << ' ' << p.get_age() << endl;

	return os;
}

istream& operator>>(istream& is, Person& p)
{
	string name;
	int age;
	cout << "Enter a name: ";
	cin >> name;
	cout << "Enter an age: ";
	cin >> age;
	p = Person(name, age);
	return is;
}

int main()
{
	try
	{
		Person Goofy("Goofy", 63);
		cout << Goofy;

		Person one;
		cin >> one;
		cout << one;

		cout << "Enter a name and age: (use 'end' to stop)" << endl;
		vector <Person> persons;
		for(Person two; cin >> two;)
		{
			if(two.get_name() == "end") break;
			else persons.push_back(two);
		}
		for(Person p:persons)
			cout << p << endl;
	
	return 0;
	}

	catch(exception& e){
		cerr << e.what() << endl;
	return 1;
	}

	catch(...){
		cerr << "Unknown error" << endl;
		return 2;
	}
}
