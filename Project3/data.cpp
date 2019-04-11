
#include "all_shit_in_one.h"

// �������� ���� ������.

void show_all_data()
{

	std::cout << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(90) << "�������� ���� ������" << std::setfill(' ') << std::setw(68) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(141) << "|                ������" << std::setfill(' ') << std::setw(17) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

	std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(11) << " # ����� | " << std::setw(15) << std::left << "��� �������� | " << std::setw(19) << std::left << "����� ���������� | " << std::setw(19) << std::left << "���� ����������� | " << std::setw(20) << std::left << "����� ����������� | " << std::setw(17) << std::left << "����� �������� | " << std::setw(19) << std::left << "��������� ������ | " << std::setw(20) << std::left << "���-�� ���������� | " << std::setw(19) << std::left << "���-�� ��������� |" << std::endl;

	for (int i = 0; i < v_Tickets.size(); i++)
	{

		std::cout << std::setfill(' ') << std::setw(2) << std::right << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | " << std::setw(7) << std::right << v_Tickets.at(i).flight_number << " | " << std::setw(12) << std::left << v_Tickets.at(i).bus_type << " | " << std::setw(16) << std::left << v_Tickets.at(i).destination << " | " << std::setw(16) << std::left << v_Tickets.at(i).departure_date << " | " << std::setw(17) << std::left << v_Tickets.at(i).departure_time << " | " << std::setw(14) << std::left << v_Tickets.at(i).arrival_time << " | " << std::setw(16) << std::left << v_Tickets.at(i).ticket_price << " | " << std::setw(17) << std::right << v_Tickets.at(i).number_of_tickets_remaining << " | " << std::setw(16) << std::right << v_Tickets.at(i).number_of_tickets_sold << " | " << std::endl;

	}

	std::cout << std::setfill(' ') << std::setw(2) << std::right << "|" << std::setfill('-') << std::setw(158) << "|" << std::endl;

	show_edit_mode_menu();

}

// ���������� ����� ������.

void add_new_data()
{

	bool isLoginExists = true;

	while (isLoginExists)
	{

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(68) << "���������� ����� ������" << std::setfill(' ') << std::setw(39) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������� ����� �����: ";

		std::cin >> temp_flight_number;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������� ��� ��������: ";

		std::cin >> temp_bus_type;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������� ����� ����������: ";

		std::cin >> temp_destination;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������� ���� �����������: ";

		std::cin >> temp_departure_date;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������� ����� �����������: ";

		std::cin >> temp_departure_time;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������� ����� ��������: ";

		std::cin >> temp_arrival_time;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������� ��������� ������: ";

		std::cin >> temp_ticket_price;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������� ���������� �������: ";

		std::cin >> temp_number_of_tickets_remaining;

		v_Tickets.push_back(s_Tickets);

		v_Tickets.at(v_Tickets.size() - 1).flight_number = temp_flight_number;

		v_Tickets.at(v_Tickets.size() - 1).bus_type = temp_bus_type;

		v_Tickets.at(v_Tickets.size() - 1).destination = temp_destination;

		v_Tickets.at(v_Tickets.size() - 1).departure_date = temp_departure_date;

		v_Tickets.at(v_Tickets.size() - 1).departure_time = temp_departure_time;

		v_Tickets.at(v_Tickets.size() - 1).arrival_time = temp_arrival_time;

		v_Tickets.at(v_Tickets.size() - 1).ticket_price = temp_ticket_price;

		v_Tickets.at(v_Tickets.size() - 1).number_of_tickets_remaining = temp_number_of_tickets_remaining;

		v_Tickets.at(v_Tickets.size() - 1).number_of_tickets_sold = 0;

		// ������� ����.

		std::ofstream fout(TICKETS_FILE, std::ios::app);

		// ���������� ������ ������ ������������.

		fout << std::endl << temp_flight_number << " " << temp_bus_type << " " << temp_destination << " " << temp_departure_date << " " << temp_departure_time << " " << temp_arrival_time << " " << temp_ticket_price << " " << temp_number_of_tickets_remaining << " " << 0;

		// ��������� ����.

		fout.close();

		show_message("add new data");

		show_edit_mode_menu();

	}

}

