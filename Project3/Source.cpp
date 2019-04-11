#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <algorithm>

// Глобальные константы.

extern const std::string AUTH_FILE = "auth.txt";

extern const std::string TICKETS_FILE = "tickets.txt";

// Локальные переменные для авторизации.

std::string temp_user_login, temp_user_password, temp_destination, temp_bus_type, temp_departure_date, temp_departure_time, temp_arrival_time;

int temp_tickets_to_buy, temp_flight_number, temp_ticket_price, temp_number_of_tickets_remaining, temp_number_of_tickets_sold;

bool temp_for_all_stuff, role, isLoggedin = false;

// Инициализация структур.

struct Auth
{

	std::string login, password;

	int role;

};

struct Tickets
{

	std::string destination, bus_type, departure_date, departure_time, arrival_time;

	int flight_number, ticket_price, number_of_tickets_remaining, number_of_tickets_sold;

};

// Инициализация локальной структуры.

Auth s_Auth;

Tickets s_Tickets;

// Инициализация локальной вектора.

std::vector<Auth> v_Auth;

std::vector<Tickets> v_Tickets;

// Процесс авторизации.

void authorization_proccess();

// Запись данных в существующий файл.

void write_data_to_file(std::string message);

// Чтение данных из существуеющего файла.

void read_file_data();

// Меню "Модуль администратора".

void show_admin_module_menu();

// Меню "Модуль администратора" => "Управление учетными записями пользователей".

void show_user_account_management_menu();

// Меню "Модуль администратора" => "Работа с данными".

void show_work_with_data_menu();

// Меню "Модуль администратора" => "Работа с данными" => "Режим редактирования".

void show_edit_mode_menu();

// Меню "Модуль администратора" => "Работа с данными" => "Режим обработки данных".

void show_data_processing_mode();

// Меню "Поиск данных".

void show_search_data_menu();

// Меню "Модуль пользователя".

void show_user_module_menu();

// Просмотр всех учетных записей.

void show_all_accounts();

// Switch function.

void func_switch(int number_of_case = 2, void(*foo0)() = NULL, void(*foo1)() = NULL, void(*foo2)() = NULL, void(*foo3)() = NULL, void(*foo4)() = NULL, void(*foo5)() = NULL);

// Zero function.

void func_zero();

// Добавление новой учетной записи.

void add_new_account();

// Редактирование учетной записи.

void edit_account();

// Удаление учетной записи.

void delete_account();

// Просмотр всех данных.

void show_all_data();

// Добавление новой учетной записи.

void add_new_data();

// Редактирование данных.

void edit_data();

// Удаление данных.

void delete_data();

// Поиск по типу автобуса.

void search_by_bus_type();

// Поиск по пункту назначения.

void search_by_destination();

// Поиск по дате отправления.

void search_by_departure_date();

// Выполнение индивидуального задания.

void example();

// Функция оповещения пользователя.

void show_message(std::string message);

// Главная функция.

int main()
{

	// Русификация.

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "russian");

	// Запись данных в существующий файл.

	write_data_to_file("first start");

	// Чтение данных из существуеющего файла.

	read_file_data();

	// Процесс авторизации.

	authorization_proccess();

	system("pause");

	return 0;

}

// Запись данных в существующий файл.

