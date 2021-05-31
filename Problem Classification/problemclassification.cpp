#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//Processes the categories and keywords associated with those categories into their respective containers
void fillTables(unordered_map<string, vector<string>>& associationTable, map<string, int>& categoryFrequency) {
    /* Initializing variables,
     * numberOfRules, stores how many categories to consider for the input
     * numberOfTerms, stores the number of keywords for a category
     * category, stores category to put into container
     * term, stores keyword to put into container
     */
    int nummberOfRules, numberOfTerms;
    string category, term;
    
    //Storing the number of categories
    cin >> nummberOfRules;
    
    //For-loop that goes through all of the categories and its keywords
    for(int i = 0; i < nummberOfRules; i++) {
        //Storing the current category and the number of keywords associated with it
        cin >> category >> numberOfTerms;
        
        //For-loop that goes through all of the keywords
        for(int j = 0; j < numberOfTerms; j++) {
            //Storing keyword
            cin >> term;
            
            //If the keyword is already associated with another category, it stores the current category in that list. Otherwise, it create a new entry
            if(associationTable.find(term) != associationTable.end())
                associationTable.at(term).push_back(category);
            else
                associationTable.insert({term, vector<string>{category}});
        }
        
        //Stores category
        categoryFrequency.insert({category, 0});
    }
}

int main(int argc, char** argv) {
    /* Initializing variables,
     * highestFrequency, stores the highest number of hits based on the keywords for any category
     * word, used to store words found in the input
     */
    int highestFrequency = 0;
    string word;
    
    /* Initializing containers,
     * categoryFrequency, stores the number of hits based on the keywords for the category. Key is category, value is total sum from the number of times each keyword associated to this category appeared
     * associationTable, relates the keyword to one or multiple categories. Key is a specifc keyword, value is a list of categories that are related to the keyword
     */
    map<string, int> categoryFrequency;
    unordered_map<string, vector<string>> associationTable;
    
    fillTables(associationTable, categoryFrequency);
    
    //While-loop that goes through every word in the input
    while(cin >> word) {
        //Checks if the word is a keyword that is associated with at least one category
        if(associationTable.find(word) != associationTable.end()) {
            //Goes through every category and increments its counter by 1
            for(const string& category : associationTable.at(word)) {
                categoryFrequency.at(category) += 1;
                
                //If the current category has a count higher than the current highest frequency count, it records this new value
                if(categoryFrequency.at(category) > highestFrequency)
                    highestFrequency = categoryFrequency.at(category);
            }
        }
    }
    
    //Outputs the categories that have a frequency count that is the same as highestFrequency
    for(auto& category : categoryFrequency)
        if(category.second == highestFrequency)
            cout << category.first << endl;
    
    return 0;
}
