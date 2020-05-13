#ifndef METHODS_H
#define METHODS_H
#include <string>
#include <iostream>
#include "Students.h"
#include "Subjects.h"
#include "School_register.h"

class Methods: public virtual School_register
{
	private:
		std::string procedure;
		std::string parameter;
		std::string parameter2; // jesli wymagany w f
		const std::string average = "srednia", bornbetween = "listaurodzonych", liveplace = "listaulica", averageabove = "sredniapowyzej"; // nazwy do wybierania odpowiedniej funkcji
	public:
		bool infoprocedures(); // polimorfizm (ze School_register)
		double f_avg(std::string p, std::string pesel); // zwracanie sredniej ktorej uzywa sie w funkcji wypisywania uczniow ze srednia wyzsza niz podana
		void f_bornbetween(std::string, std::string); // zwraca obiekt studentow
		void f_liveplace(std::string);
		void f_averageabove(std::string p1, std::string p2);
};

#endif