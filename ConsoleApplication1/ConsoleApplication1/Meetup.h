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
	Guest() {};
	Guest(string _name, Gender _gender) {
		this->Name = _name;
		this->Gender = _gender;
	}

	string Name;
	Gender Gender;
} typedef Guest;

struct Meetup {
public:
	Meetup();

	Meetup* Push(Meetup*, Guest);
	void ShowElements(Meetup*);
	bool IsEmpty();
	void Pop(Meetup**);
	void ClearStack(Meetup** p);
	int Size();
	Guest guest;
	Meetup* next;
	int size = 0;
}*begin = NULL, * t;

Meetup* Meetup::Push(Meetup* p, Guest in)
{
	Meetup* temp = new Meetup;
	temp->guest = in;
	temp->next = p;
	size++;
	return temp;
}

void Meetup::ShowElements(Meetup* p)
{
	Meetup* temp = p;
	/*
	while (temp != NULL)
	{
		string gender = "";
		Guest guest = temp->guest;
		Gender g = guest.Gender;
		switch (g) {
		case Gender::Female:
			gender = "Жен.";
			break;
		case Gender::Male:
			gender = "Муж.";
			break;
		}
		cout << gender << endl;
		temp = temp->next;
	}*/
	if (size != 0)
	{
		Meetup* temp = p;
		cout << "( ";
		while (temp->next != NULL)
		{
			cout << temp->guest.Name << ", ";
			temp = temp->next;
		}

		cout << temp->guest.Name << " )\n";
	}
}

Meetup::Meetup() {
	size = 0;
}
/*void PushELements(Stack* p, string arr[10])
{
	Stack* t = p;
	for (int i = 0; t != NULL; i++)
	{
		arr[i] = t->info;
		t = t->next;
	}
}*/

bool Meetup::IsEmpty() {
	return size == 0;
}

//TODO: Ошибка чтения памяти
void Meetup::Pop(Meetup** p) {
	while (*p != NULL && (*p)->next != NULL)
	{
		t = *p;
		*p = (*p)->next;
		delete t;
		size--;
	}
}

void OrganizeGuestsOnTable() {
	queue<Guest> temp;
	Meetup Table;
}

int Meetup::Size() {
	return size;
}

void Meetup::ClearStack(Meetup** p) {
	*p = new Meetup;
}