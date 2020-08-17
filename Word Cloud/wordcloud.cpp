#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

//Used to store the fontHeight and width of the word
class cloudWord {
    public:
        //Constructor used to create object
        cloudWord(string w, int fs, int wd) {
            word = w;
            fontHeight = fs;
            width = wd;
        }

        //Returns the fontHeight of the object
        int getFontHeight() {
            return fontHeight;
        }

        //Returns the width of the object
        int getWidth() {
            return width;
        }

    private:
        //Priavte variables that store the values of the object
        string word;
        int fontHeight, width;
};

//Calculates how wide the word is, given the fontHeight of the word and the length of the word
double calculateWidth(const int fontHeight, const int letterLength) {
    return (9.0/16.0) * fontHeight * letterLength;
}

//Calculates the font size of the word, given the number of instances of the specific word and the number of instances of the most frequent word
double calcualteFontHeight(const int wordCount, const int wordCountMax) {
    return ((40.0 * (wordCount - 4.0))/(wordCountMax - 4.0)) + 8.0;
}

int main(int argc, char** argv) {
    /* Initializing variables:
        maxCloudWidth, stores the maximum length for each possible line in the word cloud for a given input
        numberOfInputs, stores the number of words for each batch of words in the input
        numberOfInstances, stores the number of instances of the word
        max, used to store the numberOfInstances for the most frequent word
        cloudNumber, used to itemize the batches when outputing the total cloudHeight at the end
    */
    int maxWordCloudWidth, numberOfInputs, numberOfInstances, max = 0, cloudNumber = 1;

    //Used to store the string for word cloud
    string word;

    //Container used to store the word and its frequency in alphabetical order
    map<string, int> dictionary;

    //Container used to store cloudWord objects
    vector<cloudWord> cloud;

    //Container used to store each line of the cloud
    vector<vector<cloudWord>> clouds;

    //While-loop that iterates through each batch of words
    while(cin >> maxWordCloudWidth >> numberOfInputs) {
        //Checks if it has reached the end of the input
        if(maxWordCloudWidth == 0 && numberOfInputs == 0)
            break;

        //Allocating size of container to numberOfInputs in the batch
        cloud.reserve(numberOfInputs);

        //For-loop that iterates through all of the words in the batch
        for(int i = 0; i < numberOfInputs; i++) {
            //Stores word and frequency in its relevant variables
            cin >> word >> numberOfInstances;

            //Checks if the word frequency satifies the minimum requirement
            if(numberOfInstances >= 5) {
                //Stores values in dictionary, with the stirng as the key and the frequency as the value
                dictionary[word] = numberOfInstances;

                //Checks if the current word has the highest frequency. If it does, then it also stores a copy in max
                if(numberOfInstances > max)
                    max = numberOfInstances;
            }
        }

        //For-loop that iterates through all values in dictionary
        for(auto& x : dictionary) {
            //Calculates the fontHeight and width of the word
            int fontHeight = ceil(calcualteFontHeight(x.second, max)), width = ceil(calculateWidth(fontHeight, x.first.length()));

            //Creates cloudWord object with values word, fontHeight and width and stores it in cloud container
            cloud.push_back(cloudWord(x.first, fontHeight, width));
        }

        //Creating new line (empty vector) and stores it in clouds container
        clouds.push_back(vector<cloudWord>());

        /* Initializing variables:
           index, used to keep track of which line the following loop is on
           totalCloudLineWidth, stores a copy of maxWordCloudWidth and used to determine how many cloudWords can be stored on each line
        */
        int index = 0, totalCloudLineWidth = maxWordCloudWidth;

        //While-loop that continues until there are no more cloudWords
        while(!cloud.empty()) {
            //Checks if the width of the first cloudWord on the list can fit on the line. If it does, then it executes stores it on line index. Otherwise, it creates a new line and stores it there
            if(cloud.at(0).getWidth() <= totalCloudLineWidth) {
                //Stores cloudWord on line index
                clouds.at(index).push_back(cloud.at(0));

                //Subtracts the width of cloudWord + 10 from totalCloudLineWorth
                totalCloudLineWidth = totalCloudLineWidth - cloud.at(0).getWidth() - 10;

                //Removes current cloudWord from cloud
                cloud.erase(cloud.begin());
            }else {
                //Creates new line (empty vector) and stores it in clouds container
                clouds.push_back(vector<cloudWord>());

                //Increments index by one
                index++;

                //Stores cloudWord on line index
                clouds.at(index).push_back(cloud.at(0));

                //Subtracts the width of cloudWord + 10 from maxWordCloudWidth and stores difference in totalCloudLineWidth
                totalCloudLineWidth = maxWordCloudWidth - cloud.at(0).getWidth() - 10;

                //Removes current cloudWord from cloud
                cloud.erase(cloud.begin());
            }
        }

        /* Initializing variables:
           cloudHeightSum, stores sum of the maximum height of each line
           cloudHeight, stores the maximum height of the word of the current line
        */
        int cloudHeightSum = 0, cloudHeight = 0;

        //Nested for-loop that iterates through all values in clouds. Outer loop loops through vectors, inner loop loops through values in current vector
        for(auto& x : clouds) {
            for(auto& y : x) 
                //Checks if current fontHeight value is greater than current fontHeight. If it is, then it stores the value in cloudHeight
                if(y.getFontHeight() > cloudHeight)
                    cloudHeight = y.getFontHeight();

            //Adds cloudHeight to cloudHeightSum
            cloudHeightSum += cloudHeight;

            //Sets cloudHeight value back to 0
            cloudHeight = 0;
        }

        //Outputs batch number and cloudHeightSum
        cout << "CLOUD " << cloudNumber << ": " << cloudHeightSum << endl;

        //Clearing containers
        dictionary.clear();
        clouds.clear();

        //Setting max value to 0
        max = 0;

        //Increments value to label the next batch of inputs
        cloudNumber++;
    }
    
    return 0;
}