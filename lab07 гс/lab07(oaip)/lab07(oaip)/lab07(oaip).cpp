//////Разработать функцию, которая формирует стек Stack, включив в него по одному разу элементы, которые входят в стек Stack1, но не входят в стек Stack2.//
////#include <iostream>
////using namespace std;
////
////int main()
////{
////	void elements();
////	void clear();
////	void write_to_file();
////	void read_from_file();
////}
////
////struct stack1
////{
////	int elements;
////	stack1* next;
////};
////
////void push(stack1* st1, int p)
////{
////	stack1* pv = new stack1;
////	pv->elements = p;
////	pv->next = st1;
////	st1 = pv;
////}
#include <iostream>
#include "myStack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int choice; int x, y;
	Stack1* myStk1 = new Stack1;
	Stack2* myStk2 = new Stack2;   //выделение памяти для стека
	Stack3* myStk3 = new Stack3;
	myStk1 = NULL;
	myStk2 = NULL;
	myStk3 = NULL;//инициализация первого элемента	
	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек №1" << endl;
		cout << "2 - Добавление элемента в стек №2" << endl;
		cout << "3 - Извлечение элемента из стека №1" << endl;
		cout << "4 - Извлечение элемента из стека №2" << endl;
		cout << "5 - Запись в третий стек" << endl;
		cout << "6 - Запись в файл" << endl;
		cout << "7 - Чтение из файла" << endl;
		cout << "8 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент: " << endl;
			cin >> x;
			push1(x, myStk1); break;
		case 2: cout << "Введите элемент: " << endl;
			cin >> y;
			push2(y, myStk2); break;
		case 3: x = popStack1(myStk1);
			if (x != -1)
				cout << "Извлеченный элемент: " << x << endl;
			break;
		case 4: x = popStack2(myStk2);
			if (x != -1)
				cout << "Извлеченный элемент: " << x << endl;
			break;
		case 5: 
			push3(myStk3, myStk1, myStk2);
			cout << endl;
			break;
		case 6: 
			toFile(myStk1);  
			break;
		case 7: 
			fromFile(myStk1); 
			break;
		case 8: return 0; 
			break;
		}
	}
	return 0;
}


//#include<iostream>
//#include"myStack.h"
//using namespace std;
////Разработать функцию, которая формирует стек Stack, включив в него повторяющиеся элементы стеков Stack1 и Stack2.
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	int choice; int x, y;
//	Stack* myStk = new Stack; myStk = NULL;
//	Stack_2* myStk_2 = new Stack_2; myStk_2 = NULL;
//	Stack_3* myStk_3 = new Stack_3; myStk_3 = NULL;
//	for (;;)
//	{
//		cout << "Выберите команду:" << endl;
//		cout << "1 - Добавление элемента в стек" << endl;
//		cout << "2 - Добавление элемента в стек 2" << endl;
//		cout << "3 - Извлечение элемента из стека" << endl;
//		cout << "4 - Запись в файл" << endl;
//		cout << "5 - Чтение из файла" << endl;
//		cout << "6 - Вывод стека" << endl;
//		cout << "7 - Есть ли в стеке элемент, равный следующему за ним элементу?" << endl;
//		cout << "0 - Выход" << endl;
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			cout << "Введите элемент: " << endl;
//			cin >> x;
//			push(x, myStk);
//			break;
//
//		case 2:
//			cout << "Введите элемент: " << endl;
//			cin >> y;
//			push_2(y, myStk_2);
//			break;
//
//		case 3:
//			x = pop(myStk);
//			if (x != -1)
//				cout << "Извлеченный элемент: " << x << endl;
//			break;
//
//		case 4:
//			toFile(myStk);
//			break;
//
//		case 5:
//			fromFile(myStk);
//			break;
//
//		case 6:
//			cout << "Весь стек: " << endl;
//			show(myStk);
//			break;
//
//		case 7:
//			clear(myStk, myStk_2, myStk_3);
//			break;
//
//		case 0:
//			return 0;
//			break;
//		}
//	}
//	return 0;
//}
