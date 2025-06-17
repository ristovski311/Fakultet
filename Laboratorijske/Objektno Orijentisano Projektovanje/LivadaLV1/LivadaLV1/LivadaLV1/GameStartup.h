#pragma once
#include "Livada.h"

class GameStartup
{
private:
	bool autopilot;
	bool start;
	bool simple;
	bool endGame;
	void displayMsg(const char*, int);
	void gameCycle(Livada* l);
	void gameEnding(Livada* l);
	void displayTips();
public:
	void startGame();
	const char* izborLivade();
};

