#pragma once
#include <atlstr.h>

struct MODELS
{
	long	ID;
	TCHAR	modelName[256];
	long	brandID;

	MODELS()
	{
		SecureZeroMemory(this, sizeof(*this));
	};
};