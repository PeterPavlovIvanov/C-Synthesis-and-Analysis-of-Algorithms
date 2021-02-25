#pragma once
#include "Typedefs.h"
/// <summary>
/// Клас съдържащ операции със следните дискови структури: CITIES, PERSONS, PHONE_TYPES, PHONE_NUMBERS.
/// </summary>
class Operations
{
	//Methods...
public:
	/// <summary>Функция създаваща CArray от дискови структури (градове)</summary>
	/// <param name="resultCities">Масив в който се пълнят градовете</param>
	void CreateCities(CCitiesArray& resultCities);
	/// <summary>Функция създаваща CArray от дискови структури (телефонни типове)</summary>
	/// <param name="resultPhone_Types">Масив в който се пълнят телефонните типове</param>
	void CreatePhoneTypes(CPhone_TypesArray& resultPhone_Types);
	/// <summary>Функция създаваща CArray от дискови структури (абонати)</summary>
	/// <param name="resultPersons">Масив в който се пълнят абонатите</param>
	void CreatePersons(CPersonsArray& resultPersons);
	/// <summary>Функция създаваща CArray от дискови структури (телефонни номера)</summary>
	/// <param name="resultNumbers">Масив в който се пълнят телефонните номера</param>
	void CreatePhoneNumbers(CPhone_NumbersArray& resultNumbers);
	/// <summary>Функция създаваща CMap от дискови структури (ID на абонати и техните градове)</summary>
	/// <param name="resultPersonsCities">Мап в който се пълнят двойките резултати</param>
	void FillPersonsCities(CPersonsCitiesMap& resultPersonsCities, CPersonsArray& oPersons, CCitiesArray& oCities);
	/// <summary>Функция създаваща CMap от дискови структури (ID на телефонни номера и телефонни номера)</summary>
	/// <param name="resultPhone_numbers">Мап в който се пълнят двойките резултати</param>
	void FillPhoneNumbers(CPhone_NumbersMap& resultPhone_numbers);
private:
	/// <summary>Функция създаваща телефонни номера</summary>
	void CreatePhoneNumbers();
	/// <summary>Функция създаваща адреси</summary>
	void CreatePersonsAddresses();
	/// <summary>Функция създаваща ЕГН-та</summary>
	void CreatePersonsUCNs();
	/// <summary>Функция създаваща фамилии</summary>
	void CreatePersonsLastNames();
	/// <summary>Функция създаваща презимена</summary>
	void CreatePersonsMiddleNames();
	/// <summary>Функция създаваща имена</summary>
	void CreatePersonsFirstNames();
	/// <summary>Функция създаваща имена на телефонни типове</summary>
	void CreatePhoneTypes();
	/// <summary>Функция създаваща имена на региони</summary>
	void CreateCityRegions();
	/// <summary>Функция създаваща имена на градове</summary>
	void CreateCityNames();

	//Fields...
private:
	/// <summary>Масив от CString-ове в който се пълнят имената на градовете</summary>
	CArray<CString, CString> m_oCityNames;
	/// <summary>Масив от CString-ове в който се пълнят имената на регионите</summary>
	CArray<CString, CString> m_oCityRegions;
	/// <summary>Масив от CString-ове в който се пълнят имената на телефонните типове</summary>
	CArray<CString, CString> m_oPhoneTypes;
	/// <summary>Масив от CString-ове в който се пълнят имена</summary>
	CArray<CString, CString> m_oPersonsFirstNames;
	/// <summary>Масив от CString-ове в който се пълнят презимена</summary>
	CArray<CString, CString> m_oPersonsMiddleNames;
	/// <summary>Масив от CString-ове в който се пълнят фамили</summary>
	CArray<CString, CString> m_oPersonsLastNames;
	/// <summary>Масив от CString-ове в който се пълнят ЕГН-та</summary>
	CArray<CString, CString> m_oPersonsUCNs;
	/// <summary>Масив от CString-ове в който се пълнят адреси</summary>
	CArray<CString, CString> m_oPersonsAddresses;
	/// <summary>Масив от CString-ове в който се пълнят телефонни номера</summary>
	CArray<CString, CString> m_oPhoneNumbers;
};