#include <iostream>
using namespace std;

struct number 
{
	char info;
	number* next;
};

void Input(number** begin, number **end, char el);
void Output(number* begin);
void DelElement(number** begin, number** end);
void DelAfterFive(number** begin, number** end);

int main()
{
	number* begin = NULL, * end, * t;

	t = new number;
	int size;
	char el;

	cout << "Enter size of queue: ";
	cin >> size;
	cout << "Enter symbol: ";       
	cin >> el;

	t->info = el;  
	t->next = NULL;
	begin = end = t;

	for (int i = 0; i < size; i++) {
		cout << "Enter symbol: ";
		cin >> el;
		Input(&begin, &end, el);
		DelAfterFive(&begin, &end);
	}

	cout << "Number of queue elements: 5";
	cout << endl;
	cout << "Elements of queue: " << endl;
	if (begin == NULL) {
		cout << "Queue is empty." << endl;
	}
	else 
	{
		Output(begin);
	}

	cout << "Delete: " << t->info;
	DelElement(&begin, &end);
}

//функция для формирования элементов очереди//
void Input(number** begin, number** end, char el) {
	number* t = new number;

	t->next = NULL; //устанавливается в NULL, тк в данный момент является последним//

	if (*begin == NULL) {
		*begin = *end = t; //тк это первый и единственный элемент в списке//
	}
	else
	{
		t->info = el;
		(*end)->next = t; //устанавливается указатель next последнего элемента списка (*end) так, чтобы он указывал на новый элемент t, добавляя его в конец списка//
		*end = t; //указатель end обновляется//
	}
}

//функция для вывода очереди//
void Output(number* begin)
{
	number* t = begin;
	if (t == NULL) {
		cout << "Queue is empty." << endl;
		return;
	}
	else 
	{
		while (t != NULL) {
			cout << t->info << endl; //вывод инф. текущего элемента списка, на который указывает t//
			t = t->next; //переход на след.//
		}
	}
}

//функция для удаления элемента очереди//
void DelElement(number** begin, number** end)
{
	number* t = *begin;
	if (t == NULL) {
		cout << "Queue is empty." << endl;
		return;
	}
	else
	{
		*begin = (*begin)->next; //начало очереди переназначается на след. элемент//
		delete t; //удаление//
	}

	if (t == NULL) { //если после удаления начало очереди - NULL//
		*end = NULL; //конец очереди обнуляется//
	}
}

//функция для удаления элементов после 5 символа//
void DelAfterFive(number** begin, number** end) 
{ 
	int count = 0;
	number* current = *begin;
	number* previous = NULL;

	while (current != NULL) {
		count++; //подсчёт кол-ва всех элементов//
		current = current->next;
	}

	if (count <= 5) {
		return;
	}

	current = *begin;
	for (int i = 0; i < 5; i++) {
		previous = current; //смещение элементов//
		current = current->next;
	}

	previous->next = current->next; //удаление элемента и перенос указателя на след. элемент//
	delete current;

	if (previous->next == NULL) {
		*end = previous;
	}
}