﻿#include <iostream>
#include <fstream>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};

void insert(Address* e, Address** phead, Address** plast);
Address* setElement();
void appendToEnd(Address* data, Address** phead, Address** plast);
void outputList(Address** phead, Address** plast);
void find(char name[NAME_SIZE], Address** phead);
void delet(char name[NAME_SIZE], Address** phead, Address** plast);
void writeToFile(Address** phead);
void readFromFile(Address** phead, Address** plast);

int main(void)
{
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	char s[80];  int choice;
	cout << endl;
	do {
		cout << "1. Ввод имени" << endl;
		cout << "2. Удаление имени" << endl;
		cout << "3. Вывод на экран" << endl;
		cout << "4. Добавление имени в конец списка" << endl;
		cout << "5. Поиск" << endl;
		cout << "6. Выход" << endl;
		cout << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			insert(setElement(), &head, &last);
			break;
		case 2: {
			char dname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
		}
			break;
		case 3:
			outputList(&head, &last);
			break;
		case 4:
			appendToEnd(setElement(), &head, &last); // Используем appendToEnd для добавления элемента в конец списка
			break;
		case 5:
			char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
			break;
		case 6:
			exit(0);
			break;
		default:
			cout << "Error." << endl;
			break;
		}

	} while (choice != 6);
	return 0;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
Address* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void appendToEnd(Address* data, Address** phead, Address** plast) {
	Address* new_node = new Address;
	if (!new_node) {
		cerr << "Ошибка выделения памяти" << endl;
		return;
	}
	*new_node = *data; // Копируем данные
	new_node->next = nullptr; // Устанавливаем указатель как nullptr
	new_node->prev = *plast; 
	if (*plast) {
		(*plast)->next = new_node; 
	}
	*plast = new_node; // Обновляем указатель
	if (!*phead) {
		*phead = new_node; 
	}
}

//-----------------------------------------------------------
void outputList(Address** phead, Address** plast) {

	Address* t = *phead;
	while (t) {
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address** phead)    // Поиск имени в списке
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // Удаление имени
{
	struct Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name))  break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
	}
}
//-----------------------------------------------------------
void writeToFile(Address** phead)       //Запись в файл
{
	struct Address* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "wb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
//-----------------------------------------------------------
void readFromFile(Address** phead, Address** plast)   //Считывание из файла
{
	struct Address* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "rb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	cout << "Загрузка из файла" << endl;
	while (!feof(fp))
	{
		t = new Address();
		if (!t)
		{
			cerr << "Ошибка выделения памяти" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
		insert(t, phead, plast);
	}
	fclose(fp);
}

