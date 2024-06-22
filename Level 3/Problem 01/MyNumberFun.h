#pragma once
#include <iostream>
#include <iomanip>

namespace MyNumberFun {
	int RandomNumber(int From, int To) {
		int Random = rand() % (To - From + 1) + From;
		return Random;
	}
}
