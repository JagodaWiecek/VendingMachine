#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "class.h"

Element::Element(Drink* D)
{
	Element::d = D;

}
Element::~Element()
{
	delete d;
}


void Element::add(Drink* D)
{
	if (next == nullptr)
	{
		Element* b = new Element(D);
		next = b;
	}
	else
	{
		next->add(D);
	}
}


Drink& Element::get(unsigned int n)
{
	if (n == 0)
		return *d;
	if (next == nullptr)
		throw;
	else
		return next->get(n - 1);
}

void Element::showAll()
{
	if (next == nullptr)
		d->print(std::cout);
	else
	{
		d->print(std::cout);
		next->showAll();
	}
}

int Element::size()
{
	if (next == nullptr)
		return 1;
	else
		return next->size() + 1;
}

void Element::erase()
{
	if (next->next == nullptr)
	{
		delete next;
		next = nullptr;
	}
	else
		next->erase();

}

void Element::save(std::ofstream& file)
{
	d->printtf(file);
	if (next == nullptr)
		file.close();

	else
		next->save(file);
}