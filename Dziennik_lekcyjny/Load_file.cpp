#include "Load_file.h"
using namespace std;

void Load_file::load_student(string inper, Students &obper)
{
	fstream file_inper;
	file_inper.open((inper), ios::in);
	if (file_inper.good() == true)
	{
		string line, s_pesel, s_name, s_surname, s_date, s_street, s_apartment, s_city;
		while (getline(file_inper, line))
		{
			student* stu = new student;

			int first_comma = line.find(',');
			s_pesel = line.substr(0, first_comma);
			stu->pesel = s_pesel;

			string temp1 = line.substr(first_comma + 2);
			int second_comma = temp1.find(',');
			s_name = temp1.substr(0, second_comma);
			stu->name = s_name;

			string temp2 = temp1.substr(second_comma + 2);
			int third_comma = temp2.find(',');
			s_surname = temp2.substr(0, third_comma);
			stu->surname = s_surname;

			string temp3 = temp2.substr(third_comma + 2);
			int fourth_comma = temp3.find(',');
			s_date = temp3.substr(0, fourth_comma);
			stu->date = s_date;

			string temp4 = temp3.substr(fourth_comma + 2);
			int fifth_comma = temp4.find(',');
			s_street = temp4.substr(0, fifth_comma);
			stu->street = s_street;

			string temp5 = temp4.substr(fifth_comma + 2);
			int sixth_comma = temp5.find(',');
			s_apartment = temp5.substr(0, sixth_comma);
			stu->apartment = s_apartment;

			string temp6 = temp5.substr(sixth_comma + 2);
			int seventh_comma = temp6.find(',');
			s_city = temp6.substr(0, seventh_comma);
			stu->city = s_city;

			obper+=((*stu)); // operator
			
			delete stu;
		}

			file_inper.close();
		}
	}


void Load_file::load_subject(string insub, Subjects &obsub)
{
	fstream file_insub;
	file_insub.open((insub), ios::in);

	if (file_insub.good() == true)
	{
		string line, s_pesel, s_subjectname, s_grade, s_description;
		while (getline(file_insub, line))
		{
			subject* sub = new subject;

			int first_comma = line.find(',');
			s_pesel = line.substr(0, first_comma);
			sub->pesel = s_pesel;

			string temp1 = line.substr(first_comma + 2);
			int second_comma = temp1.find(',');
			s_subjectname = temp1.substr(0, second_comma);
			sub->subjectname = s_subjectname;

			string temp2 = temp1.substr(second_comma + 2);
			int third_comma = temp2.find(',');
			s_grade = temp2.substr(0, third_comma);
			sub->grade = s_grade;

			string temp3 = temp2.substr(third_comma + 2);
			int fourth_comma = temp3.find(',');
			s_description = temp3.substr(0, fourth_comma);
			sub->description = s_description;

			obsub+=((*sub)); // operator

			delete sub;
		}

		file_insub.close();
	}
} 
