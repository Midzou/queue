#include <iostream>
using namespace std;
class list
{
public:
	list() { head = new (node); head->next = NULL; }
	~list() { destroy(); delete head; }
	void push_back(int);
	void push_front(int);
	void pop_back();
	void pop_front();
	void print();
	int size();
	int back();
	int front();
	void destroy();
private:
	struct node
	{
		int data;
		node *next;
		node *prev;
	};
	node* head;
};

//Заносит элемент в конец списка
//Получает параметр el – значение элемента
void list::push_back(int el)
{
	node *p, *p1;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p1 = new (node);
	p1->data = el;
	p1->next = NULL;
	p1->prev = p;
	p->next = p1;
}

//Заносит элемент в начало списка
//Получает параметр el – значение элемента
void list::push_front(int el)
{
	node* p;
	p = new (node);
	p->data = el;
	if (head->next == NULL) //Если список пуст
	{
		p->next = head->next;
		head->next = p;
		p->prev = head;
	}
	else
	{
		p->next = head->next;
		head->next->prev = p;
		head->next = p;
		p->prev = head;
	}
}

//Выводит список на экран
void list::print()
{
	node* p;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}

	while (p != head)
	{
		if (p->data == 2)
		{
			cout << "White ";
		}
		else { cout << "Black "; }
		p = p->prev;
	}
	std::cout << std::endl << std::endl;
}

//Деструктор
void list::destroy()
{
	node* p, *p1;
	p = head;
	p1 = p->next;
	while (p1 != NULL)
	{
		p = p1;
		p1 = p1->next;
		delete p;
		p = nullptr;
	}
}

//Удаляет последний элемент списка
void list::pop_back()
{
	node* p, *p1;
	p = head;
	p1 = p->next;
	while (p1->next != NULL)
	{
		p = p1;
		p1 = p1->next;
	}
	p->next = NULL;
	delete p1;
}

//Удаляет первый элемент списка
void list::pop_front()
{
	node* p;
	p = head->next;
	head->next = p->next;
	p->next->prev = head;
	delete p;
}

//Проверяет вводимые значения
//Возвращает size-кол-во пар карт
int checking()
{
	int size = 0;
	while (true)
	{
		std::cout << "Please enter the number of pairs of cards : ";
		std::cin >> size;
		if (!std::cin)
		{
			std::cout << "WRONG!!Re-enter" << std::endl;
			std::cin.clear();
			while (std::cin.get() != '\n');
		}
		else
			return size;
	}
}

//Получает последний элемент списка
//Возвращает p1->data -значение последнего элемента
int list::back()
{
	node* p, *p1;
	p = head;
	p1 = p->next;
	while (p1->next != NULL)
	{
		p = p1;
		p1 = p1->next;
	}
	return p1->data;
}

//Получает первый элемент списка
//Возвращает значение элемента
int list::front()
{
	node* p;
	p = head->next;
	return p->data;
}

// Определяет размер списка 
//Возвращает count- количество элементов
int list::size()
{
	int count = 0;
	node* p;
	p = head->next;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

int main()
{
	int size = checking() * 2;

	list deck1;
	list deck2;

	//чередуем карты так,как они должны выкладываться на стол
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			deck2.push_front(1);
		}
		else
		{
			deck2.push_front(2);
		}
	}

	for (int i = 0; deck2.size() != 0; i++)
	{
		if (i % 2 == 0)
		{
			//кладем карту со стола на верх стопки
			deck1.push_back(deck2.back());
			deck2.pop_back();
		}
		else
		{
			//кладем карту с низа стопки на верх
			deck1.push_back(deck1.front());
			deck1.pop_front();
		}
	}
	std::cout << std::endl;
	std::cout << "The desired combination of cards: " << std::endl;
	deck1.print();
	system("pause");
	return 0;
}
