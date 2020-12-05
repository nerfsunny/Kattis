#include<iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
    /*Initializing variables
        num is used to store the oppponent's output
        prevNum is used to store the answer outputted previously
    */
    int num, prevNum;

    //Seeding random
    srand (time(NULL));

    //Randomly starting game with either 1 or 2
    num = rand() % 2 + 1;

    //Printing num to start game
    cout << num << endl;

    //Storing output
    prevNum = num;

    //While-loop that continues while num is not 99 and stores the opponents answer in num
    while(cin >> num && num != 99) {
        /*If-else statement block
            The first two if-statements check if adding either 1 or 2 to num will result in num being divisible by 3; whichever one will satisfy that condition will output it and store it in prevNum
            If the num is currently divisible by 3, it will calculate what number the opponent used to add to num by substracting prevNum from it and add it to num and output it. It then stores it in prevNum
        */
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