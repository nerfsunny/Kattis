#include<iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
    int num, prevNum;

    srand (time(NULL));

    num = rand() % 2 + 1;

    cout << num << endl;
    prevNum = num;

    while(cin >> num && num != 99) {
        if((num + 1) % 3 == 0) {
            cout << (num + 1) << endl;
            prevNum = num + 1;
        }else if((num + 2) % 3 == 0) {
            cout << (num + 2) << endl;
            prevNum = num + 2;
        }else {
            cout << (num + (num - prevNum)) << endl;
            prevNum = (num + (num - prevNum));
        }
    }

    return 0;
}