#include "std_lib_facilities.h"

template <typename C>
void print(const C& c){
	cout << endl << "Print elements: " << endl;
{	
	for (const auto elem : c)
		cout << elem << endl;
}
	cout << endl;
}

int main(){
try{
	vector<double> vd;
	ifstream ifs { "input2.txt" };
	if (!ifs)
		throw runtime_error("Cannot read from file!");
	for (double dd; ifs >> dd;)
	{
		vd.push_back(dd);
	}

	print(vd);

	vector<int> vi(vd.size());
	copy(vd.begin(), vd.end(), vi.begin());
	print(vi);

	for (int i = 0; i < vd.size(); ++i)
	{
		cout << vd[i] << '\t' << vi[i] << endl;
	}

	double vdsum = accumulate(vd.begin(), vd.end(), 0.0);
	cout << endl << "Sum of vd: " << vdsum << endl;

	double visum = accumulate(vi.begin(), vi.end(), 0);
	cout << endl << "Difference between sums: " << vdsum-visum << endl;

	reverse(vd.begin(), vd.end());
	print(vd);

	double vd_mean = vdsum / vd.size();
	cout << "vd mean: " << vd_mean << endl;

	vector<double> vd2;
	for (double d : vd)
	{
		if (d < vd_mean)
		{
			vd2.push_back(d);
		}
	}
	print(vd2);

	sort(vd.begin(), vd.end());
	print(vd);


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