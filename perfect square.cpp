#include <iostream>
using namespace std;

void perfectSquare() {
    int x = 3, y = x*x, z = y%100;
    if ((z%10 != 0) && (z/10 != 0)) cout << y;
    else x=+2;
}
int main() {
    perfectSquare();
}
