#include"Header.h"
Account inputAccount()
{
	Account *Check = new Account;
	cout << "Введите ваш логин - " << endl;
	Check->login = inputString();
	cout << "Введите ваш пароль - " << endl;
	Check->pass = inputPassword();
	return *Check;
}
double inputDouble() {
	int a;
	while (true)
	{
		cin >> a;
		if (cin.good()) break;
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Неверный ввод, попробуйте еще раз - " << endl;
		}
	}
	return a;
}
void inputData(int *data)
{
	cout << "(формата ДД.ММ.ГГГГ)";
	data[0] = inputInt();
	cin.ignore();
	data[1] = inputInt();
	cin.ignore();
	data[2] = inputInt();

	SYSTEMTIME st;
	GetSystemTime(&st);
	int sDay = st.wDay;
	int sMonth = st.wMonth;
	int sYear = st.wYear;
	if ((data[0] > 31 || data[0] < 1 || data[1] > 12 || data[1] < 1 || data[2] > 2100 || data[2] < sYear) ||
		(data[2] == sYear && data[1] < sMonth) ||
		(data[2] == sYear && data[1] == sMonth && data[0] < sDay))
	{
		cout << "Дата введена неверно\n";
		inputData(data);
	}

}
int inputInt()
{
	int a;
	while (true)
	{
		cin >> a;
		if (cin.good()) break;
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Неверный ввод, попробуйте еще раз - " << endl;
		}
	}
	return a;
}
int inputIntRange(int left, int right)
{
	int a = inputInt();
	while (a < left || a > right)
	{
		cout << "Неверный ввод, попробуйте еще раз - " << endl;
		a = inputInt();
	}

	return a;
}
string inputString()
{
	string str;

	while (true)
	{
		cin >> str;
		if (cin.good()) break;
		else
		{
			fflush(stdin);
			cin.clear();
			cout << "попробуйте еще раз - " << endl;
		}
	}
	return str;
}
string inputPassword()
{
	string pass;
	cin >> pass;
	if (pass.length() < 5)
	{
		cout << "Пароль должен содержать более 5 символов" << endl
			<< "Попробуйте ещё раз" << endl;
		pass = inputPassword();
	}
	return pass;
}
string inputTime()
{
	string data;
	const char *dPoint = ":";
	while (true)
	{
		cout << "формата(ММ:ЧЧ) - ";
		data = inputString();
		if (data < "24:00" && data >= "00:00" && data.size() == 5 && data.substr(2, 1) == dPoint) return data;
	}

}