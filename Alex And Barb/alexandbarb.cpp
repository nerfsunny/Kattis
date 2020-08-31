#include <iostream>

using namespace std;
using ull = unsigned long long int;

int main(int argc, char** argv) {
    ull deck, min, max, turn = 1;

    cin >> deck >> min >> max;

    while(true) {
        if(deck < min)
            break;
        
        if(max <= deck) {
            deck -= max;
            turn++;
            continue;
        }

        if(deck >= min && deck < max) {
            deck = 0;
            turn++;
            continue;
        }
    }

    if(turn % 2 == 0)
        cout << "Alex" << endl;
    else
        cout << "Barb" << endl;
    
    return 0;
}