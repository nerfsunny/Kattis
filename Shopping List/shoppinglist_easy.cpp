#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	/* Initializing variables,
	 * 
	 * word, stores the name of the food
	 * numberOfLists, stores the number of lists in the test case
	 * numberOfItems, stores the number of food items on a specific list
	 */
	int numberOfLists, numberOfItems;
	string word;

	/* Initializing containers,
	 * 
	 * food, stores the frequency at which a specific food occurs. 
	 *       key is the food and the value is the number of times it appeared in the test case
	 *
	 * consistentlyBoughtFood, stores the food items that have appeared on every shopping list
	 */
	unordered_map<string, int> food;
	set<string> consistentlyBoughtFood;

	//Storing values into their respecitve variables
	cin >> numberOfLists >> numberOfItems;

	//Nested for-loop that iterates through the test case. Outer for-loop goes to the next line, inner for-loop iterates through all of the food items on the line
	for(int i = 0; i < numberOfLists; i++) {
		for(int j = 0; j < numberOfItems; j++) {
			//Storing food item
			cin >> word;

			//Checks if the food item is already in food. If it is, it increments the value by 1. Otherwise, it creates a new entry and stores it
			if(food.find(word) != food.end())
				food[word]++;
			else
				food.insert({word, 1});
		}
	}

	//Goes through all of the entries in food and determines if it showed up numberOfLists times. If it did, it is stored in consistentlyBoughtFood
	for(auto& x : food)
		if(x.second == numberOfLists)
			consistentlyBoughtFood.emplace(x.first);

	//Outputs the number of food that fit the criteria
	cout << consistentlyBoughtFood.size() << endl;

	//Outputs the food items that fit the criteria
	for(string s : consistentlyBoughtFood)
		cout << s << endl;

	return 0;
}