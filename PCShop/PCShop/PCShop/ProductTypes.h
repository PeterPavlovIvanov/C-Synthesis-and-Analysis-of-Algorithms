#pragma once
#include <atlstr.h>

struct PRODUCT_TYPES
{
	long	ID;
	TCHAR	productName[256];
	long	productSize;
	TCHAR	description[256];
	double	price;
	long	categoryID;
	long	quantity;
	long	brandID;
	long	modelID;

	PRODUCT_TYPES()
	{
		SecureZeroMemory(this, sizeof(*this));
	};
};