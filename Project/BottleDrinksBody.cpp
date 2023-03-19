#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "class.h"


void BottleDrinks::SetAmount(const int& amount)
{
	BottleDrinks::amount = amount;
}
int BottleDrinks::GetAmount()
{
	return BottleDrinks::amount;
}
std::ostream& operator<<(std::ostream& out, BottleDrinks& d) {
	out << d.GetName() << " " << d.GetPrice() << " " << d.GetCode() <<" " << d.GetAmount() << "\n";
	return out;
} 
std::fstream& operator<<(std::fstream& out, BottleDrinks& d) {
	out << d.GetName() << " " << d.GetPrice() << " " << d.GetCode() << " " << d.GetAmount() << "\n";
	return out;
}

void BottleDrinks::print(std::ostream& out)
{
	out<< "|\t"<<GetName() << "    \t" << GetPrice() << "    \t " << GetAmount() << "    \t   " << GetCode() << "\t\t| \n";
}
int BottleDrinks::GetSizeOrAmount()
{
	return GetAmount();
}
int BottleDrinks::UpdateSA()
{
	if(amount>0)
		return amount = amount - 1;
	else
	{
		
		return amount;
	}
}
bool BottleDrinks::CheckAS()
{
	if (amount > 0)
		return true;
	else return false;
}
void BottleDrinks::printtf(std::ostream& out)
{
	out << "\t" << GetName() <<"  \t" << GetAmount() << "      \t" << GetPrice() << "    \t   " << GetCode() << "\n";
}
void BottleDrinks::showDrink()
{
	std::cout << "|\tDrinkName: \t" << "price:\t" << "amount:\t" << "   Code:\t|\n";
	std::cout << "|\t\t\t\t\t\t\t|\n";
}
BottleDrinks::BottleDrinks()
{

}
BottleDrinks::~BottleDrinks()
{

}
BottleDrinks::BottleDrinks(std::string name, int amount, double price, std::string code)
{
	BottleDrinks::SetName(name);
	BottleDrinks::SetAmount(amount);
	BottleDrinks::SetPrice(price);
	BottleDrinks::SetCode(code);
}


