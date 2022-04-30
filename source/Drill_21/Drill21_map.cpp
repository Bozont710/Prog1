#include "std_lib_facilities.h"

template <typename T, typename M>
void print(const map<T, M>& m)
{
	for(pair<T, M> a : m)
		cout << a.first << '\t' << a.second << endl;
}

void fromcin(map<string, int>& m)
{
	string ss;
	int ii = 0;

	while( m.size() < 10){
	cin >> ss >> ii;
	m.insert(make_pair(ss, ii));
}
}

template <typename T>
int sum(const map<T, int>& m)
{
	int Sum = accumulate(m.begin(), m.end(), 0, [](int sum, const pair<string, int>& p) { return sum += p.second; });
	return Sum;
}

template <typename T, typename F>
void swap(const map<T, F>& m, map<F, T>& l)
{
	for(pair<T, F> a : m)
		l[a.second] = a.first;
}

int main(){
try{
	
	map<string, int> msi;
	msi["Never"] = 54;
	msi["Gonna"] = 420;
	msi["Give"] = 897;
	msi["You"] = 10;
	msi["Up"] = 26;
	msi["Run"] = 43;
	msi["Around"] = 013;
	msi["And"] = 86;
	msi["Desert"] = 9865;
	msi["Down"] = 710;

	print(msi);

	msi.erase("Never");
	msi.erase("And");
	cout << endl << "New erased map: " << endl;
	print(msi);

	msi.erase(msi.begin(), msi.end());
	cout << endl << "After erasing everything: " << endl;
	print(msi);

	cout << endl << "Please enter ten name and value pair: " << endl;
	fromcin(msi);
	print(msi);

	cout << endl << "Sum of map: " << sum(msi) << endl;

	map<int, string> mis;
	swap(msi, mis);
	cout << endl << "Elements of mis: " << endl;
	print(mis);

	return 0;
}
catch(exception& e)
{
	cerr << e.what() << endl;
	return 1;
}
catch(...)
{
	cerr << "Unknown error" << endl;
	return 2;
}
}