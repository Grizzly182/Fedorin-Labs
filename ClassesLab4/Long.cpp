#include "Long.h"
#include <math.h>
#include <string>
#include <limits>

void Long::sum(Long num)
{
	int max = 0;
	Long temp = num;
	if (temp.getSecondPart() >= 0) {
		if (temp.getSecondPart() > this->getSecondPart()) {
			while (temp.getSecondPart() != std::numeric_limits<int>::max()) {
				this->setSecondPart(this->getSecondPart() - 1);
				temp.setSecondPart(temp.getSecondPart() + 1);
				std::cout << "temp " << temp.getSecondPart() << std::endl;
			}
			int remaining = this->getSecondPart();
			this->setFirstPart(this->getFirstPart() + 1);
			this->setSecondPart(remaining);
		}
		else {
			while (this->getSecondPart() != std::numeric_limits<int>::max()) {
				this->setSecondPart(this->getSecondPart() + 1);
				temp.setSecondPart(temp.getSecondPart() - 1);
				std::cout << "this " << this->getSecondPart() << std::endl;
			}
			int remaining = temp.getSecondPart();
			this->setFirstPart(this->getFirstPart() + 1);
			this->setSecondPart(remaining);
		}
	}
}
// TODO: Сначала складывать младшую часть, потом старшую
// найти способ избавиться от огромного цикла или оптимизировать его
// попробовать цикл while вместо for
//
// Цикл всегда досчитывает до максимально возможного значения, исправить.

void Long::minus(Long num)
{
}

void Long::mul(Long num)
{
}

bool Long::detectOverflow(Long num)
{
	int x = this->getSecondPart();
	int y = num.getSecondPart();
	int temp = this->getSecondPart() + num.getSecondPart();
	if (x > 0 && y > 0 && temp < 0) {
		return true;
	}
	if (x < 0 && y < 0 && temp > 0) {
		return true;
	}
	this->setSecondPart(x + y);
	return false;
}