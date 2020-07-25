/*
 Kenji Hirai
 CIS 1202
 01/14/2019
 Week 1 - Baseball statistics
 */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void loadArrays(int playerNUM[], int atBats[], int hits[], int runs[], int rbis[], double batAvg[], int &numberOfPlayer);
void calcBatAvg(int hits[], int atBats[], double batAvg[], int numberOfPlayer);
void printStats(int player[], int atBat[], int hits[], int run[], int rbi[], double batAvg[], int numberOfPlayer);

void teamAverage(int atBat[], int hits[], int runs[], int rbis[], int numberOfPlayer);
void best(double batAvg[], int num[], int numberOfplayer);
void worst(double batAvg[], int num[], int numberOfPlayer);

int main() {

	const int SIZE = 20;

	int playerNum[SIZE];
	int atBats[SIZE];
	int hits[SIZE];
	int runs[SIZE];
	int rbis[SIZE];
	double batAvg[SIZE];
	int numberOfPlayer;

	// number of players = ?
	loadArrays(playerNum, atBats, hits, runs, rbis, batAvg, numberOfPlayer);

	cout << "Loaded" << numberOfPlayer << "Player is ..." << endl;

	calcBatAvg(hits, atBats, batAvg, numberOfPlayer);

	printStats(playerNum, atBats, hits, runs, rbis, batAvg, numberOfPlayer);

	teamAverage(atBats, hits, runs, rbis, numberOfPlayer);
	
	best(batAvg, playerNum, numberOfPlayer);
	
	worst(batAvg, playerNum, numberOfPlayer);

	system("pause");
	return 0;
}

void loadArrays(int playerNUM[], int atBats[], int hits[], int runs[], int rbis[], double batAvg[], int &numberOfPlayer) {

	int i = 0;
	ifstream file;

	file.open("BaseballStats.txt");

	int playerNumber;
	
	while (file >> playerNumber) {
		cout << "Read player number" << playerNumber << endl;
		playerNUM[i] = playerNumber;
		file >> atBats[i];
		file >> hits[i];
		file >> runs[i];
		file >> rbis[i];
		i++;
	}
	file.close();
}

//Calculate batting average
void calcBatAvg(int hits[], int atBats[], double batAvg[], int numberOfPlayer) {
	for (int i = 0; i < numberOfPlayer; i++) {
		batAvg[i] = ((double) hits[i] * 1000 /(double) atBats[i] );
	}
}

//Display stats
void printStats(int player[], int atBat[], int hits[], int runs[], int rbis[], double batAvg[], int numberOfPlayer) {

	cout << "Player Num" << "\t" << "At Bats" << "\t" << "Hits" << "\t" << "Runs" << "\t" << "RBIs" <<  "\t" << "Bat Avg" << "\t" << "Comment" << endl;

	for (int i = 0; i < numberOfPlayer; i++) {
		string comment;
		
		if (batAvg[i] >= 500 && batAvg[i] <= 1000) { comment = "World Series"; }
		else if (batAvg[i] < 500 && batAvg[i] >= 300) { comment = "Farm League"; }
		else if (batAvg[i] < 300) { comment = "Little League"; }
		else { comment = "Not rated"; }

		cout << player[i] << "\t" << atBat[i] << "\t" << hits[i] << "\t" << runs[i] << "\t" << rbis[i] << "\t" << batAvg[i] << comment <<endl;
	}
}

//Team Average
void teamAverage(int atBat[], int hits[], int runs[], int rbis[], int numberOfPlayer) {

	int btotal = 0, htotal = 0, rtotal = 0, rbtotal = 0, double tavg = 0;

	for (int i = 0; i < numberOfPlayer; i++) {
		btotal += atBat[i];
		htotal += hits[i];
		rtotal += runs[i];
		rbtotal += rbis[i];
	}
	tavg = (htotal / btotal) * 1000;

	cout << "Team" << "\t" << btotal << "\t" << htotal << "\t" << rtotal << "\t" << rbtotal << "\t" << tavg << "\t" << "N/A";
	cout << "The Team Batting Average is : " << tavg << endl;
}

//Best player
void best(double batAvg[], int num[], int numberOfPlayer) {
	int i, maxIndex = 0;
	double max = batAvg[0];

	for (i = 0; i < numberOfPlayer; i++)
	{
		if (max > batAvg[i])
		{
			max = batAvg[i];
			maxIndex = i;
		}
	}
	cout << "The Best Player in PLayer number : " << num[maxIndex] << " With a Batting Average of: " << batAvg[maxIndex];
}

//finding worst
void worst(double batAvg[], int num[], int numberOfPlayer) {

	int i, minIndex = 0;
	double min = batAvg[0];

	for (i = 0; i < numberOfPlayer; i++)
	{
		if (min < batAvg[i])
		{
			min = batAvg[i];
			minIndex = i;
		}
	}
	cout << "The Worst Player in PLayer number : " << num[minIndex] << " With a Batting Average of: " << batAvg[minIndex];
}