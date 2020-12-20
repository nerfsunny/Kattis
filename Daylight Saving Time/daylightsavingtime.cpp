#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int numberOfTestCases, shift, hour, minute, hourFactor;
    char daylightSavingTime;
    
    cin >> numberOfTestCases;
    
    for(int i = 0; i < numberOfTestCases; i++) {
        cin >> daylightSavingTime >> shift >> hour >> minute;
        
        switch (daylightSavingTime) {
            case 'F':
                minute += shift;
                hourFactor = minute/60;

                minute -= (60 * hourFactor);
                hour += hourFactor;
                    
                if(hour >= 24)
                    hour -= 24;
                break;
            case 'B':
                minute -= shift;
                hourFactor = minute/60;
                
                if(hourFactor == 0 && shift != 0) {
                    minute += 60;
                    hour -= 1;
                }else {
                    minute -= (60 * hourFactor);
                    hour += hourFactor;
                }
                
                if(hour < 0)
                    hour = 23 + hourFactor;
                
                break;
            default:
                break;
        }
            
        cout << hour << " " << minute << endl;
    }
    
    return 0;
}
