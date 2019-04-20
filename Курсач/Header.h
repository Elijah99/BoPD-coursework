#ifndef __HEADER_H__
#define __HEADER_H__
#pragma once
#define NOMINMAX
#include <iomanip>
#include <limits>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <string>
#include <iterator>
#include <fstream>
#include <Windows.h>

using namespace std;

struct Account		//Структура данных аккаунта;
{
	string login;	//логин пользователя;
	string pass;	// пароль пользователя;
	int role;	// роль пользователя (1 – администратор, 0 – пользователь);

};
struct Avia	//Структура с информацией о рейсе
{
	int numberPlane;		//Номер рейса
	string Type;		//Тип самолета
	string destination;	//Пункт назначения
	int dateFlight[3];	//Дата вылета
	string timeFlight;	//Время вылета
	string timeArrival;	//Время прибытия
	int CapacityPlane;	//Вместимость самолета
	int leftTicketsBusiness;	//Кол-во оставшихся билетов бизнес-класса
	double priceTicketsBusiness;	//Цена билета бизнес-класса
	int leftTicketsEconom;	//Кол-во оставшихся билетов эконом-класса
	double priceTicketsEconom;	//цена билета эконом-класса
};


Account inputAccount();
int inputInt();
double inputDouble();
int inputIntRange(int, int);
void inputData(int *data);
string inputString();
string inputPassword();
string inputTime();
bool isLoginUnique(string &);
void authorization();
void checkFiles();
void readFileAccounts(vector<Account> &);
void showAccounts(vector<Account> &);
void addAccount(vector<Account> &);
void delAccount(vector<Account> &);
void updateAccount(vector<Account> &);
void writeFileAccounts(vector<Account> &);
bool checkInAccount(vector<Account>, Account, int &);
void adminMode();
int adminModeMenu();
void userMode();
int userModeMenu();
void manageAccounts();
int manageAccountsMenu();
void createDataFile();
void readFileTickets(vector<Avia> &); 
void writeFileTickets(vector<Avia>); 
void showTickets(vector<Avia>);
void addOnePlane(vector<Avia> &);
void workData();
int workDataMenu();
void editMode(vector<Avia> &);
int editModeMenu();
void processingMode(vector<Avia> &);
void delOnePlane(vector<Avia> &);
void updatePlanesList(vector<Avia> &);
void buyTickets(vector<Avia> &);
void searchPlane(vector<Avia> &);
int searchPlaneMenu();
void sortSpisPlanes(const string, vector<Avia>);
void sortingMode(const string, vector<Avia> &);
int sortingModeMenu();
int processingModeMenu();
int choosePlane(vector<Avia> &);
int choosePlaneMenu();
int searchByNumberPlane(vector<Avia>);
int searchByDestination(vector<Avia>, const string);
int searchByDateFlight(vector<Avia>, const string);
#endif 