void write_data_to_file(std::string message)
{

	// Запись данных администратора при первом запуске приложения.
	// Если файла не существует, программа создаст и добавит единожды данные администратора.
	// Иначе запишет данные структуры вектора.

	std::ifstream fin(AUTH_FILE);

	if (message == "first start")
	{

		// Если файла не существует.

		if (!fin.is_open())
		{

			// Создаем файл.

			std::ofstream fout(AUTH_FILE);

			// Записываем данные администратора.

			fout << "root toor 1";


			// Закрываем файл.

			fout.close();

		}

		// Закрываем файл.

		fin.close();

	}
	else if (message == "edit account" || message == "delete account")
	{

		// Создаем файл.

		std::ofstream fout(AUTH_FILE);

		// Записываем данные администратора.

		for (int i = 0; i < v_Auth.size(); i++)
		{

			if (i == v_Auth.size() - 1)
			{

				fout << v_Auth.at(i).login << " " << v_Auth.at(i).password << " " << v_Auth.at(i).role;

			}
			else
			{

				fout << v_Auth.at(i).login << " " << v_Auth.at(i).password << " " << v_Auth.at(i).role << std::endl;

			}

		}

		// Закрываем файл.

		fout.close();

	}
	else if (message == "edit data" || message == "delete data")
	{

		std::ifstream fin(TICKETS_FILE);

		// Если файла не существует.

		if (fin.is_open())
		{

			// Создаем файл.

			std::ofstream fout(TICKETS_FILE);

			// Записываем данные администратора.

			for (int i = 0; i < v_Tickets.size(); i++)
			{

				if (i == v_Tickets.size() - 1)
				{

					fout << v_Tickets.at(i).flight_number << " " << v_Tickets.at(i).bus_type << " " << v_Tickets.at(i).destination << " " << v_Tickets.at(i).departure_date << " " << v_Tickets.at(i).departure_time << " " << v_Tickets.at(i).arrival_time << " " << v_Tickets.at(i).ticket_price << " " << v_Tickets.at(i).number_of_tickets_remaining << " " << v_Tickets.at(i).number_of_tickets_sold;

				}
				else
				{

					fout << v_Tickets.at(i).flight_number << " " << v_Tickets.at(i).bus_type << " " << v_Tickets.at(i).destination << " " << v_Tickets.at(i).departure_date << " " << v_Tickets.at(i).departure_time << " " << v_Tickets.at(i).arrival_time << " " << v_Tickets.at(i).ticket_price << " " << v_Tickets.at(i).number_of_tickets_remaining << " " << v_Tickets.at(i).number_of_tickets_sold << std::endl;

				}

			}

			// Закрываем файл.

			fout.close();

		}

		// Закрываем файл.

		fin.close();

	}
	

}

// Процесс авторизации.

void authorization_proccess()
{

	// Пока не авторизован.

	while (!isLoggedin)
	{

		// Вывести надпись.

		std::cout << "Введите логин: ";

		// Ждать ввода данных.

		std::cin >> temp_user_login;

		// Вывести надпись.

		std::cout << "Введите пароль: ";

		// Ждать ввода данных.

		std::cin >> temp_user_password;

		// В цикле проходимся по вектору структуры.

		for (int i = 0; i < v_Auth.size(); i++)
		{

			// Если введенные данные, пользователем, совпадают с элементами в векторе структур.

			if (v_Auth.at(i).login == temp_user_login && v_Auth.at(i).password == temp_user_password)
			{

				// Присваиваем значение истины переменной loggedin. Пользователь авторизовался.

				isLoggedin = true;

				role = v_Auth.at(i).role;

				// Выходим из цикла.

				break;

			}
			else
			{

				// Иначе, присваиваем значение лжи переменной loggedin. Пользователь не прошел авторизацию.

				isLoggedin = false;

			}

		}

		// Если пользователь ввел верные данные.

		if (isLoggedin)
		{

			// Информируем об успешной авторизации.

			std::cout << "Вы вошли." << std::endl;

			if (role)
			{

				system("cls");

				show_admin_module_menu();

			}
			else
			{

				system("cls");

				show_user_module_menu();

			}
			

		}
		else
		{

			// Иначе, выводим сообщение об ошибке.

			std::cout << "Повторите попытку." << std::endl;

		}

	}

}

// Чтение данных из существуеющего файла.

void read_file_data()
{

	// Выгружаем данные из файла в структуру.
	// В этом случаи файл уже существует.

	std::ifstream fin(AUTH_FILE);

	// Если файл открыт.

	if (fin.is_open())
	{

		// Инициализация локальной переменной

		int i = 0;

		// Пока не конец файла.

		while (!fin.eof())
		{

			// Добавляет структуру в вектор.

			v_Auth.push_back(s_Auth);

			// Выгрузка данных в вектор структур.

			fin >> v_Auth.at(i).login >> v_Auth.at(i).password >> v_Auth.at(i).role;

			// Увеличиваем переменную на единицу.

			i++;

		}

	}

	// Закрываем файл.

	fin.close();

	// Выгружаем данные из файла в структуру.
	// В этом случаи файл уже существует.

	std::ifstream fticket(TICKETS_FILE);

	// Если файл открыт.

	if (fticket.is_open())
	{

		// Инициализация локальной переменной

		int i = 0;

		// Пока не конец файла.

		while (!fticket.eof())
		{

			// Добавляет структуру в вектор.

			v_Tickets.push_back(s_Tickets);

			// Выгрузка данных в вектор структур.

			fticket >> v_Tickets.at(i).flight_number >> v_Tickets.at(i).bus_type >> v_Tickets.at(i).destination >> v_Tickets.at(i).departure_date >> v_Tickets.at(i).departure_time >> v_Tickets.at(i).arrival_time >> v_Tickets.at(i).ticket_price >> v_Tickets.at(i).number_of_tickets_remaining >> v_Tickets.at(i).number_of_tickets_sold;

			// Увеличиваем переменную на единицу.

			i++;

		}

	}

	// Закрываем файл.

	fticket.close();

}

