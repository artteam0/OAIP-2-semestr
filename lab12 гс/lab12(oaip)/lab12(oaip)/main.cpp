#include"Heap.h"
#include<iostream>
using namespace std;
heap::CMP cmpAAA(void* a1, void* a2)  //‘ункци€ сравнени€
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	int index = 0;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(30, cmpAAA);
	for (;;)
	{
		cout << "1 - вывод первой кучи на экран" << endl;
		cout << "2 - добавить элемент в первой кучу" << endl;
		cout << "3 - вывод второй кучи на экран" << endl;
		cout << "4 - добавить элемент в второй кучу" << endl;
		cout << "5 - объединение двух куч" << endl;
		cout << "6 - удалить минимальный элемент первой кучи" << endl;
		cout << "7 - удалить i-й элемент первой кучи" << endl;
		cout << "8 - количество вершин, €вл€ющиес€ левыми дочерними" << endl;
		cout << "0 - выход" << endl;
		cout << "¬аш выбор: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: exit(0);
		case 1: h1.scan(0);
			break;
		case 2:
		{AAA* a = new AAA;
		cout << "¬ведите ключ" << endl; cin >> k;
		a->x = k;
		h1.insert(a);
		}
		break;
		case 3: h2.scan(0);
			break;
		case 4:
		{AAA* a = new AAA;
		cout << "¬ведите ключ" << endl; cin >> k;
		a->x = k;
		h2.insert(a);
		h1.insert(a);
		}
		break;
		case 5:
			h1.scan(0);
			break;
		case 6: h1.extractMin();
			break;
		case 7: h1.extractI();
			break;
		case 8:
		{
			cout << "¬ведите индекс вершины, дл€ которой хотите узнать количество левых дочерних вершин: ";
			cin >> index;
			cout << endl;
			cout << " оличество левых дочерних вершин дл€ вершины с индексом " << index << ":" << endl;
			printLeftChildrenCount(h1, index);
		}
		break;

		default: cout << endl << "¬ведена неверна€ команда!" << endl;
		}
	} return 0;
}
