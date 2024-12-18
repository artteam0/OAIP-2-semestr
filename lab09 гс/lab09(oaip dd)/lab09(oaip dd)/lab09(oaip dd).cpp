//#include <iostream>
//#include <fstream>
//using namespace std;
//const unsigned int NAME_SIZE = 30;
//const unsigned int CITY_SIZE = 20;
//
//struct Address
//{
//	char name[NAME_SIZE];
//	char city[CITY_SIZE];
//	Address* next;
//	Address* prev;
//};
////-----------------------------------------------------------
//int menu(void)
//{
//	char s[80];  int c;
//	cout << endl;
//	cout << "1. Ввод имени" << endl;
//	cout << "2. Удаление имени" << endl;
//	cout << "3. Вывод на экран" << endl;
//	cout << "4. Добавление имени в конец списка" << endl;
//	cout << "5. Поиск" << endl;
//	cout << "6. Выход" << endl;
//	cout << endl;
//	do
//	{
//		cout << "Ваш выбор: ";
//		cin.sync();
//		gets_s(s);
//		cout << endl;
//		c = atoi(s);
//	} while (c < 0 || c > 5);
//	return c;
//}
////-----------------------------------------------------------
//void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
//{
//	Address* p = *plast;
//	if (*plast == NULL)
//	{
//		e->next = NULL;
//		e->prev = NULL;
//		*plast = e;
//		*phead = e;
//		return;
//	}
//	else
//	{
//		p->next = e;
//		e->next = NULL;
//		e->prev = p;
//		*plast = e;
//	}
//}
////-----------------------------------------------------------
//Address* setElement()      // Создание элемента и ввод его значений с клавиатуры 
//{
//	Address* temp = new  Address();
//	if (!temp)
//	{
//		cerr << "Ошибка выделения памяти памяти";
//		return NULL;
//	}
//	cout << "Введите имя: ";
//	cin.getline(temp->name, NAME_SIZE - 1, '\n');
//	cin.ignore(cin.rdbuf()->in_avail());
//	cin.clear();
//	cout << "Введите город: ";
//	cin.getline(temp->city, CITY_SIZE - 1, '\n');
//	cin.ignore(cin.rdbuf()->in_avail());
//	cin.clear();
//	temp->next = NULL;
//	temp->prev = NULL;
//	return temp;
//}
////-----------------------------------------------------------
//void outputList(Address** phead, Address** plast)      //Вывод списка на экран
//{
//	setlocale(LC_ALL, "Ru");
//	Address* t = *phead;
//	while (t)
//	{
//		cout << t->name << ' ' << t->city << endl;
//		t = t->next;
//	}
//	cout << "" << endl;
//}
////-----------------------------------------------------------
//void find(char name[NAME_SIZE], Address** phead)    // Поиск имени в списке
//{
//	Address* t = *phead;
//	while (t)
//	{
//		if (!strcmp(name, t->name)) break;
//		t = t->next;
//	}
//	if (!t)
//		cerr << "Имя не найдено" << endl;
//	else
//		cout << t->name << ' ' << t->city << endl;
//}
////-----------------------------------------------------------
//void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // Удаление имени
//{
//	struct Address* t = *phead;
//	while (t)
//	{
//		if (!strcmp(name, t->name))  break;
//		t = t->next;
//	}
//	if (!t)
//		cerr << "Имя не найдено" << endl;
//	else
//	{
//		if (*phead == t)
//		{
//			*phead = t->next;
//			if (*phead)
//				(*phead)->prev = NULL;
//			else
//				*plast = NULL;
//		}
//		else
//		{
//			t->prev->next = t->next;
//			if (t != *plast)
//				t->next->prev = t->prev;
//			else
//				*plast = t->prev;
//		}
//		delete t;
//		cout << "Элемент удален" << endl;
//	}
//}
//void appendToEnd(Address* data, Address** phead, Address** plast);
//
////-----------------------------------------------------------
//int main(void)
//{
//	Address* head = NULL;
//	Address* last = NULL;
//	setlocale(LC_CTYPE, "Rus");
//	while (true)
//	{
//		switch (menu())
//		{
//		case 1:  insert(setElement(), &head, &last);
//			break;
//		case 2: {	  char dname[NAME_SIZE];
//			cout << "Введите имя: ";
//			cin.getline(dname, NAME_SIZE - 1, '\n');
//			cin.ignore(cin.rdbuf()->in_avail());
//			cin.sync();
//			delet(dname, &head, &last);
//		}
//			  break;
//		case 3:  outputList(&head, &last);
//			break;
//		case 4:
//			appendToEnd(setElement(), &head, &last);
//			break;
//		case 5: {	  char fname[NAME_SIZE];
//			cout << "Введите имя: ";
//			cin.getline(fname, NAME_SIZE - 1, '\n');
//			cin.ignore(cin.rdbuf()->in_avail());
//			cin.sync();
//			find(fname, &head);
//		}
//			  break;
//		case 6:  exit(0);
//		default: exit(1);
//		}
//	}
//	return 0;
//}
//void appendToEnd(Address* data, Address** phead, Address** plast) {
//	Address* new_node = new Address;
//	if (!new_node) {
//		cerr << "Ошибка выделения памяти" << endl;
//		return;
//	}
//	*new_node = *data; // Копируем данные
//	new_node->next = nullptr; // Устанавливаем указатель как nullptr
//	new_node->prev = *plast;
//	if (*plast) {
//		(*plast)->next = new_node;
//	}
//	*plast = new_node; // Обновляем указатель
//	if (!*phead) {
//		*phead = new_node;
//	}
//}
//void writeToFile(Address** phead)       //Запись в файл
//{
//	struct Address* t = *phead;
//	FILE* fp;
//	errno_t err = fopen_s(&fp, "mlist", "wb");
//	if (err)
//	{
//		cerr << "Файл не открывается" << endl;
//		exit(1);
//	}
//	cout << "Сохранение в файл" << endl;
//	while (t)
//	{
//		fwrite(t, sizeof(struct Address), 1, fp);
//		t = t->next;
//	}
//	fclose(fp);
//}
////-----------------------------------------------------------
//void readFromFile(Address** phead, Address** plast)   //Считывание из файла
//{
//	struct Address* t;
//	FILE* fp;
//	errno_t err = fopen_s(&fp, "mlist", "rb");
//	if (err)
//	{
//		cerr << "Файл не открывается" << endl;
//		exit(1);
//	}
//	while (*phead)
//	{
//		*plast = (*phead)->next;
//		delete* phead;
//		*phead = *plast;
//	}
//	*phead = *plast = NULL;
//	cout << "Загрузка из файла" << endl;
//	while (!feof(fp))
//	{
//		t = new Address();
//		if (!t)
//		{
//			cerr << "Ошибка выделения памяти" << endl;
//			return;
//		}
//		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
//		insert(t, phead, plast);
//	}
//	fclose(fp);
//}