/*




fucking menus




*/


// Switch function.

void func_switch(int number_of_case, void(*foo0)(), void(*foo1)(), void(*foo2)(), void(*foo3)(), void(*foo4)(), void(*foo5)())
{

	int choose;

	std::cout << " | Ваш выбор: ";

	std::cin >> choose;

	if (number_of_case == 2)
	{

		switch (choose)
		{
		case 0:

			system("cls");

			foo0();

			break;

		case 1:

			system("cls");

			foo1();

			break;

		default:

			break;

		}

	}
	else if (number_of_case == 3)
	{

		switch (choose)
		{
		case 0:

			system("cls");

			foo0();

			break;

		case 1:

			system("cls");

			foo1();

			break;

		case 2:

			system("cls");

			foo2();

			break;

		default:

			break;

		}

	}
	else if (number_of_case == 4)
	{

		switch (choose)
		{
		case 0:

			system("cls");

			foo0();

			break;

		case 1:

			system("cls");

			foo1();

			break;

		case 2:

			system("cls");

			foo2();

			break;

		case 3:

			system("cls");

			foo3();

			break;

		default:

			break;

		}

	}
	else if (number_of_case == 5)
	{

		switch (choose)
		{
		case 0:

			system("cls");

			foo0();

			break;

		case 1:

			system("cls");

			foo1();

			break;

		case 2:

			system("cls");

			foo2();

			break;

		case 3:

			system("cls");

			foo3();

			break;

		case 4:

			system("cls");

			foo4();

			break;

		default:

			break;

		}

	}
	else if (number_of_case == 6)
	{

		switch (choose)
		{
		case 0:

			system("cls");

			foo0();

			break;

		case 1:

			system("cls");

			foo1();

			break;

		case 2:

			system("cls");

			foo2();

			break;

		case 3:

			system("cls");

			foo3();

			break;

		case 4:

			system("cls");

			foo4();

			break;

		case 5:

			system("cls");

			foo5();

			break;

		default:

			break;

		}

	}

}

// Zero function.

void func_zero()
{

	isLoggedin = false;

	std::cout << "Вы нажали 0" << std::endl;

}

/*




user accounts





*/

/*



data



*/

// Поиск по типу автобуса.

void search_by_bus_type()
{

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Изменить переменные

	bool isLoginExists = true;

	while (isLoginExists)
	{

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(68) << "Поиск данных по типу автобуса" << std::setfill(' ') << std::setw(39) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | Введите тип автобуса: ";

		std::cin >> temp_bus_type;

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(90) << "Просмотр всех данных" << std::setfill(' ') << std::setw(68) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(141) << "|                Билеты" << std::setfill(' ') << std::setw(17) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(11) << " # рейса | " << std::setw(15) << std::left << "Тип автобуса | " << std::setw(19) << std::left << "Пункт назначения | " << std::setw(19) << std::left << "Дата отправления | " << std::setw(20) << std::left << "Время отправления | " << std::setw(17) << std::left << "Время прибытия | " << std::setw(19) << std::left << "Стоимость билета | " << std::setw(20) << std::left << "Кол-во оставшихся | " << std::setw(19) << std::left << "Кол-во проданных |" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << std::right << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		for (int i = 0; i < v_Tickets.size(); i++)
		{

			if (v_Tickets.at(i).bus_type == temp_bus_type)
			{

				std::cout << std::setfill(' ') << std::setw(2) << " | " << std::setw(7) << std::right << v_Tickets.at(i).flight_number << " | " << std::setw(12) << std::left << v_Tickets.at(i).bus_type << " | " << std::setw(16) << std::left << v_Tickets.at(i).destination << " | " << std::setw(16) << std::left << v_Tickets.at(i).departure_date << " | " << std::setw(17) << std::left << v_Tickets.at(i).departure_time << " | " << std::setw(14) << std::left << v_Tickets.at(i).arrival_time << " | " << std::setw(16) << std::left << v_Tickets.at(i).ticket_price << " | " << std::setw(17) << std::right << v_Tickets.at(i).number_of_tickets_remaining << " | " << std::setw(16) << std::right << v_Tickets.at(i).number_of_tickets_sold << " | " << std::endl;


				std::cout << std::setfill(' ') << std::setw(2) << std::right << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

				isLoginExists = true;

			}
			else
			{

				isLoginExists = false;

			}

		}

		show_search_data_menu();

	}

}

