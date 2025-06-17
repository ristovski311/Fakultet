//MAIN

#include "Student.h"
#include "Bafer.h"
#include <fstream>
#include <iostream>
using namespace std;

void main()
{
	ifstream ulaz("ulazstudent.txt");
	ofstream izlaz("izlazstudent.txt");

	//TEST CHAR

	Bafer<char, 30> baferChar;
	char unos = 'A';
	for (int i = 0; i < 26; i++)
	{
		baferChar.add(unos);
		unos++;
	}

	/*for (int i = 0; i < baferChar.getTop(); i++)
	{
		cout << baferChar.getItem(i) << endl;
	}*/

	cout << baferChar;

	cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

	cout << baferChar.getFirst() << endl;
	cout << baferChar.getLast() << endl;

	cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

	//TEST STUDENT

	Bafer<Student, 9> baferStudent;
	
	ulaz >> baferStudent;

	izlaz << baferStudent;

	/*for (int i = 0; i < baferStudent.getTop(); i++)
	{
		izlaz << baferStudent.getItem(i);
	}*/


}

//BAFER

#pragma once
template<class T, int max>
class Bafer
{
private:
	T niz[max];
	int top = 0;
public:
	int getTop()
	{
		return top;
	}

	T& getItem(int index)
	{
		if(index < max && index >= 0 && top != 0)
		{
			return this->niz[index];
		}
	}

	T& getFirst()
	{
		if(top != 0)
		{
			return this->niz[0];
		}
	}

	T& getLast()
	{
		if(top != 0)
		{
			return this->niz[top - 1];
		}
	}

	void add(T& t)
	{
		if (top < max)
			this->niz[top] = t;
		top++;
	}

	friend istream& operator>>(istream& i, Bafer<T,max>& t)
	{
		T temp;
		for (int j = 0; j < max; j++)
		{
			i >> temp;
			t.add(temp);
		}
		return i;
	}

	friend ostream& operator<<(ostream& o, Bafer<T, max>& t)
	{
		for (int j = 0; j < t.getTop(); j++)
		{
			o << t.getItem(j);
		}
		return o;
	}

};





//STUDENT.H


#pragma once
#include <string>
using namespace std;
class Student
{
private:
	string ime;
	string prezime;
	int indeks;
	double prosek;
public:
	Student();
	Student(Student& s);
	Student& operator=(Student& s);
	friend istream& operator>>(istream& i, Student& s);
	friend ostream& operator<<(ostream& i, Student& s);
};


//STUDENT.CPP

#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

Student::Student()
{
	this->ime = " ";
	this->prezime = " ";
	this->indeks = 1;
	this->prosek = 1;
}
Student::Student(Student& s)
{
	this->ime = s.ime;
	this->prezime = s.prezime;
	this->indeks = s.indeks;
	this->prosek = s.prosek;
}
Student& Student::operator=(Student& s)
{
	this->ime = s.ime;
	this->prezime = s.prezime;
	this->indeks = s.indeks;
	this->prosek = s.prosek;
	return *this;
}
istream& operator>>(istream& i, Student& s)
{
	i >> s.ime;
	i >> s.prezime;
	i >> s.indeks;
	i >> s.prosek;
	return i;
}
ostream& operator<<(ostream& o, Student& s)
{
	o << "Ime: " << s.ime << endl;
	o << "Prezime: " << s.prezime << endl;
	o << "Indeks: " << s.indeks << endl;
	o << "Prosek: " << s.prosek << endl << endl;
	return o;

}




//ULAZ


Ilija
Milosavljevic
1001
7.3
Milica
Peric
1002
8.6
Marko
Stanic
1003
6.0
Nemanja
Stanimirovic
1004
7.53
Bojan
Petrovic
1005
8.4
Suzana
Dzamic
1006
9.3
Natalija
Minic
1007
9.0
Goran
Miletic
1008
7.8
Petar
Zivanovic
1009
6.5
Sara
Milanovic
1010
8.3
Milovan
Peric
1011
10.0