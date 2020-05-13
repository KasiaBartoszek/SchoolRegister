#include "Students.h"

Students& Students::operator+=(student &s)
{
	students_list.push_back(s);
	return *this;
}

std::vector<student>* Students::getstudents_p() 
{
	return &students_list;
}

void Students::writevector(std::string o) 
{
	std::ofstream file_out;
	std::string tempname, tempsurname, tempid;
	file_out.open(o, std::ios::app);
	file_out << std::endl << "Imie, nazwisko, pesel" << std::endl << std::endl;

	for (int i = 0; i < this->getstudents_p()->size(); i++) 
	{
		tempname = this->getstudents_p()->at(i).name;
		tempsurname = this->getstudents_p()->at(i).surname;
		tempid = this->getstudents_p()->at(i).pesel;
		file_out << tempname << " " << tempsurname << " " << tempid << std::endl;
	}

	file_out << std::endl;

	file_out.close();
}

