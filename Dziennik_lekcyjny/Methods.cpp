#include "Methods.h"

bool Methods::infoprocedures() 
{
	std::cout << std::endl << "Wybierz procedure: " << std::endl
		<< "1. Srednia ocen wszystkich uczniow z danego przedmiotu: srednia <przedmiot> " << std::endl
		<< "2. Metoda generujaca liste urodzonych w podanym przedziale dat: listaurodzonych <rok> <rok>" << std::endl
		<< "3. Lista osob mieszkajacych na tej samej ulicy: listaulica <ulica>" << std::endl
		<< "4. Lista uczniow, ktorych srednia z danego przedmiotu jest wyzsza od podanej: sredniapowyzej <srednia> <przedmiot>" << std::endl 
		<< "5. Aby zakonczyc prace programu wcisnij klawisz f, a nastepnie enter." << std::endl << std::endl;

	std::cin >> procedure; // wczytuje ktora funkcja zostala wywolana z linii polecen
	if (average == procedure) 
	{
		std::cin >> parameter;
		f_avg(parameter, "");
		return true;
	}
	if (bornbetween == procedure) 
	{
		std::cin >> parameter;
		std::cin >> parameter2;
		f_bornbetween(parameter, parameter2);
		return true;
	}
	if (liveplace == procedure) 
	{
		std::cin >> parameter;
		f_liveplace(parameter);
		return true;
	}
	if (averageabove == procedure) 
	{
		std::cin >> parameter;
		std::cin >> parameter2; // potrzebny drugi parametr
		f_averageabove(parameter, parameter2);
		return true;
	}
	if (procedure == "f") // koniec
		return false;
}
double Methods::f_avg(std::string p, std::string pesel) // pesel uzywany w innej funkcji, jesli pusty funkcja wchodzi w inne warunki wypisujac odpowiednie dane do pliku
{ 
	int amt = 0;
	double sum = 0;
	std::string temp;
	std::fstream file_out;
	file_out.open(this->getout(), std::ios::out | std::ios::app);

	for (int i = 0; i < this->getsubjects_p()->size(); i++) 
	{
		temp = this->getsubjects_p()->at(i).subjectname;
		if (temp == p && pesel == "") 
		{
			temp = this->getsubjects_p()->at(i).grade;
			sum += stoi(temp);
			amt++;
		}

		else if (temp == p && this->getsubjects_p()->at(i).pesel == pesel) 
		{
			temp = this->getsubjects_p()->at(i).grade;
			sum += stoi(temp);
			amt++;
		}
	}

	if (amt == 0 && pesel == "") 
	{
		file_out << "Srednia z przedmiotu " << parameter << " wynosi " << 0 << "." << std::endl << std::endl;
		return 0;
	}

	if (pesel == "")
		file_out << "Srednia z przedmiotu " << parameter << " wynosi " << sum/amt << "." << std::endl << std::endl;
	file_out.close();

	return sum / amt;
}

void Methods::f_bornbetween(std::string p1, std::string p2) // zwraca obiekt uczniow
{
	std::fstream file_out;
	file_out.open(this->getout(), std::ios::out | std::ios::app);
	file_out << "Urodzeni pomiedzy " << p1 << " a " << p2 << ":" << std::endl;
	file_out.close();
	Students ob;
	std::string subs;
	int pos = 0;

	for (int i = 0; i < this->getstudents_p()->size(); i++) 
	{
		pos = this->getstudents_p()->at(i).date.find_last_of('.');
		subs = this->getstudents_p()->at(i).date.substr(pos+1, 4);
		if (subs >= p1 && subs <= p2) {
			ob += this->getstudents_p()->at(i);
		}
	}
	ob.writevector(this->getout());
}

void Methods::f_liveplace(std::string p) 
{
	std::fstream file_out;
	file_out.open(this->getout(), std::ios::out | std::ios::app);
	file_out << "Uczniowie mieszkajacy na ulicy " << p << ":" << std::endl;
	file_out.close();
	Students ob;
	std::string temp;

	for (int i = 0; i < this->getstudents_p()->size(); i++) 
	{
		temp = this->getstudents_p()->at(i).street;
		if (temp ==p) 
		{
			ob += this->getstudents_p()->at(i);
		}
	}
	ob.writevector(this->getout());
}

void Methods::f_averageabove(std::string targetavg, std::string subj) 
{
	std::fstream file_out;
	file_out.open(this->getout(), std::ios::out | std::ios::app);
	file_out << "Uczniowie posiadajacy srednie wyzsza niz " << targetavg << " z przedmiotu " << subj << ":" << std::endl;
	file_out.close();
	Students ob;
	std::string temp;

	for (int i = 0; i < this->getstudents_p()->size(); i++) 
	{
		temp = this->getsubjects_p()->at(i).pesel;
		if (f_avg(subj, temp) >= stoi(targetavg)) 
		{
			ob += this->getstudents_p()->at(i);
		}
	}
	ob.writevector(this->getout());
	}