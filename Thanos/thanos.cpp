#include <iostream>

using namespace std;
using ull = unsigned long long int;

int main(int argc, char** argv) {
    /*Initializing variables
        population, stores the initial population of the planet
        growth, stores the rate at which the population grows
        food, stores how much food the planet produces each year
        planets, stores the number of test cases 
        year, stores how many years it will take before the planet becomes unsustainable for the population
    */
    ull population, growth, food;
    int planets, year = 0;

    //Stores the number of test cases
    cin >> planets;

    //While-loop that goes until there are no more test cases
    while(cin >> population >> growth >> food) {
        //While-loop that continues while the population is less than or equal to the food population
        while(population <= food) {
            //Incremements year by 1
            year++;

            //Increases the population by growth
            population *= growth;
        }

        //Outputs how many years it took
        cout << year << endl;

        //Resets year
        year = 0;
    }

    return 0;
}