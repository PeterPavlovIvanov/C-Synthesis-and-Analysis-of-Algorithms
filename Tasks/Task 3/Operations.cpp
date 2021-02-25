#include "stdafx.h"

#include "Operations.h"

void Operations::CreateCities(CCitiesArray& resultCities) 
{
	CreateCityNames();

	CreateCityRegions();

	for (int i = 0; i < 5; i++) 
	{
		CITIES* pCity = new CITIES();

		pCity->lID = i + 1;
		pCity->lUPDATE_COUNTER = 0;
		wcscpy_s(pCity->szCITY_NAME, m_oCityNames[i]);
		wcscpy_s(pCity->szREGION, m_oCityRegions[i]);

		resultCities.Add(pCity);
	}
}

void Operations::CreatePhoneTypes(CPhone_TypesArray& resultPhone_Types) 
{
	CreatePhoneTypes();

	for (int i = 0; i < 3; i++) 
	{
		PHONE_TYPES* pPhoneType = new PHONE_TYPES();

		pPhoneType->lID = i + 1;
		pPhoneType->lUPDATE_COUNTER = 0;
		wcscpy_s(pPhoneType->szPHONE_TYPE, m_oPhoneTypes[i]);

		resultPhone_Types.Add(pPhoneType);
	}
}

void Operations::CreatePersons(CPersonsArray& resultPersons) 
{
	CreatePersonsFirstNames();

	CreatePersonsMiddleNames();

	CreatePersonsLastNames();

	CreatePersonsUCNs();

	CreatePersonsAddresses();

	for (int i = 0; i < 10; i++) 
	{
		PERSONS* pPerson = new PERSONS();

		pPerson->lID = i + 1;
		pPerson->lUPDATE_COUNTER = 0;
		pPerson->lCITY_ID = rand() % 5 + 1;
		wcscpy_s(pPerson->szFIRST_NAME, m_oPersonsFirstNames[i]);
		wcscpy_s(pPerson->szMIDDLE_NAME, m_oPersonsMiddleNames[i]);
		wcscpy_s(pPerson->szLAST_NAME, m_oPersonsLastNames[i]);
		wcscpy_s(pPerson->szUCN, m_oPersonsUCNs[i]);
		wcscpy_s(pPerson->szADDRESS, m_oPersonsAddresses[i]);

		resultPersons.Add(pPerson);
	}
}

void Operations::CreatePhoneNumbers(CPhone_NumbersArray& resultNumbers) 
{
	CreatePhoneNumbers();

	for (int i = 0; i < 6; i++) 
	{
		PHONE_NUMBERS* pPhoneNumber = new PHONE_NUMBERS();

		pPhoneNumber->lID = i + 1;
		pPhoneNumber->lUPDATE_COUNTER = 0;
		pPhoneNumber->lPHONE_TYPE_ID = rand() % 3 + 1;
		pPhoneNumber->lPERSON_ID = rand() % 10 + 1;
		wcscpy_s(pPhoneNumber->szNUMBER, m_oPhoneNumbers[i]);

		resultNumbers.Add(pPhoneNumber);
	}
};

void Operations::FillPersonsCities(CPersonsCitiesMap& oResultPersonsCities, CPersonsArray& oPersons, CCitiesArray& oCities)
{
	for (int i = 0; i < oPersons.GetCount(); i++)
	{
		PERSONS recPerson = *oPersons.GetAt(i);
	
		for (int j = 0; j < oCities.GetCount(); j++)
		{
			CITIES recCity = *oCities.GetAt(j);

			if (recCity.lID == recPerson.lCITY_ID) {
				oResultPersonsCities.SetAt(recPerson.lID, recCity);
				break;
			}

		}

	}
};

void Operations::FillPhoneNumbers(CPhone_NumbersMap& oResultPhoneNumbers)
{
	CPhone_NumbersArray oPhoneNumbers;
	CreatePhoneNumbers(oPhoneNumbers);

	for (int i = 0; i < oPhoneNumbers.GetCount(); i++) 
	{
		oResultPhoneNumbers.SetAt((*oPhoneNumbers.GetAt(i)).lID, (*oPhoneNumbers.GetAt(i)));
	}
};

void Operations::CreatePhoneNumbers() 
{
	m_oPhoneNumbers.Add(CString(_T("0823413374")));
	m_oPhoneNumbers.Add(CString(_T("0822132351")));
	m_oPhoneNumbers.Add(CString(_T("0895834763")));
	m_oPhoneNumbers.Add(CString(_T("0847611524")));
	m_oPhoneNumbers.Add(CString(_T("0890565642")));
	m_oPhoneNumbers.Add(CString(_T("0875614516")));
};

