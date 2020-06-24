#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    //vector<int> shotDistance;
    //vector<int> courseLength;
    //set<int> shotDistance;
    //set<int> courseLength;
    unordered_set<int> shotDistance;
    unordered_set<int> courseLength;

    int shotDistanceInput, courseLengthInput, input;
    int numberOfHoles = 0;

    cin >> shotDistanceInput;
    shotDistance.reserve(shotDistanceInput);

    for(int i = 0; i < shotDistanceInput; i++) {
        if(scanf("%u", &input) == 1)
        	shotDistance.emplace(input);
			//shotDistance.emplace_back(input);
    }

    cin >> courseLengthInput;
    courseLength.reserve(courseLengthInput);

    for(int i = 0; i < courseLengthInput; i++) {
        if(scanf("%u", &input) == 1)
        	courseLength.emplace(input);
			//courseLength.emplace_back(input);
    }

    auto begin = shotDistance.begin();
    auto end = shotDistance.end();

    for(auto &x : courseLength) {
        /*if(binary_search(begin, end, x)) {
            numberOfHoles++;
            continue;
        }*/

        //cout << "Course Length: " << x << endl;

        /*if(binary_search(begin, end, x)) {
        	numberOfHoles++;
        	continue;
        }*/

        if(shotDistance.find(x) != end) {
            //cout << "In if-statement 1: " << x << endl;
            numberOfHoles++;
            continue;
        }

        for(auto &y : shotDistance) {
            /*if(y > x)
                break;*/

            //cout << "Shot Distance: " << x << endl;

            /*if(binary_search(begin, end, (x - y))) {
                numberOfHoles++;
                break;
            }*/

            /*if(binary_search(begin, end, (x - y))) {
            	numberOfHoles++;
            	break;
            }*/

            if(shotDistance.find(x - y) != end) {
                //cout << "In if-statement 2: " << x - y << endl;
                numberOfHoles++;
                break;
            }
        }
    }

    cout << numberOfHoles << "\n";

    return 0;
}