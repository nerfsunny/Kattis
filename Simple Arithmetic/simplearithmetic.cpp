#include <iostream>
#include <iomanip>

using namespace std;
using ull = unsigned long long int;

int main(int argc, char** argv) {
    ull num1, num2, num3;

    cin >> num1 >> num2 >> num3;

    if(num3 == 1)
        cout << (num1 * num2) << endl;
    else
        printf("%.18Lf\n", (long double) (num1 * num2)/num3);
    
    return 0;
}