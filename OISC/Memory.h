#pragma once

#include "stdafx.h"

#include "types.h"
#include "MemoryCell.h"

typedef std::pair<bool, MemoryValue> readResult;

class Memory
{
private:
	std::vector<MemoryCell> memoryArray;

public:
	Memory(MemoryAddress size);

	readResult readAddress(MemoryAddress address);
	bool writeAddress(MemoryAddress address, MemoryValue value);

	//bool setMemoryReadCallback(MemoryAddress address, ReadCallback callback);
	//bool setMemoryWriteCallback(MemoryAddress address, WriteCallback callback);

	//bool setMemoryPermission(MemoryAddress address, MemoryCellWritePermissions perms);

	bool loadMemory(std::vector<MemoryValue>& data);
};