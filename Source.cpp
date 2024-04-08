/*
Program name: TestScoresThrowException.cpp
Programmer: Tyler Davies
Date: 11-21-21
Version: 1.0
Description: This program contains a class called TestScores, whose constructor accepts an array of
             test scores as an argument. The class has a member function for returning the average
             of all the test scores. If any score in the array is negative or greater than 100, it
             throws an exception. The class is demonstrated in the main function.
*/

#include<iostream>
using namespace std;

//The TestScores class contains an integer to hold the size of the array, a pointer to point to an
//array of floats, and an exception class InvalidScore which will be thrown if a score is less than
//0 or greater than 100.
class TestScores
{
private:
    int length; 
    float *scores;
    class InvalidScore;
public:
    //Constructor
    TestScores(float arrayList[], const int SIZE)
    {
        scores = arrayList;
        length = SIZE;
    }
    float averageScore();
};

//The private InvalidScore class is an exception class meant to hold an invalid score for output.
class TestScores::InvalidScore
{
public:
    float invalid;
    InvalidScore(float num)
        { invalid = num; }
};

//The averageScore function iterates through the array calculating the average score. If any of the
//scores are invalid, an InvalidScore class object will be created and thrown to the catch block.
float TestScores::averageScore()
{
    float average = 0.0;

    for (int i = 0; i < length; i++)
    {
        try
        {
            if (scores[i] < 0 || scores[i] > 100)
                throw InvalidScore(scores[i]);
            average += scores[i];
        }
        catch (InvalidScore obj)
        {
            cout << "Error: " << obj.invalid << " is an invalid score; setting average to -1.\n";
            return -1;
        }
    }
    average /= length;
    return average;
}

//The main function acts as a driver program to test the averageScore function.
int main()
{
    float average;
    const int SIZE = 9;
    float validScores1[SIZE] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
    float validScores2[SIZE] = { 100, 100, 100, 100, 100, 100, 100, 100, 100 };
    float invalidScores1[SIZE] = { 10, 20, 30, 40, -50, 60, 70, 80, 90 };    //Invalid score -50
    float invalidScores2[SIZE] = { 10, 20, 30, 40, 500, 60, 70, 80, 90 };    //Invalid score 500

    cout << "Testing averageScore function with an array of valid test scores.\n";
    cout << "(Scores: 10, 20, 30, 40, 50, 60, 70, 80, and 90)\n";
    TestScores scores1(validScores1, SIZE);
    average = scores1.averageScore();
    cout << "Average: " << average << endl << endl;

    cout << "Testing averageScore function with an array of valid test scores.\n";
    cout << "(Scores: 100, 100, 100, 100, 100, 100, 100, 100, and 100)\n";
    TestScores scores2(validScores2, SIZE);
    average = scores2.averageScore();
    cout << "Average: " << average << endl << endl;

    cout << "Testing averageScore function with an array containing an invalid test score.\n(less than 0)\n";
    TestScores scores3(invalidScores1, SIZE);
    average = scores3.averageScore();
    cout << "Average: " << average << endl << endl;

    cout << "Testing averageScore function with an array containing an invalid test score.\n(greater than 100)\n";
    TestScores scores4(invalidScores2, SIZE);
    average = scores4.averageScore();
    cout << "Average: " << average << endl;

    exit(0);
}