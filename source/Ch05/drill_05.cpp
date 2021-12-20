#include "../std_lib_facilities.h"

int main()
try {

	// Fragment 01	(Compile-time error)	
	// Cout << "Success!\n";
	// error: ‘Cout’ was not declared in this scope
	// Fixed:
	cout << "Success!\n";

	// Fragment 02	(Compile-time error)
	// cout << "Success!\n; 
	// error: missing terminating " character
	// Fixed:
	cout << "Success!\n";

	// Fragment 03	(Compile-time error)
	// cout << "Success" << !\n" 
	// error: - stray ‘\’ in program 
    //        - missing terminating " character
    // 		  - ‘n’ was not declared in this scope
	// Fixed:
	cout << "Success" << "!\n";		// cout << "Success!\n"; ---> IS BETTER!

	// Fragment 04	(Compile-time error)
	// cout << success << '\n';
	// error: ‘success’ was not declared in this scope
	// Fixed:
	cout << "Success!\n";

	// Fragment 05 (Compile-time error)
	// string res = 7;
    // vector<int> v(10);
    // v[5] = res;
    // cout << "Success!\n";
    // error: - conversion from ‘int’ to non-scalar type ‘std::string
    //          {aka std::basic_string<char>}’ requested
    //        - cannot convert ‘std::string {aka
    //          std::basic_string<char>}’ to ‘int’ in assignment
    // Fixed:
    int res = 7;
    vector<int> v(10);
    v[5] = res;
    cout << "Success!\n";

    // Fragment 06 (Compile-time error and Logical error)
    // vector<int> v(10);
    // v(5) = 7;
    // if (v(5) != 7) cout << "Success!\n";
    // error: no match for call to ‘(Vector<int>) (int)’
    // Fixed:
    vector<int> v6(10);
    v6[5] =7;
    if (v6[5] == 7)
    	cout << "Success!\n";

    // Fragment 07 (Compile-time error)
    // if (cond) cout << "Success!\n";
    // else cout << "Fail!\n";
    // error: ‘cond’ was not declared in this scope
    // Fixed:
    bool cond = true;
    if (cond) 
    	cout << "Success!\n";
    else 
    	cout << "Fail!\n";

	// Fragment 08 (Logical error)
    // bool c8 = false;
    // if (c8) cout << "Success!\n";
    // else cout << "Fail!\n";
    // prints Fail! instead of Success!
    // Fixed:
    bool c8 = true;
    if (c8) 
    	cout << "Success!\n";
    else 
    	cout << "Fail!\n";

    // Fragment 09 (Logical error)
    // string s9 = "ape";
    // bool c9 = "fool"<s9;
    // if (c9) cout << "Success!\n";
    // Print nothing
    // Fixed:
    string s9 = "ape";
    bool c9 = "fool"<s9;
    if (!c9) 
    	cout << "Success!\n";

    // Fragment 10 (Logical error)
    // string s10 = "ape";
    // if (s10 == "fool") cout << "Success!\n";
    // Prints nothing
    // Fixed:
    string s10 = "ape";
    if (s10 != "fool") 
    	cout << "Success!\n";

    // Fragment 11 (Compile-time error and Logical error)
    // string s11 = "ape";
    // if (s11 == "fool") cout < "Success!\n"; 
    // error: no match for ‘operator<’ (operand types are
    //		  ‘std::ostream {aka std::basic_ostream<char>}’ and ‘const char [10]’)
    // Prints nothing.
    // Fixed:
    string s11 = "ape";
    if (s11 != "fool") 
    	cout << "Success!\n";

    // Fragment 12 (Compile-time error and Logical error)
    // string s12 = "ape";
    // if (s12 + "fool") cout < "Success!\n";
    // error: - could not convert ‘std::operator+(const
    //          std::basic_string<_CharT, _Traits, _Alloc>&, const _CharT*) [with _CharT
    //          = char; _Traits = std::char_traits<char>; _Alloc
    //          = std::allocator<char>](((const char*)"fool"))’ from
    //          ‘std::basic_string<char>’ to ‘bool’
    //        - no match for ‘operator<’ (operand types are
    //          ‘std::ostream {aka std::basic_ostream<char>}’ and ‘const char[10]’)
    // Fixed:
    string s12 = "ape";
    if (s12 != "fool") 
    	cout << "Success!\n";

    // Fragment 13 (Logical error)
    // vector<char> v13(5);
    // for (int i=0; 0<v13.size(); ++i)
    // cout << "Success!\n";
    // for-loop control always true; infinite loop.
    // Fixed:
    vector<char> v13(5);
    for(int i=0; i<v13.size(); ++i)
        cout << "Success!\n";

    // Fragment 14
    // vector<char> v14(5);
    // for (int i=0; i<=v14.size(); ++i)
    //     cout << "Success!\n";
    // Fixed:
    vector<char> v14(5);
    for (int i=0; i<v14.size(); ++i)
        cout << "Success!\n";

    // Fragment 15 (Logical error)
    // Original -> The magic number 6 do not cover completely the string we
    // want to print.
    // string s15 = "Success!\n";
    // for (int i=0; i<6; ++i)
    //     cout << s15[i];
    // Fixed:
    string s15 = "Success!\n";
    for (int i=0; i<s15.size(); ++i)
        cout << s15[i];

    // Fragment 16 (Compile-time error; Syntax error)
    // if (true) then
    //     cout << "Success!\n";
    // else 
    //     cout << "Fail\n";
    // error: 'then' was not declared, it has no sense
    // Fixed:
    if (true) 
        cout << "Success!\n";
    else 
        cout << "Fail\n";

    // Fragment 17 (Non-error)
    // int x = 2000;
    // char c = x;
    // if (c == 2000) cout << "Success!\n";
    // 'char' --> 'int'
    // Fixed:
    int x = 2000;
    int c = x;
    if (c == 2000) 
    	cout << "Success!\n";

    // Fragment 18 (Non_error)
    // string s = "Success!\n";
    // for (int i=0; i<10; ++i)
    //     cout << s[i];
    // Fixed:
    string s = "Success!\n";
    for (int i=0; i<s.size(); ++i)
        cout << s[i];

    // Fragment 19 (Compile-time error)
    // vector v(5);
    // for (int i=0; i<=v.size(); ++i)
    //     cout << "Success!\n";
    // error: missing template arguments before ‘v’
    //        <= instead of <
    // Fixed:
    vector<int> v19(5);
    for (int i=0; i<v19.size(); ++i)
        cout << "Success!\n";

    // Fragment 20 (Logical error)
    // int i = 0;
    // int j = 9;
    // while (i < 10)
    //    ++j;
    // if (j < i)
    //    cout << "Success!\n";
    // Problem: ++j --> ++i
    // Fixed:
    int i = 0;
    int j = 9;
    while (i < 10)
        ++i;
    if (j < i)
        cout << "Success!\n";

    // Fragment 21 (Run-time error)
    // int x = 2;
    // double d = 5/(x-2);
    // if (d == 2*x+0.5)
    //     cout << "Success!\n";
    // Problem: floating point
    // Fixed:
    int x21 = 2;
    double d21 = 5.0/x21+2;
    if (d21 == 2*x21+0.5)
        cout << "Success!\n";

    // Fragment 22 (Compile-time error)
    // string<char> s = "Success!\n";
    // for (int i=0; i<=10; ++i)
    //     cout << s[i];
    // error: ‘std::string {aka std::basic_string<char>}’ is not a template
    // Fixed:
    string s22 = "Success!\n";
    for (int i=0; i<s22.size(); ++i)
        cout << s22[i];

    // Fragment 23 (Compile-time error)
    // int i = 0;
    // while (i < 10)
    //     ++j;
    // if (j < i)
    //     cout << "Success!\n";
    // error: 'j23' was not declared, ++j --> ++i
    // Fixed:
    int i23 = 0;
    int j23 = 0;
    while (i23 < 10)
        ++i23;
    	if (j23 < i23)
        	cout << "Success!\n";

    // Fragment 24 (= Fragment 21)
    // int x = 4;
    // double d = 5/(x-2);
    // if (d = 2*x+0.5)
    //     cout << "Success!\n";
    // Fixed:
    int x24 = 4;
    double d24 = 5.0/(x24-2);
    if (d24 == x24/2.0+0.5)
        cout << "Success!\n";

    // Fragment 25 (Compile-time error)
    // cin << "Success!\n";
    // error: cin --> cout
    // Fixed:
    cout << "Success!\n";

	return 0;
	
} 
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
} 
catch (...) {
	cerr << "Oops: unknown exception!\n";
	return 2;
}