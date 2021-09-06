#pragma once
#include <atlstr.h>
#include "atltime.h"

struct PRODUCTS
{
	long	 serialID;
	long	 productTypeID;
	TCHAR    registerDate[100];
	TCHAR    soldDate[100];
	TCHAR    addressDate[100];
	long	 shelfID;
	long	 rackID;

	PRODUCTS()
	{
		SecureZeroMemory(this, sizeof(*this));
	};
};