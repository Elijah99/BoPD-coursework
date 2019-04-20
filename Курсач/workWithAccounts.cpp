#include "Header.h"

void showAccounts(vector<Account> &arr_of_accounts)
{
	cout << "Таблица учётных записей пользователей " << endl
		<< setw(8) << left << "Номер" << setw(15) << "Логин" << setw(15) << "Пароль" << setw(15) << "Приоритет" << endl;
	for (unsigned int i = 0; i < arr_of_accounts.size(); i++)
		cout << setw(8) << left << i + 1 <<
		setw(15) << left << arr_of_accounts[i].login <<
		setw(15) << left << arr_of_accounts[i].pass <<
		setw(15) << left << arr_of_accounts[i].role << endl;
}
void addAccount(vector<Account> &arr_of_accounts)
{

	Account buffer[1];
	cout << "Чтобы добавить аккаунт введите" << endl;
	cout << "логин :";
	while (isLoginUnique(buffer[0].login)) break;
		cout << "  " << "пароль : ";
	buffer[0].pass = inputPassword();
	cout << "  " << "приоритет : ";
	buffer[0].role = inputIntRange(0, 1);
	arr_of_accounts.insert(arr_of_accounts.end(), buffer[0]);

}
void delAccount(vector<Account> &arr_of_accounts)
{
	cout << "Введите номер удаляемой записи ";
	int del_item = inputIntRange(1, arr_of_accounts.size());
	if (arr_of_accounts[del_item - 1].login == "admin") {
		cout << "Вы не можете удалить учетную запись админа\n" << "Чтобы продолжить нажмите любую клавишу"; system("pause");
		manageAccounts();
	}
	arr_of_accounts.erase(arr_of_accounts.begin() + del_item - 1);
	system("cls");
	cout << "запись удалена !" << endl;
	cout << endl;

}
void updateAccount(vector<Account> &arr_of_accounts)
{
	cout << "Введите номер редактируемой записи ";
	int upd_item;
	upd_item = inputIntRange(1, arr_of_accounts.size());
	if (arr_of_accounts[upd_item - 1].login == "admin") {
		cout << "Вы не можете изменить учетную запись админа\n" << "Чтобы продолжить нажмите любую клавишу"; system("pause");
		manageAccounts();
	}
	arr_of_accounts[upd_item - 1].login = "0";
	cout << "отредактируйте данные учётной записи: " << endl;
	cout << "логин:  !";
	while (isLoginUnique(arr_of_accounts[upd_item - 1].login))break;
	cout << "Пароль:  !";
	arr_of_accounts[upd_item - 1].pass = inputPassword();
	cout << "роль:  !";
	arr_of_accounts[upd_item - 1].role = inputIntRange(0, 1);
	system("cls");
	cout << "запись отредактирована !" << endl;
	cout << endl;

}