//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//struct Student//Для допа 2(3) все адреса были заменены на студентов и добавлены соответствующие разделы
//{
//	int data;
//	/*char initials[100];
//	int year;
//	char group[30];
//	int grades[6];*/
//	Student* next;
//	Student* prev;
//};
//
//void insert(Student** first, Student** last)
//{
//
//	Student* temp = new  Student;
//	cin >> temp->data;
//	/*int year;
//	cout << "Initials:";
//	gets_s(temp->initials);
//	gets_s(temp->initials);
//	cout << "Birth:";
//	cin >>temp->year;
//	cout << "Group:";
//	gets_s(temp->group);
//	gets_s(temp->group);
//	cout << "Grades:" << endl;
//	for (int i = 1; i <=5; i++)
//	{
//		cout << i << ":";
//		cin >> temp->grades[i];
//	}*/
//
//
//	temp->prev = NULL;
//	temp->next = NULL;
//
//	Student* e = *last;
//
//	if (*last == NULL)
//	{
//
//		temp->next = NULL;
//		temp->prev = NULL;
//		*last = temp;
//		*first = temp;
//	}
//	else
//	{
//		e->next = temp;
//		temp->next = NULL;
//		temp->prev = e;
//		*last = temp;
//	}
//
//}
//
//
//
//
//
//
//void output(Student** head)
//{
//	cout << endl;
//	Student* temp = *head;
//	while (temp)
//	{
//		cout << temp->data << " ";
//		temp = temp->next;
//	}
//	cout << endl;
//	/*Student* temp = *head;
//	while (temp)
//	{
//		cout << "Initials:";
//		cout<<temp->initials<<endl;
//		cout << "Birth:";
//		cout << temp->year << endl;
//		cout << "Group:";
//		cout << temp->group << endl;
//		cout << "Grades:" << endl;
//		for (int i = 1; i <= 5; i++)
//		{
//			cout << i << ":";
//			cout<<temp->grades[i] << endl;
//		}
//		temp = temp->next;
//	}
//	cout << endl;*/
//}
//
//
//
////void delet(Student** phead, Student** plast) 
////{
////	Student* t = *phead;
////	char street[100];
////	cout << endl << "Delete:";
////	gets_s(street);
////	gets_s(street);
////while (t)
////{
////	if (!strcmp(street, t->street))  break;
////	t = t->next;
////}
////if (!t)
////cerr << "Имя не найдено" << endl;
////else
////{
////	if (*phead == t)
////	{
////		*phead = t->next;
////		if (*phead)
////			(*phead)->prev = NULL;
////		else
////			*plast = NULL;
////	}
////	else
////	{
////		t->prev->next = t->next;
////		if (t != *plast)
////			t->next->prev = t->prev;
////		else
////			*plast = t->prev;
////	}
////	delete t;
////	cout << "Deleted succesfully" << endl;
////}
////}
//
////void writeToFile(Student** phead)
////{
////	Student* t = *phead;
////	ofstream file("gg.txt");
////	
////	while (t)
////	{
////		file << t->city << "--" << t->street << endl;
////		t = t->next;
////	}
////	file.close();
////}
////
////void readFromFile()
////{
////	ifstream File("gg.txt");
////	string tempString;
////	while (getline(File,tempString))
////	{
////		cout << tempString <<endl;
////	}
////	File.close();
////}
//
////void execution(Student **phead)
////{
////
////	int count = 0,m;
////	Student* t = *phead;
////	cout << "Every:";
////	cin >> m;
////	while (t)
////	{
////		count += 1;
////		if (count % m == 0)
////		{
////			t->prev->next = t->next;
////			t = t->next;
////		}
////		else { t = t->next; }
////	}	
////}
//
////void execution(Student **phead)//Для допа 2
////{
////	string nameMin, nameMax, nameGrade;
////	int minAge = 999, maxAge = 0;
////	float maxAverageGrade = 0, sum;
////	Student* temp= *phead;
////	while (temp)
////	{
////		if ((2024 - temp->year) > maxAge)
////		{
////			maxAge = 2024 - temp->year;
////			nameMax = temp->initials;
////		}
////		if ((2024 - temp->year) < minAge)
////		{
////minAge = 2024 - temp->year;
////nameMin = temp->initials;
////		}
////		sum = 0;
////		for (int i = 1; i <= 5; i++)
////		{
////			sum += temp->grades[i];
////		}
////		if (sum / 5 > maxAverageGrade)
////			{
////maxAverageGrade = sum / 5;
////nameGrade = temp->initials;
////			}
////		temp = temp->next;
////	}
////	cout << endl << "--------------------------------------------" << endl << "Youngest:" << nameMin << endl << "Oldest:" << nameMax << endl << "Most succesfull:" << nameGrade << endl << "----------------------------------------------------" << endl;
////}
//
//void execution(Student** phead, int K)//для допа 3
//{
//	int count = 1;
//	Student* temp = *phead;
//	cout << endl << "-------------------------------------" << endl;
//	while (temp)
//	{
//		cout << "Current:";
//		output(&temp);
//		Student* t = temp;
//		while (t)
//		{
//			if (count % K == 0)
//			{
//
//				cout << "Out:" << t->data << " ";
//				if (t->prev == NULL && t->next == NULL)
//				{
//					exit(69);
//				}
//				if (t->prev == NULL)
//				{
//					temp = temp->next;
//					temp->prev = NULL;
//				}
//				else
//				{
//					if (t->next == NULL)
//					{
//						t->prev->next = NULL;
//					}
//					else t->prev->next = t->next;
//				}
//
//
//
//			}
//			count += 1;
//			t = t->next;
//		}
//	}
//	cout << endl << "-------------------------------------" << endl;
//}
//
//void main()
//{
//	Student* head = NULL, * tail = NULL;
//	//Доп 3
//	int n;
//	cout << "N:";
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		insert(&head, &tail);
//	}
//	output(&head);
//	cout << endl << "K:";
//	int K;
//	cin >> K;
//	execution(&head, K);
//	/////////////////////////////////////////////////////////////////////////////
////	while (true)
////	{
////		cout << "1.Enter element" << endl << "2.Output" << endl << "3.Delete" << endl<<"4.Write to file"<<endl<<"5.Read from file"<<endl<<"6.EXE"<<endl;
////		int choice;
////		cin >> choice;
////		switch (choice)
////		{
////		case 1:
////		{
////insert(&head, &tail);
////break;
////		}
////		case 2:
////		{
////output(&head);
////break;
////		}
//////		case 3:
//////		{
//////delet(&head,&tail);
//////break;
//////		}
//////		case 4:
//////		{
//////			writeToFile(&head);
//////			break;
//////		}
//////		case 5:
//////		{
//////			readFromFile();
//////		}
////		case 6:
////		{
////			execution(&head);
////		}
////		}
////	}
//
//}


