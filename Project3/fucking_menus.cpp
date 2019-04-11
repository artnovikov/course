
#include "all_shit_in_one.h"

// ���� "������ ��������������".

void show_admin_module_menu()
{

	std::cout << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << " |+--- ������ �������������� " << std::setfill(' ') << std::setw(80) << "|" << std::endl;

	std::cout << " |   +--- 1) ���������� �������� �������� ������������� " << std::setfill(' ') << std::setw(53) << "|" << std::endl;

	std::cout << " |   +--- 2) ������ � ������� " << std::setfill(' ') << std::setw(79) << "|" << std::endl;

	std::cout << " |   +--- 0) ����� " << std::setfill(' ') << std::setw(90) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	func_switch(3, func_zero, show_user_account_management_menu, show_work_with_data_menu);

}

// ���� "������ ��������������" => "���������� �������� �������� �������������".

void show_user_account_management_menu()
{

	std::cout << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << " |+--- ������ �������������� " << std::setfill(' ') << std::setw(80) << "|" << std::endl;

	std::cout << " |   +--- ���������� �������� �������� ������������� " << std::setfill(' ') << std::setw(56) << "|" << std::endl;

	std::cout << " |      +--- 1) �������� ���� ������� ������� " << std::setfill(' ') << std::setw(63) << "|" << std::endl;

	std::cout << " |      +--- 2) ���������� ����� ������� ������ " << std::setfill(' ') << std::setw(61) << "|" << std::endl;

	std::cout << " |      +--- 3) �������������� ������� ������ " << std::setfill(' ') << std::setw(63) << "|" << std::endl;

	std::cout << " |      +--- 4) �������� ������� ������ " << std::setfill(' ') << std::setw(69) << "|" << std::endl;

	std::cout << " |      +--- 0) ����� " << std::setfill(' ') << std::setw(87) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	func_switch(5, show_admin_module_menu, show_all_accounts, add_new_account, edit_account, delete_account);

}

// ���� "������ ��������������" => "������ � �������".

void show_work_with_data_menu()
{

	std::cout << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << " |+--- ������ �������������� " << std::setfill(' ') << std::setw(80) << "|" << std::endl;

	std::cout << " |   +--- ������ � ������� " << std::setfill(' ') << std::setw(82) << "|" << std::endl;

	std::cout << " |      +--- 1) ����� �������������� " << std::setfill(' ') << std::setw(72) << "|" << std::endl;

	std::cout << " |      +--- 2) ����� ��������� ������ " << std::setfill(' ') << std::setw(70) << "|" << std::endl;

	std::cout << " |      +--- 0) ����� " << std::setfill(' ') << std::setw(87) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	func_switch(3, show_admin_module_menu, show_edit_mode_menu, show_data_processing_mode);

}

// ���� "������ ��������������" => "������ � �������" => "����� ��������������".

void show_edit_mode_menu()
{

	std::cout << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << " |+--- ������ �������������� " << std::setfill(' ') << std::setw(80) << "|" << std::endl;

	std::cout << " |   +--- ������ � ������� " << std::setfill(' ') << std::setw(82) << "|" << std::endl;

	std::cout << " |      +--- ����� �������������� " << std::setfill(' ') << std::setw(75) << "|" << std::endl;

	std::cout << " |         +--- 1) �������� ���� ������ " << std::setfill(' ') << std::setw(69) << "|" << std::endl;

	std::cout << " |         +--- 2) ���������� ����� ������ " << std::setfill(' ') << std::setw(66) << "|" << std::endl;

	std::cout << " |         +--- 3) �������������� ������ " << std::setfill(' ') << std::setw(68) << "|" << std::endl;

	std::cout << " |         +--- 4) �������� ������ " << std::setfill(' ') << std::setw(74) << "|" << std::endl;

	std::cout << " |         +--- 0) ����� " << std::setfill(' ') << std::setw(84) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	func_switch(5, show_work_with_data_menu, show_all_data, add_new_data, edit_data, delete_data);

}

// ���� "������ ��������������" => "������ � �������" => "����� ��������� ������".

