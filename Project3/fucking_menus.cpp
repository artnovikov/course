
#include "all_shit_in_one.h"

// Меню "Модуль администратора".

void show_admin_module_menu()
{

	std::cout << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << " |+--- Модуль администратора " << std::setfill(' ') << std::setw(80) << "|" << std::endl;

	std::cout << " |   +--- 1) Управление учетными записями пользователей " << std::setfill(' ') << std::setw(53) << "|" << std::endl;

	std::cout << " |   +--- 2) Работа с данными " << std::setfill(' ') << std::setw(79) << "|" << std::endl;

	std::cout << " |   +--- 0) Выход " << std::setfill(' ') << std::setw(90) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	func_switch(3, func_zero, show_user_account_management_menu, show_work_with_data_menu);

}

// Меню "Модуль администратора" => "Управление учетными записями пользователей".

void show_user_account_management_menu()
{

	std::cout << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << " |+--- Модуль администратора " << std::setfill(' ') << std::setw(80) << "|" << std::endl;

	std::cout << " |   +--- Управление учетными записями пользователей " << std::setfill(' ') << std::setw(56) << "|" << std::endl;

	std::cout << " |      +--- 1) Просмотр всех учетных записей " << std::setfill(' ') << std::setw(63) << "|" << std::endl;

	std::cout << " |      +--- 2) Добавление новой учетной записи " << std::setfill(' ') << std::setw(61) << "|" << std::endl;

	std::cout << " |      +--- 3) Редактирование учетной записи " << std::setfill(' ') << std::setw(63) << "|" << std::endl;

	std::cout << " |      +--- 4) Удаление учетной записи " << std::setfill(' ') << std::setw(69) << "|" << std::endl;

	std::cout << " |      +--- 0) Назад " << std::setfill(' ') << std::setw(87) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	func_switch(5, show_admin_module_menu, show_all_accounts, add_new_account, edit_account, delete_account);

}

// Меню "Модуль администратора" => "Работа с данными".

void show_work_with_data_menu()
{

	std::cout << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << " |+--- Модуль администратора " << std::setfill(' ') << std::setw(80) << "|" << std::endl;

	std::cout << " |   +--- Работа с данными " << std::setfill(' ') << std::setw(82) << "|" << std::endl;

	std::cout << " |      +--- 1) Режим редактирования " << std::setfill(' ') << std::setw(72) << "|" << std::endl;

	std::cout << " |      +--- 2) Режим обработки данных " << std::setfill(' ') << std::setw(70) << "|" << std::endl;

	std::cout << " |      +--- 0) Назад " << std::setfill(' ') << std::setw(87) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	func_switch(3, show_admin_module_menu, show_edit_mode_menu, show_data_processing_mode);

}

// Меню "Модуль администратора" => "Работа с данными" => "Режим редактирования".

void show_edit_mode_menu()
{

	std::cout << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << " |+--- Модуль администратора " << std::setfill(' ') << std::setw(80) << "|" << std::endl;

	std::cout << " |   +--- Работа с данными " << std::setfill(' ') << std::setw(82) << "|" << std::endl;

	std::cout << " |      +--- Режим редактирования " << std::setfill(' ') << std::setw(75) << "|" << std::endl;

	std::cout << " |         +--- 1) Просмотр всех данных " << std::setfill(' ') << std::setw(69) << "|" << std::endl;

	std::cout << " |         +--- 2) Добавление новой записи " << std::setfill(' ') << std::setw(66) << "|" << std::endl;

	std::cout << " |         +--- 3) Редактирование записи " << std::setfill(' ') << std::setw(68) << "|" << std::endl;

	std::cout << " |         +--- 4) Удаление записи " << std::setfill(' ') << std::setw(74) << "|" << std::endl;

	std::cout << " |         +--- 0) Назад " << std::setfill(' ') << std::setw(84) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	func_switch(5, show_work_with_data_menu, show_all_data, add_new_data, edit_data, delete_data);

}

// Меню "Модуль администратора" => "Работа с данными" => "Режим обработки данных".

