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
