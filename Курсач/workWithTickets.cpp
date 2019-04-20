#include "Header.h"
void showTickets(vector<Avia> arr_of_planes)
{

	cout << setw(2) << setw(10) << right << "|Рейс №" << setw(8) << left << "|Type" << setw(14) << left << "|Destination"
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
	cout << "Чтобы добавить самолет введите" << endl;
	cout << "Номер самолета :";
	buffer[0].numberPlane = inputIntRange(1, 999);
	cout << "  " << "Тип самолета :";
	cin >> buffer[0].Type;
	cout << "Пункт назначения :";
	cin >> buffer[0].destination;
	cout << "  " << "Дата полета :";
	inputData(buffer[0].dateFlight);
	cout << "Время вылета :";
	buffer[0].timeFlight = inputTime();
	cout << "  " << "Время прибытия :";
	buffer[0].timeArrival = inputTime();
	cout << " " << "Вместимость самолета :";
	buffer[0].CapacityPlane = inputIntRange(1, 1000);
	cout << " " << "Введите кол-во билетов бизнес-класса :";
	buffer[0].leftTicketsBusiness = inputIntRange(1, buffer[0].CapacityPlane);
	cout << " " << "Введите цену билета бизнес-класса :";
	buffer[0].priceTicketsBusiness = inputDouble();
	buffer[0].leftTicketsEconom = buffer[0].CapacityPlane - buffer[0].leftTicketsBusiness;
	cout << " " << "Введите цену билета эконом-класса :";
	buffer[0].priceTicketsEconom = inputDouble();
	arr_of_planes.insert(arr_of_planes.end(), buffer[0]);
}
void delOnePlane(vector<Avia> &arr_of_planes)
{
	cout << "Введите номер удаляемой записи ";
	int del_item = inputIntRange(1, arr_of_planes.size());
	arr_of_planes.erase(arr_of_planes.begin() + del_item - 1);
	system("cls");
	cout << "запись удалена !" << endl;
	cout << endl;
}
void updatePlanesList(vector<Avia> &arr_of_planes)
{
	cout << "Введите номер редактируемой записи ";
	int upd_item;
	upd_item = inputIntRange(1, arr_of_planes.size());

	cout << "Отредактируейте данные учётной записи: " << endl;
	cout << "Номер самолета :";
	arr_of_planes[upd_item - 1].numberPlane = inputIntRange(1, 1000);
	cout << "  " << "Тип самолета : ";
	cin >> arr_of_planes[upd_item - 1].Type;
	cout << "Пункт назначения :";
	cin >> arr_of_planes[upd_item - 1].destination;
	cout << "  " << "Дата полета : ";
	inputData(arr_of_planes[upd_item - 1].dateFlight);
	cout << "Время вылета :";
	arr_of_planes[upd_item - 1].timeFlight = inputTime();
	cout << "  " << "Время прибытия : ";
	arr_of_planes[upd_item - 1].timeArrival = inputTime();
	cout << " " << "Вместимость самолета";
	arr_of_planes[upd_item - 1].CapacityPlane = inputIntRange(1, 1000);
	cout << " " << "Введите кол-во билетов бизнес-класса";
	arr_of_planes[upd_item - 1].leftTicketsBusiness = inputIntRange(1, arr_of_planes[upd_item - 1].CapacityPlane);
	cout << " " << "Введите цену билета бизнес-класса";
	arr_of_planes[upd_item - 1].priceTicketsBusiness = inputDouble();
	arr_of_planes[upd_item - 1].leftTicketsEconom = arr_of_planes[upd_item - 1].CapacityPlane - arr_of_planes[upd_item - 1].leftTicketsBusiness;
	cout << " " << "Введите цену билета эконом-класса";
	arr_of_planes[upd_item - 1].priceTicketsEconom = inputDouble();
	system("cls");
	cout << "запись отредактирована !" << endl;
	cout << endl;

}
void buyTickets(vector<Avia> &arr_of_planes)
{
	int number_of_tickets, Class;
	int number_of_choosen_plane = choosePlane(arr_of_planes);
	cout << "Выберите класс обслуживания :\n"
		<< "1. Бизнес класс\n"
		<< "2. Эконом класс\n";
	Class = inputIntRange(1, 2);
	if (arr_of_planes[number_of_choosen_plane].leftTicketsBusiness == 0 && arr_of_planes[number_of_choosen_plane].leftTicketsEconom == 0) {
		cout << "Билетов на данный самолет не осталось, желаете выбрать другой самолет ?\n"
			<< "1 - Да\n" << "2 - Нет\n";
		int choise = inputIntRange(1, 2);
		if (choise == 1) buyTickets(arr_of_planes); else processingMode(arr_of_planes);
	}
	if (Class == 1)
	{
		if (arr_of_planes[number_of_choosen_plane].leftTicketsBusiness == 0)
		{
			cout << "Билетов бизнес-класса на данный рейс не осталось, желаете приобрести билет эконом класса?\n"
				<< "1 - Да\n" << "2 - Нет\n";
			int choise = inputIntRange(1, 2);
			if (choise == 1) Class = 2; else processingMode(arr_of_planes);
		}
		if (arr_of_planes[number_of_choosen_plane].leftTicketsEconom == 0)
		{
			cout << "Билетов эконом-класса на данный рейс не осталось, желаете приобрести билет бизнесс класса?\n"
				<< "1 - Да\n" << "2 - Нет\n";
			int choise = inputIntRange(1, 2);
			if (choise == 1) Class = 1; else processingMode(arr_of_planes);
		}
	}
	cout << "Сколько билетов вы хотите купить ?\n";
	if (Class == 1) number_of_tickets = inputIntRange(1, arr_of_planes[number_of_choosen_plane].leftTicketsBusiness);
	else number_of_tickets = inputIntRange(1, arr_of_planes[number_of_choosen_plane].leftTicketsEconom);

	switch (Class)
	{
	case 1: {
		arr_of_planes[number_of_choosen_plane].leftTicketsBusiness -= number_of_tickets;
		cout << "Билет(ы) успешно куплен(ы)\n";
	} break;
	case 2: {arr_of_planes[number_of_choosen_plane].leftTicketsEconom -= number_of_tickets;
		cout << "Билет(ы) успешно куплен(ы)\n";
	}break;
	}
}
