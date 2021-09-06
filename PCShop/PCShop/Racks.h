#pragma once
#include <atlstr.h>

struct RACKS
{
	long	ID;
	TCHAR	rackName[256];

	RACKS()
	{
		SecureZeroMemory(this, sizeof(*this));
	};
};