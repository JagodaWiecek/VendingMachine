#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "class.h"

void CupDrinks::SetSize(const int& size)
{
	CupDrinks::size = size;
}
int CupDrinks::GetSize()
{
	return CupDrinks::size;
}
std::ostream& operator<<(std::ostream& out, CupDrinks& d) {
	out << d.GetName() << " " << d.GetPrice() << " " << d.GetCode()<< "\n";
	return out;
}
std::ofstream& operator<<(std::ofstream file, CupDrinks& d) {
	file << d.GetName() << " " << d.GetPrice() << " " << d.GetCode() << " " << d.GetSize() << "\n";
	return file;
}
void CupDrinks::print(std::ostream& out)
{
	out << "|\t" << GetName() << "   \t" << GetPrice() << "   \t " << GetCode() << " \t\t|\n";
}
void CupDrinks::printtf(std::ostream& out)
{
	out <<"  " << GetName() << " \t  " << GetSize() << "\t " << GetPrice() << "  \t " << GetCode() << " \n";
}

int CupDrinks::GetSizeOrAmount()
{
	return GetSize();
}
int CupDrinks::UpdateSA()
{
	return size = size - 250;
}
bool CupDrinks::CheckAS()
{
	if (size >= 250)
		return true;
	else
		return false;

}
void CupDrinks::showDrink()
{
	std::cout << "|\tDrinkName: \t" << "price:\t" << " Code:\t\t| \n";
	std::cout << "|\t\t\t\t\t\t|\n";
}
CupDrinks::CupDrinks()
{
	
}
CupDrinks::~CupDrinks()
{

}
CupDrinks::CupDrinks(std::string name, int size, double price, std::string code)
{
	CupDrinks::SetName(name);
	CupDrinks::SetSize(size);
	CupDrinks::SetPrice(price);
	CupDrinks::SetCode(code);
}
