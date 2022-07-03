#include "stdafx.h"

#include "OISC.h"

int main()
{
	MemoryAddress size = 64;
	OISC::init(size);

	std::vector<MemoryValue> hello_world =
	{
		16, ~0 - 2, 3,
		15, 0, 6,
		15, 10, 9,
		31, 16, ~0,
		31, 31, 0,
		-1, 72, 69,
		76, 76, 79,
		44, 32, 87,
		79, 82, 76,
		68, 33, 10,
		0,  0
	};

	OISC::loadProgram(hello_world);
	OISC::run();
	return 0;
}