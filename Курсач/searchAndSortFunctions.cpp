#include "Header.h"
int searchByNumberPlane(vector<Avia> arr_of_planes)
{
	int number_of_plane;
	cout << "Введите номер рейса - ";
	number_of_plane = inputInt();
	for (unsigned int i = 0; i < arr_of_planes.size(); i++)
	{
		if (arr_of_planes[i].numberPlane == number_of_plane)
		{
			vector<Avia> foundPlane;
			Avia buffer;
			buffer = arr_of_planes[i];
			foundPlane.push_back(buffer);
			system("cls");
			cout << "Рейс с заданным номером :\n";
			showTickets(foundPlane);
			return number_of_plane;
		}
	}
	return NULL;
}
int searchByDestination(vector<Avia> arr_of_planes, const string checkMode)
{
	string check_destination;
	vector<Avia> foundPlanes;
	cout << "Введите пункт назначения - ";
	cin >> check_destination;
	for (unsigned int i = 0; i < arr_of_planes.size(); i++)
	{
		if (arr_of_planes[i].destination == check_destination) foundPlanes.push_back(arr_of_planes[i]);
	}
	if (foundPlanes.size() > 0) {
		system("cls");
		cout << "Список самолетов с заданным пунктом назначения:\n";
		showTickets(foundPlanes);
		if (checkMode == "Buy") {
			if (foundPlanes.size() == 1) return foundPlanes[0].numberPlane;
			else {
				int number_of_found_plane = searchByNumberPlane(foundPlanes);
				return number_of_found_plane;
			}
		}
		else return NULL;
	}
	else {
		cout << "Самолетов с заданным пунктом назначения не найдено\n";
		return NULL;
	}
}
int searchByDateFlight(vector<Avia> arr_of_planes, const string checkMode)
{
	int checkData[3];
	vector<Avia> foundPlanes;
	inputData(checkData);
	for (unsigned int i = 0; i < arr_of_planes.size(); i++)
	{
		if (
			checkData[0] == arr_of_planes[i].dateFlight[0]
			&& checkData[1] == arr_of_planes[i].dateFlight[1]
			&& checkData[2] == arr_of_planes[i].dateFlight[2]
			) foundPlanes.push_back(arr_of_planes[i]);
	}

	if (foundPlanes.size() > 0) {
		system("cls");
		cout << "Список самолетов с заданной датой вылета:\n";
		showTickets(foundPlanes);
		if (checkMode == "Buy") {
			if (foundPlanes.size() == 1) return foundPlanes[0].numberPlane;
			else {
				int number_of_found_plane = searchByNumberPlane(foundPlanes);
				return number_of_found_plane;
			}
		}
		else return NULL;
	}
	else {
		cout << "Самолетов с заданной датой вылета не найдено\n";
		return NULL;
	}
}
void sortSpisPlanes(const string a, vector<Avia> Sort)
{
	for (unsigned int i = 0; i < Sort.size() - 1; i++) {
		for (unsigned int j = i + 1; j < Sort.size(); j++) {
			if (a == "Number" && Sort[i].numberPlane > Sort[j].numberPlane) {
				swap(Sort[i], Sort[j]);
			}
			else if (a == "Destination" && Sort[i].destination > Sort[j].destination) {
				swap(Sort[i], Sort[j]);
			}
			else if (a == "Date" && Sort[i].dateFlight[2] > Sort[j].dateFlight[2])
			{
				swap(Sort[i], Sort[j]);
			}
			else if (Sort[i].dateFlight[2] == Sort[j].dateFlight[2]) if (Sort[i].dateFlight[1] > Sort[j].dateFlight[1])
			{
				swap(Sort[i], Sort[j]);
			}
			else if (Sort[i].dateFlight[1] == Sort[j].dateFlight[1] && Sort[i].dateFlight[0] > Sort[j].dateFlight[0])
			{
				swap(Sort[i], Sort[j]);
			}
		}
	}
	system("cls");
	showTickets(Sort);
	cout << endl;
	cout << "Press any key to continue ..." << endl;
	_getch();

}