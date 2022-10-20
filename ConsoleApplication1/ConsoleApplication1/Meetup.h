#pragma once
#include <iostream>
#include <string>

using namespace std;


enum Gender {
	Male,
	Female
};

struct Guest {
public:
	Guest(string _name, string _surname, Gender _gender) {
		Name = _name;
		Surname = _surname;
		gender = _gender;
	}

	string Name;
	string Surname;
	Gender gender;
} typedef Guest;

struct Meetup {
public:
	void Push(Guest guest) {
		Guests.push(guest);
	}

	bool IsEmpty() {
		return Guests.empty();
	}

	void Pop() {
		Guests.pop();
	}

	void OrganizeGuestsOnTable() {
		queue<Guest> temp = Guests;
		Meetup Table;
		Table.Push(temp.front()); //Добавляем за стол первого гостя
		while (!IsEmpty())
		{
			
		}
	}

	Guest Back() {
		return Guests.back();
	}

	Guest Top() {
		return Guests.front();
	}

	int Size() {
		return Guests.size();
	}

	void ClearStack() {
		for (int i = 0; i < Guests.size(); i++) {
			Pop();
			
		}
	}

private:
	queue<Guest> Guests;

} typedef Meetup;