//#include <iomanip>
//#include <iostream>
//using namespace std;
//
//const unsigned int NAME_SIZE = 30;
//
//struct Address
//{
//	char name[NAME_SIZE];
//	char surname[NAME_SIZE];
//	char parentname[NAME_SIZE];
//	int month;
//	int year;
//	int day;
//	int course;
//	int group;
//	float math;
//	float OAIP;
//	float English;
//	float Yap;
//	float Kyar;
//	Address* next;
//	Address* prev;
//};
//void insert(Address* e, Address** phead, Address** plast);
//Address* setElement();
//void outputList(Address** phead, Address** plast);
//void studentOld(Address** phead, Address** plast);
//void studentYoung(Address** phead, Address** plast);
//void outputFirstCourse(Address** phead, Address** plast);
//void outputSecondCourse(Address** phead, Address** plast);
//void outputThirdCourse(Address** phead, Address** plast);
//void outputFourthCourse(Address** phead, Address** plast);
//void average(Address** phead, Address** plast);
//void insert(Address* e, Address** phead, Address** plast)
//{
//	Address* p = *plast;
//	if (*plast == NULL)
//	{
//		e->next = NULL;
//		e->prev = NULL;
//		*plast = e;
//		*phead = e;
//		return;
//	}
//	else
//	{
//		p->next = e;
//		e->next = NULL;
//		e->prev = p;
//		*plast = e;
//	}
//}
////-----------------------------------------------------------
//Address* setElement()
//{
//	Address* temp = new Address();
//	if (!temp)
//	{
//		cerr << "Ошибка выделения памяти памяти";
//		return NULL;
//	}
//	cout << "Введите фамилию: ";
//	cin >> temp->surname;
//	cout << "Введите имя: ";
//	cin >> temp->name;
//	cout << "Введите отчество: ";
//	cin >> temp->parentname;
//	cout << "Введите дату рождения: " << endl;;
//	cout << "Введите день:";
//	cin >> temp->day;
//	cout << endl;
//	cout << "Введите месяц:";
//	cin >> temp->month;
//	cout << endl;
//	cout << "Введите год:";
//	cin >> temp->year;
//	cout << endl;
//	cout << "Введите номер курса: ";
//	cin >> temp->course;
//	cout << "Введите номер группы: ";
//	cin >> temp->group;
//	cout << "Введите оценки по предметам: " << endl;
//	cout << "Математика:";
//	cin >> temp->math;
//	cout << endl;
//	cout << "ОАиП:";
//	cin >> temp->OAIP;
//	cout << endl;
//	cout << "Английский язык:";
//	cin >> temp->English;
//	cout << endl;
//	cout << "ЯП:";
//	cin >> temp->Yap;
//	cout << endl;
//	cout << "КЯР:";
//	cin >> temp->Kyar;
//	cout << endl;
//	temp->next = NULL;
//	temp->prev = NULL;
//	return temp;
//}
//void outputList(Address** phead, Address** plast)
//{
//	Address* t = *phead;
//	if (t == NULL)
//	{
//		cout << "Список пуст!" << endl;
//	}
//	while (t)
//	{
//
//		cout << "--------------------------------------------------" << endl;
//		cout << "Фамилия:" << t->surname << endl;
//		cout << "Имя:" << t->name << endl;
//		cout << "Отчество:" << t->parentname << endl;
//		cout << "Дата рождения:" << t->day << "." << t->month << "." << t->year << endl;
//		cout << "Курс:" << t->course << endl;
//		cout << "Группа:" << t->group << endl;
//		cout << "Оценки:" << endl;
//		cout << "Математика:" << t->math << endl;
//		cout << "ОАиП:" << t->OAIP << endl;
//		cout << "Английский язык:" << t->English << endl;
//		cout << "ЯП:" << t->Yap << endl;
//		cout << "КЯР:" << t->Kyar << endl;
//		t = t->next;
//
//	}
//}
//void outputFirstCourse(Address** phead, Address** plast)
//{
//	int i = 0;
//	Address* t = *phead;
//	if (t == NULL)
//	{
//		cout << "Список пуст!" << endl;
//	}
//	cout << "---------------------Студенты 1 курса-------------------" << endl;
//	if (strcmp(t->surname, (t->next)->surname) > 0)
//	{
//		t = t->next;
//		t->next = t->prev;
//		t->prev = t;
//	}
//	while (i != 2)
//	{
//
//
//		if (t->course == 1)
//		{
//			cout << "--------------------------------------------------" << endl;
//			cout << "Фамилия:" << t->surname << endl;
//			cout << "Имя:" << t->name << endl;
//			cout << "Отчество:" << t->parentname << endl;
//			cout << "Дата рождения:" << t->day << "." << t->month << "." << t->year << endl;
//			cout << "Курс:" << t->course << endl;
//			cout << "Группа:" << t->group << endl;
//			cout << "Оценки:" << endl;
//			cout << "Математика:" << t->math << endl;
//			cout << "ОАиП:" << t->OAIP << endl;
//			cout << "Английский язык:" << t->English << endl;
//			cout << "ЯП:" << t->Yap << endl;
//			cout << "КЯР:" << t->Kyar << endl;
//			t = t->next;
//		}
//		else
//		{
//			t = t->next;
//		}
//
//		i++;
//	}
//}
//void outputSecondCourse(Address** phead, Address** plast)
//{
//	Address* t = *phead;
//	if (t == NULL)
//	{
//		cout << "Список пуст!" << endl;
//	}
//	cout << "--------------------Студенты 2 курса----------------" << endl;
//	while (t)
//	{
//		if (t->course == 2)
//		{
//			cout << "--------------------------------------------------" << endl;
//			cout << "Фамилия:" << t->surname << endl;
//			cout << "Имя:" << t->name << endl;
//			cout << "Отчество:" << t->parentname << endl;
//			cout << "Дата рождения:" << t->day << "." << t->month << "." << t->year << endl;
//			cout << "Курс:" << t->course << endl;
//			cout << "Группа:" << t->group << endl;
//			cout << "Оценки:" << endl;
//			cout << "Математика:" << t->math << endl;
//			cout << "ОАиП:" << t->OAIP << endl;
//			cout << "Английский язык:" << t->English << endl;
//			cout << "ЯП:" << t->Yap << endl;
//			cout << "КЯР:" << t->Kyar << endl;
//			t = t->next;
//		}
//		else
//			t = t->next;
//
//	}
//}
//void outputThirdCourse(Address** phead, Address** plast)
//{
//	Address* t = *phead;
//	if (t == NULL)
//	{
//		cout << "Список пуст!" << endl;
//	}
//	cout << "--------------------Студенты 3 курса----------------" << endl;
//	while (t)
//	{
//		if (t->course == 3)
//		{
//			cout << "--------------------------------------------------" << endl;
//			cout << "Фамилия:" << t->surname << endl;
//			cout << "Имя:" << t->name << endl;
//			cout << "Отчество:" << t->parentname << endl;
//			cout << "Дата рождения:" << t->day << "." << t->month << "." << t->year << endl;
//			cout << "Курс:" << t->course << endl;
//			cout << "Группа:" << t->group << endl;
//			cout << "Оценки:" << endl;
//			cout << "Математика:" << t->math << endl;
//			cout << "ОАиП:" << t->OAIP << endl;
//			cout << "Английский язык:" << t->English << endl;
//			cout << "ЯП:" << t->Yap << endl;
//			cout << "КЯР:" << t->Kyar << endl;
//			t = t->next;
//		}
//		else
//			t = t->next;
//
//	}
//}
//void outputFourthCourse(Address** phead, Address** plast)
//{
//	Address* t = *phead;
//	if (t == NULL)
//	{
//		cout << "Список пуст!" << endl;
//	}
//	cout << "--------------------Студенты 4 курса----------------" << endl;
//	while (t)
//	{
//		if (t->course == 4)
//		{
//			cout << "--------------------------------------------------" << endl;
//			cout << "Фамилия:" << t->surname << endl;
//			cout << "Имя:" << t->name << endl;
//			cout << "Отчество:" << t->parentname << endl;
//			cout << "Дата рождения:" << t->day << "." << t->month << "." << t->year << endl;
//			cout << "Курс:" << t->course << endl;
//			cout << "Группа:" << t->group << endl;
//			cout << "Оценки:" << endl;
//			cout << "Математика:" << t->math << endl;
//			cout << "ОАиП:" << t->OAIP << endl;
//			cout << "Английский язык:" << t->English << endl;
//			cout << "ЯП:" << t->Yap << endl;
//			cout << "КЯР:" << t->Kyar << endl;
//			t = t->next;
//		}
//		else
//			t = t->next;
//
//	}
//}
//void studentOld(Address** phead, Address** plast)
//{
//	int old = 0;
//	Address* tmp = *phead;
//	old = tmp->year;
//	while (tmp)
//	{
//
//		if (tmp->year < old)
//		{
//			old = tmp->year;
//		}
//		tmp = tmp->next;
//
//	}
//	Address* t = *phead;
//	while (t)
//	{
//		if (t->year == old)
//		{
//			cout << "Старший студент=" << t->surname << endl;
//		}
//		t = t->next;
//	}
//
//}
//void studentYoung(Address** phead, Address** plast)
//{
//	int young = 0;
//	Address* tmp = *phead;
//	young = tmp->year;
//	while (tmp)
//	{
//
//		if (tmp->year > young)
//		{
//			young = tmp->year;
//		}
//		tmp = tmp->next;
//
//	}
//	Address* t = *phead;
//	while (t)
//	{
//		if (t->year == young)
//		{
//			cout << "Младший студент=" << t->surname << endl;
//		}
//		t = t->next;
//	}
//}
//void average(Address** phead, Address** plast)
//{
//	float average1 = 0, average2 = 0, average3 = 0;
//	Address* t = *phead;
//	while (t)
//	{
//		average1 = (t->English + t->math + t->Kyar + t->Yap + t->OAIP) / 5;
//		cout << "Студент:" << t->surname << " " << "средний балл=" << average1 << endl;
//		t = t->next;
//		average2 = (t->English + t->math + t->Kyar + t->Yap + t->OAIP) / 5;
//		cout << "Студент:" << t->surname << " " << "средний балл=" << average2 << endl;
//		t = t->next;
//
//	}
//	Address* emp = *phead;
//	while (emp)
//	{
//		if (average1 >= average2 && average1 >= average3)
//		{
//			cout << "Best students:" << emp->surname << endl;
//		}
//		emp = emp->next;
//		if (average2 >= average1 && average2 >= average3)
//		{
//			cout << "Best students:" << emp->surname << endl;
//		}
//		emp = emp->next;
//
//
//	}
//}
//int main()
//{
//	Address* head = NULL;
//	Address* last = NULL;
//	setlocale(LC_CTYPE, "Rus");
//	int choice;
//	char s[80]; int c;
//	cout << endl;
//	cout << "1. Ввод элемента" << endl;
//	cout << "2. Старший студент" << endl;
//	cout << "3. Младший студент" << endl;
//	cout << "4. Лучший ученик" << endl;
//	cout << "5. вывод списка" << endl;
//	cout << "6. 1 курс" << endl;
//	cout << "7. 2 курс" << endl;
//	cout << "8. 3 курс" << endl;
//	cout << "9. 4 курс" << endl;
//	cout << "10. Выход" << endl;
//	cout << endl;
//	for (;;)
//	{
//		cout << "Ваш выбор: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1: insert(setElement(), &head, &last);
//			break;
//		case 2: studentOld(&head, &last);
//			break;
//		case 3: studentYoung(&head, &last);
//			break;
//		case 4: average(&head, &last);
//			break;
//		case 5: outputList(&head, &last);
//			break;
//		case 6: outputFirstCourse(&head, &last);
//			break;
//		case 7:
//			outputSecondCourse(&head, &last);
//			break;
//		case 8:
//			outputThirdCourse(&head, &last);
//			break;
//		case 9:
//			outputFourthCourse(&head, &last);
//			break;
//		case 10: exit(0);
//		default: exit(1);
//		}
//	}
//	return 0;
//}


