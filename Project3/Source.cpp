#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <algorithm>

// ���������� ���������.

extern const std::string AUTH_FILE = "auth.txt";

extern const std::string TICKETS_FILE = "tickets.txt";

// ��������� ���������� ��� �����������.

std::string temp_user_login, temp_user_password, temp_destination, temp_bus_type, temp_departure_date, temp_departure_time, temp_arrival_time;

int temp_tickets_to_buy, temp_flight_number, temp_ticket_price, temp_number_of_tickets_remaining, temp_number_of_tickets_sold;

bool temp_for_all_stuff, role, isLoggedin = false;

// ������������� ��������.

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

// ������������� ��������� ���������.

Auth s_Auth;

Tickets s_Tickets;

// ������������� ��������� �������.

std::vector<Auth> v_Auth;

std::vector<Tickets> v_Tickets;

// ������� �����������.

void authorization_proccess();

// ������ ������ � ������������ ����.

void write_data_to_file(std::string message);

// ������ ������ �� �������������� �����.

void read_file_data();

// ���� "������ ��������������".

void show_admin_module_menu();

// ���� "������ ��������������" => "���������� �������� �������� �������������".

void show_user_account_management_menu();

// ���� "������ ��������������" => "������ � �������".

void show_work_with_data_menu();

// ���� "������ ��������������" => "������ � �������" => "����� ��������������".

void show_edit_mode_menu();

// ���� "������ ��������������" => "������ � �������" => "����� ��������� ������".

void show_data_processing_mode();

// ���� "����� ������".

void show_search_data_menu();

// ���� "������ ������������".

void show_user_module_menu();

// �������� ���� ������� �������.

void show_all_accounts();

// Switch function.

void func_switch(int number_of_case = 2, void(*foo0)() = NULL, void(*foo1)() = NULL, void(*foo2)() = NULL, void(*foo3)() = NULL, void(*foo4)() = NULL, void(*foo5)() = NULL);

// Zero function.

void func_zero();

// ���������� ����� ������� ������.

void add_new_account();

// �������������� ������� ������.

void edit_account();

// �������� ������� ������.

void delete_account();

// �������� ���� ������.

void show_all_data();

// ���������� ����� ������� ������.

void add_new_data();

// �������������� ������.

void edit_data();

// �������� ������.

void delete_data();

// ����� �� ���� ��������.

void search_by_bus_type();

// ����� �� ������ ����������.

void search_by_destination();

// ����� �� ���� �����������.

void search_by_departure_date();

// ���������� ��������������� �������.

void example();

// ������� ���������� ������������.

void show_message(std::string message);

// ������� �������.

int main()
{

	// �����������.

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "russian");

	// ������ ������ � ������������ ����.

	write_data_to_file("first start");

	// ������ ������ �� �������������� �����.

	read_file_data();

	// ������� �����������.

	authorization_proccess();

	system("pause");

	return 0;

}

// ������ ������ � ������������ ����.

void write_data_to_file(std::string message)
{

	// ������ ������ �������������� ��� ������ ������� ����������.
	// ���� ����� �� ����������, ��������� ������� � ������� �������� ������ ��������������.
	// ����� ������� ������ ��������� �������.

	std::ifstream fin(AUTH_FILE);

	if (message == "first start")
	{

		// ���� ����� �� ����������.

		if (!fin.is_open())
		{

			// ������� ����.

			std::ofstream fout(AUTH_FILE);

			// ���������� ������ ��������������.

			fout << "root toor 1";


			// ��������� ����.

			fout.close();

		}

		// ��������� ����.

		fin.close();

	}
	else if (message == "edit account" || message == "delete account")
	{

		// ������� ����.

		std::ofstream fout(AUTH_FILE);

		// ���������� ������ ��������������.

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

		// ��������� ����.

		fout.close();

	}
	else if (message == "edit data" || message == "delete data")
	{

		std::ifstream fin(TICKETS_FILE);

		// ���� ����� �� ����������.

		if (fin.is_open())
		{

			// ������� ����.

			std::ofstream fout(TICKETS_FILE);

			// ���������� ������ ��������������.

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

			// ��������� ����.

			fout.close();

		}

		// ��������� ����.

		fin.close();

	}
	

}

// ������� �����������.

