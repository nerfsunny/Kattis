#include <iostream>
#include <unordered_map>
#include <set>
#include <cmath>

using namespace std;

void storeFriendOneMoviePreferences(unordered_map<int, int>& associatedMovieDay, set<int>& movieDays) {
    int movieDay, numberOfMovies;
    
    cin >> numberOfMovies;
    
    for(int i = 0; i < numberOfMovies; i++) {
        cin >> movieDay;
        movieDays.emplace(movieDay);
        associatedMovieDay.insert({movieDay, 1});
    }
}

void storeFriendTwoMoviePreferences(unordered_map<int, int>& associatedMovieDay, set<int>& movieDays) {
    int movieDay, numberOfMovies;
    
    cin >> numberOfMovies;
    
    for(int i = 0; i < numberOfMovies; i++) {
        cin >> movieDay;
        
        if(associatedMovieDay.find(movieDay) != associatedMovieDay.end()) {
            associatedMovieDay.at(movieDay) += 2;
        } else {
            movieDays.emplace(movieDay);
            associatedMovieDay.insert({movieDay, 2});
        }
    }
}

int main(int argc, char** argv) {
    unordered_map<int, int> associatedMovieDay;
    set<int> movieDays;
    
    storeFriendOneMoviePreferences(associatedMovieDay, movieDays);
    storeFriendTwoMoviePreferences(associatedMovieDay, movieDays);
    
    int numberOfConsecutiveDays = 0, numberOfConsecutiveDaysMax = 0, previousPerson = 0;
    
    for(const int& movie : movieDays) {
        if(associatedMovieDay.at(movie) == 3) {
            numberOfConsecutiveDays++;
            previousPerson = 3;
        }else if(associatedMovieDay.at(movie) == 1 && previousPerson != 1) {
            numberOfConsecutiveDays++;
            previousPerson = 1;
        }else if(associatedMovieDay.at(movie) == 2 && previousPerson != 2) {
            numberOfConsecutiveDays++;
            previousPerson = 2;
        }else {
            if(numberOfConsecutiveDays > numberOfConsecutiveDaysMax)
                numberOfConsecutiveDaysMax = numberOfConsecutiveDays;
            
            numberOfConsecutiveDays = 0;
        }
    }
    
    cout << max(numberOfConsecutiveDaysMax, numberOfConsecutiveDays) << endl;
    
    return 0;
}
