#include "game_of_life.h"
#include <ctime>
using namespace std;

bool game_of_life::slucajna_vrijednost()
{
	if (rand() % 20 < 1) {
		return true;
	}
	return false;

}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (_generacija[i][j] == true) {
		return true;
	}
	return false;
}

game_of_life::game_of_life()
{
	srand(time(nullptr));
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (slucajna_vrijednost() == true) {
				_generacija[i][j] = true;
			}
			else {
				_generacija[i][j] = false;
			}
		}
	}

	
}

void game_of_life::sljedeca_generacija()
{
	
	int counter = 0;
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			//Provjere za trenutne koordinate
				
				if (_generacija[i][j + 1] == true)
				{
					counter++;
				}
				if (_generacija[i][j - 1] == true)
				{
					counter++;
				}
				if (_generacija[i + 1][j] == true)
				{
					counter++;
				}
				if (_generacija[i - 1][j] == true)
				{
					counter++;
				}
				if (_generacija[i + 1][j + 1] == true)
				{
					counter++;
				}
				if (_generacija[i - 1][j + 1] == true)
				{
					counter++;
				}
				if (_generacija[i + 1][j - 1] == true)
				{
					counter++;
				}
				if (_generacija[i - 1][j - 1] == true)
				{
					counter++;
				}
				if (counter >= 4)
				{
					_sljedeca_generacija[i][j] = false;
				}
				if (counter == 3 || counter == 2)
				{
					_sljedeca_generacija[i][j] = true;
				}
				if (counter = 0)
				{
					_sljedeca_generacija[i][j] = false;
				} 
				counter = 0;

				//Nova generacija je sadasnja
				
		}
	}
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
	

}

void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (celija_zauzeta(i, j) == true) {
				cout << "*";
			}
			else {
				cout << "-";
			}
			if (j == STUPACA - 1) {
				cout << endl;
			}
			
		}
	}
}
