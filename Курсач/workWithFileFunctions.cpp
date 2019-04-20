#include "Header.h"
#include "globals.h"
void readFileAccounts(vector<Account> &arr_of_accounts)
{

	ifstream fin(FILE_OF_ACCOUNTS, ios::in);
	Account buffer;
	if (fin.is_open()) {
		while (fin >> buffer.login
			>> buffer.pass
			>> buffer.role)
		{
			arr_of_accounts.push_back(buffer);
		}
	}
	fin.close();
}
void writeFileAccounts(vector<Account> &arr_of_accounts)
{
	ofstream fout(FILE_OF_ACCOUNTS, ios::out);
	for (unsigned int i = 0; i < arr_of_accounts.size(); i++)
	{
		fout << arr_of_accounts[i].login << " "
			<< arr_of_accounts[i].pass << " "
			<< arr_of_accounts[i].role << endl;
	}
	fout.close();
}
void createDataFile()
{
	ofstream tickets(FILE_OF_TICKETS, ios::out);
	tickets.close();
}
void readFileTickets(vector<Avia> &arr_of_planes)
{

	ifstream fin(FILE_OF_TICKETS, ios::in);
	Avia buffer;
	if (fin.is_open()) {
		while (fin >> buffer.numberPlane
			>> buffer.Type
			>> buffer.destination
			>> buffer.dateFlight[0]
			>> buffer.dateFlight[1]
			>> buffer.dateFlight[2]
			>> buffer.timeFlight
			>> buffer.timeArrival
			>> buffer.CapacityPlane
			>> buffer.leftTicketsBusiness
			>> buffer.priceTicketsBusiness
			>> buffer.leftTicketsEconom
			>> buffer.priceTicketsEconom)

		{
			arr_of_planes.push_back(buffer);
		}
		fin.close();
	}
	else {
		cout << "Файл пуст" << endl;

	}
}
void writeFileTickets(vector<Avia> arr_of_planes)
{
	ofstream fout(FILE_OF_TICKETS, ios::out);
	for (unsigned int i = 0; i < arr_of_planes.size(); i++)
	{
		fout << arr_of_planes[i].numberPlane << " "
			<< arr_of_planes[i].Type << " "
			<< arr_of_planes[i].destination << " "
			<< arr_of_planes[i].dateFlight[0] << " "
			<< arr_of_planes[i].dateFlight[1] << " "
			<< arr_of_planes[i].dateFlight[2] << " "
			<< arr_of_planes[i].timeFlight << " "
			<< arr_of_planes[i].timeArrival << " "
			<< arr_of_planes[i].CapacityPlane << " "
			<< arr_of_planes[i].leftTicketsBusiness << " "
			<< arr_of_planes[i].priceTicketsBusiness << " "
			<< arr_of_planes[i].leftTicketsEconom << " "
			<< arr_of_planes[i].priceTicketsEconom << " ";


	}
	fout.close();
}
bool isLoginUnique(string &login) {
	while (true) {
		login = inputString();
		Account account;
		ifstream file(FILE_OF_ACCOUNTS, ios::in);
		bool flag = true;
		while (file >> account.login >> account.pass >> account.role) {
			if (account.login == login) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			cout << "Этот логин уже занят, попробуйте ещё:" << endl;
		}
		else {
			return flag;
		}
	}
}
void checkFiles()
{
	ifstream fin(FILE_OF_ACCOUNTS, ios::in);
	if (!fin.is_open()) {
		vector<Account> arr_of_accounts;
		arr_of_accounts[0].login = "admin";
		arr_of_accounts[0].pass = "admin";
		arr_of_accounts[0].role = 1;
		writeFileAccounts(arr_of_accounts);
	}fin.close();
	ifstream fin1(FILE_OF_TICKETS, ios::in);
	if (!fin1.is_open()) {
		createDataFile();
	}
	fin1.close();
}
bool checkInAccount(vector<Account> arr_of_accounts, Account check_acc, int &role)
{
	for (unsigned int i = 0; i < arr_of_accounts.size(); i++)
	{
		if (arr_of_accounts[i].login == check_acc.login && arr_of_accounts[i].pass == check_acc.pass)
		{
			role = arr_of_accounts[i].role;
			return true;
		}
	}
	return false;
}