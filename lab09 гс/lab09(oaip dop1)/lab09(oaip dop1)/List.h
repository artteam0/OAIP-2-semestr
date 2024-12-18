#pragma once
#include<iostream>
#include<cstring>

// Структура для хранения информации о государстве
structCountry{
char Name[50];
char Capital[50];
int Population;
doubleArea;
charPresidentLastName[50];
};

// Структура элемента списка государств
structElement{
Element * Prev;
Element* Next;
Country Data;

// Конструкторэлементасписка
    Element(Element* prev, constchar* name, constchar* capital, intpopulation, doublearea, constchar* presidentLastName, Element* next);

    // Методы получения указателей на предыдущий и следующий элементы
    Element* GetNext();
    Element* GetPrev();
};

// Структура управления списком государств
structObject{
Element * Head;

// Конструктор объекта управления списком
    Object();

    // Деструктор объекта управления списком
        ~Object();

        // Методы получения указателей на первый и последний элементы списка
        Element* GetFirst();
        Element* GetLast();

        // Методы для работы с элементами списка
        bool Insert(constchar* name, constchar* capital, intpopulation, doublearea, constchar* presidentLastName);
        bool Delete(Element* e);
        Element* Search(constchar* name);
        bool Delete(constchar* name);
        bool DeleteList();

        // Метод для вывода списка государств
        void PrintList();
};

// Функция создания объекта управления списком государств
Object Create();
