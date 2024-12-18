#include <iostream>
#include <fstream>
#include "myStack.h"
using namespace std;

void push1(int x, Stack1*& myStk1)   //Добавление элемента х в стек	
{
	Stack1* e1 = new Stack1;
	cout << "->" << x << endl;//выделение памяти для нового элемента
	e1->data1 = x;             //запись элемента x в поле data 
	e1->next = myStk1;         //перенос вершины на следующий элемент 
	myStk1 = e1;               //сдвиг вершины на позицию вперед
}

void push2(int y, Stack2*& myStk2)   //Добавление элемента y в стек	
{
	Stack2* e2 = new Stack2; 
	cout << "->" << y << endl; //выделение памяти для нового элемента
	e2->data2 = y;             //запись элемента y в поле data 
	e2->next = myStk2;         //перенос вершины на следующий элемент 
	myStk2 = e2;              //сдвиг вершины на позицию вперед
}

void push3(Stack3*& myStk3, Stack1*& myStk1, Stack2*& myStk2)
{
	int i = 0, j = 0;
	bool flag = true;
	Stack1* e = myStk1; 
	Stack2* d = myStk2;
	Stack3* c = myStk3;

	while (e != NULL) { // подсчет элементов 1 стека
		i++;
		e = e->next;
	}
	e = myStk1;

	while (d != NULL) { // подсчет элементов 2 стека
		j++;
		d = d->next;
	}
	d = myStk2;

	for (int a = 0; a < i; a++) {

		for (int b = 0; b < j; b++) {

			if (e->data1 == d->data2) {
				flag = false;
			}	
		}
		if (flag == true) {
			Stack3* c = new Stack3;
			c->data3 = e->data1;
			c->next = myStk3;
			myStk3 = c;

			d = d->next;
			d = myStk2;
		}
		
		e = e->next;
		flag = true;
	}
	e = myStk1;
	d = myStk2;
	c = myStk3;
	while (c != NULL) { // вывод
		cout << c->data3;
		cout << "->>";
		c = c->next;
	}
	c = myStk3;

	//while (myStk1 != NULL) {
	//	Stack3* e1 = new Stack3;    //выделение памяти для нового элемента
	//	e1->data3 = x;             //запись элемента x в поле data 
	//	e1->next = myStk3;         //перенос вершины на следующий элемент 
	//	myStk3 = e1;
	//}

	//while (myStk2 != NULL) {
	//	Stack3* e2 = new Stack3;    //выделение памяти для нового элемента
	//	e2->data3 = x;             //запись элемента x в поле data 
	//	e2->next = myStk3;         //перенос вершины на следующий элемент 
	//	myStk3 = e2;
	//}
}

char popStack1(Stack1*& myStk1)   //Извлечение элемента из стека №1
{
	if (myStk1 == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат (-1) 
	}
	else
	{
		Stack1* e = myStk1;        //переменная для хранения адреса элемента
		char x = myStk1->data1;    //запись элемента из поля data в x 
		if (myStk1)
			myStk1 = myStk1->next;   //перенос вершины
		delete e;
		return x;
	}
}

char popStack2(Stack2*& myStk2)   //Извлечение элемента из стека №2
{
	if (myStk2 == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат (-1) 
	}
	else
	{
		Stack2* d = myStk2;        //переменная для хранения адреса элемента
		char y = myStk2->data2;    //запись элемента из поля data в y 
		if (myStk2)
			myStk2 = myStk2->next;   //перенос вершины
		delete d;
		return y;
	}
}

void toFile(Stack1*& myStk1) //Запись в файл
{
	Stack1* e = myStk1;
	Stack1 buf;
	ofstream frm("Stack1.txt");
	while (e)
	{
		buf = *e;
		frm.write((char*)&buf, sizeof(Stack1));
		e = e->next;
	}
	frm.close();
	cout << "Стек записан\n";
}

void fromFile(Stack1*& myStk1)          //Считывание из файла
{
	Stack1 buf, * p = nullptr, * e = nullptr;
	ifstream frm("Stack1.txt");
	frm.seekg(0);
	frm.read((char*)&buf, sizeof(Stack1));
	while (!frm.eof())
	{
		push1(buf.data1, e);
		frm.read((char*)&buf, sizeof(Stack1));
	}
	frm.close();
	while (e != NULL)
	{
		buf.data1 = popStack1(e);
		push1(buf.data1, p);
		myStk1 = p;
	}
	cout << "\nСтек считан\n\n";
}


