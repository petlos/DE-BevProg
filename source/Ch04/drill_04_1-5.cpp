#include "../std_lib_facilities.h"


double min(double a, double b)
{
	if (a < b)
		return a;
	else
		return b;
}

double max(double a, double b)
{
	if (a > b)
		return a;
	else
		return b;
}

constexpr double differ = 1.0/100;

bool almost_equal(double a, double b)
{
	if (abs(a-b) < differ)
		return true;
	else
		return false;
}

int main ()	
{

	double a = 0;
	double b = 0;

	cout << "Please enter two numbers:\n";

	while(cin >> a >> b)
	{
		if (a == b)
			cout << "The numbers are equal.\n";	
		else
		{
			cout << "The smaller value is: " << min(a,b) << "\n";
			cout << "The larger value is: " << max(a,b) << "\n";
			if (almost_equal(a,b))
				cout << "The numbers are almost equal.\n";
		}
	}

	return 0;
}