// �������������� ������.

void edit_data()
{

	// �������� ����������
	// ���������� ����� �� ��������!!!

	bool isLoginExists = true;

	int choose;

	while (isLoginExists)
	{

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(68) << "�������������� ������" << std::setfill(' ') << std::setw(39) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������� ����� �����: ";

		std::cin >> temp_flight_number;

		for (int i = 0; i < v_Tickets.size(); i++)
		{

			if (v_Tickets.at(i).flight_number == temp_flight_number)
			{

				show_edit_menu();

				std::cout << " | ��� �����: ";

				std::cin >> choose;

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

				switch (choose)
				{
				case 0:

					show_edit_mode_menu();

					break;

				case 1:

					std::cout << " | ������� ����� ����� �����: ";

					std::cin >> temp_flight_number;

					v_Tickets.at(i).flight_number = temp_flight_number;

					break;

				case 2:

					std::cout << " | ������� ����� ��� ��������: ";

					std::cin >> temp_bus_type;

					v_Tickets.at(i).bus_type = temp_bus_type;

					break;

				case 3:

					std::cout << " | ������� ����� ����� ����������: ";

					std::cin >> temp_destination;

					v_Tickets.at(i).destination = temp_destination;

					break;

				case 4:

					std::cout << " | ������� ����� ���� �����������: ";

					std::cin >> temp_departure_date;

					v_Tickets.at(i).departure_date = temp_departure_date;

					break;

				case 5:

					std::cout << " | ������� ����� ����� �����������: ";

					std::cin >> temp_departure_time;

					v_Tickets.at(i).departure_time = temp_departure_time;

					break;

				case 6:

					std::cout << " | ������� ����� ����� ��������: ";

					std::cin >> temp_arrival_time;

					v_Tickets.at(i).arrival_time = temp_arrival_time;

					break;

				case 7:

					std::cout << " | ������� ����� ��������� ������: ";

					std::cin >> temp_ticket_price;

					v_Tickets.at(i).ticket_price = temp_ticket_price;

					break;

				case 8:

					std::cout << " | ������� ����� ���������� ���������� �������: ";

					std::cin >> temp_number_of_tickets_remaining;

					v_Tickets.at(i).number_of_tickets_remaining = temp_number_of_tickets_remaining;

					break;

				case 9:

					std::cout << " | ������� ����� ���������� ��������� �������: ";

					std::cin >> temp_number_of_tickets_sold;

					v_Tickets.at(i).number_of_tickets_sold = temp_number_of_tickets_sold;

					break;

				default:

					show_edit_mode_menu();

					break;

				}

				write_data_to_file("edit data");

				show_message("edit data");

				isLoginExists = true;

			}
			else
			{

				isLoginExists = false;

			}

		}

		if (!isLoginExists)
		{

			show_message("data 404");

		}

		show_edit_mode_menu();

	}

}

// �������� ������.

void delete_data()
{

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// �������� ����������

	bool isLoginExists = true;

	while (isLoginExists)
	{

		std::cout << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') << std::setw(68) << "�������� ������" << std::setfill(' ') << std::setw(39) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

		std::cout << std::setfill(' ') << std::setw(2) << " | ������� ����� �����: ";

		std::cin >> temp_flight_number;

		for (int i = 0; i < v_Tickets.size(); i++)
		{

			if (v_Tickets.at(i).flight_number == temp_flight_number)
			{

				std::cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill('-') << std::setw(107) << "|" << std::endl;

				std::cout << std::setfill(' ') << std::setw(2) << " | �� ������������� ������ ������� ������? (��� �������� ����������!) (�� - 1/��� - 0): ";

				std::cin >> temp_for_all_stuff;

				if (temp_for_all_stuff)
				{

					v_Tickets.erase(v_Tickets.begin() + i);

					write_data_to_file("delete data");

					show_message("delete data");

					

				}
				else
				{

					show_edit_mode_menu();

				}

				isLoginExists = true;

			}
			else
			{

				isLoginExists = false;

			}

		}

		if (!isLoginExists)
		{

			show_message("data 404");

		}

		show_edit_mode_menu();

	}

}