void authorization_proccess()
{

	// ���� �� �����������.

	while (!isLoggedin)
	{

		// ������� �������.

		std::cout << "������� �����: ";

		// ����� ����� ������.

		std::cin >> temp_user_login;

		// ������� �������.

		std::cout << "������� ������: ";

		// ����� ����� ������.

		std::cin >> temp_user_password;

		// � ����� ���������� �� ������� ���������.

		for (int i = 0; i < v_Auth.size(); i++)
		{

			// ���� ��������� ������, �������������, ��������� � ���������� � ������� ��������.

			if (v_Auth.at(i).login == temp_user_login && v_Auth.at(i).password == temp_user_password)
			{

				// ����������� �������� ������ ���������� loggedin. ������������ �������������.

				isLoggedin = true;

				role = v_Auth.at(i).role;

				// ������� �� �����.

				break;

			}
			else
			{

				// �����, ����������� �������� ��� ���������� loggedin. ������������ �� ������ �����������.

				isLoggedin = false;

			}

		}

		// ���� ������������ ���� ������ ������.

		if (isLoggedin)
		{

			// ����������� �� �������� �����������.

			std::cout << "�� �����." << std::endl;

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

			// �����, ������� ��������� �� ������.

			std::cout << "��������� �������." << std::endl;

		}

	}

}

// ������ ������ �� �������������� �����.

void read_file_data()
{

	// ��������� ������ �� ����� � ���������.
	// � ���� ������ ���� ��� ����������.

	std::ifstream fin(AUTH_FILE);

	// ���� ���� ������.

	if (fin.is_open())
	{

		// ������������� ��������� ����������

		int i = 0;

		// ���� �� ����� �����.

		while (!fin.eof())
		{

			// ��������� ��������� � ������.

			v_Auth.push_back(s_Auth);

			// �������� ������ � ������ ��������.

			fin >> v_Auth.at(i).login >> v_Auth.at(i).password >> v_Auth.at(i).role;

			// ����������� ���������� �� �������.

			i++;

		}

	}

	// ��������� ����.

	fin.close();

	// ��������� ������ �� ����� � ���������.
	// � ���� ������ ���� ��� ����������.

	std::ifstream fticket(TICKETS_FILE);

	// ���� ���� ������.

	if (fticket.is_open())
	{

		// ������������� ��������� ����������

		int i = 0;

		// ���� �� ����� �����.

		while (!fticket.eof())
		{

			// ��������� ��������� � ������.

			v_Tickets.push_back(s_Tickets);

			// �������� ������ � ������ ��������.

			fticket >> v_Tickets.at(i).flight_number >> v_Tickets.at(i).bus_type >> v_Tickets.at(i).destination >> v_Tickets.at(i).departure_date >> v_Tickets.at(i).departure_time >> v_Tickets.at(i).arrival_time >> v_Tickets.at(i).ticket_price >> v_Tickets.at(i).number_of_tickets_remaining >> v_Tickets.at(i).number_of_tickets_sold;

			// ����������� ���������� �� �������.

			i++;

		}

	}

	// ��������� ����.

	fticket.close();

}

/*




fucking menus




*/


// Switch function.

void func_switch(int number_of_case, void(*foo0)(), void(*foo1)(), void(*foo2)(), void(*foo3)(), void(*foo4)(), void(*foo5)())
{

	int choose;

	std::cout << " | ��� �����: ";

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

	std::cout << "�� ������ 0" << std::endl;

}

/*




user accounts





*/

/*



data



*/

// ����� �� ���� ��������.

