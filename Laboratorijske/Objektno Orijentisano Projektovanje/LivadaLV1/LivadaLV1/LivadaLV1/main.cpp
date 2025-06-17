#include "Livada.h"
#include "SemeRuze.h"
#include "JajascePuza.h"
#include "Ruza.h"
#include "Puz.h"
#include "TrojanskaRuza.h"
#include "TrojanskiPuz.h"
#include "GameStartup.h"
using namespace std;

int Livada::brojPronadjenih;
int Livada::brojZametaka;

int main()
{
	try
	{
		GameStartup* game1 = new GameStartup();
		game1->startGame();
	}
	catch (const char* msg)
	{
		cout << msg;
	}
}