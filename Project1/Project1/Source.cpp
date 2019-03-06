#include <iostream>
using namespace std;

class Queue {
public:
	Queue();
	void push(int num);
	void print();
	int size();
	void pop_front();
	void pop_back();
	int checking();
	int front();
	int back();
private:
	const int SIZE = 40; //максимум мышей вокруг кошки
	int *queue;
	int value, last;
};
// онструктор
Queue::Queue() {
	queue = new int[SIZE];
	value = last = 0;
}
//¬ывод элементов очереди
void Queue::print() {
	for (int i = value + 1; i < last + 1; i++)
	{
		if (queue[i] == 1)
			std::cout << " white";
		if (queue[i] == 2)
			std::cout << " black";
	}
}
//ѕомещение элемента в очередь
void Queue::push(int num) {
	if (last + 1 == value || (last + 1 == SIZE && !value)) {
		std::cout << "FULL" << std::endl;
		return;
	}
	last++;
	if (last == SIZE) last = 0;
	queue[last] = num;
}

void Queue::pop_front() { // »звлечение первого элемента из очереди
	if (value == last) {
		std::cout << "FULL" << std::endl;
		return;
	}
	value++;
	if (value == SIZE) value = 0;
}

void Queue::pop_back() { // »звлечение последнего элемента из очереди
	if (value == last) {
		std::cout << "FULL" << std::endl;
		return;
	}
	last--;
	if (last == SIZE) last = 0;
}


//ќпределение размера очереди
int Queue::size() {
	int s = 0;
	for (int i = value; i<last; i++)
		s++;
	return s;
}
// ѕоследний элемент очереди
int Queue::back() {
	return queue[last];
}
// ѕервый элемент очереди
int Queue::front() {
	return queue[value + 1];
}

int Cheking1() //«ащита от дурака
{
	int value = 0;
	while (true)
	{
		cin >> value;
		if (!cin)
		{
			cout << "WRONG!!Re-enter" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else
			return value;
	}

}


void Cheking(int &fg, int &lg, int &fw, int &lw, int &step) //«ащита от дурака
{

	cout << "Pls enter count first Gray mous:";
	fg = Cheking1();
	cout << "Pls enter count first  White mous:";
	fw = Cheking1();
	cout << "Pls enter count last Gray mous:";
	lg = Cheking1();
	while (!(lg < fg))//если коне4ное кол-во мышей больше на4ального
	{
		cout << "Last gray mouse more first gray mouse!!Re-enter" << endl;
		cin.clear();
		while (cin.get() != '\n');
		lg = Cheking1();
	}
	cout << "Pls enter count last White mous:";
	lw = Cheking1();
	while (!(lw < fw))//если коне4ное кол-во мышей больше на4ального
	{
		cout << "Last white mouse more first white mouse!!Re-enter" << endl;
		cin.clear();
		while (cin.get() != '\n');
		lw = Cheking1();
	}
	cout << "Pls enter step cat:";
	step = Cheking1();
	while (!(step != 0))//если кошка не ходит больше одного круга
	{
		cout << "Re-enter" << endl;
		cin.clear();
		while (cin.get() != '\n');
		step = Cheking1();
	}
}



int main()
{
	int first_gray_mouse;//Ќачальное кол-во серых мышей
	int last_gray_mouse;// онечное кол-во серых мышей
	int first_white_mouse;//Ќачальное кол-во белых мышей
	int last_white_mouse;// онечное кол-во белых мышей
	int step;//Ўаг кошки
	Cheking(first_gray_mouse, last_gray_mouse, first_white_mouse, last_white_mouse, step); //«аполнение с проверками

	int difference_white = first_white_mouse - last_white_mouse;//кол-во сьеденных белых мышей
	int difference_gray = first_gray_mouse - last_gray_mouse;//колв- сьеденных серых мышей

	Queue deck1; //заполн€ема€ о4ередь
	Queue deck2; //—ьеденные мыши
	Queue deck3; //∆ивые мыши



	int counter_1 = difference_gray;//с4етик дл€ сьеденных серых мышей
	int counter_2 = difference_white;//с4етик дл€ мьеденных белых мышей
	for (int i = 0; i < difference_white + difference_gray; i++)//заполн€ем deck2 сьеденными мышами
	{
		if (counter_1 != 0)
		{
			deck2.push(1);
			counter_1--;
		}
		else
		{
			deck2.push(2);
			counter_2--;
		}
	}


	int counter_3 = last_white_mouse;//с4ет4ик дл€ ост. живых белых мышей
	int counter_4 = last_gray_mouse;//с4ет4ик д€л ост. живых серых мышей

	for (int i = 0; i < last_white_mouse + last_gray_mouse; i++)//заполн€ем deck3 ост. живыми мышами
	{
		if (counter_4 != 0)
		{
			deck3.push(1);
			counter_4--;
		}
		else
		{
			deck3.push(2);
			counter_3--;
		}
	}
	////////////////////////////////////////////////////////////////

	int t = 0;//позици€ хода кошки
	bool eat = false;//ест или не ест
	for (int i = 1; i < first_white_mouse + first_gray_mouse + 1; i++)//кол-во шагов кошки
	{

		for (int j = 1; j < difference_white + difference_gray + 1; j++)//бежим по кол-ву ходов кошки
		{
			t = j * step;

			if (j * step > first_white_mouse + first_gray_mouse) //если ход кошки за пределом нашего пол€ ответов
			{
				t = t % (first_white_mouse + first_gray_mouse);
			}

			if (t == i)//если ест
			{
				eat = true;
			}
		}

		if (eat == true)//если ест
		{
			deck1.push(deck2.front());//ƒобавл€ем с конца,т.к первыми заносили серых мышей
			deck2.pop_front();
			eat = false;
		}
		else
		{
			deck1.push(deck3.back());
			deck3.pop_back();
		}

	}

	deck1.print();
	std::cout << std::endl;
	system("pause");
	return 0;
}
