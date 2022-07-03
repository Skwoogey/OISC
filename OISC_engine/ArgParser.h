#pragma once

#include "stdafx.h"

#include "types.h"
#include "Memory.h"

class ArgParser
{
	union Value
	{
		float f;
		int i;
		bool b;
	};

	struct ValueDesc
	{
		enum eType
		{
			Bool,
			Int,
			Float
		} type;

		Value defaultValue;
	};

	std::map<std::string, ValueDesc> argDesc;


};