void search_by_bus_type()
{

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// �������� ����������

	bool isLoginExists = true;

	while (isLoginExists)
	{

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(68) << "����� ������ �� ���� ��������" << std::setfill(' ') << std::setw(39) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������� ��� ��������: ";

		std::cin >> temp_bus_type;

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(90) << "�������� ���� ������" << std::setfill(' ') << std::setw(68) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(141) << "|                ������" << std::setfill(' ') << std::setw(17) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(11) << " # ����� | " << std::setw(15) << std::left << "��� �������� | " << std::setw(19) << std::left << "����� ���������� | " << std::setw(19) << std::left << "���� ����������� | " << std::setw(20) << std::left << "����� ����������� | " << std::setw(17) << std::left << "����� �������� | " << std::setw(19) << std::left << "��������� ������ | " << std::setw(20) << std::left << "���-�� ���������� | " << std::setw(19) << std::left << "���-�� ��������� |" << std::endl;

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

// ����� �� ������ ����������.

void search_by_destination()
{

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// �������� ����������

	bool isLoginExists = true;

	while (isLoginExists)
	{



		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(68) << "����� ������ �� ������ ����������" << std::setfill(' ') << std::setw(39) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������� ����� ����������: ";

		std::cin >> temp_destination;

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(90) << "�������� ���� ������" << std::setfill(' ') << std::setw(68) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(141) << "|                ������" << std::setfill(' ') << std::setw(17) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(11) << " # ����� | " << std::setw(15) << std::left << "��� �������� | " << std::setw(19) << std::left << "����� ���������� | " << std::setw(19) << std::left << "���� ����������� | " << std::setw(20) << std::left << "����� ����������� | " << std::setw(17) << std::left << "����� �������� | " << std::setw(19) << std::left << "��������� ������ | " << std::setw(20) << std::left << "���-�� ���������� | " << std::setw(19) << std::left << "���-�� ��������� |" << std::endl;

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

// ����� �� ���� �����������.

void search_by_departure_date()
{

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// �������� ����������

	bool isLoginExists = true;

	while (isLoginExists)
	{

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(68) << "����� ������ �� ���� �����������" << std::setfill(' ') << std::setw(39) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������� ���� �����������: ";

		std::cin >> temp_departure_date;

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(90) << "�������� ���� ������" << std::setfill(' ') << std::setw(68) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(141) << "|                ������" << std::setfill(' ') << std::setw(17) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(11) << " # ����� | " << std::setw(15) << std::left << "��� �������� | " << std::setw(19) << std::left << "����� ���������� | " << std::setw(19) << std::left << "���� ����������� | " << std::setw(20) << std::left << "����� ����������� | " << std::setw(17) << std::left << "����� �������� | " << std::setw(19) << std::left << "��������� ������ | " << std::setw(20) << std::left << "���-�� ���������� | " << std::setw(19) << std::left << "���-�� ��������� |" << std::endl;

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

// ���������� ��������������� �������.

void example()
{

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// �������� ����������

	bool isLoginExists = true;

	while (isLoginExists)
	{

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(60) << "������� ������" << std::setfill(' ') << std::setw(47) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ���� ������ ������ �����?: ";

		std::cin >> temp_destination;

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(90) << "�������� ���� ������" << std::setfill(' ') << std::setw(68) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(141) << "|                ������" << std::setfill(' ') << std::setw(17) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(11) << " # ����� | " << std::setw(15) << std::left << "��� �������� | " << std::setw(19) << std::left << "����� ���������� | " << std::setw(19) << std::left << "���� ����������� | " << std::setw(20) << std::left << "����� ����������� | " << std::setw(17) << std::left << "����� �������� | " << std::setw(19) << std::left << "��������� ������ | " << std::setw(20) << std::left << "���-�� ���������� | " << std::setw(19) << std::left << "���-�� ��������� |" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << std::right << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		for (int i = 0; i < v_Tickets.size(); i++)
		{

			if (v_Tickets.at(i).destination == temp_destination && v_Tickets.at(i).number_of_tickets_remaining > 0)
			{

				std::cout << std::setfill(' ') << std::setw(2) << " | " << std::setw(7) << std::right << v_Tickets.at(i).flight_number << " | " << std::setw(12) << std::left << v_Tickets.at(i).bus_type << " | " << std::setw(16) << std::left << v_Tickets.at(i).destination << " | " << std::setw(16) << std::left << v_Tickets.at(i).departure_date << " | " << std::setw(17) << std::left << v_Tickets.at(i).departure_time << " | " << std::setw(14) << std::left << v_Tickets.at(i).arrival_time << " | " << std::setw(16) << std::left << v_Tickets.at(i).ticket_price << " | " << std::setw(17) << std::right << v_Tickets.at(i).number_of_tickets_remaining << " | " << std::setw(16) << std::right << v_Tickets.at(i).number_of_tickets_sold << " | " << std::endl;


				std::cout << std::setfill(' ') << std::setw(2) << std::right << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

				std::cout << std::endl;

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(60) << "������� ������" << std::setfill(' ') << std::setw(47) << "|" << std::endl;

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

				std::cout << std::setfill(' ') << std::setw(2) << " | ������� ����: ";

				std::cin >> temp_flight_number;

				std::cout << std::endl;

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

				std::cout << std::setfill(' ') << std::setw(2) << " | ������� ���������� ������� ��� �������: ";

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

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(60) << "������ ������� �������." << std::setfill(' ') << std::setw(47) << "|" << std::endl;

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

				std::ifstream fin(TICKETS_FILE);

				// ���� ����� �� ����������.

				if (fin.is_open())
				{

					// ������� ����.

					std::ofstream fout(TICKETS_FILE);

					// ���������� ������ ��������������.

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

					// ��������� ����.

					fout.close();

				}

				// ��������� ����.

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