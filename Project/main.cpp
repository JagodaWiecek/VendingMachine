#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>


#include "class.h"

int main()
{
	std::string start;
	std::cin >> start;
	
	List l;
	Interface I(start,l);
	I.show(l);
	I.enterCode(l);
}