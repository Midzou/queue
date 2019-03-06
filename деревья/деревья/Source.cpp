#include <iostream>
#include <ctime>
using namespace std;

int N; // определяет N-арность дерева
int Count = 0;//Счетчик для массива

struct Node
{
	int v = 0; // значение в узле дерева
	Node **cld; // массив потомков
};

Node *root = 0; // корень дерева

int repet = 0;//Счетчик повторяющихся вершин

			  //Вывод дерева на экран
			  //Получает вершину
			  //Получает отступы
void showTreeR(Node *r, int sh)
{
	if (!r) return; // Если нет вершины
	for (int j = 0; j < sh; ++j) putchar(' ');
	cout << r->v << endl;
	for (int i = 0; i < N; ++i)
		showTreeR(r->cld[i], sh + 5); //sh-кол-во отступов для отображения
}

//Проверяет вводимые значения
//Возвращает value-значение вводимого с клавиатуры элемента
int checking()
{
	int value = 0;
	while (true)
	{
		cin >> value;
		if (!cin)
		{
			cout << "WRONG!!Re-enter" << endl;
			cin.clear();//очищение буфера
			while (cin.get() != '\n');
		}
		else
			return value;
	}
}


//Заполняет дерево
//Получает вершину, массив значений, размер массива
void push(Node *&r, int *arr, int size)
{
	if (Count < size)
	{
		if (!r)//если нет вершины
		{
			r = new Node();
			r->cld = new Node *[N];
			for (int i = 0; i < N; ++i)
				r->cld[i] = 0;
			r->v = arr[Count];
			Count++;

		}
		else
		{
			for (int i = 0; i < N; ++i)
				push(r->cld[i], arr, size);
		}
	}
}

//Поиск повторяющихся вершин
//Получает вершину, значение искомой вершины
void findOrderTreeR(Node *r, int value)
{
	if (!r) return; // Если не конец

	if (r->v == value)
	{
		repet++;
	}
	for (int i = 0; i < N; ++i)
		findOrderTreeR(r->cld[i], value);
}


//Удаление дерева
//Получает вершину 
void destroyTree(Node *r)
{
	if (!r)
	{
		for (int i = 0; i < N; ++i)
			destroyTree(r->cld[i]);
		delete(r);
	}
}


int main()
{
	N = 3; // Задаем N-арность дерева
	int size;
	cout << "pls enter count element :";
	size = checking();
	int *arr = new int[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 10 + 1;
	for (int i = 0; i < size; i++)
		push(root, arr, size);
	cout << endl << "Tree : " << endl << endl;
	showTreeR(root, 0);
	cout << endl;
	int value;
	cout << "Repeat vertex value : ";
	value = checking();
	findOrderTreeR(root, value);
	cout << "Number of repetitions " << repet << endl;
	destroyTree(root);
	system("pause");
	return 0;
}
