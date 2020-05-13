#include "Subjects.h"


Subjects& Subjects::operator+=(subject &g)
{
	subjects_list.push_back(g);
	return *this;
}
std::vector<subject>* Subjects::getsubjects_p() 
{
	return &subjects_list;
}

