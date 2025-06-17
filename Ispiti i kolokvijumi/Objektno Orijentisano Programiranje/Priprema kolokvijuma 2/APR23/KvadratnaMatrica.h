	#pragma once
	#include <iostream>
	#include <fstream>
	using namespace std;

	template<class T>
	class KvadratnaMatrica
	{
	public:
		KvadratnaMatrica(int x);
		KvadratnaMatrica(const KvadratnaMatrica<T>& km);
		~KvadratnaMatrica();
		template<class T> friend istream& operator>>(istream& i, KvadratnaMatrica<T>& km);
		template<class T> friend ostream& operator<<(ostream& o, KvadratnaMatrica<T>& km);
		KvadratnaMatrica<T>& operator=(KvadratnaMatrica<T> km);
		void Citaj(const char* file);
		void Ispisi(const char* file);
		KvadratnaMatrica operator+(KvadratnaMatrica<T>& km);
		KvadratnaMatrica operator*(KvadratnaMatrica<T>& km);

	private:
		int m;
		T** mat;
	};
	template<class T>
	KvadratnaMatrica<T>& KvadratnaMatrica<T>::operator=(KvadratnaMatrica<T> km)
	{
		for (int i = 0; i < this->m; i++)
			delete[] this->mat[i];
		delete[] this->mat;

		this->m = km.m;
		this->mat = new T * [km.m];
		for (int i = 0; i < km.m; i++)
			this->mat[i] = new T[m];

		for (int i = 0; i < km.m; i++)
			for (int j = 0; j < km.m; j++)
				this->mat[i][j] = km.mat[i][j];

		return *this;
	}

	template<class T>
	KvadratnaMatrica<T>::KvadratnaMatrica(int x)
	{
		m = x;
		mat = new T * [x];
		for (int i = 0; i < m; i++)
			mat[i] = new T[m];
	}


	template<class T>
	KvadratnaMatrica<T>::KvadratnaMatrica(const KvadratnaMatrica<T>& km)
	{
		for (int i = 0; i < this->m; i++)
			delete[] this->mat[i];
		delete[] this->mat;

		this->m = km.m;
		this->mat = new T * [km.m];
		for (int i = 0; i < km.m; i++)
			this->mat[i] = new T[m];

		for (int i = 0; i < km.m; i++)
			for (int j = 0; j < km.m; j++)
				this->mat[i][j] = km.mat[i][j];

	}


	template<class T>
	KvadratnaMatrica<T>::~KvadratnaMatrica()
	{
		for (int i = 0; i < this->m; i++)
			delete[] this->mat[i];
		delete[] mat;
	}


	template<class T>
	istream& operator>>(istream& i, KvadratnaMatrica<T>& km)
	{
		for (int p = 0; p < km.m; p++)
			for (int j = 0; j < km.m; j++)
				i >> km.mat[p][j];
		return i;
	}


	template<class T>
	ostream& operator<<(ostream& o, KvadratnaMatrica<T>& km)
	{
		for (int p = 0; p < km.m; p++)
		{
			for (int j = 0; j < km.m; j++)
				o << km.mat[p][j] << " ";
			o << endl;
		}

		return o;
	}



	template<class T>
	void KvadratnaMatrica<T>::Citaj(const char* file)
	{
		ifstream fajl(file);
		if (fajl.good())
		{
			fajl >> *this;
		}
		else
			throw "Greska pri citanju iz fajla\n";
	}

	template<class T>
	void KvadratnaMatrica<T>::Ispisi(const char* file)
	{
		ofstream fajl(file);
		if (fajl.good())
		{
			fajl << *this;
		}
		else
			throw "Greska pri upisu u fajl\n";
	}


	template<class T>
	KvadratnaMatrica<T> KvadratnaMatrica<T>::operator+(KvadratnaMatrica<T>& km)
	{
		if (this->m == km.m)
		{
			KvadratnaMatrica<T> temp(this->m);
			for (int i = 0; i < this->m; i++)
				for (int j = 0; j < this->m; j++)
					temp.mat[i][j] = this->mat[i][j] + km.mat[i][j];
			return temp;
		}
		else
			throw "Greska pri sabiranju matrica\n";
	
	}

	template<class T>
	KvadratnaMatrica<T> KvadratnaMatrica<T>::operator*(KvadratnaMatrica<T>& km)
	{
		if (this->m != km.m)
			throw "Greska pri mnozenju";

		KvadratnaMatrica<T> temp(this->m);
		for (int i = 0; i < this->m; i++)
			for (int j = 0; j < this->m; j++)
			{
				for (int k = 0; k < this->m; k++)
					temp.mat[i][j] = temp.mat[i][j] + this->mat[i][k] * km.mat[k][j];
			}
		return temp;

		/*KvadratnaMatrica<T> temp(this->m);
		if (this->m == km.m)
		{
			for(int i = 0; i < this->m; i++)
				for(int j = 0; j < this->m; j++)
				{
					for (int k = 0; k < this->m; k++)
						temp.mat[i][j] = temp.mat[i][j] + this->mat[i][k] * km.mat[k][j];
				}
		}
		else
			throw "Greska pri sabiranju matrica\n";
		return temp;*/
	}