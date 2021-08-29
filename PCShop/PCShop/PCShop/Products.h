#pragma once
#include <atlstr.h>
#include "atltime.h"

struct PRODUCTS
{
	long	 serialID;
	long	 productTypeID;
	TCHAR    registerDate[10];
	TCHAR    soldDate[10];
	TCHAR    addressDate[10];
	long	 shelfID;
	long	 rackID;

	PRODUCTS()
	{
		SecureZeroMemory(this, sizeof(*this));
	};
};