void show_data_processing_mode()
{

	std::cout << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << " |+--- Модуль администратора " << std::setfill(' ') << std::setw(80) << "|" << std::endl;

	std::cout << " |   +--- Работа с данными " << std::setfill(' ') << std::setw(82) << "|" << std::endl;

	std::cout << " |      +--- Режим обработки данных " << std::setfill(' ') << std::setw(73) << "|" << std::endl;

	std::cout << " |         +--- 1) Выполнение индивидуального задания " << std::setfill(' ') << std::setw(55) << "|" << std::endl;

	std::cout << " |         +--- 2) Поиск данных " << std::setfill(' ') << std::setw(77) << "|" << std::endl;

	std::cout << " |         +--- 3) Сортировка " << std::setfill(' ') << std::setw(79) << "|" << std::endl;

	std::cout << " |         +--- 0) Назад " << std::setfill(' ') << std::setw(84) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	func_switch(4, show_work_with_data_menu, example, show_search_data_menu, show_data_processing_mode); // ИЗМЕНИ!!!

}

// Меню "Поиск данных".

void show_search_data_menu()
{

	std::cout << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << " |+--- Поиск данных по " << std::setfill(' ') << std::setw(86) << "|" << std::endl;

	std::cout << " |   +--- 1) Типу автобуса " << std::setfill(' ') << std::setw(82) << "|" << std::endl;

	std::cout << " |   +--- 2) Пункту назначения " << std::setfill(' ') << std::setw(78) << "|" << std::endl;

	std::cout << " |   +--- 3) Дате отправления " << std::setfill(' ') << std::setw(79) << "|" << std::endl;

	std::cout << " |   +--- 0) Назад " << std::setfill(' ') << std::setw(90) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	func_switch(4, show_data_processing_mode, search_by_bus_type, search_by_destination, search_by_departure_date);

}

// Меню "Модуль пользователя". Что за хуйня??? Взгляни на функцию show_data_processing_mode!!!

void show_user_module_menu()
{

	std::cout << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << " |+--- Модуль пользователя " << std::setfill(' ') << std::setw(82) << "|" << std::endl;

	std::cout << " |   +--- 1) Просмотр всех данных " << std::setfill(' ') << std::setw(75) << "|" << std::endl;

	std::cout << " |   +--- 2) Выполнение индивидуального задания " << std::setfill(' ') << std::setw(61) << "|" << std::endl;

	std::cout << " |   +--- 3) Поиск данных " << std::setfill(' ') << std::setw(83) << "|" << std::endl;

	std::cout << " |   +--- 4) Сортировка " << std::setfill(' ') << std::setw(85) << "|" << std::endl;

	std::cout << " |   +--- 0) Выход " << std::setfill(' ') << std::setw(90) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	func_switch(4, func_zero, show_all_data, example, show_search_data_menu, show_user_module_menu); //	ИЗМЕНИ!!!

}

// Меню "Модуль администратора" => "Работа с данными" => "Режим редактирования" => "Редактирование записи".

void show_edit_menu()
{

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << " | Выберите что изменить:" << std::setfill(' ') << std::setw(84) << "|" << std::endl;

	std::cout << " | 1) Номер рейса" << std::setfill(' ') << std::setw(92) << "|" << std::endl;

	std::cout << " | 2) Тип автобуса" << std::setfill(' ') << std::setw(91) << "|" << std::endl;

	std::cout << " | 3) Пункт назначения" << std::setfill(' ') << std::setw(87) << "|" << std::endl;

	std::cout << " | 4) Дата отправления" << std::setfill(' ') << std::setw(87) << "|" << std::endl;

	std::cout << " | 5) Вреня отправления" << std::setfill(' ') << std::setw(86) << "|" << std::endl;

	std::cout << " | 6) Время прибытия" << std::setfill(' ') << std::setw(89) << "|" << std::endl;

	std::cout << " | 7) Стоимость билета" << std::setfill(' ') << std::setw(87) << "|" << std::endl;

	std::cout << " | 8) Количество оставшихся билетов" << std::setfill(' ') << std::setw(74) << "|" << std::endl;

	std::cout << " | 9) Количество проданных билетов" << std::setfill(' ') << std::setw(75) << "|" << std::endl;

	std::cout << " | 0) Назад" << std::setfill(' ') << std::setw(98) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

}