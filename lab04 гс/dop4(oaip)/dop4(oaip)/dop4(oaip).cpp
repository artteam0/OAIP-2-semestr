//#include <iostream>
//#include <string>
//#include <Windows.h>
//#include <fstream>
//#include <vector>
//#define SIZE 10
//#define OPTIONS 3
//using namespace std;
//
//
//
////создаем структуру//
//struct Exam {
//	string name;
//	string surname;
//	string patronymic;
//	int amountOfExem = 10;
//	vector<int> marks;
//
//	//создаем конструктор для нашей структуры 
//	Exam(string name, string surname, string patronomyc, int amountOfExem, vector<int> marks)
//	{
//		this->name = name;
//		this->surname = surname;
//		this->patronymic = patronomyc;
//		this->amountOfExem = amountOfExem;
//		this->marks = marks;
//	}
//};
//
//
////функция записи данных в структуру
//void add(vector<Exam>& info)
//{
//	//создаем необходимые переменные
//	string surname, name, patronomyc;
//	unsigned int amountOfExem;
//	vector<int> marks;
//	int temp;
//
//	cout << "Enter full name: "; cin >> surname >> name >> patronomyc;
//	cout << "Enter number of exams: "; cin >> amountOfExem;
//	cout << "Enter rating: ";
//	for (int i = 0; i < amountOfExem; i++)
//	{
//		cin >> temp;
//		marks.push_back(temp);
//	}
//
//	//записываем данные в структуру student
//	Exam student(name, surname, patronomyc, amountOfExem, marks);
//	info.push_back(student);
//}
//
////фунция вывода данных
//void outInfo(vector<Exam>& info)
//{
//	for (int i = 0; i < info.size(); i++)
//	{
//		cout << "Full name " << info[i].surname << " " << info[i].name << " " << info[i].patronymic << endl;
//		cout << "Number of exams: " << info[i].amountOfExem << endl << "Rating: ";
//		for (int j = 0; j < info[i].amountOfExem; j++)
//		{
//			cout << info[i].marks[j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//
////поиск элемента вектора по ФИО в структуре
//int findInfo(vector<Exam>& info, char surname[], char name[], char patronymic[])
//{
//	for (int i = 0; i < info.size(); i++)
//	{
//		if (info[i].name == name && info[i].surname == surname && info[i].patronymic == patronymic)
//		{
//			return i;
//		}
//	}
//}
//
////функция для анализа данных
//void dataFindProcessing(vector<Exam>& info, int number)
//{
//	bool retake = false;
//	int count = 0;
//
//	for (int i = 0; i < info[number].amountOfExem; i++)
//	{
//		//при оценке ниже 4, ведем подсчет несданных экзаменов
//		if (info[number].marks[i] < 4)
//		{
//			count++;
//			retake = true;
//		}
//	}
//
//
//	if (retake)
//	{
//		cout << "Exams written below 4: " << count << endl;
//	}
//	else
//	{
//		cout << "All exams are written above 4!" << endl;
//	}
//}
//
////функция анализа всех учеников на сдачу экзамена
//void dataProcessing(vector<Exam>& info)
//{
//	int count = 0;
//	bool retake = false;
//
//	for (int i = 0; i < info.size(); i++)
//	{
//		retake = false;
//
//		//перебираем оценки каждого студента и сравниваем
//		for (int j = 0; j < info[i].amountOfExem; j++)
//		{
//			if (info[i].marks[j] < 4)
//			{
//				retake = true;
//			}
//		}
//
//		if (!retake)
//		{
//			count++;
//		}
//	}
//	cout << (count / (double)info.size()) * 100 << "% of students passed the exams." << endl;
//}
//
//void menu()
//{
//	vector<Exam> students;
//	int answer = 0;
//
//	cout << "1 - Add. 2 - Conclusion. 3 - Find and check. 4 - All rating. 5 - Exit. " << endl;
//
//	while (answer != 5)
//	{
//		cout << "enter(choose): ";
//		cin >> answer;
//		switch (answer)
//		{
//		case 1:
//			add(students);
//			break;
//		case 2:
//			outInfo(students);
//			break;
//		case 3:
//			char name[33], surname[33], patronymic[33];
//			cout << "Enter the student's full name for verification: "; cin >> surname >> name >> patronymic;
//			dataFindProcessing(students, findInfo(students, surname, name, patronymic));
//			break;
//		case 4:
//			dataProcessing(students);
//			break;
//		}
//	}
//
//}
//
//int main()
//{
//	SetConsoleOutputCP(1251);
//	SetConsoleCP(1251);
//
//	menu();
//
//	return 0;
//}

