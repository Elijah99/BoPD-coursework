#include "Header.h"
void authorization()
{
	system("cls");
	cout << setw(40) << "Добро пожаловать!" << endl;
	cout << setw(36) << "Авторизация" << endl;
	Account Check;
	int role;
	checkFiles();
	vector<Account> AllAccounts;
	readFileAccounts(AllAccounts);
	Check = inputAccount();
	if (checkInAccount(AllAccounts, Check, role) == 1)
	{
		if (role == 1) adminMode(); else userMode();
	}
	else
	{
		cout << " Провал " << endl
			<< " Попробуйте ещё" << endl;
		authorization();
	}
}
void adminMode()
{
	system("cls");
	switch (adminModeMenu()) {
	case 0:exit(1); break;
	case 1: manageAccounts(); break;
	case 2: workData(); break;
	case 3: authorization(); break;
	}
}
void userMode()
{
	system("cls");
	vector<Avia> allTickets;
	readFileTickets(allTickets);
	while (true) {
		switch (userModeMenu()) {
		case 0:
			writeFileTickets(allTickets);
			exit(0);
			break;
		case 1: buyTickets(allTickets); break;
		case 2: showTickets(allTickets); break;
		case 3: searchPlane(allTickets); break;
		case 4: sortingMode("User", allTickets); break;
		case 5: authorization(); break;
		}
	}
}
void manageAccounts()
{
	checkFiles();
	vector<Account> arr_of_accounts;
	readFileAccounts(arr_of_accounts);
	system("cls");
	while (true)
	{
		switch (manageAccountsMenu())
		{
		case 0: writeFileAccounts(arr_of_accounts); exit(1); break;
		case 1: showAccounts(arr_of_accounts); break;
		case 2: addAccount(arr_of_accounts);  writeFileAccounts(arr_of_accounts); break;
		case 3: updateAccount(arr_of_accounts);  writeFileAccounts(arr_of_accounts); break;
		case 4: delAccount(arr_of_accounts); writeFileAccounts(arr_of_accounts); break;
		case 5: {system("cls"); adminMode(); writeFileAccounts(arr_of_accounts); }break;
		}
	}
	writeFileAccounts(arr_of_accounts);
}
void workData()
{
	system("cls");
	vector<Avia> allTickets;
	readFileTickets(allTickets);
	switch (workDataMenu()) {
	case 0: exit(1); break;
	case 1: editMode(allTickets); break;
	case 2: processingMode(allTickets); break;
	case 3: adminMode(); break;
	}
}
void editMode(vector<Avia> &arr_of_planes)
{
	system("cls");
	while (true) {
		switch (editModeMenu())
		{
		case 0: exit(1); break;
		case 1: system("cls"); cout << setw(40) << "Список билетов " << endl; showTickets(arr_of_planes);  break;
		case 2: addOnePlane(arr_of_planes); writeFileTickets(arr_of_planes);  break;
		case 3: delOnePlane(arr_of_planes); writeFileTickets(arr_of_planes); break;
		case 4: updatePlanesList(arr_of_planes); writeFileTickets(arr_of_planes); break;
		case 5: system("cls"); writeFileTickets(arr_of_planes); workData(); break;

		}
	}
	writeFileTickets(arr_of_planes);
}
void processingMode(vector<Avia> &arr_of_planes)
{
	system("cls");
	while (true) {
		switch (processingModeMenu())
		{
		case 0:
			writeFileTickets(arr_of_planes);
			exit(0);  break;
		case 1: buyTickets(arr_of_planes); writeFileTickets(arr_of_planes); break;
		case 2: searchPlane(arr_of_planes); break;
		case 3: showTickets(arr_of_planes); break;
		case 4: sortingMode("Processing", arr_of_planes); break;
		case 5: system("cls"); workData(); break;
		}
	}
}
void sortingMode(const string a, vector<Avia> &arr_of_planes) {
	while (true) {
		switch (sortingModeMenu())
		{
		case 1:
			sortSpisPlanes("Number", arr_of_planes);
			break;
		case 2:
			sortSpisPlanes("Destination", arr_of_planes);
			break;
		case 3:
			sortSpisPlanes("Data", arr_of_planes);
			break;
		case 4:
			if (a == "User") userMode();
			else processingMode(arr_of_planes);
			break;
		default:
			cout << "Choose 1-4" << endl;
			break;
		}
	}
}
int choosePlane(vector<Avia> &arr_of_planes)
{
	int number_of_plane;
	cout << setw(40) << "Список билетов " << endl;
	showTickets(arr_of_planes);
	switch (choosePlaneMenu())
	{
	case 1:
	{
		number_of_plane = searchByNumberPlane(arr_of_planes);
		while (number_of_plane == NULL) {
			cout << "Такого рейса не существует, пожалуйста повторите ввод\n";
			number_of_plane = searchByNumberPlane(arr_of_planes);
		}
	} break;
	case 2:
	{
		number_of_plane = searchByDestination(arr_of_planes, "Buy");
		while (number_of_plane == NULL) {
			cout << "Такого рейса не существует, пожалуйста повторите ввод\n";
			number_of_plane = searchByDestination(arr_of_planes, "Buy");
		}
	}break;
	case 3:
	{
		number_of_plane = searchByDateFlight(arr_of_planes, "Buy");
		while (number_of_plane == NULL) {
			cout << "Такого рейса не существует, пожалуйста повторите ввод\n";
			number_of_plane = searchByDateFlight(arr_of_planes, "Buy");
		}
	}break;
	}
	for (unsigned i = 0; i < arr_of_planes.size(); i++) {
		if (arr_of_planes[i].numberPlane == number_of_plane) return i;
	}
}
void searchPlane(vector<Avia> &arr_of_planes)
{
	while (true)
	{
		switch (searchPlaneMenu())
		{
		case 1: searchByNumberPlane(arr_of_planes); break;
		case 2: searchByDestination(arr_of_planes, "Search"); break;
		case 3: searchByDateFlight(arr_of_planes, "Search"); break;
		case 4: userMode(); break;
		}
	}
}