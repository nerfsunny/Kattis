#include <iostream>

//Takes a 2D coordinate as an input. Checks if x > 0; If it is, then it checks if y > 0 to determine if the point lies in quadrant 1 or 4. Otherwise, it checks if y > 0 to determine if the point lies in quadrant 2 or 3.
#define QUADRANT(x, y) ( ((x) > (0)) ? ( ((y) > (0)) ? (1) : (4) ) : ( ((y) > (0)) ? (2) : (3) ) )

using namespace std;

int main(int argc, char** argv) {
    //Initializing variables; used to store input coordinates
    int x, y;

    //Storing coordinates
    cin >> x >> y;

    //Passing values into preproccessor directive
    cout << QUADRANT(x, y) << endl;

    return 0;
}