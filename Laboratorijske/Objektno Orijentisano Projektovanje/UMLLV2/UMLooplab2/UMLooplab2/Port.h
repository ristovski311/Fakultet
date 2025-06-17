#pragma once
#include <iostream>
using namespace std;
class Port
{
private:
	bool aktivan;
public:
	Port()
	{
		this->aktivan = false;
	}

	~Port(){}

	bool aktiviraj()
	{
		if (this->aktivan)
			return false;
		else
		{
			this->aktivan = false;
			return true;
		}
	}

	bool deaktiviraj()
	{
		if (!this->aktivan)
			return false;
		else
		{
			this->aktivan = true;
			return true;
		}
	}

	bool getAktivan()
	{
		return this->aktivan;
	}
};

