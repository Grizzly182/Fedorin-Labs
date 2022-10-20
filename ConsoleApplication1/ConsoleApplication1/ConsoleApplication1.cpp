// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Windows.h>
#include <iostream>
#include <stack>
#include <string.h>
#include <string>
#include <cctype>
#include <queue>
#include "Meetup.h"

using namespace std;

bool IsAlphaRus(char c) {
	return (c <= 'я' && c >= 'а') || (c <= 'Я' && c >= 'А') || (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A');
}

void ShowMenu() {
	cout << "Выберите что хотите сделать:\n1)Пригласить людей\t2)Удалить "
		<< "первого в списке гостя\n3)Очистить список гостей\t4)Инфор-ия о количестве гостей\n5)Упорядочить гостей за столом"
		<< "\t6) Выход" << endl;
}

void PrintGuestsAmount(Meetup meetup) {
	cout << "Приглашено " << meetup.Size() << " гостя(-ей)" << endl;
}

void InviteRandomGuests(Meetup& meetup) {
	meetup.Push(Guest("Михаил", "Белоусов", Gender::Male));
	meetup.Push(Guest("Дарья", "Поздеева", Gender::Female));
	meetup.Push(Guest("Светлана", "Никитина", Gender::Female));
	meetup.Push(Guest("Даниил", "Заманов", Gender::Male));
	meetup.Push(Guest("Галина", "Исмагилова", Gender::Female));
	meetup.Push(Guest("Иван", "Урванцев", Gender::Male));
	meetup.Push(Guest("Даниил", "Соковнин", Gender::Male));
	meetup.Push(Guest("Матвей", "Третьяков", Gender::Male));
	meetup.Push(Guest("Андрей", "Королёв", Gender::Male));
}

void InviteTo(Meetup &meetup) {
	bool Break = false;
	bool isOk = false;
	cout << "Введите имя и фамилию того, кого хотите пригласить.(Введите \'0\' для отмены)\n";

	cout << "Имя: ";
	string name;
	do {
		isOk = true;
		cin >> name;
		if (name == "0") {
			return;
		}
		for (int i = 0; i < name.length(); i++) {
			if (!IsAlphaRus(name[i])) {
				isOk = false;
				cout << "Вводите буквы!" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
				break;
			}
		}
	} while (!isOk);
	if (Break) {
		return;
	}
	cout << "\nФамилия(0 для отмены): ";
	string surname;
	do {
		isOk = true;
		cin >> surname;
		if (surname == "0") {
			return;
		}
		for (int i = 0; i < surname.length(); i++) {
			if (!IsAlphaRus(surname[i])) {
				isOk = false;
				cout << "Вводите буквы!" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
				break;
			}
		}
	} while (!isOk);


	cout << "\nПол(Введите цифру):\n1) Женский\n2) Мужской\n0) Отмена" << endl;
	int gender = 3;
	do {
		isOk = true;
		cin >> gender;
		if (cin.fail() || gender > 2 || gender <=-1 || cin.peek() == '.') {
			isOk = false;
			cout << "Введите корректную цифру!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			gender = -1;
		}
		if (gender == 0) {
			return;
		}
	} while (!isOk);

	Gender _gender;
	switch (gender) {
	case 1:
		_gender = Gender::Female;
		break;
	case 2:
		_gender = Gender::Male;
		break;
	}

	Guest newGuest = Guest(name, surname, _gender);
	meetup.Push(newGuest);
}

void PrintAllGuests(Meetup meetup) {
	int i = 0;
	Meetup temp = meetup;
	while (!temp.IsEmpty()) {
		i++;
		Guest guest = temp.Top();
		string gender;
		switch (guest.gender) {
		case Gender::Female:
			gender = "Жен.";
			break;
		case Gender::Male:
			gender = "Муж.";
			break;
		}
		cout << i << ". " << guest.Name << " " << guest.Surname << "\t " << gender << endl;
		temp.Pop();
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	Meetup meetup;
	InviteRandomGuests(meetup);
	while (true) {
		system("cls");
		ShowMenu();
		bool isOk = false;
		int decision;
		do {
			isOk = true;
			cin >> decision;
			if (cin.fail() || cin.peek() == '.') {
				cout << "Ошибка ввода!" << endl;
				isOk = false;
				cin.clear();
				cin.ignore(32767, '\n');
			}
		} while (!isOk);

		if (isOk) {
			switch (decision) {
			case 1:
				InviteTo(meetup);
				break;
			case 2:
				if (!meetup.IsEmpty()) {
					meetup.Pop();
					system("pause");
					break;
				}
				else {
					cout << "Список гостей пуст." << endl;
					system("pause");
					break;
				}
			case 3:
				if (!meetup.IsEmpty()) {
					meetup.ClearStack();
					break;
				}
				else
				{
					cout << "Список гостей пуст." << endl;
					system("pause");
					break;
				}
				break;
			case 4:
				if (!meetup.IsEmpty()) {
					PrintGuestsAmount(meetup);
					cout << '\n';
					PrintAllGuests(meetup);
					system("pause");
					break;
				}
				else 
				{
					cout << "Список гостей пуст." << endl;
					system("pause");
					break;
				}
			case 5:

				break;
			case 6:
				return 0;
			}
		}
	}
}