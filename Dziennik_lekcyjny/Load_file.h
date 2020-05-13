#ifndef LOAD_FILE_H
#define LOAD_FILE_H
#include <string>
#include <fstream>
#include "structs.h"
#include "load_params.h"
#include "Students.h"
#include "Subjects.h"

class Load_file : public Params
{
	public:
		Load_file() {}; // konstruktor
		~Load_file() {}; // destruktor
		static void load_student(std::string inper, Students &); // pobiera dane z pliku inper
		static void load_subject(std::string insub, Subjects &); // pobiera dane z pliku insub
};

#endif