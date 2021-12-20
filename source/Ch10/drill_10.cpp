#include "../std_lib_facilities.h"

struct Point {													// 1.
    int x;
    int y;
};

istream& operator>>(istream& is, Point& p)						// 2.
{
    char ch1;
    
    if (is >> ch1 && ch1 != '(') {
        is.unget();
        is.clear(ios_base::failbit);
        
        return is;
    }

    char ch2;
    char ch3;
    int xx;
    int yy;

    is >> xx >> ch2 >> yy >> ch3;
    
    if (!is || ch3 != ')') {
        if (is.eof()) return is;
        	error("bad point");
    }

    p.x = xx;
    p.y = yy;
    
    return is;
}

ostream& operator<<(ostream& os, Point& p)						// 3.
{
    return os << '(' << p.x << ',' << p.y << ')';
}

void fill_from_file(vector<Point>& points, string& name)		// 5.
{
    ifstream ist {name};
    ist.exceptions(ist.exceptions()|ios_base::badbit);

    if (!ist) error("can't open input file ", name);
    
    for (Point p; ist >> p; )
        points.push_back(p);
}


int main()
try {
    
    cout << "Please enter 7 sets of (x,y) points:\n";			// 2.
    
    vector<Point> original_points;

    while (original_points.size() < 7) {
        Point p;
        cin >> p;
        original_points.push_back(p);
    } 

    for (Point p : original_points)								// 3.
        cout << p;
    cout << '\n';

    string fname = "mydata.txt";								// 4.
    
    ofstream ost { fname };
    if (!ost) error("could not open file ", fname);

    for (Point p : original_points)
        ost << p;
    ost.close();

    vector<Point> processed_points;								// 5.
    fill_from_file(processed_points, fname);

    for (Point p : processed_points)
        cout << p;
    cout << '\n';

    if (original_points.size() != processed_points.size())
        cout << "Something's wrong!\n";
}

catch (runtime_error& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}

catch (...) {
    cerr << "Something error happened!\n";
    return 2;
}