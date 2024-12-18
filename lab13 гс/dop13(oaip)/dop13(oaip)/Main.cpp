#include "Hash.h"
#include <iostream>
#include <chrono>
using namespace std;
struct AAA
{
	char* key;
	//int key;
	char* mas;
	AAA(char* k, char* z)
	{
		key = k;  mas = z;
	} AAA() {}
};
//-------------------------------
char* key(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(void* d)
{
	cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int siz = 10, choice;
	cout << "Введите размер хеш-таблицы: ";
	cin >> siz;
	Object H = create(siz, key);
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;   cin >> choice;
		switch (choice)
		{
		case 0: exit(0);
		case 1: H.scan(AAA_print);  break;
		case 2: {
			AAA* a = new AAA;
			char* str = new char[20];
			char* k = new char[20];
			cout << "введите ключ" << endl;
			cin >> k;
			cout << "введите строку" << endl;
			cin >> str;
			a->key = k;
			a->mas = str;

			if (H.N == H.size)
				cout << "Таблица заполнена" << endl;
			else H.insert(a);
		} break;
		case 3: {  cout << "введите ключ для удаления" << endl;
			char* k = new char[20];
			cin >> k;
			H.deleteByKey(k);
		}  break;
		case 4: {
			char* k = new char[20];
			double time1, time2;
			time1 = clock();
			cout << "введите ключ для поиска" << endl;
			cin >> k;
			if (H.search(k) == NULL)
				cout << "Элемент не найден" << endl;
			else
				AAA_print(H.search(k));
			time2 = clock();
			cout << endl << "Time of search:" << (time2 - time1) / 1000 << endl;
		}  break;
		}
	}
	return 0;
}