// Поиск по пункту назначения.

void search_by_destination()
{

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Изменить переменные

	bool isLoginExists = true;

	while (isLoginExists)
	{



		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(68) << "Поиск данных по пункту назначения" << std::setfill(' ') << std::setw(39) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | Введите пункт назначения: ";

		std::cin >> temp_destination;

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(90) << "Просмотр всех данных" << std::setfill(' ') << std::setw(68) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(141) << "|                Билеты" << std::setfill(' ') << std::setw(17) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(11) << " # рейса | " << std::setw(15) << std::left << "Тип автобуса | " << std::setw(19) << std::left << "Пункт назначения | " << std::setw(19) << std::left << "Дата отправления | " << std::setw(20) << std::left << "Время отправления | " << std::setw(17) << std::left << "Время прибытия | " << std::setw(19) << std::left << "Стоимость билета | " << std::setw(20) << std::left << "Кол-во оставшихся | " << std::setw(19) << std::left << "Кол-во проданных |" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << std::right << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		for (int i = 0; i < v_Tickets.size(); i++)
		{

			if (v_Tickets.at(i).destination == temp_destination)
			{

				std::cout << std::setfill(' ') << std::setw(2) << " | " << std::setw(7) << std::right << v_Tickets.at(i).flight_number << " | " << std::setw(12) << std::left << v_Tickets.at(i).bus_type << " | " << std::setw(16) << std::left << v_Tickets.at(i).destination << " | " << std::setw(16) << std::left << v_Tickets.at(i).departure_date << " | " << std::setw(17) << std::left << v_Tickets.at(i).departure_time << " | " << std::setw(14) << std::left << v_Tickets.at(i).arrival_time << " | " << std::setw(16) << std::left << v_Tickets.at(i).ticket_price << " | " << std::setw(17) << std::right << v_Tickets.at(i).number_of_tickets_remaining << " | " << std::setw(16) << std::right << v_Tickets.at(i).number_of_tickets_sold << " | " << std::endl;


				std::cout << std::setfill(' ') << std::setw(2) << std::right << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

				isLoginExists = true;

			}
			else
			{

				isLoginExists = false;

			}

		}

		show_search_data_menu();

	}

}

// Поиск по дате отправления.

void search_by_departure_date()
{

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Изменить переменные

	bool isLoginExists = true;

	while (isLoginExists)
	{

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(68) << "Поиск данных по дате отправления" << std::setfill(' ') << std::setw(39) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | Введите дату отправления: ";

		std::cin >> temp_departure_date;

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(90) << "Просмотр всех данных" << std::setfill(' ') << std::setw(68) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(141) << "|                Билеты" << std::setfill(' ') << std::setw(17) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(11) << " # рейса | " << std::setw(15) << std::left << "Тип автобуса | " << std::setw(19) << std::left << "Пункт назначения | " << std::setw(19) << std::left << "Дата отправления | " << std::setw(20) << std::left << "Время отправления | " << std::setw(17) << std::left << "Время прибытия | " << std::setw(19) << std::left << "Стоимость билета | " << std::setw(20) << std::left << "Кол-во оставшихся | " << std::setw(19) << std::left << "Кол-во проданных |" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << std::right << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		for (int i = 0; i < v_Tickets.size(); i++)
		{

			if (v_Tickets.at(i).departure_date == temp_departure_date)
			{

				std::cout << std::setfill(' ') << std::setw(2) << " | " << std::setw(7) << std::right << v_Tickets.at(i).flight_number << " | " << std::setw(12) << std::left << v_Tickets.at(i).bus_type << " | " << std::setw(16) << std::left << v_Tickets.at(i).destination << " | " << std::setw(16) << std::left << v_Tickets.at(i).departure_date << " | " << std::setw(17) << std::left << v_Tickets.at(i).departure_time << " | " << std::setw(14) << std::left << v_Tickets.at(i).arrival_time << " | " << std::setw(16) << std::left << v_Tickets.at(i).ticket_price << " | " << std::setw(17) << std::right << v_Tickets.at(i).number_of_tickets_remaining << " | " << std::setw(16) << std::right << v_Tickets.at(i).number_of_tickets_sold << " | " << std::endl;


				std::cout << std::setfill(' ') << std::setw(2) << std::right << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

				isLoginExists = true;

			}
			else
			{

				isLoginExists = false;

			}

		}

		show_search_data_menu();

	}

}

// Выполнение индивидуального задания.

