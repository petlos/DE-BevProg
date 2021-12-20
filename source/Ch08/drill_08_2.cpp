#include "../std_lib_facilities.h"

void swap_v(int a, int b)
{
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b)
{
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

//  DOESN'T COMPILE
/*
void swap_cr(const int& a, const int& b)
{
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}
*/

int main()
{
    int x = 7;
    int y = 9;

    //swap_v(x, y);             // Does not swap
    //swap_v(7, 9);             // Does nothing
    swap_r(x, y);               // OK
    //swap_r(7, 9);             // Does not compile
    
    cout << "x is now " << x << " and y is now " << y << '\n';


    const int cx = 7;
    const int cy = 9;
    
    //swap_v(cx, cy);           // OK, but does not swap
    //swap_v(7.7, 9.9);         // Does nothing
    //swap_r(cx, cy);           // Does not compile
    //swap_r(7.7, 9.9);         // Does not compile
    
    cout << "cx is now " << cx << " and cy is now " << cy << '\n';


    double dx = 7.7;
    double dy = 9.9;
    
    //swap_v(dx, dy);           // OK, but does not swap
    //swap_r(dx, dy);           // Does not compile (???)

    cout << "dx is now " << dx << " and dy is now " << dy << '\n';

    return 0;
}