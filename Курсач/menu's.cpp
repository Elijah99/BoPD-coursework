#include "Header.h"
int adminModeMenu()
{
	cout << setw(40) << "Меню администратора" << endl
		<< "Что вы хотите сделать?\n" << "1. Управление учетными записями пользователей\n" << "2. Работа со списком рейсов\n"
		<< "3. Разлогиниться\n" << "0. Выход\n";
	int choise = inputIntRange(0, 3);
	return choise;
}
int userModeMenu()
{
	cout << setw(40) << "Меню пользователя" << endl
		<< "Что вы хотите сделать?\n" << "1. Покупка билетов\n" << "2. Показать список рейсов\n"
		<< "3. Поиск рейса\n" << "4. Сортировка списка рейсов\n" << "5. Разлогиниться\n" << "0. Выход\n";
	int choise = inputIntRange(0, 5);
	return choise;
}
int manageAccountsMenu()
{
	cout << "Выберите:\n" << "1. Просмотр всех учетных записей\n" << "2. Добавление новой учетной записи\n" << "3. Редактирование учетной записи\n"
		<< "4. Удаление учетной записи\n" << "5. Назад\n" << "0. Выход\n";
	int choise = inputIntRange(0, 5);
	return choise;
}
int workDataMenu()
{
	cout << setw(40) << "Меню работы с данными о билетах\n"
		<< "Выберите:\n" << "1. Режим редактирования данных\n" << "2. Режим обработки данных\n"
		<< "3. Вернуться назад\n" << "0. Выход\n";
	int choise = inputIntRange(0, 3);
	return choise;
}
int editModeMenu()
{
	cout << setw(40) << "Меню редактирования данных\n"
		<< "Выберите:\n" << "1. Просмотр списка билетов\n" << "2. Добавление самолета\n" << "3. Удаление самолета\n"
		<< "4. Редактирование списка\n" << "5. Вернуться назад\n" << "0. Выход\n";
	int choise = inputIntRange(0, 5);
	return choise;
}
int choosePlaneMenu()
{
	cout << "Выберите нужный самолет:\n"
		<< "1. Поиск по номеру рейса\n"
		<< "2. Поиск по месту назначения\n"
		<< "3. Поиск по дате вылета\n";
	int choise = inputIntRange(1, 3);
	return choise;
}
int searchPlaneMenu()
{
	int choise;
	cout << "Выберите вариант поиска:\n"
		<< "1. По номеру рейса\n"
		<< "2. По пункту назначения\n"
		<< "3. По дате вылета\n"
		<< "4. Назад\n";
	choise = inputIntRange(1, 4);
	return choise;
}
int sortingModeMenu() {
	system("cls");
	cout << endl;
	cout << "Выберите вариант сортировки" << endl;
	cout << "1 - По номеру рейса" << endl;
	cout << "2 - По пункту назначения" << endl;
	cout << "3 - По дате вылета" << endl;
	cout << "4 - назад" << endl;
	int choise;
	cout << endl;
	choise = inputIntRange(1, 4);
	return choise;
}
int processingModeMenu()
{
	cout << setw(40) << "Меню обработки данных\n"
		<< "Выберите:\n" << "1. Купить билет\n" << "2. Поиск билетов на самолет\n" << "3. Показать список самолетов\n"
		<< "4. Сортировка списка самолетов\n" << "5. Назад\n" << "0. Выход\n";
	int choise = inputIntRange(0, 5);
	return choise;
}