//#include <iostream>
//#include <Windows.h>
//#include <fstream>
//#include <string>
//#include <vector>
//
//#define SIZE 3
//using namespace std;
//
//
////создаем структру
//struct Train
//{
//	string name;
//	int number;
//	int hours;
//	int minutes;
//
//	//создаем конструктор для структуры
//	Train(string name, int number, int hours, int minutes)
//	{
//		this->name = name;
//		this->number = number;
//		this->hours = hours;
//		this->minutes = minutes;
//	}
//
//	void swap(Train& second)
//	{
//
//		int itemp;
//		string stemp;
//
//		stemp = name;
//		name = second.name;
//		second.name = stemp;
//
//		itemp = number;
//		number = second.number;
//		second.number = itemp;
//
//		itemp = hours;
//		hours = second.hours;
//		second.hours = itemp;
//
//		itemp = minutes;
//		minutes = second.minutes;
//		second.minutes = itemp;
//
//
//	}
//
//	void print()
//	{
//		//вывод данных о станции
//		cout << "Name of station : " << name << endl;
//		cout << "Train number : " << number << endl;
//		cout << "Train departure time: ";
//
//		if (hours < 10)
//		{
//			cout << "0";
//		}
//		cout << hours << ":";
//		if (minutes < 10)
//		{
//			cout << "0";
//		}
//		cout << minutes << endl << endl;
//	}
//};
//
//
////функция для вывода информации из структуры
//void outInfo(vector<Train>& a)
//{
//
//	for (int i = 0; i < a.size(); i++)
//	{
//		cout << "Station name: " << a[i].name << endl;
//		cout << "Train number: " << a[i].number << endl;
//		cout << "Train departure time: ";
//
//		if (a[i].hours < 10)
//		{
//			cout << "0";
//		}
//		cout << a[i].hours << ":";
//		if (a[i].minutes < 10)
//		{
//			cout << "0";
//		}
//		cout << a[i].minutes << endl << endl;
//	}
//}
//
////функция добавления информации в структуру
//void add(vector<Train>& a)
//{
//	bool out = false;
//	string name;
//	int number, hours, minutes;
//
//	for (int i = 0; out != true; i++)
//	{
//		cout << "Enter station name: "; cin >> name;
//		cout << "Enter train number: "; cin >> number;
//		cout << "Enter train departure time: "; cin >> hours >> minutes;
//		cout << endl;
//
//		if (hours > 24 || hours < 0)
//		{
//			cout << "Not matching time data, please re-enter." << endl;
//			i--;
//			continue;
//		}
//
//		if ((minutes < 0 || minutes > 60))
//		{
//			cout << "Not matching time data, please re-enter." << endl;
//			i--;
//			continue;
//		}
//
//		out = true;
//	}
//
//	//записываем данные в структуру train
//	Train train(name, number, hours, minutes);
//	//добавляем данные в конец векторного массива структур
//	a.push_back(train);
//}
//
////функция сортировки
//void sortLetter(vector<Train>& a)
//{
//	int count = 0;
//	int itemp;
//	string stemp;
//
//	for (int i = 0; i < a.size() - 1; i++)
//	{
//		if (a[i].name[0] > a[i + 1].name[0])
//		{
//			a[i].swap(a[i + 1]);
//		}
//	}
//
//	for (int i = 0; i < a.size() - 1; i++)
//	{
//		if (a[i].name[0] > a[i + 1].name[0])
//		{
//			count++;
//		}
//	}
//
//	if (count != 0)
//	{
//		return sortLetter(a);
//	}
//}
//
////поиск поездов, которые вызываются позже заданного времени
//void outTimeInfo(vector<Train>& a, int& hours, int& minutes)
//{
//	int count = 0;
//
//	cout << "Trains that depart after the entered time: " << endl << endl;
//	for (int i = 0; i < a.size(); i++)
//	{
//		//при условии, если время из структуры больше заданного, то вызываем метод print
//		if ((a[i].hours > hours))
//		{
//			a[i].print();
//			count++;
//		}
//
//		if ((a[i].hours == hours) && (a[i].minutes > minutes))
//		{
//			count++;
//			a[i].print();
//		}
//	}
//	if (count == 0)
//	{
//		cout << endl << "No trains found." << endl;
//	}
//
//}
//
//void menu()
//{
//	vector<Train> info;
//	int answer = 0;
//	int hours = 0, minutes = 0;
//
//	cout << "1 - Add. 2 - Conclusion. 3 - Sort. 4 - Trains after time. 5 - Exit. " << endl;
//
//	while (answer != 5)
//	{
//		cout << "enter(choose): "; cin >> answer;
//
//		switch (answer)
//		{
//		case 1:
//			add(info);
//			break;
//		case 2:
//			outInfo(info);
//			break;
//		case 3:
//			sortLetter(info);
//			break;
//		case 4:
//			cout << "Enter time: "; cin >> hours >> minutes;
//			outTimeInfo(info, hours, minutes);
//			break;
//		}
//	}
//}
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	menu();
//
//	return 0;
//}


