#include <iostream>
#include <string>
#include "Students.h"
#include "Teacher.h"
using namespace std;



void get_average_score(Students *arr, int  &size) //Средний бал студентво преподавателя
{

	Teacher teacher("Elena", "Aleksandrovna", NULL, NULL, NULL, NULL);

	teacher.Print(); //Выводим имя и фамилию

	int sum = 0; //Сумма оценок всех студентов
	for (int i = 0; i < size; i++) 
	{
		sum = sum + arr[i].GetValue_1() + arr[i].GetValue_2() + arr[i].GetValue_3() + arr[i].GetValue_4();
	}
	cout << endl;
	cout << "Average score Teacher : " << sum / (size * 4) << endl;
}



