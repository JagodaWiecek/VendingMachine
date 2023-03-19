#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "class.h"


void List::add(Drink* D)
{
	if (first == nullptr)
	{
		Element *a= new Element(D);
		first = a;
	}
	else
	{
		first->add(D);
	}
}

Drink& List::get(unsigned int n)
{
	if (first == nullptr)
		throw;
	else
		return first->get(n);
}

void List::showAll()
{
	if (first == nullptr)
		std::cout << "List is empty\n";
	else
		first->showAll();
}

int List::size()
{
	if (first == nullptr)
		return 0;
	else
		return first->size();
}

void List::erase()
{
	if (first == nullptr)
		throw;
	else if (first->next == nullptr)
	{
		delete first;
		first = nullptr;
	}
	else
		first->erase();
}

void List::save(std::ofstream& file)
{
	if (first == nullptr)
		throw;
	else
		first->save(file);
}
