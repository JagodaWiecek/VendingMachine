#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "class.h"


void Drink::SetName(const std::string& name)
{
	Drink::drink_name = name;
}
void Drink::SetPrice(const double& price)
{
	Drink::price = price;
}
std::string Drink::GetName()
{
	return Drink::drink_name;
}

double Drink::GetPrice()
{
	return Drink::price;
}
void Drink::SetCode(const std::string& code)
{
	Drink::code = code;
}
std::string Drink::GetCode()
{
	return Drink::code;
}
std::ostream& operator<<(std::ostream& out, Drink& d) {
	out << d.GetName() << " " << d.GetPrice() << " " << d.GetCode() << "\n";
	return out;
}
void Drink::print(std::ostream& out)
{
	out << GetName() << "  " <<GetPrice() << "\t" <<GetCode() << "\n";
}
void Drink::printtf(std::ostream& out)
{
	out << GetName() << "  " << GetPrice() << "\t" << GetCode() << "\n";
}
void Drink::showDrink()
{
	std::cout << "|\tDrinkName: \t" << "price:\t" << " Code:\t\t| \n";
	std::cout << "|\t\t\t\t\t\t|\n";
}
Drink::Drink()
{
	
}
Drink::~Drink()
{
}