#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

void addClient();
void showClients();
void deleteClient();
void searchingClient();
void writeToFile();
void readFromFile();

int main()
{

	int choice;

	do {
		cout << "Menu: " << endl;
		cout << "1. Enter client data: " << endl;
		cout << "2. Client data output: " << endl;
		cout << "3. Removing a client: " << endl;
		cout << "4. Searching the client: " << endl;
		cout << "5. Enter information into file: " << endl;
		cout << "6. Read information from file: " << endl;
		cout << "7. Exit the program: " << endl;
		cin >> choice;

		switch (choice) {
		case 1: addClient();
			break;
		case 2: showClients();
			break;
		case 3: deleteClient();
			break;
		case 4: searchingClient();
			break;
		case 5: writeToFile();
			break;
		case 6: readFromFile();
			break;
		case 7:
			cout << "Exit the program: " << endl;
			break;
		default:
			cout << "erRor" << endl;
			break;
		}

	} while (choice != 7);

	return 0;
}

//структура//
struct Client {

	string clientsPersonalData;
	string nameOfProduct;
	string assessedValue;
	string bailAmount;
	string dueDate;
	string shelfLife;
};

const int maxClients = 100;
Client clients[maxClients];
int clientCount = 1;

//функция для добавления клиента//
void addClient() {

	if (clientCount > maxClients) {
		cout << "Limit of clients." << endl;
		exit(7);
	}

	Client newClient;

	for (int i = 0; i < clientCount; i++)
	{
		newClient.clientsPersonalData = "Enter the clients personal information: ";
		cout << newClient.clientsPersonalData << endl;
		cin >> clients[i].clientsPersonalData;

		newClient.nameOfProduct = "Enter product name: ";
		cout << newClient.nameOfProduct << endl;
		cin >> clients[i].nameOfProduct;

		newClient.assessedValue = "Enter estimated value: ";
		cout << newClient.assessedValue << endl;
		cin >> clients[i].assessedValue;

		newClient.bailAmount = "Enter the bail amount: ";
		cout << newClient.bailAmount << endl;
		cin >> clients[i].bailAmount;

		newClient.dueDate = "Enter due date: ";
		cout << newClient.dueDate << endl;
		cin >> clients[i].dueDate;

		newClient.shelfLife = "Enter storage period: ";
		cout << newClient.shelfLife << endl;
		cin >> clients[i].shelfLife;

		//clients[clientCount] = newClient;
		//clientCount++;
	}

	cout << "Client added successfully." << endl;
}

