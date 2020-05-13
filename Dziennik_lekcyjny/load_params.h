#ifndef LOAD_PARAMS_H
#define LOAD_PARAMS_H
#include <string>
#include <iostream>

class Params
{
	private:
		std::string inper; // plik wejsciowy
		std::string insub; // plik wejsciowy
		std::string out; // plik wyjsciowy
	public:
		std::string	getper(); // akcesory
		std::string	getsub();
		std::string getout();
		Params() {}; // konstruktor
		~Params() {}; // destruktor
		bool load_params( int &argc, char* argv[]); // pobiera parametry wpisane w wierszu polecen
};
#endif