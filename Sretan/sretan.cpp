#include <iostream>
#include <string>

using namespace std;

void constructLuckyNumber(string& luckyNumber) {
    string number = "";
    string carryOver;
    int counter = luckyNumber.size() - 1;

    if(luckyNumber[counter] == '4')
        luckyNumber[counter] = '7';
    else {
        luckyNumber[counter] = '4';
        carryOver =  "4";
    }

    counter--;

    while(carryOver == "4" && counter >= 0) {
        if(luckyNumber[counter] == '7')
            luckyNumber[counter] = '4';
        else {
            luckyNumber[counter] = '7';
            carryOver =  "";
            break;
        }

        counter--;
    }

    carryOver += luckyNumber;
    luckyNumber = carryOver;
}

int main(int argc, char** argv) {
    string luckyNumber = "4";
    int ithLuckyNumber;

    cin >> ithLuckyNumber;

    for(int i = 1; i < ithLuckyNumber; i++)
        constructLuckyNumber(luckyNumber);

    cout << luckyNumber << endl;

    return 0;
}