

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <algorithm>

// Глобальные константы.

extern const std::string AUTH_FILE;

extern const std::string TICKETS_FILE;

// Локальные переменные для авторизации.

extern std::string temp_user_login, temp_user_password, temp_destination, temp_bus_type, temp_departure_date, temp_departure_time, temp_arrival_time;

extern int temp_tickets_to_buy, temp_flight_number, temp_ticket_price, temp_number_of_tickets_remaining, temp_number_of_tickets_sold;

extern bool temp_for_all_stuff, isLoggedin;

// Инициализация структур.

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

// Инициализация локальной структуры.

extern Auth s_Auth;

extern Tickets s_Tickets;

// Инициализация локальной вектора.

extern std::vector<Auth> v_Auth;

extern std::vector<Tickets> v_Tickets;

// Процесс авторизации.

extern void authorization_proccess();

// Запись данных в существующий файл.

extern void write_data_to_file(std::string message);

// Чтение данных из существуеющего файла.

extern void read_file_data();

// Меню "Модуль администратора".

extern void show_admin_module_menu();

// Меню "Модуль администратора" => "Управление учетными записями пользователей".

extern void show_user_account_management_menu();

// Меню "Модуль администратора" => "Работа с данными".

extern void show_work_with_data_menu();

// Меню "Модуль администратора" => "Работа с данными" => "Режим редактирования".

extern void show_edit_mode_menu();

// Меню "Модуль администратора" => "Работа с данными" => "Режим обработки данных".

extern void show_data_processing_mode();

// Меню "Модуль администратора" => "Работа с данными" => "Режим редактирования" => "Редактирование записи".

extern void show_edit_menu();

// Меню "Поиск данных".

extern void show_search_data_menu();

// Меню "Модуль пользователя".

extern void show_user_module_menu();

// Просмотр всех учетных записей.

extern void show_all_accounts();

// Switch function.

extern void func_switch(int number_of_case = 2, void(*foo0)() = NULL, void(*foo1)() = NULL, void(*foo2)() = NULL, void(*foo3)() = NULL, void(*foo4)() = NULL, void(*foo5)() = NULL);

// Zero function.

extern void func_zero();

// Добавление новой учетной записи.

extern void add_new_account();

// Редактирование учетной записи.

extern void edit_account();

// Удаление учетной записи.

extern void delete_account();

// Просмотр всех данных.

extern void show_all_data();

// Добавление новой учетной записи.

extern void add_new_data();

// Редактирование данных.

extern void edit_data();

// Удаление данных.

extern void delete_data();

// Поиск по типу автобуса.

extern void search_by_bus_type();

// Поиск по пункту назначения.

extern void search_by_destination();

// Поиск по дате отправления.

extern void search_by_departure_date();

// Выполнение индивидуального задания.

extern void example();

// Функция оповещения пользователя.

extern void show_message(std::string message);