void Operations::CreatePersonsAddresses() 
{
	m_oPersonsAddresses.Add(CString(_T("Street 3A2 Building 10")));
	m_oPersonsAddresses.Add(CString(_T("Street 63B4 Building 31")));
	m_oPersonsAddresses.Add(CString(_T("Street 3C2 Building 23")));
	m_oPersonsAddresses.Add(CString(_T("Street 523CA Building 71")));
	m_oPersonsAddresses.Add(CString(_T("Street 67T Building 34")));
	m_oPersonsAddresses.Add(CString(_T("Street J4K Building 7")));
	m_oPersonsAddresses.Add(CString(_T("Street 722 Building 9")));
	m_oPersonsAddresses.Add(CString(_T("Street 3G1 Building 1")));
	m_oPersonsAddresses.Add(CString(_T("Street 345 Building 12")));
	m_oPersonsAddresses.Add(CString(_T("Street 11 Building 55")));
};

void Operations::CreatePersonsUCNs() 
{
	m_oPersonsUCNs.Add(CString(_T("6534567890")));
	m_oPersonsUCNs.Add(CString(_T("9345671235")));
	m_oPersonsUCNs.Add(CString(_T("6745757967")));
	m_oPersonsUCNs.Add(CString(_T("8733253731")));
	m_oPersonsUCNs.Add(CString(_T("8735463272")));
	m_oPersonsUCNs.Add(CString(_T("7625742357")));
	m_oPersonsUCNs.Add(CString(_T("5563281249")));
	m_oPersonsUCNs.Add(CString(_T("7889253896")));
	m_oPersonsUCNs.Add(CString(_T("3457282456")));
	m_oPersonsUCNs.Add(CString(_T("7682136724")));
};

void Operations::CreatePersonsLastNames()
{
	m_oPersonsLastNames.Add(CString(_T("Pavlova")));
	m_oPersonsLastNames.Add(CString(_T("Mihailov")));
	m_oPersonsLastNames.Add(CString(_T("Petrov")));
	m_oPersonsLastNames.Add(CString(_T("Ivanova")));
	m_oPersonsLastNames.Add(CString(_T("Dimitrova")));
	m_oPersonsLastNames.Add(CString(_T("Minchev")));
	m_oPersonsLastNames.Add(CString(_T("Pavlov")));
	m_oPersonsLastNames.Add(CString(_T("Petrova")));
	m_oPersonsLastNames.Add(CString(_T("Stoqnova")));
	m_oPersonsLastNames.Add(CString(_T("Georgiev")));
};

void Operations::CreatePersonsMiddleNames() 
{
	m_oPersonsMiddleNames.Add(CString(_T("Dimitrova")));
	m_oPersonsMiddleNames.Add(CString(_T("Georgiev")));
	m_oPersonsMiddleNames.Add(CString(_T("Ivanov")));
	m_oPersonsMiddleNames.Add(CString(_T("Stoqnova")));
	m_oPersonsMiddleNames.Add(CString(_T("Petrova")));
	m_oPersonsMiddleNames.Add(CString(_T("Martinov")));
	m_oPersonsMiddleNames.Add(CString(_T("Stoqnev")));
	m_oPersonsMiddleNames.Add(CString(_T("Aleksandrova")));
	m_oPersonsMiddleNames.Add(CString(_T("Dimitrova")));
	m_oPersonsMiddleNames.Add(CString(_T("Pavlov")));
};

void Operations::CreatePersonsFirstNames() 
{
	m_oPersonsFirstNames.Add(CString(_T("Viktoria")));
	m_oPersonsFirstNames.Add(CString(_T("Aleksandar")));
	m_oPersonsFirstNames.Add(CString(_T("Georgi")));
	m_oPersonsFirstNames.Add(CString(_T("Maria")));
	m_oPersonsFirstNames.Add(CString(_T("Nikol")));
	m_oPersonsFirstNames.Add(CString(_T("Martin")));
	m_oPersonsFirstNames.Add(CString(_T("Dimitar")));
	m_oPersonsFirstNames.Add(CString(_T("Raia")));
	m_oPersonsFirstNames.Add(CString(_T("Aleksandra")));
	m_oPersonsFirstNames.Add(CString(_T("Ivan")));
};

void Operations::CreatePhoneTypes()
{
	m_oPhoneTypes.Add(CString(_T("Home")));
	m_oPhoneTypes.Add(CString(_T("Mobile")));
	m_oPhoneTypes.Add(CString(_T("Business")));
};

void Operations::CreateCityRegions()
{
	m_oCityRegions.Add(CString(_T("Sofia Central Province")));
	m_oCityRegions.Add(CString(_T("Plovdiv Province")));
	m_oCityRegions.Add(CString(_T("Varna Province")));
	m_oCityRegions.Add(CString(_T("Burgas Province")));
	m_oCityRegions.Add(CString(_T("Pleven Province")));
};

void Operations::CreateCityNames()
{
	m_oCityNames.Add(CString(_T("Sofia")));
	m_oCityNames.Add(CString(_T("Plovdiv")));
	m_oCityNames.Add(CString(_T("Varna")));
	m_oCityNames.Add(CString(_T("Burgas")));
	m_oCityNames.Add(CString(_T("Pleven")));
};