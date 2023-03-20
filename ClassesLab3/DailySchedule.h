#pragma once
#include <vector>
#include "DailyTerm.h"

using namespace std;
class DailySchedule {
private:
	vector <DailyTerm> terms;
	int findTermIndex(DailyTerm term);
public:
	void addTerm(DailyTerm term);
	void removeTermAt(int index);
};