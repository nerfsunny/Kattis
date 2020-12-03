#include <iostream>
#include <vector>

using namespace std;

//Calculates the average value of grades
double average(vector<int>& grades) {
    //Initializing variable; stores the total sum of grades
    int sum = 0;

    //For-each loop that adds grade to grades
    for(auto& grade : grades)
        sum += grade;

    //Returns the average value of grades by diving the total sum by the number of values in grades
    return sum/grades.size();
}

//Determines the number of students that are above the given average
double aboveAverageStudents(vector<int>& grades, double average) {
    //Initializing variable; stores the number of students who are above the average
    int numberOfStudents = 0;

    //For-each loop that determines if the grade is stictly greater than the average. If it is, then it increments the numberOfStudents by 1
    for(auto& grade : grades)
        if(grade > average)
            numberOfStudents++;

    //Returns percent value of students who grades are above the average
    return (double) numberOfStudents/grades.size() * 100;
}

int main(int argc, char** argv) {
    //Initializing vector; stores the student grades for a given test case
    vector<int> grades;

    /*Initilizing variables
        numberOfTestCases stores the number of test cases for a given input
        numberOfGrades stores the number of grades for a given test case
        grade is used to store grade into grades
    */
    int numberOfTestCases, numberOfGrades, grade;

    //Storing number of test cases
    cin >> numberOfTestCases;

    //For-loop that iterates through the test cases in an input
    for(int i = 0; i < numberOfTestCases; i++) {
        //Stores the number of grades for test case i
        cin >> numberOfGrades;

        //Allocating grades size to numberOfGrades
        grades.reserve(numberOfGrades);

        //For-loop that iterates through grades in test case i and stores it in grades
        for(int j = 0; j < numberOfGrades; j++) {
            cin >> grade;
            grades.emplace_back(grade);
        }

        //Prints percentage of students who are above average and rounds to the thousandth place (or to three decimal places)
        printf("%.3f%s\n", aboveAverageStudents(grades, average(grades)), "%");

        //Clearing grades
        grades.clear();
    }

    return 0;
}