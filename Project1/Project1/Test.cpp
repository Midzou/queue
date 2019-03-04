#include <string>
#include <iostream>
#include "Students.h"
#include "Teacher.h"

void student_add(Students *arr, int  &size);
void student_delete(Students *arr, int  &size);
void student_edit(Students *arr, int  &size);
void student_search(Students *arr, int  &size);
void student_list(Students *arr, int  &size);
void get_average_score(Students *arr, int  &size);
void compare_students(Students *arr, int  &size);

void student_write(Students *arr, int  &size);
void student_read(Students *arr, int  &size);

using namespace std;

int main()
{
	system("color F0"); //Белый фон консоли
	
	 
	cout << "Pls enter number of students or press ZERO if the database is already created: ";
	int size; //Размер массива
	cin >> size;
	Students * arr = new Students[size]; //Выделяем память под массив студентов

	cin.ignore();
	student_add(arr, size); //Добавляем студентов
	unsigned item;
	do
	{
		std::cout << "Menu:" << std::endl;
		std::cout << "\t1. Delete student" << std::endl;
		std::cout << "\t2. Edit student" << std::endl;
		std::cout << "\t3. Search student" << std::endl;
		std::cout << "\t4. Look student" << std::endl;
		std::cout << "\t5. Information about the teacher" << std::endl;
		std::cout << "\t6. Check for matches" << std::endl;
		std::cout << "\t7. Cleaning console" << std::endl;
		std::cout << "\t8. Save" << std::endl;
		std::cout << "\t9. Load" << std::endl;
		std::cout << "\t10. Exite" << std::endl;
		std::cout << "Enter item: ";
		std::cin >> item;
		switch (item)
		{
		case 1:
			student_delete(arr, size);
			break;
		case 2:
			student_edit(arr, size);
			break;
		case 3:
			student_search(arr, size);
			break;
		case 4:
			student_list(arr, size);
			break;
		case 5:
			get_average_score(arr, size);
			break;
		case 6:
			compare_students(arr, size);
			break;
		case 7:
			system("cls");
			break;
		case 8:
			student_write(arr, size);
			break;
		case 9:
			student_read(arr, size);//Чтение с файла	
			break;
		case 10:
			delete[] arr;
			system("pause");
			return 0;
		}
	} while (item != 0);
	delete[] arr;
	system("pause");
	return 0;
}
