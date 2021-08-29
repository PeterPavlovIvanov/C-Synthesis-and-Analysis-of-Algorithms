#pragma once
#include <atlstr.h>

struct SHELVES
{
	long	ID;
	TCHAR	shelfName[256];
	long	capacity;
	long	spaceTaken;
	long	rackID;
	long	productCount;

	SHELVES()
	{
		SecureZeroMemory(this, sizeof(*this));
	};
};