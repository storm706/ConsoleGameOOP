/*
A miniature game without graphics, here you can shoot at different monsters,
kill them with different weapons and change them during the game
*/
#include "pch.h"
#include <iostream>
#include <string>
#include<Windows.h>
#include<vector>
using namespace std;

class Bomb;
class Weapon;
class pulemet;
class nagan;
class Monster
{
	friend class Weapon;
	friend class pulemet;
	friend class nagan;
	friend class Bomb;
public:
	Monster(string name, int helth)
	{
		this->helth = helth;
		this->name = name;
		count++;
	}
	void life()
	{
		if (helth > 0) {

			cout << "------------------------------------------------------------------------\n";
			cout << " Monster : " << name << " his health : " << helth << endl;
			cout << "------------------------------------------------------------------------\n";
		}
		else
		{
			cout << " Monster : " << name << " is \tKILLED : " << helth << endl;
			if (name != "")
				count--;
			name = "";
		}
		if (count == 0)
		{

			cout << "You WON !!!\n  ‡†‡†±‡†‡†‡±††‡†"; Sleep(300);
			cout << " ALL MONSTORS SLEEP ON THE"; Sleep(300);
			cout << "††‡†‡†±‡†‡†‡±†‡†±‡†" << endl;
		}
	}
	int get_count()
	{
		return count;
	}
	int get_health()
	{
		return helth;
	}
	static int count;
private:int helth; string name;
};
int Monster::count = 0;

class Weapon
{
public:
	virtual void damage(Monster&d) {}
};

class nagan :public Weapon
{
	friend class person;

public:
	void damage(Monster&d) override
	{
		char c;
		if (d.name == "DRAGON")  c = '$';
		if (d.name == "WOLF")  c = '*';
		if (d.name == "TROL")  c = '?';
		if (d.name == "LEWIY")  c = '%';

		d.helth -= 20; cout << "NAGAN "; Sleep(500);
		cout << "->>\t"; 	Sleep(200);
		cout << "	>>>\t"; Sleep(200);
		cout << "	>>>>"; Sleep(200);
		cout << "	>>>>" << c << d.name << endl;

		d.life();
	}
};

class pulemet :public nagan
{
	friend class person;
public:
	void damage(Monster&d) override
	{
		char c;
		if (d.name == "DRAGON")  c = '$';
		if (d.name == "WOLF")  c = '*';
		if (d.name == "TROL")  c = '?';
		if (d.name == "LEWIY")  c = '%';
		d.helth -= 10; cout << " MASINGUN "; Sleep(500);
		cout << "->>\t"; 	Sleep(200);
		cout << "	>>\t"; Sleep(200);
		cout << "	>>"; Sleep(200);
		cout << "	>>" << c << d.name << endl;
		d.helth -= 10; cout << "You  shoted with MASINGUN "; Sleep(500);
		cout << "->>\t"; 	Sleep(200);
		cout << "	>>\t"; Sleep(200);
		cout << "	>>"; Sleep(200);
		cout << "	>>" << c << d.name << endl;
		d.helth -= 10; cout << "You  shoted with MASINGUN "; Sleep(500);
		cout << "->>\t"; 	Sleep(200);
		cout << "	>>\t"; Sleep(200);
		cout << "	>>"; Sleep(200);
		cout << "	>>" << c << d.name << endl;

		d.life();
	}
};
class Bomb :public Weapon
{
	friend class person;

public:
	void damage(Monster&d) override
	{
		char c;
		if (d.name == "DRAGON")  c = '$';
		if (d.name == "WOLF")  c = '*';
		if (d.name == "TROL")  c = '?';
		if (d.name == "LEWIY")  c = '%';

		d.helth = 0; cout << "BAAA "; Sleep(500);
		cout << "\n->>BAAHHHHH\t"; 	Sleep(200);
		cout << "\n\n\n\n\n	>>>\t"; Sleep(200);

		cout << "	>>>>" << c << d.name << endl;

		d.life();
	}
};