//фукция для просмотра клиентов//
void showClients() {

	/*if (clientCount == 0) {
		cout << "No clients." << endl;
		exit(7);
	}*/
	int clientCounter = 1;


	for (int i = 0; i < clientCount; i++) {
		cout << "Client №" << clientCount << ": " << endl;
		cout << "Personal information of client: ";
		cout << clients[i].clientsPersonalData << endl;
		cout << "Product name: ";
		cout << clients[i].nameOfProduct << endl;
		cout << "Estimated value: ";
		cout << clients[i].assessedValue << endl;
		cout << "Bail amount: ";
		cout << clients[i].bailAmount << endl;
		cout << "Due date: ";
		cout << clients[i].dueDate << endl;
		cout << "Storage period: ";
		cout << clients[i].shelfLife << endl;
	}
}

//функция для удаления клиента//
void deleteClient() {

	/*if (clientCount == 0) {
		cout << "No clients" << endl;
		exit(7);
	}*/

	int del;
	cout << endl << "Enter number of client: ";
	cin >> del;

	for (int i = del - 1; i < clientCount - 1; i++)
	{
		clients[i] = clients[i + 1];
	}

	cout << endl << "Delete run success!" << endl;
	clientCount -= 1;
}

//функция для поиска клиента по его персональным данным//
void searchingClient() {

	if (clientCount == 0) {
		cout << "No clients" << endl;
		exit(7);
	}

	string clientsPersonalData;
	cout << "Enter the clients personal information: " << endl;
	cin >> clientsPersonalData;

	bool found = false;
	cout << "Results of the searching for '" << clientsPersonalData << "':" << endl;

	for (int i = 0; i < clientCount; i++) {

		if (clients[i].clientsPersonalData == clientsPersonalData) {

			found = true;
			cout << "Personal information of client: " << clients[i].clientsPersonalData << endl;
			cout << "Estimated value: " << clients[i].assessedValue << endl;
			cout << "Bail amount: " << clients[i].bailAmount << endl;
			cout << "Due date: " << clients[i].dueDate << endl;
			cout << "Storage period: " << clients[i].shelfLife << endl;
			cout << "__________________" << endl;
		}
	}
	if (!found) {
		cout << "Searching for '" << clientsPersonalData << "' failed." << endl;
	}
}

