#include "stdafx.h"

#include "Memory.h"

Memory::Memory(MemoryAddress size)
{
    for (MemoryAddress i = 0; i < size; i++)
    {
        memoryArray.push_back(MemoryCell(i, 0));
    }
}

readResult Memory::readAddress(MemoryAddress address)
{
    if (address >= memoryArray.size())
        return readResult(true, 0);

    return readResult(true, memoryArray[address].read());
}

bool Memory::writeAddress(MemoryAddress address, MemoryValue value)
{
    if(address >= memoryArray.size())
        return false;

    return memoryArray[address].write(value);
}

//bool Memory::setMemoryReadCallback(MemoryAddress address, ReadCallback callback)
//{
//    assert(address < memoryArray.size());
//
//    return memoryArray[address].setReadCallback(callback);
//}
//
//bool Memory::setMemoryWriteCallback(MemoryAddress address, WriteCallback callback)
//{
//    assert(address < memoryArray.size());
//
//    return memoryArray[address].setWriteCallback(callback);
//}
//
//bool Memory::setMemoryPermission(MemoryAddress address, MemoryCellWritePermissions perms)
//{
//    assert(address < memoryArray.size());
//
//    return memoryArray[address].setPermission(perms);
//}

bool Memory::loadMemory(std::vector<MemoryValue>& data)
{
    if (data.size() > memoryArray.size())
        return false;

    auto memoryIterator = memoryArray.begin();
    for (auto& dataIterator : data)
    {
        memoryIterator++->setValue(dataIterator);
    }
    return true;
}
