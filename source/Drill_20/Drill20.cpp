#include "std_lib_facilities.h"

template<typename Iter1, typename Iter2>
Iter2 mycopy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for (auto i = f1; i != e1; i++)
		{ *f2 = *i; f2++; }
		return f2;
};

int main(){
	
	int ar[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> ve {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int ar2[10];
	for (int i = 0; i < 10; ++i) { ar2[i] = ar[i]; } 
	vector<int> ve2 = ve;
	list<int> li2 = li;

	cout << "New array: ";
	for (auto& x: ar){ x += 2; cout << x << ' ';}
	cout << endl;
	
	cout << "New vector: ";
	for (auto& x: ve){ x += 3; cout << x << ' '; }
	cout << endl;

	cout << "New list: ";
	for (auto& x: li){ x += 5; cout << x << ' '; }
	cout << endl;

	cout << "copy array into second vector" << endl;
	mycopy( begin(ar), end(ar), begin(ve2));
	for (auto x: ve2){ cout << x << ' '; }
	cout << endl;

	cout << "copy list into the second array" << endl;
	mycopy( begin(li), end(li), begin(ar2));
	for (auto x: ar2){ cout << x << ' '; }
	cout << endl;

	int three = 3;
	int tseven = 27;
	auto elem_1 = find(begin(ve), end(ve), three);
	if (elem_1 != end(ve))
		cout << "Element in vector found at: " << distance( begin(ve), elem_1) << endl;
	else 
		cout << "Element in vector not found!" << endl;
	
	auto elem_2 = find(begin(li), end(li), tseven);
	if (elem_2 != end(li))
		cout << "Element in list found at: " << distance( begin(li), elem_2) << endl;
	else 
		cout << "Element in list not found!" << endl;
	return 0;
}