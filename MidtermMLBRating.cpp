/*
Kenji Hirai
March 21, 2019
CIS 1202_Midterm Project
MLB 2019 Predictive power rating
Description:
You can display predictive team rating by 4 analysts. 
Additionally, you can see average rating of team 
and highest rating of each analyst.
You can also enter new rating.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_ANALYSTS = 4; // Number of analysts
const int NUM_TEAMS = 6; // Number of teams	  

// Name of baseball teams
enum baseballTeams {DODGERS, YANKEES, ASTROS, CUBS, ANGELS, REDS};
struct teams { baseballTeams team; };
const string NAME_LABELS[] = { "DODGERS", "YANKEES", "ASTROS", "CUBS", "ANGELS", "REDS" };

// Name of analysts
enum baseballAnalysts { AlexRodriguez, AaronBoone, JessicaMendoza, KeithOlbermann };
struct analysts { baseballAnalysts analyst; };
const string ANALYST_LABELS[] = { "Alex Rodriguez", "Aaron Boone", "Jessica Mendoza", "Keith Olbermann" };


// Function prototypes
int  displayMenu();
void displayRatings(const int[][NUM_TEAMS], const int[], int);
void showAverageRatings(const int[][NUM_TEAMS], const int[], int);
void showAnalystsHighestRating(const int[][NUM_TEAMS], const int[], int);
void getNewRatings(int[][NUM_TEAMS], const int[], int);

int main()
{
	int teamReviews[NUM_ANALYSTS][NUM_TEAMS] = { {5,4,4,3,3,2},
											     {5,5,4,4,3,3},
												 {4,5,5,5,4,2},
												 {5,3,5,4,3,1} };
	
	int teamID[NUM_TEAMS] = { 1,2,3,4,5,6 };


	cout << "--2019 MLB Baseball Team Predictive Power Rating--" << endl << endl;

	// Display name of teams and analysts
	for (int i = 0; i < NUM_TEAMS; i++) {
		cout << "   Team Number" << teamID[i] << " is " << NAME_LABELS[i] << endl;
		}
	cout << endl;
	for (int i = 0; i < NUM_ANALYSTS; i++) {
		cout << "Analyst Number" << (i+1) << " is " << ANALYST_LABELS[i] << endl;
	}

	// Menu
	bool loop = true;
	while (loop)
	{
	int choice = displayMenu();  

		switch (choice)
		{
		case 1: displayRatings(teamReviews, teamID, NUM_ANALYSTS);
			break;
		case 2: showAverageRatings(teamReviews, teamID, NUM_ANALYSTS);
			break;
		case 3: showAnalystsHighestRating(teamReviews, teamID, NUM_ANALYSTS);
			break;
		case 4: getNewRatings(teamReviews, teamID, NUM_ANALYSTS);
			break;
		case 5: cout << "You have chosen to exit the program!" << endl;
			loop = false;
			break;
		default: cout << "Incorrect menu selection, Please enter a choice from 1 to 5." << endl;
		}
		cout << endl;
	} 
	system("pause");
	return 0;
}

// Display menu selection
int displayMenu() 
{              
	int choice = 0;

	cout << "\n*** Menu ***" << endl << endl;
	cout << "1. Display predictive team ratings" << endl;
	cout << "2. Show the average rating for each team." << endl;
	cout << "3. Show a analysts highest rated team. (enter analyst # 1-4)" << endl;
	cout << "4. Enter new ratings (1-5) for team number 1-6 for four analysts" << endl;
	cout << "5. Exit program" << endl;
	cout << endl << "Enter your choice:";
	cin >> choice;
	cout << endl;
	return choice;
}

// Display predictive ratings
void displayRatings(const int ratings[][NUM_TEAMS], const int team[], int rows)
{
	cout << "---------------------- MLB TEAM RATINGS ------------------------" << endl;
	cout << setw(9) << "ANALYST ";
	
	for (int m = 0; m < NUM_TEAMS; m++)
		cout << setw(8) << " TEAM #" << team[m];
	cout << "\n----------------------------------------------------------------" << endl;

	for (int i = 0; i < rows; i++)
	{
		cout << setw(5) << "# " << i + 1;
		for (int j = 0; j < NUM_TEAMS; j++)
			cout << setw(9) << ratings[i][j];
		cout << endl;
	}
	cout << "\nRating (1=Low to 5=High)" << endl;
	cout << endl;
}

// Display average ratings
void showAverageRatings(const int ratings[][NUM_TEAMS], const int team[], int rows) 
{
	displayRatings(ratings, team, rows); 
	cout << "Average rating for each team:" << endl;
	
	for (int j = 0; j < NUM_TEAMS; j++)
	{
		int sum = 0;
		for (int i = 0; i < rows; i++)
			sum = sum + ratings[i][j];
		cout << "Team number" << team[j] << setw(6) << float(sum) / rows << endl;
	}
	cout << endl;
}

// Display higest rating
void showAnalystsHighestRating(const int ratings[][NUM_TEAMS], const int team[], int rows) 
{
	displayRatings(ratings, team, rows);
	int j;           
	int analyst = 0;  
	int count = 0;   

	cout << "Enter a analyst number (1-4), to find the team they rated the highest:";
	cin >> analyst;

	while (analyst < 1 || analyst > 4)
	{
		cout << "That is an invalid analyst number." << endl;
		cout << "Enter a analyst number (1-4), to find the Team they rated the highest:";
		cin >> analyst;
	}

	cout << "Analyst number" << analyst << " rated Team number";
	int highest = ratings[analyst - 1][0]; 
										
	for (j = 0; j < NUM_TEAMS; j++)
	{
		if (ratings[analyst - 1][j] > highest)
			highest = ratings[analyst - 1][j];
	}

	count = 0;
	for (j = 0; j < NUM_TEAMS; j++)
	{
		if (ratings[analyst - 1][j] == highest)
			count++;
	}

	for (j = 0; j < NUM_TEAMS; j++)
	{
		if (ratings[analyst - 1][j] == highest)
		{
			cout << team[j];
			count--;
			if (count == 1)
				cout << " and ";
			else if (count > 1)
				cout << ", ";
			else if (count == 0)
				cout << " as the highest." << endl << endl;
		}
	}
}

// Display new ratings
void getNewRatings(int ratings[][NUM_TEAMS], const int team[], int rows) 
{
	cout << "*** Data entry for new team ratings ***" << endl;

	for (int i = 0; i < rows; i++)
	{
		cout << "\nAnalyst # " << i + 1 << endl << endl;

		for (int j = 0; j < NUM_TEAMS; j++)
		{
			cout << "Enter rating (1-5) for team number" << team[j] << ": ";
			cin >> ratings[i][j];

			while (ratings[i][j] < 1 || ratings[i][j] > 5)
			{
				cout << "Invalid rating.  It must be from 1-5." << endl;
				cout << "Enter rating (1-5) for team number " << team[j] << ": ";
				cin >> ratings[i][j];
			}
		}
	}
	cout << endl;
}