void show_data_processing_mode()
{

	std::cout << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << " |+--- ������ �������������� " << std::setfill(' ') << std::setw(80) << "|" << std::endl;

	std::cout << " |   +--- ������ � ������� " << std::setfill(' ') << std::setw(82) << "|" << std::endl;

	std::cout << " |      +--- ����� ��������� ������ " << std::setfill(' ') << std::setw(73) << "|" << std::endl;

	std::cout << " |         +--- 1) ���������� ��������������� ������� " << std::setfill(' ') << std::setw(55) << "|" << std::endl;

	std::cout << " |         +--- 2) ����� ������ " << std::setfill(' ') << std::setw(77) << "|" << std::endl;

	std::cout << " |         +--- 3) ���������� " << std::setfill(' ') << std::setw(79) << "|" << std::endl;

	std::cout << " |         +--- 0) ����� " << std::setfill(' ') << std::setw(84) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	func_switch(4, show_work_with_data_menu, example, show_search_data_menu, show_data_processing_mode); // ������!!!

}

// ���� "����� ������".

void show_search_data_menu()
{

	std::cout << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << " |+--- ����� ������ �� " << std::setfill(' ') << std::setw(86) << "|" << std::endl;

	std::cout << " |   +--- 1) ���� �������� " << std::setfill(' ') << std::setw(82) << "|" << std::endl;

	std::cout << " |   +--- 2) ������ ���������� " << std::setfill(' ') << std::setw(78) << "|" << std::endl;

	std::cout << " |   +--- 3) ���� ����������� " << std::setfill(' ') << std::setw(79) << "|" << std::endl;

	std::cout << " |   +--- 0) ����� " << std::setfill(' ') << std::setw(90) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	func_switch(4, show_data_processing_mode, search_by_bus_type, search_by_destination, search_by_departure_date);

}

// ���� "������ ������������". ��� �� �����??? ������� �� ������� show_data_processing_mode!!!

void show_user_module_menu()
{

	std::cout << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << " |+--- ������ ������������ " << std::setfill(' ') << std::setw(82) << "|" << std::endl;

	std::cout << " |   +--- 1) �������� ���� ������ " << std::setfill(' ') << std::setw(75) << "|" << std::endl;

	std::cout << " |   +--- 2) ���������� ��������������� ������� " << std::setfill(' ') << std::setw(61) << "|" << std::endl;

	std::cout << " |   +--- 3) ����� ������ " << std::setfill(' ') << std::setw(83) << "|" << std::endl;

	std::cout << " |   +--- 4) ���������� " << std::setfill(' ') << std::setw(85) << "|" << std::endl;

	std::cout << " |   +--- 0) ����� " << std::setfill(' ') << std::setw(90) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	func_switch(4, func_zero, show_all_data, example, show_search_data_menu, show_user_module_menu); //	������!!!

}

// ���� "������ ��������������" => "������ � �������" => "����� ��������������" => "�������������� ������".

void show_edit_menu()
{

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << " | �������� ��� ��������:" << std::setfill(' ') << std::setw(84) << "|" << std::endl;

	std::cout << " | 1) ����� �����" << std::setfill(' ') << std::setw(92) << "|" << std::endl;

	std::cout << " | 2) ��� ��������" << std::setfill(' ') << std::setw(91) << "|" << std::endl;

	std::cout << " | 3) ����� ����������" << std::setfill(' ') << std::setw(87) << "|" << std::endl;

	std::cout << " | 4) ���� �����������" << std::setfill(' ') << std::setw(87) << "|" << std::endl;

	std::cout << " | 5) ����� �����������" << std::setfill(' ') << std::setw(86) << "|" << std::endl;

	std::cout << " | 6) ����� ��������" << std::setfill(' ') << std::setw(89) << "|" << std::endl;

	std::cout << " | 7) ��������� ������" << std::setfill(' ') << std::setw(87) << "|" << std::endl;

	std::cout << " | 8) ���������� ���������� �������" << std::setfill(' ') << std::setw(74) << "|" << std::endl;

	std::cout << " | 9) ���������� ��������� �������" << std::setfill(' ') << std::setw(75) << "|" << std::endl;

	std::cout << " | 0) �����" << std::setfill(' ') << std::setw(98) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

}