#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

//Stores unique food items found in a list in foodItems
void constructUniqueShoppingList(set<string>& foodItems, const int numberOfItems) {
	//Initializing variable, used to store a food item from a given list
	string item;

	//Iterates through all of the items in the list
	for(int j = 0; j < numberOfItems; j++) {
		//Storing value
		cin >> item;

		//Adding item to foodItems, regardless if it is already there or not
		foodItems.emplace(item);
	}
}

//Updates the count for food items in foods if it appears in foodItems or it creates a new entry in foods if it did not exist previously
void countFrequency(unordered_map<string, int>& foods, set<string>& foodItems) {
	//Iterates through all of the items in foodItems
	for(const string& item : foodItems) 
		//If it is in foods, it incremenets it value by 1; otherwise, it creates a new entry
		if(foods.find(item) != foods.end())
			foods[item]++;
		else
			foods.insert({item, 1});
}

int main(int argc, char** argv) {
	/* Initializing variables,
	 * 
	 * numberOfLists, stores the number of lists in the test case
	 * numberOfItems, stores the number of food items on a specific list
	 */
	int numberOfLists, numberOfItems;

	/* Initializing containers,
	 * 
	 * food, stores the frequency at which a specific food occurs. 
	 *       key is the food and the value is the number of times it appeared in the test case
	 *
	 * consistentlyBoughtFood, stores the food items that have appeared on every shopping list
	 *
	 * foodItems, stores the food items from a given list
	 */
	unordered_map<string, int> foods;
	set<string> consistentlyBoughtFood, foodItems;

	//Storing values into their respective variables
	cin >> numberOfLists >> numberOfItems;

	for(int i = 0; i <= numberOfLists - 1; ++i) {
		/* Reconstructing shopping list. This creates a shopping list that contains all of the unique values in the list; 
		 * in other words, it ignores duplicates of a food item that are on a list
		 */
		constructUniqueShoppingList(foodItems, numberOfItems);

		//Used to keep track of how many lists a food item has appeared in
		countFrequency(foods, foodItems);

		//Checks the end of the input has been reached. If it hasn't, then it clears foodItems for the next list
		if(i != (numberOfLists-1))
			foodItems.clear();
	}

	/* Checks if any of the items found in the last list showed up in every list
	 * This is done to potentially decrease the amount of time spent determining if a food item has appeared on every list 
	 * as items that would satisfy that requirement would have to appear on the last list
	 */
	for(const string& item : foodItems)
		if(foods[item] == numberOfLists)
			consistentlyBoughtFood.emplace(item);

	//Outputs the number of items that were on every list
	cout << consistentlyBoughtFood.size() << endl;

	//Outputs the items in consistentlyBoughtFood
	for(const string& food : consistentlyBoughtFood)
		cout << food << endl;

	return 0;
}