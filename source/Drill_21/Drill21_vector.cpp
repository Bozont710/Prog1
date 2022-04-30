#include "std_lib_facilities.h"

struct Item
{
	Item (string ss, int ii, double dd) : name (ss), iid(ii), value(dd){}
	Item() {};

	string name;
	int iid;
	double value;
};

istream& operator>>(istream& is, Item& I)
{
	return is >> I.name >> I.iid >> I.value;
}

template <typename Iter>
void print (Iter begin, Iter end)
{
	while (begin != end){
		cout << begin->name << "\t" << begin->iid << "\t" << begin->value << endl;
		++begin;
	}
}

bool byname(Item a, Item b)
{
	return a.name < b.name;
}

bool byiid(Item a, Item b)
{
	return a.iid < b.iid;
}

bool byvalue(Item a, Item b)
{
	return a.value > b.value;
}

template <typename T>
void RemoveByName(T& container, string Removename)
{
	container.erase(remove_if(container.begin(), container.end(), [=](Item item) { return item.name == Removename; }), container.end());
}

template <typename T>
void RemoveByiid(T& container, int Removeiid)
{
	container.erase(remove_if(container.begin(), container.end(), [=](Item item) { return item.iid == Removeiid; }), container.end());
}

int main(){
try{
	vector<Item> vi;
	ifstream ifs {"input.txt"};
	if (!ifs)
	{
		throw runtime_error ("Cannot read from file!");
	}
	for (Item d; ifs >> d;)
	{
		vi.push_back(d);
	}
	ifs.close();
	cout << endl << "Elements: " << endl;
	print(vi.begin(), vi.end());


	sort(vi.begin(), vi.end(), byname);
	cout << endl << "By name: " << endl;
	print(vi.begin(), vi.end());

	sort(vi.begin(), vi.end(), byiid);
	cout << endl << "By iid: " << endl;
	print(vi.begin(), vi.end());

	sort(vi.begin(), vi.end(), byvalue);
	cout << endl << "By value: " << endl;
	print(vi.begin(), vi.end());

	Item hs("horse shoe", 99, 12.34);
	vi.insert(vi.end(), hs);
	Item cs("Canon S400", 9988, 499.95);
	vi.insert(vi.end(), cs);
	cout << endl << "With the new elements: " << endl;
	print(vi.begin(), vi.end());

	RemoveByName(vi, "Never");
	RemoveByName(vi, "Up");
	cout << endl << "New vector with removal by names" << endl;
	print(vi.begin(), vi.end());

	RemoveByiid(vi, 345);
	RemoveByiid(vi, 0);
	cout << endl << "New vector with removal by iid" << endl;
	print(vi.begin(), vi.end());

	//same with list

	list<Item> li;
	ifstream ifst {"input.txt"};
	if (!ifst)
	{
		throw runtime_error("Cannot read from file!");
	}
	for (Item d; ifst >> d;)
	{
		li.push_back(d);
	}
	ifst.close();
	cout << endl << "List elements: " << endl;
	print(li.begin(), li.end());

	li.sort(byname);
	cout << endl << "List sorted by name: " << endl;
	print(li.begin(), li.end());

	li.sort(byiid);
	cout << endl << "List sorted by iid: " << endl;
	print(li.begin(), li.end());

	li.sort(byvalue);
	cout << endl << "List sorted by value: " << endl;
	print(li.begin(), li.end());

	li.insert(li.end(), hs);
	li.insert(li.end(), cs);
	cout << endl << "List with new elements: " << endl;
	print(li.begin(), li.end());

	RemoveByName(li, "Never");
	RemoveByName(li, "Up");
	cout << endl << "New list with removal by name: " << endl;
	print(li.begin(), li.end());

	RemoveByiid(li, 345);
	RemoveByiid(li, 0);
	cout << endl << "New list with removal by iid: " << endl;
	print(li.begin(), li.end());


	return 0;
}//endoftry

catch(exception& e){
	cerr << e.what() << endl;
	return 1;
}
catch (...){
	cerr << "Unknown error!" << endl;
	return 2;
}
}