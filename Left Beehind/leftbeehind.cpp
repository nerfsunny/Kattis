#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    /* Initializing input
        sweet, stores number of sweet jars
        sour, stores number of sour jars
    */
    int sweet, sour;

    //While-loop stores the number of sweet and sours jars; continues until both sweet and sour jars are both zero
    while((cin >> sweet >> sour) && (sweet != 0 || sour != 0)) {
        if((sweet + sour) == 13)
            cout << "Never speak again.\n";
        else if(sweet == sour)
            cout << "Undecided.\n";
        else if(sour > sweet)
            cout << "Left beehind.\n";
        else
            cout << "To the convention.\n";
    }
    
    return 0;
}