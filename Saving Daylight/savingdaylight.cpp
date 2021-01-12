#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    /* Initializing variables
       month, sunrise, sunset, day, year: stores the given parameters from the input
       sunriseColon, sunsetColon: stores the index where the colon is
       hoursDifference, minutesDifference: store the time elapsed between sunrise and sunet
    */
    string month, sunrise, sunset;
    int day, year, sunriseColon, sunsetColon, hoursDifference, minutesDifference;

    while(cin >> month >> day >> year >> sunrise >> sunset) {
        //Stores the index where the colon is
        sunriseColon = sunrise.find(":"), sunsetColon = sunset.find(":");

        //Extracts the hours and stores the difference
        hoursDifference = stoi(sunset.substr(0, sunsetColon)) - stoi(sunrise.substr(0, sunriseColon));

        //Extracts the minutes and stores the difference
        minutesDifference = stoi(sunset.substr(sunsetColon + 1)) - stoi(sunrise.substr(sunriseColon + 1));

        //Checks if the minutesDifference is below zero. If it is, then it adds 60 to minutesDifference and decrements hoursDifference in order to display positive values
        if(minutesDifference < 0) {
            minutesDifference += 60;
            hoursDifference--;
        }

        //Outputs date and time elapsed
        printf("%s %i %i %i hours %i minutes \n", month.c_str(), day, year, hoursDifference, minutesDifference);
    }

    return 0;
}