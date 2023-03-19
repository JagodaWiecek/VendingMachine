#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <windows.h>
#include <cstring>
#include <cctype>

#include "class.h"

double Interface::GiveTotal()
{
	return total;
}
double Interface::UpdateTotal(const double& money)
{
	Cash c;
	c.SetMoney(money);
	if (c.Check()) {
		return total = total + money;
	}
	else
		return total;
}
double Interface::ChangeTotal(const double& money)
{
	return total = total - money;
}
double Interface::NullTotal()
{
	return total = 0;
}
Interface::Interface( std::string& info, List& l)
{
	if (info == "cup" || info == "Cup")
	{
		std::ifstream outc("CupMachine.txt");
		outc.seekg(0, outc.beg);
		std::string nd, cd;
		double p;
		int s;
		if (outc) {
			while (outc >> nd >> s >> p >> cd)
			{
				Drink* c = new CupDrinks(nd,s,p,cd);
				l.add(c);
			}
		}
		else
			std::cout << "error\n";
		outc.close();
	}
	else if (info == "bottle" || info == "Botlle")
	{
		std::ifstream outb("BottleMachine.txt");
		outb.seekg(0, outb.beg);
		std::string nd, cd;
		double p;
		int a;
		if (outb) {
			while (outb >> nd >> a >> p >> cd)
			{
				Drink* b = new BottleDrinks(nd, a, p, cd);
				l.add(b);
			}
		}
		else
			std::cout << "error\n";
		outb.close();
	}
	else
		exit(0);
}

void Interface::show(List& l)
{
	system("cls");
	l.get(1).showDrink();
	l.showAll();
	std::cout << "|   Total:\t" << GiveTotal() << "\t\t\t\t\t|\n";
}
bool Interface::doublecheck(std::string str)
{
	int p=0;
	for (int i=0;i<str.length();i++)
	{
		if (str[i] == 46 && p == 0 && i != 0) 
		{
			p++;
			continue;
		}
		else if (str[i] < 48 || str[i]>57)
			return false;
	}
	return true;
	
}

void Interface::TestCode(List& l, int& indx, std::string code,bool& what)
{
	for (int i = 0; i < l.size(); i++)
	{
		if (code == l.get(i).GetCode())
		{
			indx = i;
			what = true;
			break;
		}
		else
			what = false;
	}
	
}
void Interface::TestTotal(List& l, int& indx, bool& what)
{
	if (GiveTotal() >= l.get(indx).GetPrice())
	{
		what = true;
	}
	else
		what = false;
}
void Interface::MakeChange(List& l)
{
	for (int i = 0 ; i < 3; i++)
	{
		Interface::show(l);
		std::cout << "Please, wait for your change.\n";
		Sleep(1000);
		Interface::show(l);
		std::cout << "Please, wait for your change..\n";
		Sleep(1000);
		Interface::show(l);
		std::cout << "Please, wait for your change...\n";
		Sleep(1000);
	}
	Interface::NullTotal();
	Interface::show(l);
}
void Interface::GiveProduct(List& l,int indx)
{
	for (int i = 0; i < 4; i++)
	{
		Interface::show(l);
		std::cout << "Hold, please. \n";
		Sleep(1000);
		Interface::show(l);
		std::cout << "Hold, please.. \n";
		Sleep(1000);
		Interface::show(l);
		std::cout << "Hold, please... \n";
		Sleep(1000);
	}
	l.get(indx).UpdateSA();
	Interface::ChangeTotal(l.get(indx).GetPrice());
	Interface::show(l);
	Sleep(2000);
}
void Interface::End(std::string& str,List& l)
{
	if (str=="yes"||str=="Yes"||str=="YES")
	{
		if (Interface::GiveTotal() != 0) {
			Interface::MakeChange(l);
			Sleep(2000);
			system("CLS");
		}
		system("CLS");
		std::string save;
		std::cout << "Where do you want to save it? : ";
		std::cin >> save;
		std::ofstream file(save);
		l.save(file);
		system("CLS");
		std::cout << "Thank you, call again!! :D \n\n ";
		
		int d = l.size();
		for (int i = 0; i < d; i++)
		{
			l.erase();
		}
		file.close();
		exit(0);
	}
	else if (str == "end")
	{
		system("CLS");
		std::cout << "Thank you, call again!! :D \n\n ";

		int d = l.size();
		for (int i = 0; i < d; i++)
		{
			l.erase();
		}
		exit(0);
	}
}
void Interface::deposit(List& l)
{
	std::cout << "Deposite coin: ";
	std::string money;
	std::cin >> money;
	Interface::End(money,l);
	while(Interface::doublecheck(money))
	{
		double coin = std::stod(money);
		Sleep(2000);
		UpdateTotal(coin);
		Interface::show(l);
		std::cout << "Deposite coin: ";
		std::cin >> money;
		Interface::End(money,l);

	}
	Interface::show(l);
}
void Interface::Finish(List& l, int& indx)
{
	Interface::GiveProduct(l, indx);
	std::string answer,save;
	std::cout << "Do you want to finish? ";
	std::cin >> answer;

	Interface::show(l);
	Interface::End(answer,l);
	Interface::enterCode(l);
}

void Interface::enterCode(List& l)
{
	Interface::deposit(l);
	std::string code;
	int indx=0;
	bool what=true;
	std::cout << "enter a code: ";
	std::cin >> code;
	Interface::End(code,l);
	Interface::TestCode(l, indx, code, what);
	while (!what)
	{
		std::cout << "There is no drink with that code\nEntre an other code: ";
		std::cin >> code;
		Interface::End(code,l);
		Interface::TestCode(l, indx, code, what);
		Interface::show(l);
	}
	while (!l.get(indx).CheckAS() || !what) 
	{
		std::cout << "There is not enought drink in a machine\nEntre an other code: ";
		std::cin >> code;
		Interface::End(code,l);
		Interface::TestCode(l, indx, code, what);
		Interface::show(l);
	}
	bool what1=true;
	Interface::TestTotal(l, indx, what1);
	while (!what1)
	{
		std::cout << "Not enought money in a machine\nDeposite more coins: ";
		Interface::deposit(l);
		Interface::TestTotal(l, indx, what1);
		Interface::show(l);
	}
	
	Interface::Finish(l, indx);
	
	
}
