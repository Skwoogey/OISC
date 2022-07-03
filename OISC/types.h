#pragma once

#include "stdafx.h"

typedef unsigned int MemoryAddress;
typedef int MemoryValue;

const MemoryAddress PRINT_MEMORY_ADDRESS = ~0 - 2;
const MemoryAddress SCAN_MEMORY_ADDRESS = ~0 - 1;
const MemoryAddress HALT_MEMORY_ADDRESS = ~0;

const MemoryValue PRINT_MEMORY_VALUE = static_cast<MemoryValue>(PRINT_MEMORY_ADDRESS);
const MemoryValue SCAN_MEMORY_VALUE = static_cast<MemoryValue>(SCAN_MEMORY_ADDRESS);
const MemoryValue HALT_MEMORY_VALUE = static_cast<MemoryValue>(HALT_MEMORY_ADDRESS);

