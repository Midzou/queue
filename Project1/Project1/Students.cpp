#include <iostream>
#include <string>
#include "Students.h"
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#pragma warning(disable: 4996);
using namespace std;

Students::Students() :value_1(0), value_2(0), value_3(0), value_4(0) {} //Конструткор

Students::Students(string name_, string group_, int value_1_, int value_2_, int value_3_, int value_4_) :
	name(name_), group(group_), value_1(value_1_), value_2(value_2_), value_3(value_3_), value_4(value_4_) {}

string Students::GetName()const //Взятие имени
{
	return name;
}

string Students::GetGroup()const //Взятие группы
{
	return group;
}

int Students::GetValue_1()const //Взятие оценки по математике
{
	return value_1;
}

int Students::GetValue_2()const //Взятие оценки по программированию
{
	return value_2;
}

int Students::GetValue_3()const //Взятие оценки по химии
{
	return value_3;
}

int Students::GetValue_4()const //Взятие оценки по истории
{
	return value_4;
}


void Students::SetName(string name_) //Установка имени
{
	name = name_;
}

void Students::SetGroup(string group_) //Установка группы
{
	group = group_;
}

void Students::SetValue_1(int value_1_) //Взятие предмета(математика)
{
	value_1 = value_1_;
}

void Students::SetValue_2(int value_2_)//Взятие предмета(программирование)
{
	value_2 = value_2_;
}

void Students::SetValue_3(int value_3_)//Взятие предмета(химия)
{
	value_3 = value_3_;
}

void Students::SetValue_4(int value_4_)//Взятие предмета(история)
{
	value_4 = value_4_;
}



void Students::Print()const //Вывод на экран информации о студенте
{

	std::cout << std::endl << std::endl;
	std::cout << "Name : " << name.c_str() << std::endl;
	if (value_1 == NULL)  //Если оценки по математике нет,то печатается фамилия
		std::cout << "Second name : " << group.c_str() << std::endl;

	if (value_1 != NULL) //Если оценки по математики нет,то оценки по предметам не печатаются
	{
		std::cout << "Group : " << group.c_str() << std::endl;
		std::cout << "Mathematics : " << value_1 << std::endl;
		std::cout << "Programming : " << value_2 << std::endl;
		std::cout << "Chemistry : " << value_3 << std::endl;
		std::cout << "History : " << value_4 << std::endl;
		std::cout << std::endl << std::endl;
	}
}




Students::~Students()
{
}


void student_add(Students *arr, int  &size) //добавление студента
{
	for (int i = 0; i<size; i++)
	{
		char temp[100];
		int a;

		std::cout << "Enter name : ";
		///cin.ignore();
		cin.getline(temp, 100);
		std::cout << endl;

		arr[i].SetName(temp); 

		std::cout << "Enter group : ";
		////cin.ignore();
		cin.getline(temp, 100);
		std::cout << endl;
		arr[i].SetGroup(temp);//Обращение обьекта к элементу класса

		a = rand() % 5 + 1;
		arr[i].SetValue_1(a);

		a = rand() % 5 + 1;
		arr[i].SetValue_2(a);

		a = rand() % 5 + 1;
		arr[i].SetValue_3(a);

		a = rand() % 5 + 1;
		arr[i].SetValue_4(a);

		std::cout << endl << endl << endl;

	}

	std::cout << "" << endl;
}



void student_delete(Students *arr, int  &size) //Удаление студента
{
	std::cout << "Enter student's name to delete : ";
	char temp[100];
	cin >> temp;
	std::cout << endl;


	int luck; //позицию нужного студента в массиве 
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetName() == temp)
		{
			luck = i;
		}
	}
	

	for (int ix = luck; ix < size - 1; ix++) //Удаление найденного элемента из массива
	{
		arr[ix] = arr[ix + 1];
	}
	size--;
}


void student_edit(Students *arr, int  &size) //Редактирование студента
{
	std::cout << "Enter student's name to edit : ";
	///cin.ignore();
	char temp[100];
	cin >> temp;
	std::cout << endl;
	cin.ignore();
	std::cout << endl;
	int luck; //Позиция нужного студента в массиве
	int a;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetName() == temp)
		{
			luck = i;
		}
	}
	///cin.ignore();
	std::cout << "Enter new name : ";
	cin.getline(temp, 100);
	std::cout << endl;
	arr[luck].SetName(temp); //Перезапись имени

	std::cout << "Enter new group : ";
	///cin.ignore();
	cin.getline(temp, 100);
	std::cout << endl;
	arr[luck].SetGroup(temp);


}

