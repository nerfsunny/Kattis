#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

//Takes a given string and turns every character in it to lower case
void tolower(string& str) {
    for(int i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);
}

int main(int argc, char** argv) {
    /* Initializing variables
       line, used to store the given input. Also used to store the complete animal name
       animalType, stores the "generic" form of animal
       listSize, stores the size of a sub-testcase
       listNumber, used to denote what list the input is one
    */
    string animalType, line;
    int listSize, listNumber = 1;

    /* Initializing container
       Stores how many of a animal type exists in the input
       Key is the animalType
       Value is the number of occurrences
    */
    map<string, int> animalList;

    while(getline(cin, line) && stoi(line) != 0) {
        //Stores the sub-test case size
        listSize = stoi(line);

        //Iterates though all of the inputs in the given sub-test case
        for(int i = 0; i < listSize; i++) {
            //Stores input into animal
            getline(cin, line);

            //Stores the index of the last space 
            int spaceIndex = line.rfind(" ");

            //Determines if the animal is "generic" or not. If it is not, then it stores a substring of animal from [spaceIndex +1, end] into animalType. Otherwise, it is already in its generic form and stores it in animalType
            if(spaceIndex != -1)
                animalType = line.substr(spaceIndex + 1);
            else
                animalType = line;
            
            //Converts all of the characters in the string to lower case
            tolower(animalType);
            
            //Checks if the animalType is already in the animalList. If it is, then it increments it value by 1. Otherwise, it inserts it into animalList with a value of 1
            if(animalList.find(animalType) != animalList.end())
                animalList[animalType]++;
            else 
                animalList.insert({animalType, 1});
        }

        //Prints list number in desired format
        printf("List %i:\n", listNumber);

        //For-each loop that iterates through all of the values in the map; outputs the values from the map in the desired format
        for(auto& kv : animalList)
            printf("%s | %i\n", kv.first.c_str(), kv.second);

        //Increments list number by 1
        listNumber++;

        //Clears for next sub-test case
        animalList.clear();
    }
    
    return 0;
}