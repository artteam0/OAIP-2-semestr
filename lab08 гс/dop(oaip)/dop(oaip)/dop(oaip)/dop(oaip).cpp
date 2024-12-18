//#include<iostream>
//using namespace std;
//struct Item
//{
//    int data;
//    Item* next;
//};
//Item* head, * tail;
//
//bool isNull(void)    //Проверка на пустоту
//{
//    return (head == nullptr);
//}
//void deletFirst()   //Извлечение элемента из начала
//{
//    if (isNull())
//        cout << "Queue is empty." << endl;
//    else
//    {
//        Item* p = head;
//        head = head->next;
//        delete p;
//    }
//}
//void deletlast()   //Извлечение элемента из начала
//{
//    if (isNull())
//        cout << "Queue is empty." << endl;
//    else
//    {
//        Item* p;
//        tail->data = NULL;
//
//    }
//}
//void getFromHead()  //Получение элемента из начала
//{
//    if (isNull())
//        cout << "Queue is empty." << endl;
//    else
//        cout << "Begin = " << head->data << endl;
//}
//void getFromTail()  //Получение элемента из конца
//{
//    if (isNull())
//        cout << "Queue is empty." << endl;
//    else
//        cout << "End = " << tail->data << endl;
//}
//void insertToQueue(int x)  //Добавление элемента в очередь 
//{
//    Item* p = new Item;      //новый указатель 
//    p->data = x;
//    p->next = nullptr;
//    Item* v = new Item;      //указатель для нового числа
//    Item* p1 = new Item;
//    Item* p2 = new Item;
//    int i = 0;               //флажок 
//    if (isNull())
//        head = tail = p;
//    else
//    {
//        p2 = head; p1 = head; // !!!Чтобы реализовать ввод LiFo необходимо чтобы указатель p2 был позади, FiFo наобарот
//        while (p1 != nullptr)  //пока очередь не закончится
//        {
//            if (i == 1) //ТАКЖЕ НЕОБХОДИМЫ ДЛЯ РЕАЛИЗАЦИИ LiFo
//            {
//                if (i == 1)
//                {
//                    if (x > p1->data)  //число больше, чем в очереди
//                    {
//                        v->data = x;
//                        v->next = p1;
//                        p2->next = v;
//                        return;
//                    }
//                    if (x == p1->data)
//                    {
//                        v->data = x;
//                        v->next = p1->next;
//                        p1->next = v;
//                        return;
//                    }
//                    p2 = p2->next;
//                }
//                if (x > p1->data)
//                {
//                    v->data = x;
//                    v->next = p1;
//                    head = v;
//                    return;
//                }
//                if (p1->next == nullptr)
//                {
//                    v->data = x;
//                    v->next = nullptr;
//                    tail->next = v;
//                    tail = v;
//                    return;
//                }
//                i = 1;
//
//                p1 = p1->next;      // следующее число
//            }
//            else // else необходимое для реализации вставки LiFo
//            {
//                if (x >= p1->data)
//                {
//                    v->data = x;
//                    v->next = p2;
//                    head = v;
//                    return;
//                }
//            }
//            p1 = p1->next; //ТАКЖЕ НЕОБХОДИМЫ ДЛЯ РЕАЛИЗАЦИИ LiFo
//            i = 1;
//        }
//        if (p1 == NULL) // Выражение ДЛЯ РЕАЛИЗЦИИ LiFo
//        {
//            v->data = x;
//            v->next = tail;
//            p2->next = v;
//        }
//    }
//}
//
//void printQueue()             //Вывод очереди
//{
//    int g;
//    Item* p = new Item;
//    if (isNull())
//        cout << "Queue is empty." << endl;
//    else
//    {
//        cout << "Queue: ";
//        p = head;
//        while (!isNull())
//        {
//            if (p != nullptr)
//            {
//                g = p->data;
//                if (g == 0) {
//
//                }
//                else { cout << p->data << " "; cout << "->"; }
//                p = p->next;
//            }
//            else
//            {
//                cout << "NULL" << endl;
//                return;
//            }
//        }
//    }
//}
//
//void clrQueue()           //Очистка очереди
//{
//    while (!isNull()) deletFirst();
//}
//int main()
//{
//    int i = 1, choice = 1, z; head = nullptr;  tail = nullptr;
//    while (choice != 7)
//    {
//        cout << "1. Add element." << endl;
//        cout << "2. Get element from beginning." << endl;
//        cout << "3. Extract element from beginning." << endl;
//        cout << "4. Display elements." << endl;
//        cout << "5. Clear queue." << endl;
//        cout << "6. Get element from end." << endl;
//        cout << "7. Exit." << endl;
//        cin >> choice;
//        switch (choice)
//        {
//        case 1: cout << "Enter element:  "; cin >> z;
//            insertToQueue(z); printQueue();  break;
//        case 2: getFromHead(); break;
//        case 3: deletFirst();  break;
//        case 4: printQueue();  break;
//        case 5: clrQueue();    break;
//        case 6: getFromTail(); break;
//        case 7: deletlast(); break;
//        }
//    }
//    return 0;
//}



