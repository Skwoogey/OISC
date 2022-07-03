#pragma once

#include "stdafx.h"

#include "types.h"

class MemoryCell;

typedef std::function<MemoryValue(MemoryCell&, MemoryAddress, MemoryValue)> ReadCallback;
typedef std::function<bool(MemoryCell&, MemoryAddress, MemoryValue)> WriteCallback;


enum class MemoryCellWritePermissions
{
	allow,
	ignore,
	forbid
};

class MemoryCell
{
private:
	//MemoryCellWritePermissions writePermission;
	MemoryValue value = 0;
	MemoryAddress address;

	//signature
	//	bool - result to be returned by write()
	//	MemoryCell& - this MemoryCell
	// 	uint64 - address of this cell
	//	MemoryValue - value written
	//std::vector<WriteCallback> writeCallbacks;

	//signature
	//	MemoryValue - result to be returned by read()
	//	MemoryCell& - this MemoryCell
	// 	uint64 - address of this cell
	//	MemoryValue - value read
	//std::vector<ReadCallback> readCallbacks;

public:

	MemoryCell(MemoryAddress address, MemoryValue defaultValue) : address(address), value(defaultValue) {};

	MemoryValue read();
	bool write(MemoryValue newValue);
	//bool setReadCallback(ReadCallback& callback);
	//bool setWriteCallback(WriteCallback& callback);
	//bool setPermission(MemoryCellWritePermissions newPerms);

	bool setValue(MemoryValue newValue) { return this->value = newValue; };
	bool setValue() { return value; };
};

