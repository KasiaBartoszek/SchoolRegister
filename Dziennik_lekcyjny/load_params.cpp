#include "load_params.h"

using namespace std;

string Params::getper() 
{
	return inper;
}
string Params::getsub() 
{
	return insub;
}

string Params::getout()
{
	return out;
}

bool Params::load_params( int &argc,  char* argv[])
{
	const string params[4] = { "-h", "-inper", "-insub", "-out" };
	int flag[3] = { 0 };

	if (argc <= 1)
		cout << "Nie podano parametrow wejsciowych. Uruchom program z przelacznikiem h, aby uzyskac pomoc." << endl;

	else
		for (int i = 1; i < argc; i++)
		{
			if (argv[i] == params[0]) // pomoc
				cout << "Wpisz przy uruchomieniu programu:\n"
				"-h - pomoc\n" 
				"-inper - plik wejsciowy z opisem osob\n" 
				"-insub - plik wejsciowy z opisem przedmiotow\n" 
				"-out - plik wyjsciowy z informacjami\n";

			if (argv[i] == params[1]) // plik wejsciowy z opisem osob
			{
				inper = argv[i + 1];
				flag[0] = 1;
			}

			if (argv[i] == params[2]) // plik wejsciowy z opisem przedmiotow
			{
				insub = argv[i + 1];
				flag[1] = 1;
			}

			if (argv[i] == params[3]) // plik wyjsciowy z informacjami
			{
				out = argv[i + 1];
				flag[2] = 1;
			}
		}

	for (int i = 0; i < 3; i++)
	{
		if (flag[i] == 0)
			return false;
	}

	return true;
};