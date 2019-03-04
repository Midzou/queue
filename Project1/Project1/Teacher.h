#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED

#include "Students.h"
#include <string>

class Teacher : public Students { //Клас наследователь
public:


	Teacher() :Students() //Класс Teacher использует констурктор Students
	{}

	Teacher(std::string name_, std::string group_, int value_1_, int value_2_, int value_3_, int value_4_) :Students(name_, group_, value_1_, value_2_, value_3_, value_4_)
	{}
	
		void get_average_score(Students *arr, int  &size); 


};
#endif #pragma once