void example()
{

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Изменить переменные

	bool isLoginExists = true;

	while (isLoginExists)
	{

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(60) << "Покупка билета" << std::setfill(' ') << std::setw(47) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | Куда хотите купить билет?: ";

		std::cin >> temp_destination;

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(90) << "Просмотр всех данных" << std::setfill(' ') << std::setw(68) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(141) << "|                Билеты" << std::setfill(' ') << std::setw(17) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(11) << " # рейса | " << std::setw(15) << std::left << "Тип автобуса | " << std::setw(19) << std::left << "Пункт назначения | " << std::setw(19) << std::left << "Дата отправления | " << std::setw(20) << std::left << "Время отправления | " << std::setw(17) << std::left << "Время прибытия | " << std::setw(19) << std::left << "Стоимость билета | " << std::setw(20) << std::left << "Кол-во оставшихся | " << std::setw(19) << std::left << "Кол-во проданных |" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << std::right << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		for (int i = 0; i < v_Tickets.size(); i++)
		{

			if (v_Tickets.at(i).destination == temp_destination && v_Tickets.at(i).number_of_tickets_remaining > 0)
			{

				std::cout << std::setfill(' ') << std::setw(2) << " | " << std::setw(7) << std::right << v_Tickets.at(i).flight_number << " | " << std::setw(12) << std::left << v_Tickets.at(i).bus_type << " | " << std::setw(16) << std::left << v_Tickets.at(i).destination << " | " << std::setw(16) << std::left << v_Tickets.at(i).departure_date << " | " << std::setw(17) << std::left << v_Tickets.at(i).departure_time << " | " << std::setw(14) << std::left << v_Tickets.at(i).arrival_time << " | " << std::setw(16) << std::left << v_Tickets.at(i).ticket_price << " | " << std::setw(17) << std::right << v_Tickets.at(i).number_of_tickets_remaining << " | " << std::setw(16) << std::right << v_Tickets.at(i).number_of_tickets_sold << " | " << std::endl;


				std::cout << std::setfill(' ') << std::setw(2) << std::right << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

				std::cout << std::endl;

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(60) << "Покупка билета" << std::setfill(' ') << std::setw(47) << "|" << std::endl;

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

				std::cout << std::setfill(' ') << std::setw(2) << " | Введите рейс: ";

				std::cin >> temp_flight_number;

				std::cout << std::endl;

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

				std::cout << std::setfill(' ') << std::setw(2) << " | Введите количество билетов для покупки: ";

				std::cin >> temp_tickets_to_buy;

				std::cout << std::endl;

				for (int i = 0; i < v_Tickets.size(); i++)
				{

					if (v_Tickets.at(i).flight_number == temp_flight_number)
					{

						v_Tickets.at(i).number_of_tickets_remaining = v_Tickets.at(i).number_of_tickets_remaining - temp_tickets_to_buy;

						v_Tickets.at(i).number_of_tickets_sold = v_Tickets.at(i).number_of_tickets_sold + temp_tickets_to_buy;

					}

				}

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(60) << "Билеты успешно куплены." << std::setfill(' ') << std::setw(47) << "|" << std::endl;

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

				std::ifstream fin(TICKETS_FILE);

				// Если файла не существует.

				if (fin.is_open())
				{

					// Создаем файл.

					std::ofstream fout(TICKETS_FILE);

					// Записываем данные администратора.

					for (int i = 0; i < v_Tickets.size(); i++)
					{

						if (i == v_Tickets.size() - 1)
						{

							fout << v_Tickets.at(i).flight_number << " " << v_Tickets.at(i).bus_type << " " << v_Tickets.at(i).destination << " " << v_Tickets.at(i).departure_date << " " << v_Tickets.at(i).departure_time << " " << v_Tickets.at(i).arrival_time << " " << v_Tickets.at(i).ticket_price << " " << v_Tickets.at(i).number_of_tickets_remaining << " " << v_Tickets.at(i).number_of_tickets_sold;

						}
						else
						{

							fout << v_Tickets.at(i).flight_number << " " << v_Tickets.at(i).bus_type << " " << v_Tickets.at(i).destination << " " << v_Tickets.at(i).departure_date << " " << v_Tickets.at(i).departure_time << " " << v_Tickets.at(i).arrival_time << " " << v_Tickets.at(i).ticket_price << " " << v_Tickets.at(i).number_of_tickets_remaining << " " << v_Tickets.at(i).number_of_tickets_sold << std::endl;

						}

					}

					// Закрываем файл.

					fout.close();

				}

				// Закрываем файл.

				fin.close();

				isLoginExists = true;

			}
			else
			{

				isLoginExists = false;

			}

		}

		show_data_processing_mode();

	}

}