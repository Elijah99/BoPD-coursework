#include "Header.h"
int adminModeMenu()
{
	cout << setw(40) << "���� ��������������" << endl
		<< "��� �� ������ �������?\n" << "1. ���������� �������� �������� �������������\n" << "2. ������ �� ������� ������\n"
		<< "3. �������������\n" << "0. �����\n";
	int choise = inputIntRange(0, 3);
	return choise;
}
int userModeMenu()
{
	cout << setw(40) << "���� ������������" << endl
		<< "��� �� ������ �������?\n" << "1. ������� �������\n" << "2. �������� ������ ������\n"
		<< "3. ����� �����\n" << "4. ���������� ������ ������\n" << "5. �������������\n" << "0. �����\n";
	int choise = inputIntRange(0, 5);
	return choise;
}
int manageAccountsMenu()
{
	cout << "��������:\n" << "1. �������� ���� ������� �������\n" << "2. ���������� ����� ������� ������\n" << "3. �������������� ������� ������\n"
		<< "4. �������� ������� ������\n" << "5. �����\n" << "0. �����\n";
	int choise = inputIntRange(0, 5);
	return choise;
}
int workDataMenu()
{
	cout << setw(40) << "���� ������ � ������� � �������\n"
		<< "��������:\n" << "1. ����� �������������� ������\n" << "2. ����� ��������� ������\n"
		<< "3. ��������� �����\n" << "0. �����\n";
	int choise = inputIntRange(0, 3);
	return choise;
}
int editModeMenu()
{
	cout << setw(40) << "���� �������������� ������\n"
		<< "��������:\n" << "1. �������� ������ �������\n" << "2. ���������� ��������\n" << "3. �������� ��������\n"
		<< "4. �������������� ������\n" << "5. ��������� �����\n" << "0. �����\n";
	int choise = inputIntRange(0, 5);
	return choise;
}
int choosePlaneMenu()
{
	cout << "�������� ������ �������:\n"
		<< "1. ����� �� ������ �����\n"
		<< "2. ����� �� ����� ����������\n"
		<< "3. ����� �� ���� ������\n";
	int choise = inputIntRange(1, 3);
	return choise;
}
int searchPlaneMenu()
{
	int choise;
	cout << "�������� ������� ������:\n"
		<< "1. �� ������ �����\n"
		<< "2. �� ������ ����������\n"
		<< "3. �� ���� ������\n"
		<< "4. �����\n";
	choise = inputIntRange(1, 4);
	return choise;
}
int sortingModeMenu() {
	system("cls");
	cout << endl;
	cout << "�������� ������� ����������" << endl;
	cout << "1 - �� ������ �����" << endl;
	cout << "2 - �� ������ ����������" << endl;
	cout << "3 - �� ���� ������" << endl;
	cout << "4 - �����" << endl;
	int choise;
	cout << endl;
	choise = inputIntRange(1, 4);
	return choise;
}
int processingModeMenu()
{
	cout << setw(40) << "���� ��������� ������\n"
		<< "��������:\n" << "1. ������ �����\n" << "2. ����� ������� �� �������\n" << "3. �������� ������ ���������\n"
		<< "4. ���������� ������ ���������\n" << "5. �����\n" << "0. �����\n";
	int choise = inputIntRange(0, 5);
	return choise;
}