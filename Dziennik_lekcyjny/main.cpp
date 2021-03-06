//#include "School_register.h"
#include "main.h"
using namespace std;

int main(int argc, char* argv[])
{
	Methods o; // dziedziczy po paramterach, rejestrach i wszystkim co potrzebne (tylko po public lub virtual public)
	
	if (o.load_params(argc, argv))
	{
		Load_file::load_student(o.getper(), o); // l-wartosc akcesora (uzyskana poprzez wywolanie nie moze byc referencja)
		// funkcja static - nie potrzebuje wlasnego obiektu do wywolania, ale jest zadeklarowana wewnatrz klasy.
		Load_file::load_subject(o.getsub(), o);
		bool not_end = true;
		while (not_end)
			not_end = o.infoprocedures();
	}
	
    return 0;
}