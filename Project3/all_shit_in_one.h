

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <algorithm>

// ���������� ���������.

extern const std::string AUTH_FILE;

extern const std::string TICKETS_FILE;

// ��������� ���������� ��� �����������.

extern std::string temp_user_login, temp_user_password, temp_destination, temp_bus_type, temp_departure_date, temp_departure_time, temp_arrival_time;

extern int temp_tickets_to_buy, temp_flight_number, temp_ticket_price, temp_number_of_tickets_remaining, temp_number_of_tickets_sold;

extern bool temp_for_all_stuff, isLoggedin;

// ������������� ��������.

extern struct Auth
{

	std::string login, password;

	int role;

};

extern struct Tickets
{

	std::string destination, bus_type, departure_date, departure_time, arrival_time;

	int flight_number, ticket_price, number_of_tickets_remaining, number_of_tickets_sold;

};

// ������������� ��������� ���������.

extern Auth s_Auth;

extern Tickets s_Tickets;

// ������������� ��������� �������.

extern std::vector<Auth> v_Auth;

extern std::vector<Tickets> v_Tickets;

// ������� �����������.

extern void authorization_proccess();

// ������ ������ � ������������ ����.

extern void write_data_to_file(std::string message);

// ������ ������ �� �������������� �����.

extern void read_file_data();

// ���� "������ ��������������".

extern void show_admin_module_menu();

// ���� "������ ��������������" => "���������� �������� �������� �������������".

extern void show_user_account_management_menu();

// ���� "������ ��������������" => "������ � �������".

extern void show_work_with_data_menu();

// ���� "������ ��������������" => "������ � �������" => "����� ��������������".

extern void show_edit_mode_menu();

// ���� "������ ��������������" => "������ � �������" => "����� ��������� ������".

extern void show_data_processing_mode();

// ���� "������ ��������������" => "������ � �������" => "����� ��������������" => "�������������� ������".

extern void show_edit_menu();

// ���� "����� ������".

extern void show_search_data_menu();

// ���� "������ ������������".

extern void show_user_module_menu();

// �������� ���� ������� �������.

extern void show_all_accounts();

// Switch function.

extern void func_switch(int number_of_case = 2, void(*foo0)() = NULL, void(*foo1)() = NULL, void(*foo2)() = NULL, void(*foo3)() = NULL, void(*foo4)() = NULL, void(*foo5)() = NULL);

// Zero function.

extern void func_zero();

// ���������� ����� ������� ������.

extern void add_new_account();

// �������������� ������� ������.

extern void edit_account();

// �������� ������� ������.

extern void delete_account();

// �������� ���� ������.

extern void show_all_data();

// ���������� ����� ������� ������.

extern void add_new_data();

// �������������� ������.

extern void edit_data();

// �������� ������.

extern void delete_data();

// ����� �� ���� ��������.

extern void search_by_bus_type();

// ����� �� ������ ����������.

extern void search_by_destination();

// ����� �� ���� �����������.

extern void search_by_departure_date();

// ���������� ��������������� �������.

extern void example();

// ������� ���������� ������������.

extern void show_message(std::string message);