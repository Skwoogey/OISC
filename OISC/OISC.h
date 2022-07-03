#pragma once

#include "stdafx.h"

#include "types.h"
#include "Memory.h"


class OISC
{
private:

	static enum class eCpuState
	{
		preparing,
		running,
		error,
		halted
	} state;

	static MemoryAddress InstructionPointer;
	static int cycleCounter;
	static std::unique_ptr<Memory> memory;
	static std::istream* inputStream;
	static std::ostream* outputStream;

	static MemoryValue readValue(MemoryAddress address);
	static bool writeValue(MemoryAddress address, MemoryValue value);
	static bool tick();
	
	OISC() {};

public:
	static void init(MemoryAddress size, std::istream* is = &std::cin, std::ostream* os = &std::cout);

	static bool loadProgram(std::vector<MemoryValue> data);

	static bool runN(int cycles = 1);
	static bool run();
};

