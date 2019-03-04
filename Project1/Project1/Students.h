
#ifndef STUDENTS_H
#define STUDENTS_H
class Students //Класс родитель
{
public:
	Students();
	Students(std::string name_, std::string group_, int value_1_, int value_2_, int value_3_, int value_4_);

	~Students();
	std::string GetName()const;
	std::string GetGroup()const;

	int GetValue_1()const;
	int GetValue_2()const;
	int GetValue_3()const;
	int GetValue_4()const;

	void student_add(Students *arr, int  &size);
	void student_delete(Students *arr, int  &size);
	void student_edit(Students *arr, int  &size);
	void student_search(Students *arr, int  &size);
	void student_list(Students *arr, int  &size);
	
	void compare_students(Students *arr, int  &size);


	void SetName(std::string name_);
	void SetGroup(std::string group_);
	void SetValue_1(int value_1_);
	void SetValue_2(int value_2_);
	void SetValue_3(int value_3_);
	void SetValue_4(int value_4_);
	void Print()const;
	
	void student_read(Students *arr, int  &size);
	void student_write(Students *arr, int  &size);
	
	friend bool operator ==(Students &arr1, Students &arr2); //перегрузка ==
	friend bool operator >(Students &arr1, Students &arr2); //перегрузка >
	friend bool operator <(Students &arr1, Students &arr2); //перегрузка <

private:

	std::string name, group; //Имя и группа
	int value_1, value_2, value_3, value_4; //оценки по предметам
	};
#endif
