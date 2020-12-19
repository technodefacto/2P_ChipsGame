//This is currently a stone/chips drawing Game from a pile.
//Whoever draws last chip from the file is the loser.
/* Autor: Naveenkumar Pattabiraman */

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cctype>

using namespace std;

// functions
int GameInit(int&, int&, string[]);
int AskUser(bool, int, string[]);
bool IsInputValid(int, int, int);
void AnnounceWinner(bool, string[]);
int PlayAgain();

// global constants
const int MAX_RANDOM_CHIPS = 100;
const float MAX_ALLOWED_CHIPS_PERCENTAGE = 0.5;

int main()
{
	
	string players[2]; // store player names
	int chipsInPile; // Manual selected chips
	int randomChipsInPile = 0; // Randomly selected chips
	
	int chipsAllowed = 0;
	int chipsTaken = 0;
	
	bool gameOver = false;
	bool player1Turn = true;
	

	int gameMode;
	int userChoice;
	gameMode = GameInit(chipsInPile, randomChipsInPile, players);
//	if (gameMode == 1)
//	{
//		chipsInPile = chipsInPile;
//	}
//	else if (gameMode == 2)
//	{
//		chipsInPile = randomChipsInPile;
//	}
	//cout << players[0] << players[1];
	//cout << chipsInPile;
	
	
	//cout << chipsTaken;
	//cout << chipsInPile << ":" << chipsAllowed << " , " << randomChipsInPile << ":" << chipsAllowed;
	while (gameOver == false)
	{
		chipsTaken = AskUser(player1Turn, chipsInPile, players);
		
		chipsInPile -= chipsTaken;
		//cout << chipsTaken << "," << chipsInPile;
		if (chipsInPile == 0)
		{
			gameOver = true;
			AnnounceWinner(player1Turn, players);
			//userChoice = PlayAgain();
			//cout << "userChoice " << userChoice; 
			
		}
		else
		{
			player1Turn = !player1Turn;
		}
	}
}


/////////////////////////////////////////////////////////////////
/*Function: PlayAgain()
Inputs 	  : 
Outputs   : 
Procedure : Ask user if he/she would like to play the game again
*/
/////////////////////////////////////////////////////////////////


int PlayAgain()
{
	int userChoice;
	cout << "Thank you for Playing!, Would you like to play again? 1 -> Continue, 2 -> Quit: > ";
	cin >> userChoice;
	while (cin.fail() || (userChoice>2 || userChoice<1))
	{
		cout << "Invalid Input: 1 -> Continue, 2 -> Quit: >";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> userChoice;
	}
	return userChoice;
}

/////////////////////////////////////////////////////////////////
/*Function: AnnounceWinner()
Inputs 	  : bool player1Turn, string players[]
Outputs   : None
Procedure : The person who picks the last chip is the loser.
*/
/////////////////////////////////////////////////////////////////

void AnnounceWinner(bool player1Turn, string players[])
{
	if (player1Turn)
	{
		cout << "Congratulations " << players[1] <<", You won!\n";
	}
	else
	{
		cout << "Congratulations " << players[0] <<", You won!\n";
	}
}

///////////////////////////////////////////////////////////////////////////
/*Function: IsInputValid()
Inputs 	  : int chipsTaken, int chipsInPile
Outputs   : bool validInput
Procedure : Checking all valid conditions for the input entered by the user.
*/
///////////////////////////////////////////////////////////////////////////

bool IsInputValid(int chipsTaken, int chipsInPile, int chipsAllowed)
{
	
	bool validInput;
		
	if (chipsInPile>1)
	{
		if (chipsTaken>0 && chipsTaken<=chipsAllowed)
		{
			validInput = true;
		}
		else
		{
			validInput = false;
		}
	}
	
	if (chipsInPile==1)
	{
		if (chipsTaken==1)
		{
			validInput = true;		
		}
		else
		{
			validInput = false;
		}
	}
	return validInput;
}
	
//////////////////////////////////////////////////////////////////////
/*Function: AskUser()
Inputs 	  : bool player1Turn, int chipsInPile, string players[]
Outputs   : int chipsTaken
Procedure : Ask current player to take chips from allowed pile.
*/
//////////////////////////////////////////////////////////////////////