//
//#include<iostream>
//#include<fstream>
//#include"myStack.h"
//using namespace std;
//
//void push(int x, Stack*& myStk)   //Добавление элемента х в стек	
//{
//	Stack* e = new Stack;    //выделение памяти для нового элемента
//	e->data = x;             //запись элемента x в поле data
//	e->next = myStk;         //перенос вершины на следующий элемент 
//	myStk = e;               //сдвиг вершины на позицию вперед
//}
//
//void push_2(int y, Stack_2*& myStk_2)   //Добавление элемента y в стек	
//{
//	Stack_2* r = new Stack_2;
//	r->data_2 = y;
//	r->next = myStk_2;
//	myStk_2 = r;
//}
//
//char pop(Stack*& myStk)   //Извлечение (удаление) элемента из стека
//{
//	if (myStk == NULL)
//	{
//		cout << "Стек пуст!" << endl;
//		return -1;               //если стек пуст - возврат (-1) 
//	}
//	else
//	{
//		Stack* e = myStk;        //е-переменная для хранения адреса элемента
//		char x = myStk->data;    //запись элемента из поля data в перем. x 
//		if (myStk)
//			myStk = myStk->next;   //перенос вершины
//		delete e;
//		return x;
//	}
//}
//
//void toFile(Stack*& myStk) //Запись в файл
//{
//	Stack* e = myStk;
//	Stack buf;
//	ofstream frm("mStack.dat");
//	if (frm.fail())
//	{
//		cout << "\n Ошибка открытия файла";
//		exit(1);
//	}
//	while (e)
//	{
//		buf = *e;
//		frm.write((char*)&buf, sizeof(Stack));
//		e = e->next;
//	}
//	frm.close();
//	cout << "Стек записан в файл mStack.dat\n";
//}
//
//void fromFile(Stack*& myStk)          //Считывание из файла
//{
//	Stack buf, * p = nullptr, * e = nullptr;
//	ifstream frm("mStack.dat");
//	if (frm.fail())
//	{
//		cout << "\n Ошибка открытия файла";
//		exit(1);
//	}
//	frm.seekg(0);
//	frm.read((char*)&buf, sizeof(Stack));
//	while (!frm.eof())
//	{
//		push(buf.data, e);
//		frm.read((char*)&buf, sizeof(Stack));
//	}
//	frm.close();
//	while (e != NULL)
//	{
//		buf.data = pop(e);
//		push(buf.data, p);
//		myStk = p;
//	}
//	cout << "\nСтек считан из файла mStack.dat\n\n";
//}
//
//void show(Stack*& myStk)  //Вывод стека с очисткой
//{
//	Stack* e = myStk;
//	if (e == NULL)
//		cout << "Стек пуст!" << endl;
//	while (e != NULL)
//		cout << pop(e) << " ";
//	cout << endl;
//}
//
//void clear(Stack*& myStk, Stack_2*& myStk_2, Stack_3*& myStk_3) { // Сравнивание следующих элементов
//	Stack* e = myStk; int i = 0, j = 0;
//	Stack_2* d = myStk_2;
//	Stack_3* c = myStk_3;
//	while (e != NULL) { // подсчет элементов 1 стека
//		i++;
//		e = e->next;
//	}
//	e = myStk;
//
//	while (d != NULL) {// подсчет элементов 2 стека
//		j++;
//		d = d->next;
//	}
//	d = myStk_2;
//	for (int a = 0; a < i; a++) { // проверка на равность
//
//		for (int w = 0; w < j; w++) {
//
//			if (e->data == d->data_2) { // Запись в 3 стек
//				Stack_3* c = new Stack_3;
//				c->data_3 = e->data;
//				c->next = myStk_3;
//				myStk_3 = c;
//			}
//			d = d->next;
//		}
//		d = myStk_2;
//		e = e->next;
//	}
//	e = myStk;
//	d = myStk_2;
//	c = myStk_3;
//	while (c != NULL) { // Вывод
//		cout << c->data_3;
//		cout << "-->";
//		c = c->next;
//	}
//	cout << "--NULL";
//	c = myStk_3;
//
//
//}
