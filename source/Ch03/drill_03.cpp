#include "../std_lib_facilities.h"

int main ()	{
	
	cout << "Enter the name of the person you wanted to write to:\n";
	string first_name;
	cin >> first_name;

	cout << "Enter the age of this person:\n";
	int age = 0;
	cin >> age;
	if (age <= 0 || age >= 110)
		simple_error("you're kidding!");

	cout << "Enter the name of a mutual friend:\n";
	string friend_name;
	cin >> friend_name;

	cout << "Enter friend's sex (m=male, f=female):\n";
	char friend_sex {0};
	cin >> friend_sex;


	cout << "\n\nDear " << first_name << ",\n\n";
	
	cout << "How are you? I am fine. I miss you.\n";

	cout << "Have you seen " << friend_name << " lately?\n";
	if (friend_sex == 'm')
		cout << "If you see " << friend_name << " please ask him to call me.\n";
	if (friend_sex == 'f')
		cout << "If you see " << friend_name << " please ask her to call me.\n";

	cout << "I hear you just had a birthday and you are " << age << " years old.\n";
	if (age < 12)
		cout << "Next year you will be " << age+1 << ".\n";
	else if (age == 17)
		cout << "Next year you will be able to vote.\n";
	else if (age > 70)
		cout << "I hope you are enjoying retirement.\n";

	cout << "\n\nYours sincerely,";
	cout << "\n\n\t\tMiki\n\n";

	return 0;
}