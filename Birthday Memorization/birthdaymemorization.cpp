#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Data about Krarkl's friend. Stores the name, rating and birthday of Krarkl's friend
class Person {
    public:
        //Workhorse constructor
        Person(string str, int num, string date) {
            name = str;
            rating = num;
            birthday = date;
        }

        //Returns name of object
        const string getName() const {
            return name;
        }

        //Returns birthday of object
        const string getBirthday() const {
            return birthday;
        }

        //Returns rating of object
        const int getRating() const {
            return rating;
        }

        //Retuns all of the data in the object in string format
        string toString() {
            return name + " " + to_string(rating) + " " + birthday;
        }

        //Checks if the given object is the same as this object
        bool equals(Person p) {
            return name == p.getName() &&
                   birthday == p.getBirthday() &&
                   rating == p.getRating();
        }

        //Overrides the < operator to sort Person objects by their name in alphabetical order
        bool operator < (const Person& p) const {
            return name < p.getName();
        }
    
    private:
        string name, birthday;
        int rating;
};

/*Checks if p's birthday is already in friends (and also determines if p has a higher rating than the other person who has the same birthday as p); 
  Returns true if the birthday is already in the list and/or the replacement occurs. Returns false otherwise
*/
bool containsBirthday(vector<Person>& friends, Person& p) {
    //For-loop that iterates through friends
    for(int i = 0; i < friends.size(); i++)
        //Checks if friend i has the same birthday as p
        if(friends.at(i).getBirthday() == p.getBirthday()) {
            //Checks if friend i has a lower rating than p
            if(friends.at(i).getRating() < p.getRating())
                //Replaces friend i with p
                friends.at(i) = p;
            
            //Returns true to indicate that either there is a friend who has the same birthday as p (but has a higher rating) or p replaces friend i as they have a higher rating
            return true; 
        }

    //Returns false if no one has the same birthday as p
    return false;
}

int main(int argc, char** argv) {
    /*Initializing variable
      name, stores the person name
      birthday, stores the person birthday
      rating, stores how Krarkl rates the person
      inputSize, stores how many people are in the test case
    */
    string name, birthday;
    int rating, inputSize;
    vector<Person> favoritePeople;

    //Storing number of people to check
    cin >> inputSize;

    //Allocates space to inputSize
    favoritePeople.reserve(inputSize);

    //While-loop that iterates through people in the test case
    while(cin >> name >> rating >> birthday) {
        //Constructs Person object
        Person person(name, rating, birthday);

        //Checks if person's birthday is already in favoritePeople. If it's not, then it adds person favoritePeople
        if(!containsBirthday(favoritePeople, person))
            favoritePeople.push_back(person);
    }
    
    //Sorts favoritePeople in alphabetical order by name
    sort(favoritePeople.begin(), favoritePeople.end());

    //Outputs the size of favoritePeople
    cout << favoritePeople.size() << endl;

    //Iterates through favoritePeople. Outputs the name of the object
    for(Person p : favoritePeople)
        cout << p.getName() << endl;

    return 0;
}