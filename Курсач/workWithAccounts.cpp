#include "Header.h"

void showAccounts(vector<Account> &arr_of_accounts)
{
	cout << "������� ������� ������� ������������� " << endl
		<< setw(8) << left << "�����" << setw(15) << "�����" << setw(15) << "������" << setw(15) << "���������" << endl;
	for (unsigned int i = 0; i < arr_of_accounts.size(); i++)
		cout << setw(8) << left << i + 1 <<
		setw(15) << left << arr_of_accounts[i].login <<
		setw(15) << left << arr_of_accounts[i].pass <<
		setw(15) << left << arr_of_accounts[i].role << endl;
}
void addAccount(vector<Account> &arr_of_accounts)
{

	Account buffer[1];
	cout << "����� �������� ������� �������" << endl;
	cout << "����� :";
	while (isLoginUnique(buffer[0].login)) break;
		cout << "  " << "������ : ";
	buffer[0].pass = inputPassword();
	cout << "  " << "��������� : ";
	buffer[0].role = inputIntRange(0, 1);
	arr_of_accounts.insert(arr_of_accounts.end(), buffer[0]);

}
void delAccount(vector<Account> &arr_of_accounts)
{
	cout << "������� ����� ��������� ������ ";
	int del_item = inputIntRange(1, arr_of_accounts.size());
	if (arr_of_accounts[del_item - 1].login == "admin") {
		cout << "�� �� ������ ������� ������� ������ ������\n" << "����� ���������� ������� ����� �������"; system("pause");
		manageAccounts();
	}
	arr_of_accounts.erase(arr_of_accounts.begin() + del_item - 1);
	system("cls");
	cout << "������ ������� !" << endl;
	cout << endl;

}
void updateAccount(vector<Account> &arr_of_accounts)
{
	cout << "������� ����� ������������� ������ ";
	int upd_item;
	upd_item = inputIntRange(1, arr_of_accounts.size());
	if (arr_of_accounts[upd_item - 1].login == "admin") {
		cout << "�� �� ������ �������� ������� ������ ������\n" << "����� ���������� ������� ����� �������"; system("pause");
		manageAccounts();
	}
	arr_of_accounts[upd_item - 1].login = "0";
	cout << "�������������� ������ ������� ������: " << endl;
	cout << "�����:  !";
	while (isLoginUnique(arr_of_accounts[upd_item - 1].login))break;
	cout << "������:  !";
	arr_of_accounts[upd_item - 1].pass = inputPassword();
	cout << "����:  !";
	arr_of_accounts[upd_item - 1].role = inputIntRange(0, 1);
	system("cls");
	cout << "������ ��������������� !" << endl;
	cout << endl;

}