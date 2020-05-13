#ifndef STUDENTS_H
#define STUDENTS_H
#include <vector>
#include <fstream>
#include "structs.h"

class Students
{
	private:
		std::vector<student> students_list; // wektor z danymi uczniow
	public:
		Students() {}; // konstruktor
		~Students() {}; // destruktor
		Students& operator+=(student &s); // operator dodajacy strukture student do wektora students_list
		std::vector<student>* getstudents_p(); // akcesor zwracajacy wskaznik na wektor
		void writevector(std::string o); // metoda wyluskujaca imie, nazwisko i PESEL danego ucznia
};

#endif













//dodaj konstruktor do robienia pustej wetkro 
//vector<student> get_equal(int elements, string member);