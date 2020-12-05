#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
    public:
        Person(string word, string date, int num) {
            name = word;
            birthday = date;
            rating = num;
        }

        int gettingRating() {
            return rating;
        }

        string getName() {
            return name;
        }

        string getBirthday() {
            return birthday;
        }

        string toString() {
            return name + " " + to_string(rating) + " " + birthday;
        }

    private:
        string name, birthday;
        int rating;
};

int main(int argc, char** argv) {
    string name, birthday;
    int rating, inputSize;

    cin >> rating;

    while(cin >> name >> rating >> birthday) {
        Person friend(name, birthday, rating);
    }
    
    return 0;
}