int AskUser(bool player1Turn, int chipsInPile, string players[])
{
	int chipsTaken = 0;
	bool validInput;
	int chipsAllowed = chipsInPile * MAX_ALLOWED_CHIPS_PERCENTAGE;
	
	if (player1Turn==true)
	{
		cout << players[0] << ", How many chips would you like to take? Available: " << chipsInPile ;
		cout << ", Allowed: ";
		if (chipsAllowed == 0)
		{
			cout << "1 : your Input >  ";
		}
		else
		{
			cout << chipsAllowed << " : your Input >  "; 
		}
		cin >> chipsTaken;
		validInput = IsInputValid(chipsTaken, chipsInPile, chipsAllowed);
		while (validInput==false)
	  	{
			cout << "Invalid Input: Please take not more than allowed chips :";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> chipsTaken;
			validInput = IsInputValid(chipsTaken, chipsInPile, chipsAllowed);
	  	}
  	}
  	
  	if (player1Turn==false)
	{
		cout << players[1] << ", How many chips would you like to take? Available: " << chipsInPile ;
		cout << ", Allowed: ";
		if (chipsAllowed == 0)
		{
			cout << "1 : your Input >  ";
		}
		else
		{
			cout << chipsAllowed << " : your Input >  "; 
		}
		cin >> chipsTaken;
		validInput = IsInputValid(chipsTaken, chipsInPile, chipsAllowed);
		while (validInput==false)
	  	{
			cout << "Invalid Input: Please take not more than allowed chips :";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> chipsTaken;
			validInput = IsInputValid(chipsTaken, chipsInPile, chipsAllowed);
	  	}
  	}
  	return chipsTaken;
}

///////////////////////////////////////////////////////////////////////
/*Function: GameInit()
Inputs 	  : int& chipsInPile, int& randomChipsInPile, int& chipsAllowed
Outputs   : Pointed to address of the input variable.
Procedure : get player names and select game mode
*/
///////////////////////////////////////////////////////////////////////

int GameInit(int& chipsInPile, int& randomChipsInPile, string players[])
{
	int pileMode = 0;
	
	// Getting players names
	for (int i=0 ; i<2 ; i++)
	{
		cout << "Enter player " << i+1 << " Name: ";
		getline(cin, players[i]);
		cout << "Hello " << players[i] << ", Good Luck!\n" ;
	}
	
	// Pile mode selection 
	cout << "Pile selection: Manual -> 1, Automatic -> 2 , AI -> 3 ?: ";
	cin >> pileMode;
	
	// If invalid input, ask user enter again
	while (!cin || pileMode <= 0 || pileMode>3) 
	{
		cout << "Invalid Input: Manual -> 1, Automatic -> 2 , AI -> 3?: " ;
		cin.clear(); // This is necessary to avoid infinite loop
		cin.ignore(256, '\n'); // This is necessary to avoid infinite loop
		cin >> pileMode;
    }		

	switch (pileMode)
	{
		case 1:
			cout << "Select the chips in pile between 1 and 100: ";
			cin >> chipsInPile;
			// validation check: non integer and integer range
			while (!cin || chipsInPile < 1 || chipsInPile > 100)
			{
				cout << "Invalid Input: Enter number between 1 and 100 : " ;
				cin.clear(); // Put us back in 'normal' operation mode 
				cin.ignore(256, '\n'); // and remove the bad input to avoid infinite loop problem
				cin >> chipsInPile;
    		}
    		cout << "Thank you! Beginning game in Manual mode with " << chipsInPile << " chips in pile.\n";
			break;
			
		case 2:
			//seeding random number generator, so that we can vary the starting point of random genertor:
			srand(time(0));
			chipsInPile = (rand() % MAX_RANDOM_CHIPS) + 1; // Random number generation between 1 and 100
			cout << "Thank you! Beginning game in Automatic mode with " << chipsInPile << " chips in pile.\n";	
			break;
		
		default:
			cout << "Invalid Input";
			break;
				
	}
	return pileMode;
}
