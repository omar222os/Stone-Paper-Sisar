#include <iostream>
#include<cstdlib>
#include <windows.h>
#include<iomanip>
using namespace std;
enum enGame
{
	Stone = 1, Paper , Scissors
};

int GenerateRandumChar(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

short ReadPositiveNumber(string massege)
{
	short n;
	do
	{
		cout << massege << " \n";
		cin >> n;
	} while (n < 0);
	return n;
}

void PrintBiginning(short round)
{
	cout << "Round [" << round << "] begins: \n";
}



enGame GetComputerChoice()
{
	return enGame(GenerateRandumChar(1,3));
}

enGame GetPlayerChoice()
{
	short PlayreChoise;
	do
	{
		 PlayreChoise = ReadPositiveNumber("Your Choise : [1]:Stone, [2]:Paper, [3]:Scisors ?");
	} while (PlayreChoise < 1 || PlayreChoise > 3);
	return enGame(PlayreChoise);


}


string GetWinner(enGame PlayerChoise, enGame ComputerChoise)
{
	switch(PlayerChoise)
	{
		case Stone:
		{
			if (ComputerChoise == Stone)
				return "No Winner\n";
			else if (ComputerChoise == Paper)
				return "Computer";
			else
				return "Player";

		}
		case Paper:
		
			{
			if (ComputerChoise == Paper)
				return "No Winner\n";
			else if (ComputerChoise == Scissors)
				return "Computer";
			else
				return "Player";

			}
		case Scissors:
		{
			if (ComputerChoise == Scissors)
				return "No Winner\n";
			else if (ComputerChoise == Stone)
				return "Computer";
			else
				return "Player";

		}
		

	}
	
}

void ScoreCounter(string Winner , short &PlayreScore , short &ComputerScore , short &Draw)
{
	if (Winner == "Player")
		PlayreScore++;
	else if (Winner == "Computer")
		ComputerScore++;
	else
		Draw++;

}

void ColorTheConsole(string Winner)
{
	if (Winner == "Player")
		system("color 2F");
	else if (Winner == "Computer")
		system("color 4F");
	else
		system("color 6F");
}

void PrintResult(enGame PlayerChoise, enGame ComputerChoise, short round ,string Winner)
{
	if (Winner == "Computer")
		cout << "\a";
	string Choices[4] = {"NUll", "Stone","Paper", "Scissors"};
	ColorTheConsole(Winner);
		cout << "___________________________Round [" << round << "]_______________________ \n\n";
		
		cout << "Playre1 Choice : " << Choices[PlayerChoise]<<endl;
		
		cout << "Computer Choice: " << Choices[ComputerChoise] << endl;
		cout << "Round Winner   : " << Winner ;
		cout << "\n\n_______________________________________________________________________\n";
	
}

short MaxNum(short num1, short num2, short num3)
{
	if (num1 > num2)
	{
		if (num1 > num2)
			return num1;
		else
			return num3;
	}
	else if (num2 > num1)
	{
		if (num2 > num3)
			return num2;
		else
			return num3;
	}
	else
		return num3;
}

char EndGame()
{
	char Restart;
	cout << "Do you want to play againg Y/N? \n";
	cin >> Restart;
	return tolower(Restart);

}
void ClearConsole()
{

	system("cls");
	system("color 0F");
}

void PrintFinalResult(short playreScore, short ComputerScore, short Draw, short rounds)
{
	cout <<setw(9)<< "\n\n---------------------------------------------------\n\n";
	cout << setw(9) << "\t +++ G a m e  O v e r e +++ \n\n";
	cout << setw(9) << "---------------------------------------------------\n\n";
	cout << setw(9) << "___________________________________ ";
	cout <<setw(9)<< "[Game Results ]";
	cout <<setw(9)<< "___________________________________ \n\n";
	cout <<setw(9)<< "Game Rounds \t    :" << rounds<<endl;
	cout <<setw(9)<< "Playre1 won times   :" << playreScore << endl;
	cout <<setw(9)<< "Computer won times  :" << ComputerScore << endl;
	cout <<setw(9)<< "Draw times \t    :" << Draw << endl;
	cout <<setw(9)<< "Final Winnar \t    :";
	if (MaxNum(playreScore, ComputerScore, Draw) == playreScore)
		cout<< "Playre1\n";
	else if (MaxNum(playreScore, ComputerScore, Draw) == ComputerScore)
		cout<< "Computer\n";
	else
		cout<< "No Winner"<<endl;
	cout << "---------------------------------------------------------------------------------------\n\n";

}



void PlayGame()
{
	ClearConsole();
	int NumberOfrounds = ReadPositiveNumber("How many rounds 1 to 10 ? ");
	short PlayerScore = 0, ComputerScore = 0, Draw = 0;
	for (int i = 1; i <= NumberOfrounds; i++)
	{
		PrintBiginning(i);
		enGame PlayerChoice = GetPlayerChoice();
		enGame ComputerChoice = GetComputerChoice();
		string Winner = GetWinner(PlayerChoice, ComputerChoice);
		ScoreCounter(Winner, PlayerScore, ComputerScore, Draw);
		
		PrintResult(PlayerChoice, ComputerChoice, i,Winner);

	}
	PrintFinalResult(PlayerScore, ComputerScore, Draw,NumberOfrounds);
	
	//char& Restartref = Restart;

}

void RestaGame()
{

}


int main()
{
	srand((unsigned)time(NULL));
	//PlayGame();
	char Restart;
	do {
		PlayGame();
		Restart = EndGame();
		
	} while (Restart == 'y');
	

	return 0;
}


