#include <iostream>
#include <stdio.h>
#include <string>
#include <map>

using namespace std;

int main(int argc, char** argv) {
    /* Initialiizng variables,
     * numberOfElements, stores the number of lines (or species) processed in the test case
     * species, used to store the given species from the input
     */
    int numberOfElements = 0;
    string species;
    
    //Initializing container, used to store how many times a certain species has appeared in the test case/input
    map<string, int> treeSpeciesFrequency;
    
    //While-loop that goes through every line in the input
    while(getline(cin, species)) {
        //Either increments the current number of times a species has appeared in the input or adds a new entry into treeSpeciesFrequency
        if(treeSpeciesFrequency.find(species) != treeSpeciesFrequency.end())
            treeSpeciesFrequency.at(species) += 1;
        else
            treeSpeciesFrequency.insert({species, 1});
        
        //Increments value by 1
        numberOfElements++;
    }
    
    //Goes through every element in treeSpeciesFrequency, outputs the species name and its percentage value in the input
    for(const auto& treeSpecies : treeSpeciesFrequency)
        printf("%s %.6f\n", treeSpecies.first.c_str(), ((double) treeSpecies.second/numberOfElements) * 100);
    
    return 0;
}
