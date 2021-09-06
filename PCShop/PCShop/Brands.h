#pragma once
#include <atlstr.h>

struct BRANDS
{
	long	ID;
	TCHAR	brandName[256];

	BRANDS()
	{
		SecureZeroMemory(this, sizeof(*this));
	};
};