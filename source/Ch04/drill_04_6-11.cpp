#include "../std_lib_facilities.h"


constexpr double cm_to_m = 0.01;
constexpr double in_to_m = 2.54 * cm_to_m;
constexpr double ft_to_m = 12.0 * in_to_m;
const vector<string> legal_units {"cm", "m", "in", "ft"};

bool legalUnit(string unit)
{
	bool legal = false;
	for (auto legal_unit : legal_units)
	{
		if (unit == legal_unit)
		{
			legal = true;
		}
	}
	return legal;
}

void printLegalUnits()
{
	cout << "\tcm for centimeters\n"
			<< "\tm for meters\n"
			<< "\tin for inches\n"
			<< "\tft for feet\n";
}

double convertToMeter (double a, string unit)
{
	if ("cm" == unit)
	{
		return a * cm_to_m;
	}
	else if ("in" == unit)
	{
		return a * in_to_m;
	}
	else if ("ft" == unit)
	{
		return a * ft_to_m;
	}
	else
	{
		return a;
	}
}


int main()
{
	cout << "Please enter a value followed by a unit:\n";

	double a = 0.0;
	double smallest = 0.0;
	double largest = 0.0;
	bool first = true;
	string unit = " ";
	double valMeter = 0.0;
	int count = 0;
	double sum = 0.0;
	vector<double> values(0);

	printLegalUnits();

	while (cin >> a >> unit)
	{
		if (legalUnit(unit))
		{
			valMeter = convertToMeter(a, unit);
			if (unit != "m")
			{
				cout << a << unit << " (" << valMeter << "m) ";
			}
			
			if (0 == count)
			{
				smallest = a;
				largest = a;
				cout << a << unit << " is the first value and therefore the smallest and the largest so far.\n";
			}
			else if (valMeter < smallest)
			{
				cout << a << unit << " is the smallest so far.\n";
				smallest = valMeter;
			}
			else if (valMeter > largest)
			{
				cout << a << unit << " is the largest so far.\n";
				largest = valMeter;
			}
			else
			{
				cout << "\n";
			}
			sum += valMeter;
			values.push_back(valMeter);
			count++;
		}
		else
		{
			cout << "Error: no legal unit. Please enter one of \n";
			printLegalUnits();
		}
	}

	cout << "The smallest: " << smallest << "m\n";
	cout << "The largest: " << largest << "m\n";
	cout << "Number of values entered: " << count << "\n";
	cout << "The sum of values: " << sum << "m\n";

	sort(values);

	cout << "The entered values ins orted order: ";
	for (auto value : values)
	{
		cout << value << " ";
	}
	cout << "\n";

	return 0;
}