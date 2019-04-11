
#include "all_shit_in_one.h"

// �������� ���� ������� �������.

void show_all_accounts()
{

	std::cout << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(68) << "�������� ���� ������� �������" << std::setfill(' ') << std::setw(39) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(8) << " ID# | " << std::setw(13) << std::left << "�����" << std::setw(85) << std::left << "| ������" << "|" << std::endl;

	for (int i = 0; i < v_Auth.size(); i++)
	{

		std::cout << std::setfill(' ') << std::setw(2) << std::right << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(5) << i + 1 << " | " << std::setw(12) << std::left << v_Auth.at(i).login << " | " << std::setw(82) << std::left << v_Auth.at(i).password << " |" << std::endl;

	}

	std::cout << std::setfill(' ') << std::setw(2) << std::right << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

	show_user_account_management_menu();

}

// ���������� ����� ������� ������.

void add_new_account()
{

	bool isLoginExists = true;

	while (isLoginExists)
	{

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(68) << "���������� ����� ������� ������" << std::setfill(' ') << std::setw(39) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������� �����: ";

		std::cin >> temp_user_login;

		for (int i = 0; i < v_Auth.size(); i++)
		{

			if (v_Auth.at(i).login == temp_user_login)
			{

				show_message("login already exists");

				isLoginExists = true;

			}
			else
			{

				isLoginExists = false;

			}

		}

		if (!isLoginExists)
		{

			std::cout << std::setfill(' ') << std::setw(2) << " | ������� ������: ";

			std::cin >> temp_user_password;

			v_Auth.push_back(s_Auth);

			v_Auth.at(v_Auth.size() - 1).login = temp_user_login;

			v_Auth.at(v_Auth.size() - 1).password = temp_user_password;

			// ������� ����. ���������� ����. �� �������� �� ������������� �����.

			std::ofstream fout(AUTH_FILE, std::ios::app);

			// ���������� ������ ������ ������������.

			fout << std::endl << temp_user_login << " " << temp_user_password << " " << 0;

			// ��������� ����.

			fout.close();

			show_message("created new account");

		}

		show_user_account_management_menu();

	}

}

// �������������� ������� ������.

void edit_account()
{

	// �������� ����������

	bool isLoginExists = true;

	int choose;

	while (isLoginExists)
	{

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(68) << "�������������� ������� ������" << std::setfill(' ') << std::setw(39) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������� �����: ";

		std::cin >> temp_user_login;

		for (int i = 0; i < v_Auth.size(); i++)
		{

			if (v_Auth.at(i).login == temp_user_login)
			{

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

				std::cout << " | �������� ��� ��������:" << std::setfill(' ') << std::setw(84) << "|" << std::endl;

				std::cout << " | 1) �����" << std::setfill(' ') << std::setw(98) << "|" << std::endl;

				std::cout << " | 2) ������" << std::setfill(' ') << std::setw(97) << "|" << std::endl;

				std::cout << " | 0) �����" << std::setfill(' ') << std::setw(98) << "|" << std::endl;

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

				std::cout << " | ��� �����: ";

				std::cin >> choose;

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

				switch (choose)
				{
				case 0:

					show_admin_module_menu();

					break;

				case 1:

					std::cout << " | ������� ����� �����: ";

					std::cin >> temp_user_login;

					v_Auth.at(i).login = temp_user_login;

					break;

				case 2:

					std::cout << " | ������� ����� ������: ";

					std::cin >> temp_user_password;

					v_Auth.at(i).password = temp_user_password;

					break;

				default:

					show_admin_module_menu();

					break;

				}

				write_data_to_file("edit account");

				show_message("upgraded account");

				isLoginExists = true;

			}
			else
			{

				isLoginExists = false;

			}

		}

		if (!isLoginExists)
		{

			show_message("account 404");

		}

		show_user_account_management_menu();

	}

}

// �������� ������� ������.

void delete_account()
{

	// �������� ����������

	bool isLoginExists = true;

	while (isLoginExists)
	{

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(68) << "�������� ������� ������" << std::setfill(' ') << std::setw(39) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������� �����: ";

		std::cin >> temp_user_login;

		for (int i = 0; i < v_Auth.size(); i++)
		{

			if (v_Auth.at(i).login == temp_user_login)
			{

				v_Auth.erase(v_Auth.begin() + i);

				write_data_to_file("delete account");

				show_message("account deleted");

				isLoginExists = true;

			}
			else
			{

				isLoginExists = false;

			}

		}

		if (!isLoginExists)
		{

			show_message("account 404");

		}

		show_user_account_management_menu();

	}

}
