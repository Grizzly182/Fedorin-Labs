#include <iostream>
#include "Long.h"

int main()
{
	Long p = Long(5, 2);

	p.display();
	p.sum(Long(7, 20));
	p.display();
}