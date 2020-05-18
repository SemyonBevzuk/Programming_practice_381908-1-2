#include "TicketOffice.h"

int main()
{
	SetConsoleCP(1251); //Установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); //В поток вывода
	vector<Cinema> film1; //Вектор, хранит данные о сеансах
	//Добавляем сеансы
	film1.push_back(Cinema(13, 05, 2020, 8, 00, "Побег из Шоушенка", 1, 300));
	film1.push_back(Cinema(13, 05, 2020, 13, 15, "Темный рыцарь", 1, 300));
	film1.push_back(Cinema(13, 05, 2020, 18, 00, "Тор", 1, 300));

	film1.push_back(Cinema(16, 05, 2020, 8, 00, "Брат", 2, 400));
	film1.push_back(Cinema(16, 05, 2020, 12, 00, "Жмурки", 2, 400));
	film1.push_back(Cinema(16, 05, 2020, 18, 00, "Хроники Нарнии", 2, 400));

	TicketOffice t1(film1); //Передаем вектор в класс кассы
	Date w1(13, 5, 2020, 13, 20); //Устанавливаем дату

	int menu, t;
	int day, month;
	int quantity;
	vector<string> temp, temp_ticket;
	string name_temp, zone;

	while (1)
	{
		cout << endl;
		cout << "1. Узнать сеансы" << endl;
		cout << "2. Купить билеты" << endl;
		cout << "3. Узнать наличие мест" << endl;
		cout << "4. Зарезервировать места" << endl;
		cout << "5. Отменить покупку билетов" << endl;
		cout << "6. Сформировать билеты" << endl;
		cout << endl << "Выберите операцию: ";

		cin >> menu;

		switch (menu)
		{
		case 1:
			temp = t1.Print(); //Вывод всех сеансов
			for (int i = 0; i < temp.size(); i++)
			{
				cout << endl << temp[i] << endl;
			}
			break;
		case 2:
			cout << endl << "Введите дату(день месяц):";
			cin >> day >> month;
			cin.get();
			cout << endl << "Введите название фильма: ";
			getline(cin, name_temp);
			cout << endl << "Введите количество билетов: ";
			cin >> quantity;
			cout << endl << "Введите зону: (base/vip): ";
			cin >> zone;

			t = t1.Buy(day, month, name_temp, quantity, zone, w1); //Покупка

			if (t == 0)
			{
				cout << endl << "Мест нет, либо срок продажи истек или еще не наступил.";
			}
			else if (t != 0)
			{
				cout << endl << "Билеты заказаны, к оплате - " << t;
			}
			break;
		case 3:
			cout << endl << "Введите дату(день месяц):";
			cin >> day >> month;
			cin.get();
			cout << endl << "Введите название фильма: ";
			getline(cin, name_temp);

			t = t1.FindPlaces(day, month, name_temp); //Свободные места
			cout << endl << "Мест свободно: " << t;
			break;
		case 4:
			cout << endl << "Введите дату(день месяц):";
			cin >> day >> month;
			cin.get();
			cout << endl << "Введите название фильма: ";
			getline(cin, name_temp);
			cout << endl << "Введите количество билетов: ";
			cin >> quantity;
			cout << endl << "Введите зону: (base/vip): ";
			cin >> zone;

			t = t1.Reservation(day, month, name_temp, quantity, zone); //Резерв

			if (t == 0)
			{
				cout << endl << "Мест нет.";
			}
			else if (t == 1)
			{
				cout << endl << "Билеты забронированы.";
			}
			break;
		case 5:
			cout << endl << "Введите дату(день месяц):";
			cin >> day >> month;
			cin.get();
			cout << endl << "Введите название фильма: ";
			getline(cin, name_temp);
			cout << endl << "Введите количество билетов для отмены: ";
			cin >> quantity;

			t = t1.Cancel(day, month, name_temp, quantity); //Отмена
			if (t == 0)
			{
				cout << endl << "Столько купленых мест нет.";
			}
			else if (t == 1)
			{
				cout << endl << "Покупка отменена.";
			}

			break;
		case 6:
			cout << endl << "Введите дату(день месяц):";
			cin >> day >> month;
			cin.get();
			cout << endl << "Введите название фильма: ";
			getline(cin, name_temp);

			temp_ticket = t1.CreateTicket(day, month, name_temp); //Формирование
			for (int i = 0; i < temp_ticket.size(); i++)
			{
				cout << endl << temp_ticket[i];
			}
			break;
		}
	}
	return 0;
}