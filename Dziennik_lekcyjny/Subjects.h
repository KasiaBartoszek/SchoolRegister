#ifndef SUBJECTS_H
#define SUBJECTS_H
//#include "Load_file.h"
#include <vector>
#include <fstream>
#include "structs.h"

class Subjects
{
	private:
		std::vector<subject> subjects_list; // wektor z danymi przedmiotow

	public:
		Subjects() {}; // konstruktor
		~Subjects() {}; // destruktor
		Subjects& operator+=(subject &s); // operator dodajacy strukture subject do wektora subjects_list
		std::vector<subject>* getsubjects_p(); // akcesor zwracajacy wskaznik na wektor
};

#endif
