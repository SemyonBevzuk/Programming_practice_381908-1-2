#pragma once
#include"Dictionary.h"
class MainMenu {
public:
    MainMenu();
    void Start();
private:

    void MenuHandler();
    int Menu();

    void printHead();
    void PrintMainMenu();
    void IncorrectAnswer();
    void Waiting();

    void AddWord();
    void FindWord();
    void TranslateForWord();
    void AddTranslateToWord();
    void DeleteWord();
    void LoadFromFile();
    void SaveToFile();

    Dictionary myDict;
};

//�������� � ������� ����� � ��� �������
//�������� ������� ���������� �����,
//������ ������� ���������� �����,
//��������� ������� ����� � �������,
//������ ����� ���� � �������,
//��������� ������� � ����, ������� ������� �� �����.
//����������� �������� ������������ � ����������� ��������.