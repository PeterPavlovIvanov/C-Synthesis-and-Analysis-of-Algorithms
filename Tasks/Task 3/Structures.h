#pragma once
#include <afxstr.h>

#define TCHAR_SIZE 256
#define NAMES_SIZE 128
#define UCN_SIZE 32

/// <summary>
/// Структура PERSONS - запис в таблицата PERSONS (абонат)
/// </summary>
struct PERSONS 
{
	/// <summary>ID</summary>
	long lID;
	/// <summary>Брояч на промените върху дадения PERSON</summary>
	long lUPDATE_COUNTER;
	/// <summary>ID на града от който е дадения PERSON</summary>
	long lCITY_ID;
	/// <summary>Първото име на дадения PERSON</summary>
	TCHAR szFIRST_NAME[NAMES_SIZE];
	/// <summary>Презимето на дадения PERSON</summary>
	TCHAR szMIDDLE_NAME[NAMES_SIZE];
	/// <summary>Фамилията на дадения PERSON</summary>
	TCHAR szLAST_NAME[NAMES_SIZE];
	/// <summary>ЕГН на дадения PERSON</summary>
	TCHAR szUCN[UCN_SIZE];
	/// <summary>Адресът на дадения PERSON</summary>
	TCHAR szADDRESS[TCHAR_SIZE];
	/// <summary>Конструктор</summary>
	PERSONS() {
		SecureZeroMemory(this, sizeof(*this));
	};
};

/// <summary>
/// Структура CITIES - запис в таблицата CITIES (град)
/// </summary>
struct CITIES
{
	/// <summary>ID</summary>
	long lID;
	/// <summary>Брояч на промените върху даденото CITY</summary>
	long lUPDATE_COUNTER;
	/// <summary>Името на даденото CITY</summary>
	TCHAR szCITY_NAME[TCHAR_SIZE];
	/// <summary>Регионът на даденото CITY</summary>
	TCHAR szREGION[TCHAR_SIZE];
	/// <summary>Конструктор</summary>
	CITIES() {
		SecureZeroMemory(this, sizeof(*this));
	};
};

/// <summary>
/// Структура PHONE_NUMBERS - запис в таблицата PHONE_NUMBERS (номер на абонат)
/// </summary>
struct PHONE_NUMBERS 
{
	/// <summary>ID</summary>
	long lID;
	/// <summary>Брояч на промените върху дадения PHONE_NUMBER</summary>
	long lUPDATE_COUNTER;
	/// <summary>ID на PERSON(абонат) притежаващ номера</summary>
	long lPERSON_ID;
	/// <summary>ID на PHONE_TYPE - типът на телефона</summary>
	long lPHONE_TYPE_ID;
	/// <summary>Номер на абонат</summary>
	TCHAR szNUMBER[TCHAR_SIZE];
	/// <summary>Конструктор</summary>
	PHONE_NUMBERS() {
		SecureZeroMemory(this, sizeof(*this));
	};
};

/// <summary>
/// Структура PHONE_TYPES - запис в таблицата PHONE_TYPES (тип на телефон)
/// </summary>
struct PHONE_TYPES
{
	/// <summary>ID</summary>
	long lID;
	/// <summary>Брояч на промените върху дадения PHONE_TYPE</summary>
	long lUPDATE_COUNTER;
	/// <summary>Тип на телефон</summary>
	TCHAR szPHONE_TYPE[TCHAR_SIZE];
	/// <summary>Конструктор</summary>
	PHONE_TYPES()
	{
		SecureZeroMemory(this, sizeof(*this));
	};
};
