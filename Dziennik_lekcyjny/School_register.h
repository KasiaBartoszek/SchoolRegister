#ifndef SCHOOL_REGISTER_H
#define SCHOOL_REGISTER_H
#include <vector>
#include "structs.h"
#include "Load_file.h"
#include "Students.h"
#include "Subjects.h"

class School_register: public Students, public Subjects, public Params
{
	public:
		School_register() {}; // konstruktor
		~School_register() {}; // destruktor
		virtual bool infoprocedures() = 0; // funkcja czysto wirtualna
};

#endif