class person
{
public:
	void damage(Weapon* n, Monster&d)//
	{
		int count = d.get_count();
		int hp = d.get_health();
		if (hp > 0 && count > 0)
			n->damage(d);//
		else
			cout << "This monster was kill!! \n";
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	Monster drakon("DRAGON", 150);
	Monster lewiy("LEWIY", 100);
	Monster wolk("WOLF", 80);
	Monster trol("TROL", 100);
	
	person p;
	Bomb b;
	nagan n;
	pulemet pul;
	
	Sleep(500);
	vector<string> data =
	{
		"                                         /||",
		"                                        / ||",
		"                                        \\ ||",
		"                                         \\||",
		"                                           ||",
		"           _                              /||",
		"          / \\                           / ||",
		"          \\_/                          \\ ||",
		"           |                             \\||",
		"          /|\\                             ||",
		"         / | \\                           /||",
		"        /  |  \\                         / ||",
		"          / \\                           \\ ||",
		"         /   \\                           \\||",
		"        /     \\                          /||",
		"   \\_________________/                  / ||",
		"      / \\      / \\                      \\ ||",
		"      \\_/      \\_/                       \\||",
		"------------------------------------------------"
	};
	for (auto& s : data)
	{
		cout << s << endl; Sleep(100);
	}

	cout << "\n	   WELCOME!!		 " << endl << endl;
	Sleep(3000);

	cout << "We were attacked by monsters.!!! HELP -  HELP..........	 " << endl << endl;
	Sleep(1000);
	cout << "------------------------------------------------------------------------\n";
	Sleep(1000);
	cout << "\n	You must save all people from monsters	 " << endl;
	Sleep(1500);
	cout << "\t\t\tChoose a weapon "; Sleep(200); cout << ".."; Sleep(200);  cout << "..."; Sleep(200);  cout << "...";
	Sleep(2000);
	cout << "\n\t\t\tFaster!!!	 " << endl; Sleep(200);
	char cng;
	char cng1 = ' ';
	while (wolk.count != 0 && cng1 != '0')
	{
		cng1 = 0;
		char switch_on;
		cout << "========================================================================================================" << endl;
		cout << "=>	Use NAGAN      - press numbers   :1   " << endl;
		cout << "=>	Use MASHINEGUN  - press numbers   :2" << endl;
		cout << "=>	Use BAZUKA       - press numbers :3" << endl;
		cout << "=>	Or if you want to EXIT			 - press (O)\t " << endl;
		cin >> switch_on;
		cout << "========================================================================================================" << endl;
		Weapon *wp;
		wp = &n;
		switch (switch_on)
		{
		case '1':
			cout << "NAGAN!!!\n";
			break;
		case '2':
			wp = &pul;
			cout << "MASHINEGUN!!!\n";
			break;
		case '3':
			wp = &b;
			cout << "BAZUKA!!!\n";
			break;
		case 'o':
			cng = 'n';
			break;
		}

		char switch_on1;
		while (cng1 != '0' && cng1 != '9')
		{
			Sleep(1000);
			cout << "========================================================================================================" << endl;
			Sleep(500);
			cout << "=>	Attack to >>>DRAGON(" << drakon.get_health() << ")\t-press litter :1\t   " << endl;
			cout << "=>	Attack to >>>LEWIY(" << lewiy.get_health() << ")\t\t-press litter :2\t	" << endl;
			cout << "=>	Attack to >>>WOLF(" << wolk.get_health() << ")\t\t-press litter :3\t	" << endl;
			cout << "=>	Attack to >>>TROL(" << trol.get_health() << ")\t\t-press litter :4\t	" << endl;
			cout << "=>	Change weapons			 \t- press :9 " << endl;
			cout << "=>	Or if you want to EXIT	 \t\t- press :O " << endl;
			cin >> switch_on1;
			Sleep(200);
			cout << "========================================================================================================" << endl;
			switch (switch_on1)
			{
			case '1':
				p.damage(wp, drakon);
				break;
			case '2':
				p.damage(wp, lewiy);
				break;
			case '3':
				p.damage(wp, wolk);
				break;
			case '4':
				p.damage(wp, trol);
				break;
			case '9':
				cng1 = '9';
				break;
			case '0':
				cng1 = '0';
				break;
				Sleep(500);
				cout << "========================================================================================================" << endl;
				Sleep(500);
			}
		}
	}
	if (wolk.count > 0)
	{
		cout << "\n\nYou LOSE !!!\n  ‡†‡†±‡†‡†‡±†‡†"; Sleep(300);
		cout << " ALL MONSTORS  to EAT you!!"; Sleep(300);
		cout << "‡†‡†±‡†‡†‡±†‡†±‡†" << endl;
	}
	else
	{
		cout << "\n\nYou WON !!!\n  ‡†‡†±‡†‡†‡±†‡†"; Sleep(300);
		cout << " ALL MONSTORS SLEEP ON THE"; Sleep(300);
		cout << "‡†‡†±‡†‡†‡±†‡†±‡†" << endl;
	}
}
