
#include "all_shit_in_one.h"

void show_message(std::string message)
{

	if (message == "login already exists")
	{

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ����� ����� ��� ����������. ��������� �������." << std::setfill(' ') << std::setw(60) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	}
	else if (message == "created new account")
	{

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ��������� ����� ������� ������." << std::setfill(' ') << std::setw(75) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	}
	else if (message == "upgraded account")
	{

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������ � ������������ ���������." << std::setfill(' ') << std::setw(74) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	}
	else if (message == "account 404")
	{

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������� ������ �� �������." << std::setfill(' ') << std::setw(80) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	}
	else if (message == "account deleted")
	{

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������." << std::setfill(' ') << std::setw(99) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	}
	else if (message == "add new data")
	{

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ��������� ����� ������." << std::setfill(' ') << std::setw(83) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	}
	else if (message == "edit data")
	{

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ���������� ������ �������." << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	}
	else if (message == "delete data")
	{

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������." << std::setfill(' ') << std::setw(99) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	}
	else if (message == "data 404")
	{

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������ �� �������." << std::setfill(' ') << std::setw(88) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	}

}