void student_search(Students *arr, int  &size) //Поиск студента
{
	std::cout << "Enter student's name to search: " << endl;
	char temp[100];
	cin >> temp;
	std::cout << endl;
	int luck; //Позиция нужного студента в массиве

	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetName() == temp)
		{
			luck = i;
		}
	}
	std::cout << "Name : " << arr[luck].GetName() << endl; //Вывод на экран нужного значения
	std::cout << "Group : " << arr[luck].GetGroup() << endl;
	std::cout << "Mathematics : " << arr[luck].GetValue_1() << std::endl;
	std::cout << "Programming : " << arr[luck].GetValue_2() << std::endl;
	std::cout << "Chemistry : " << arr[luck].GetValue_3() << std::endl;
	std::cout << "History : " << arr[luck].GetValue_4() << std::endl;

}



void student_list(Students *arr, int  &size) //Вывод на экран всех студентов
{
	for (int i = 0; i<size; i++)
	{
		arr[i].Print();
	}
	cout << "" << endl;
}








bool operator == (Students &arr1, Students &arr2)
{

	int sum1 = arr1.value_1 + arr1.value_2 + arr1.value_3 + arr1.value_4;
	int sum2 = arr2.value_1 + arr2.value_2 + arr2.value_3 + arr2.value_4;

	if (sum1 == sum2)
	{
		return 1;
	}
	else
		return 0;
}


bool operator > (Students &arr1, Students &arr2)
{

	int sum1 = arr1.value_1 + arr1.value_2 + arr1.value_3 + arr1.value_4;
	int sum2 = arr2.value_1 + arr2.value_2 + arr2.value_3 + arr2.value_4;

	if (sum1 > sum2)
	{
		return 1;
	}
	else
		return 0;

}

bool operator < (Students &arr1, Students &arr2)
{

	int sum1 = arr1.value_1 + arr1.value_2 + arr1.value_3 + arr1.value_4;
	int sum2 = arr2.value_1 + arr2.value_2 + arr2.value_3 + arr2.value_4;

	if (sum1 < sum2)
	{
		return 1;
	}
	else
		return 0;

}






void compare_students(Students *arr, int  &size)
{
	char temp1[100];
	char temp2[100];
	std::cout << "Enter student's name one " << endl;
	cin >> temp1;
	std::cout << "Enter student's name two " << endl;
	cin >> temp2;



	int luck1;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetName() == temp1)
		{
			luck1 = i;
		}
	}

	int luck2;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetName() == temp2)
		{
			luck2 = i;
		}
	}




	if (arr[luck1] == arr[luck2])
	{
		cout << "Grades of students are equal" << endl;
	}
	if (arr[luck1] > arr[luck2])
	{
		cout << "The first student's grades are better than the second" << endl;
	}
	if (arr[luck1] < arr[luck2])
	{
		cout << "The first student's scores are worse than the second" << endl;
	}
}


void student_write(Students *arr, int  &size) //ф-я запись в файл
{
	FILE * fd;
	fd = fopen("myfile.txt", "wb");
	fwrite(&size, sizeof(int), 1, fd); //Запись размера массива
	for (int i = 0; i < size; i++) //Запись самого массива
	{
		fwrite(&arr[i], sizeof(Students), 1, fd); 

	}
	fclose(fd);
}




void student_read(Students *arr, int  &size)
{

	FILE *fd; //Все студенты

	size = 0;
	for (int i = 0; i<size; i++)
	{

		arr[i].SetName(NULL);
		arr[i].SetGroup(NULL);
		arr[i].SetValue_1(NULL);
		arr[i].SetValue_2(NULL);
		arr[i].SetValue_3(NULL);
		arr[i].SetValue_4(NULL);

	}
	if ((fd = fopen("myfile.txt", "r")) != NULL)
	{
		fread(&size, sizeof(int), 1, fd);
		///Students* arr = new Students[size + sizeof(Students)];

		for (unsigned i = 0; i < size; i++)
		{
			fread(&arr[i], sizeof(Students), 1, fd);
		}
		fclose(fd);
	}
}