//функция для записи в файл данных о клиенте//
void writeToFile()
{
	ofstream file("file.txt");

	if (file.is_open()) {

		for (int i = 0; i < clientCount; i++) {

			file << clients[i].clientsPersonalData << "\n";
			file << clients[i].nameOfProduct << "\n";
			file << clients[i].assessedValue << "\n";
			file << clients[i].bailAmount << "\n";
			file << clients[i].dueDate << "\n";
			file << clients[i].shelfLife << "\n";
		}

		cout << "Data upload success!" << endl;
		file.close();
	}
	else {
		cout << "Error of opening file." << endl;
	}
}

//функция для чтения данных о клиенте из файла//
void readFromFile() {
	ifstream file("file.txt");
	if (file.is_open()) {
		clientCount = 0;
		while (!file.eof()) {
			Client newItem;

			file >> newItem.clientsPersonalData;
			file >> newItem.nameOfProduct;
			file >> newItem.assessedValue;
			file >> newItem.bailAmount;
			file >> newItem.dueDate;
			file >> newItem.shelfLife;
			if (!file.fail()) {
				clients[clientCount] = newItem;
				clientCount++;
			}
		}
		cout << "Data download success!" << endl;
		file.close();
	}
	else {
		cout << "Error of opening file." << endl;
	}
}
