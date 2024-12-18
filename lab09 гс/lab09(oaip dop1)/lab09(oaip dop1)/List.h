#pragma once
#include<iostream>
#include<cstring>

// ��������� ��� �������� ���������� � �����������
structCountry{
char Name[50];
char Capital[50];
int Population;
doubleArea;
charPresidentLastName[50];
};

// ��������� �������� ������ ����������
structElement{
Element * Prev;
Element* Next;
Country Data;

// �������������������������
    Element(Element* prev, constchar* name, constchar* capital, intpopulation, doublearea, constchar* presidentLastName, Element* next);

    // ������ ��������� ���������� �� ���������� � ��������� ��������
    Element* GetNext();
    Element* GetPrev();
};

// ��������� ���������� ������� ����������
structObject{
Element * Head;

// ����������� ������� ���������� �������
    Object();

    // ���������� ������� ���������� �������
        ~Object();

        // ������ ��������� ���������� �� ������ � ��������� �������� ������
        Element* GetFirst();
        Element* GetLast();

        // ������ ��� ������ � ���������� ������
        bool Insert(constchar* name, constchar* capital, intpopulation, doublearea, constchar* presidentLastName);
        bool Delete(Element* e);
        Element* Search(constchar* name);
        bool Delete(constchar* name);
        bool DeleteList();

        // ����� ��� ������ ������ ����������
        void PrintList();
};

// ������� �������� ������� ���������� ������� ����������
Object Create();
