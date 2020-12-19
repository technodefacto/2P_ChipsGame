//This is two player chips game
/* Author: Naveenkumar Pattabiraman*/
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;


const int MAX_CHIPS = 100;
const float MAX_PER_TURN = 0.5;
int main()
{
	bool player1Turn = true;
	bool gameOver = false;
	
	int chipsInPile = 0;
	int chipsTaken = 0;
	bool moreChipTaken = true;
	int chipsAllowed = 0;

	string playerNames[2];
	
	// Setting seed for random number generator helps avoid 
	// the same set of random numbers being generated. 
	// Different points is set every time we run.
	// Number of seconds since Jan 1. 1970 is the output of time(0)
	srand(time(0)); 
	
	// Asking for players Names
	cout << "Welcome to play this 2 players chips Game.\n";
	cout << "Enter Player 1 Name: ";
	cin >> playerNames[0];
	cout << "Thank you and Good Luck, " << playerNames[0] << "!\nEnter Player 2 Name: ";
	cin >> playerNames[1];
	cout << "Thank you and Good Luck, " << playerNames[1] << "!" << endl;
	
	// Starting game with random number of chips in pile
	chipsInPile = (rand() % MAX_CHIPS) + 1;
	cout << "\nThis round will start with " << chipsInPile << " chips in pile.\n";
	while (gameOver == false)
	{
		while (moreChipTaken) // Loop again until the valid number of chips entered.
		{
			if (player1Turn)
			{
				cout << playerNames[0] << ", How many chips would you like to take?\n";
			}
			else
			{
				cout << playerNames[1] << ", How many chips would you like to take?\n";
			}
			//cout << "You can only take " << static_cast<int>(chipsInPile * MAX_PER_TURN) << " chips" << endl;
			chipsAllowed = chipsInPile * MAX_PER_TURN;
			cout << "You can take upto ";
			if (chipsAllowed == 0)
			{
				cout << "1 chips\n";
			}
			else
			{
				cout << chipsAllowed << " chips" << endl; 
			}
			cin >> chipsTaken; // This cin is out of box thinking. Very interesting about compiler.
			while (!cin) 
			{
		        cout << "\n ERROR, enter a number: " ;
		        cin.clear();
		        cin.ignore(256, '\n');
		        cin >> chipsTaken;
    		}		
			if (chipsTaken < 0)
			{
				cout << "Number can't be Negative!\n";
				moreChipTaken = true;
			}
			//if ((chipsTaken > chipsAllowed) && (chipsInPile > 1))
			else if (chipsAllowed != 0 && chipsTaken > chipsAllowed && chipsInPile > 1)
			{
				cout << "PROMPT CONDITION ...........A\n";
				moreChipTaken = true; 						
			}
			else if (chipsAllowed == 0 && chipsTaken != 1) //ChipsTaken !=1 is the Solving criteria. 
			{
				cout << "PROMPT CONDITION ************B\n";
				moreChipTaken = true; 
			}
			else
			{
				moreChipTaken = false;
			}
			//chipsTaken = (rand() % chipsAllowed) + 1;
			//cout << "Chips taken is: " << chipsTaken << endl;		
		}; 
		moreChipTaken = true;
		chipsInPile -= chipsTaken;
		cout << "\nThere are " << chipsInPile << " chips left in Pile.\n"; 
		if (chipsInPile == 0)
		{
			gameOver = true;
			if (player1Turn)
			{
				cout << "Congratulations, "<<playerNames[1] << "! You Won\n";
			}
			else
			{
				cout << "Congratulations, "<<playerNames[0] << "! You Won\n";
			}
		}
		else
		{
			player1Turn = !player1Turn;
		}
	}
	return 0;
}
