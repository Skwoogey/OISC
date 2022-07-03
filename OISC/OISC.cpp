#include "stdafx.h"
#include "OISC.h"

OISC::eCpuState OISC::state = OISC::eCpuState::halted;
MemoryAddress OISC::InstructionPointer = 0;
int OISC::cycleCounter = 0;
std::unique_ptr<Memory> OISC::memory = nullptr;
std::istream* OISC::inputStream;
std::ostream* OISC::outputStream;

void OISC::init(MemoryAddress size, std::istream* is, std::ostream* os)
{
	memory = std::make_unique<Memory>(size);

	InstructionPointer = 0;
	cycleCounter = 0;
	inputStream = is;
	outputStream = os;
}

MemoryValue OISC::readValue(MemoryAddress address)
{
	switch(address)
	{
	case SCAN_MEMORY_ADDRESS:
	{
		// should be read as a
		char in;
		inputStream->get(in);
		return -in;
	}
	case PRINT_MEMORY_ADDRESS:
		// reading is ignored
		return 0;
	default:
	{
		auto readRes = memory->readAddress(address);
		if (!readRes.first)
		{
			state = eCpuState::error;
			return 0;
		}
		return readRes.second;
	}
	}
}

bool OISC::writeValue(MemoryAddress address, MemoryValue value)
{
	switch (address)
	{
	case SCAN_MEMORY_ADDRESS:
		// cannot be written to
		return false;
	case PRINT_MEMORY_ADDRESS:
	{
		char out = value;
		outputStream->put(-out);
		return true;
	}
	default:
		return memory->writeAddress(address, value);
	}
}

bool OISC::tick()
{
	auto ptr_a = static_cast<MemoryAddress>(readValue(InstructionPointer + 0));
	auto ptr_b = static_cast<MemoryAddress>(readValue(InstructionPointer + 1));
	auto ptr_c = static_cast<MemoryAddress>(readValue(InstructionPointer + 2));

	auto a = readValue(ptr_a);
	auto b = readValue(ptr_b);

	auto result = b - a;
	writeValue(ptr_b, result);

	if (state == eCpuState::error)
		return false;

	InstructionPointer += 3;
	if (result <= 0)
		InstructionPointer = ptr_c;

	cycleCounter++;
	return true;
}

bool OISC::loadProgram(std::vector<MemoryValue> data)
{
	InstructionPointer = 0;
	state = eCpuState::preparing;
	return memory->loadMemory(data);
}

bool OISC::runN(int cycles)
{
	if (state != eCpuState::preparing && state == eCpuState::running)
		return false;

	state = eCpuState::running;

	for (int i = 0; i < cycles; i++)
	{
		if (InstructionPointer == HALT_MEMORY_ADDRESS)
		{
			state = eCpuState::halted;
			break;
		}

		if (!tick())
		{
			state = eCpuState::error;
			return false;
		}
	}
}

bool OISC::run()
{
	if (state != eCpuState::preparing && state == eCpuState::running)
		return false;

	state = eCpuState::running;
	while (state == eCpuState::running)
	{
		if (InstructionPointer == HALT_MEMORY_ADDRESS)
		{
			state = eCpuState::halted;
			break;
		}

		if (!tick())
		{
			state = eCpuState::error;
			return false;
		}
	}
	return true;
}