#include <iostream>
#include<string>
#include <cstdlib>
using namespace std;

//задание структуры//
struct Sanatorium
{
	string name, location, therapy;
	int amount;
};

void main()
{
	Sanatorium a[100];
	int n;
	cout << "Number of sanatorium: ";
	cin >> n;
	//Ввод информации//
	for (int i = 0; i < n; i++)
	{
		cout << "Information about the sanatorium: " << i + 1 << endl;
		cout << "Name: ";
		getline(cin, a[i].name);
		getline(cin, a[i].name);
		cout << "Location: ";
		getline(cin, a[i].location);

		cout << "Therapy profile: ";
		getline(cin, a[i].therapy);
		cout << "Tickets amount: ";
		cin >> a[i].amount;
		cout << endl << endl;
	}

	int choice;
	cout << "Choose " << endl << "1.Show info " << endl << "2.Search " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		string gg;
		int g;
		for (int i = 0; i < n; i++)
		{
			//сортировка по имени//
			for (int j = 0; j < n; j++)
			{
				if (a[i].name < a[j].name)
				{
					gg = a[i].name;
					a[i].name = a[j].name;
					a[j].name = gg;

					gg = a[i].therapy;
					a[i].therapy = a[j].therapy;
					a[j].therapy = gg;

					gg = a[i].location;
					a[i].location = a[j].location;
					a[j].location = gg;

					g = a[i].amount;
					a[i].amount = a[j].amount;
					a[j].amount = g;
				}
			}
		}
		//Вывод информации//
		for (int i = 0; i < n; i++)
		{
			for (int i = 0; i < n; i++)
			{
				cout << endl << "Information about the sanatorium: " << i + 1 << endl;
				cout << "Name: ";
				cout << a[i].name << endl;
				cout << "Location: ";
				cout << a[i].location << endl;
				cout << "Therapy profile: ";
				cout << a[i].therapy << endl;
				cout << "Tickets amount: ";
				cout << a[i].amount << endl;
				cout << endl << endl;
			}
		}
		break;
	}
	case 2:
	{
		string profile;
		cout << endl << "Therapy profile: ";
		//Ввод интересующего профиля//
		getline(cin, profile);
		getline(cin, profile);
		for (int i = 0; i < n; i++)
		{
			if (a[i].therapy == profile)
			{
				cout << "Information about the sanatorium: " << i + 1 << endl;
				cout << "Name: ";
				cout << a[i].name << endl;
				cout << "Location: ";
				cout << a[i].location << endl;
				cout << "Therapy profile: ";
				cout << a[i].therapy << endl;
				cout << "Tickets amount: ";
				cout << a[i].amount << endl;
				cout << endl << endl;
			}
		}
		break;
	}
	}
}
