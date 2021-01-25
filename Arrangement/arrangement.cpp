#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	/* Initializing variables
       rooms, stores the number of rooms to store teams
       teams, stores the number of teams attending
       teamsPerRoom, stores how many teams to evenly store per room
       remainder, stores the excess number of teams
       counter, used to access elements in teamsAllocated
	*/
	int rooms, teams, teamsPerRoom, remainder, counter = 0;

	//Initializing container, used to store how many teams are in reach room
	vector<string> teamsAllocated;

	//Storing values into their respective variables
	cin >> rooms >> teams;

	//Calculates how many teams can allocated to each room (in an equal manner)
	teamsPerRoom = teams/rooms;

	//Calculates how many teams are left over
	remainder = teams - (rooms * teamsPerRoom);

	//Sets the capacity of teamsAllocated
	teamsAllocated.reserve(rooms);

	//Creates a string that represents how many teams (represented as asterisks) are in each room and then stores it in teamsAllocated
	for(int i = 0; i < rooms; i++)
		teamsAllocated.emplace_back(string(teamsPerRoom, '*'));

	//While-loop that continues until all of the remaining teams have been added to a room
	while(remainder > 0) {
		//If the counter has reached the end of the vector, it resets the counter back to 0 (or wraps around)
		if(counter == teamsAllocated.size())
			counter = 0;

		//Adds a team (or appends an asterisk) to the string at index counter
		teamsAllocated.at(counter) += '*';
		//Increments counter by 1 to move to next room
		counter++;

		//Decrements the counter by 1
		remainder--;
	}

	//Prints out the room arrangments
	for(string& s : teamsAllocated)
		cout << s << endl;

	return 0;
}