#include <iostream>

using namespace std;

struct Node {
	float Number;
	Node* next;
};

struct Queue {
	int size = 0;
	Node* head;
	Node* tail;
};



void CreateQueue(Queue* Q) {
	Q->head = new Node();
	Q->head->next = NULL;
	Q->tail = Q->head;
	Q->size = 0;
}
void AddElem(Queue* Q) {
	float newElem;
	cout << "Enter element: ";
	cin >> newElem;
	Q->tail->next = new Node();
	Q->tail = Q->tail->next;
	Q->tail->Number = newElem;
	Q->tail->next = NULL;
	Q->size++;
}
int OutQueue(Queue* Q) {
	if (Q->head == Q->tail) {
		cout << "Queue is empty.";
		return 0;
	}
	else {
		Node* Temp = Q->head->next;
		while (Temp) {
			cout << Temp->Number << endl;
			Temp = Temp->next;
		}
	}
}
int Shift(Queue* Q) {
	if (Q->head == Q->tail) {
		cout << "Queue is empty." << endl;
		return 0;
	}
	else {
		float max = 0;
		Node* Temp = Q->head->next;
		while (Temp) {
			if (Temp->Number > max)
				max = Temp->Number;
			Temp = Temp->next;
		}
		cout << "Max value: " << max << endl;
		cout << "Queue with shift: ";
		Temp = Q->head;
		Temp->Number = max;
		cout << Temp->Number << endl;
		while (Temp) {
			if (Temp->Number != max) cout << Temp->Number << endl;
			Temp = Temp->next;
		}
	}
}

int main()
{
	Queue t;
	int choice;
	CreateQueue(&t);
	for (;;)
	{
		cout << "Menu" << endl;
		cout << "1. Add element." << endl;
		cout << "2. Output queue." << endl;
		cout << "3. Cyclic shift." << endl;
		cout << "4. Exit." << endl;
		cin >> choice;
		switch (choice)
		{

		case 1:
			AddElem(&t);
			break;
		case 2:
			OutQueue(&t);
			break;
		case 3:
			Shift(&t);
			break;
		case 4:
			return 0;
			break;

		}
	}
}
//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//// Определение структуры для связанного списка
//struct Item {
//	char data;
//	Item* next;
//};
//
//// Инициализация указателей head и tail
//Item* head = nullptr;
//Item* tail = nullptr;
//
//// Проверка, пустой ли список
//bool isNull() {
//	return (head == nullptr);
//}
//
//// Вставка элемента в очередь
//void insertToQueue(char x) {
//	Item* p = new Item;
//	p->data = x;
//	p->next = nullptr;
//
//	if (isNull()) {
//		head = tail = p;
//	}
//	else {
//		tail->next = p;
//		tail = p;
//	}
//}
//
//// Обработка строки ввода и вставка цифр в очередь
//void processLine(string& line) {
//	for (char ch : line) {
//		if (isdigit(ch)) {
//			insertToQueue(ch);
//		}
//	}
//}
//
//// Печать содержимого очереди в выходной файл
//void printQueue(ofstream& out) {
//	if (!isNull()) {
//		Item* p = head;
//		while (p != nullptr) {
//			out << p->data;
//			p = p->next;
//		}
//	}
//}
//
//int main() {
//	setlocale(LC_CTYPE, "Russian");
//
//	// Открытие входного и выходного файлов
//	ifstream inFile("first.txt");
//	ofstream outFile("second.txt");
//
//	if (!inFile.is_open() || !outFile.is_open()) {
//		cerr << "Ошибка открытия файла." << endl;
//		return 1;
//	}
//
//	string line;
//	while (getline(inFile, line)) {
//		processLine(line);
//
//		outFile << line;
//		printQueue(outFile);
//		outFile << endl;
//	}
//
//	// Закрытие файлов
//	inFile.close();
//	outFile.close();
//
//	cout << "Данные успешно записаны." << endl;
//
//	return 0;
//}
