#pragma once
#include <atlstr.h>

struct CATEGORIES
{
	long	ID;
	TCHAR	categoryName[256];

	CATEGORIES()
	{
		SecureZeroMemory(this, sizeof(*this));
	};
};