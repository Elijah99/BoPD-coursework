#include "Header.h"
void showTickets(vector<Avia> arr_of_planes)
{

	cout << setw(2) << setw(10) << right << "|���� �" << setw(8) << left << "|Type" << setw(14) << left << "|Destination"
		<< setw(14) << left << "|Date Flight" << setw(6) << left << "|Time" << setw(12) << left << "|Time arrival" << setw(8) << left << "|Capacity"
		<< setw(10) << left << "|left b-cl." << setw(10) << left << "|cost b-cl."
		<< setw(10) << left << "|left e-cl." << setw(10) << left << "|left e-cl.|" << endl;
	for (unsigned int i = 0; i < arr_of_planes.size(); i++)
		cout << "|" << setw(2) << left << i + 1 <<
		"|" << setw(6) << left << arr_of_planes[i].numberPlane <<
		"|" << setw(7) << left << arr_of_planes[i].Type <<
		"|" << setw(13) << left << arr_of_planes[i].destination <<
		"|" << setw(2) << right << arr_of_planes[i].dateFlight[0] <<
		"." << setw(2) << right << arr_of_planes[i].dateFlight[1] <<
		"." << setw(7) << left << arr_of_planes[i].dateFlight[2] <<
		"|" << setw(5) << left << arr_of_planes[i].timeFlight <<
		"|" << setw(12) << left << arr_of_planes[i].timeArrival <<
		"|" << setw(8) << left << arr_of_planes[i].CapacityPlane <<
		"|" << setw(10) << left << arr_of_planes[i].leftTicketsBusiness <<
		"|" << setw(10) << left << arr_of_planes[i].priceTicketsBusiness <<
		"|" << setw(10) << left << arr_of_planes[i].leftTicketsEconom <<
		"|" << setw(10) << left << arr_of_planes[i].priceTicketsEconom << endl;

}
void addOnePlane(vector<Avia> &arr_of_planes)
{
	Avia buffer[1];
	cout << "����� �������� ������� �������" << endl;
	cout << "����� �������� :";
	buffer[0].numberPlane = inputIntRange(1, 999);
	cout << "  " << "��� �������� :";
	cin >> buffer[0].Type;
	cout << "����� ���������� :";
	cin >> buffer[0].destination;
	cout << "  " << "���� ������ :";
	inputData(buffer[0].dateFlight);
	cout << "����� ������ :";
	buffer[0].timeFlight = inputTime();
	cout << "  " << "����� �������� :";
	buffer[0].timeArrival = inputTime();
	cout << " " << "����������� �������� :";
	buffer[0].CapacityPlane = inputIntRange(1, 1000);
	cout << " " << "������� ���-�� ������� ������-������ :";
	buffer[0].leftTicketsBusiness = inputIntRange(1, buffer[0].CapacityPlane);
	cout << " " << "������� ���� ������ ������-������ :";
	buffer[0].priceTicketsBusiness = inputDouble();
	buffer[0].leftTicketsEconom = buffer[0].CapacityPlane - buffer[0].leftTicketsBusiness;
	cout << " " << "������� ���� ������ ������-������ :";
	buffer[0].priceTicketsEconom = inputDouble();
	arr_of_planes.insert(arr_of_planes.end(), buffer[0]);
}
void delOnePlane(vector<Avia> &arr_of_planes)
{
	cout << "������� ����� ��������� ������ ";
	int del_item = inputIntRange(1, arr_of_planes.size());
	arr_of_planes.erase(arr_of_planes.begin() + del_item - 1);
	system("cls");
	cout << "������ ������� !" << endl;
	cout << endl;
}
void updatePlanesList(vector<Avia> &arr_of_planes)
{
	cout << "������� ����� ������������� ������ ";
	int upd_item;
	upd_item = inputIntRange(1, arr_of_planes.size());

	cout << "��������������� ������ ������� ������: " << endl;
	cout << "����� �������� :";
	arr_of_planes[upd_item - 1].numberPlane = inputIntRange(1, 1000);
	cout << "  " << "��� �������� : ";
	cin >> arr_of_planes[upd_item - 1].Type;
	cout << "����� ���������� :";
	cin >> arr_of_planes[upd_item - 1].destination;
	cout << "  " << "���� ������ : ";
	inputData(arr_of_planes[upd_item - 1].dateFlight);
	cout << "����� ������ :";
	arr_of_planes[upd_item - 1].timeFlight = inputTime();
	cout << "  " << "����� �������� : ";
	arr_of_planes[upd_item - 1].timeArrival = inputTime();
	cout << " " << "����������� ��������";
	arr_of_planes[upd_item - 1].CapacityPlane = inputIntRange(1, 1000);
	cout << " " << "������� ���-�� ������� ������-������";
	arr_of_planes[upd_item - 1].leftTicketsBusiness = inputIntRange(1, arr_of_planes[upd_item - 1].CapacityPlane);
	cout << " " << "������� ���� ������ ������-������";
	arr_of_planes[upd_item - 1].priceTicketsBusiness = inputDouble();
	arr_of_planes[upd_item - 1].leftTicketsEconom = arr_of_planes[upd_item - 1].CapacityPlane - arr_of_planes[upd_item - 1].leftTicketsBusiness;
	cout << " " << "������� ���� ������ ������-������";
	arr_of_planes[upd_item - 1].priceTicketsEconom = inputDouble();
	system("cls");
	cout << "������ ��������������� !" << endl;
	cout << endl;

}
void buyTickets(vector<Avia> &arr_of_planes)
{
	int number_of_tickets, Class;
	int number_of_choosen_plane = choosePlane(arr_of_planes);
	cout << "�������� ����� ������������ :\n"
		<< "1. ������ �����\n"
		<< "2. ������ �����\n";
	Class = inputIntRange(1, 2);
	if (arr_of_planes[number_of_choosen_plane].leftTicketsBusiness == 0 && arr_of_planes[number_of_choosen_plane].leftTicketsEconom == 0) {
		cout << "������� �� ������ ������� �� ��������, ������� ������� ������ ������� ?\n"
			<< "1 - ��\n" << "2 - ���\n";
		int choise = inputIntRange(1, 2);
		if (choise == 1) buyTickets(arr_of_planes); else processingMode(arr_of_planes);
	}
	if (Class == 1)
	{
		if (arr_of_planes[number_of_choosen_plane].leftTicketsBusiness == 0)
		{
			cout << "������� ������-������ �� ������ ���� �� ��������, ������� ���������� ����� ������ ������?\n"
				<< "1 - ��\n" << "2 - ���\n";
			int choise = inputIntRange(1, 2);
			if (choise == 1) Class = 2; else processingMode(arr_of_planes);
		}
		if (arr_of_planes[number_of_choosen_plane].leftTicketsEconom == 0)
		{
			cout << "������� ������-������ �� ������ ���� �� ��������, ������� ���������� ����� ������� ������?\n"
				<< "1 - ��\n" << "2 - ���\n";
			int choise = inputIntRange(1, 2);
			if (choise == 1) Class = 1; else processingMode(arr_of_planes);
		}
	}
	cout << "������� ������� �� ������ ������ ?\n";
	if (Class == 1) number_of_tickets = inputIntRange(1, arr_of_planes[number_of_choosen_plane].leftTicketsBusiness);
	else number_of_tickets = inputIntRange(1, arr_of_planes[number_of_choosen_plane].leftTicketsEconom);

	switch (Class)
	{
	case 1: {
		arr_of_planes[number_of_choosen_plane].leftTicketsBusiness -= number_of_tickets;
		cout << "�����(�) ������� ������(�)\n";
	} break;
	case 2: {arr_of_planes[number_of_choosen_plane].leftTicketsEconom -= number_of_tickets;
		cout << "�����(�) ������� ������(�)\n";
	}break;
	}
}
