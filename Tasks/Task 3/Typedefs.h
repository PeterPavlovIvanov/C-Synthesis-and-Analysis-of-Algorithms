#pragma once

#include "Structures.h"

#include "afxtempl.h"

/// <summary>typedef-ове за градове</summary>
typedef CTypedPtrArray<CPtrArray, CITIES*> CCitiesArray;

/// <summary>typedef-ове за типове на телефон</summary>
typedef CTypedPtrArray<CPtrArray, PHONE_TYPES*> CPhone_TypesArray;

/// <summary>typedef-ове за абонати</summary>
typedef CTypedPtrArray<CPtrArray, PERSONS*> CPersonsArray;

/// <summary>typedef-ове за телефонни номера</summary>
typedef CTypedPtrArray<CPtrArray, PHONE_NUMBERS*> CPhone_NumbersArray;

/// <summary>typedef за мап от ID на абонати и съответните градове от който са</summary>
typedef CMap<int, int, CITIES, CITIES> CPersonsCitiesMap;

/// <summary> typedef за мап от ID на телефонен номер и телефонен номер</summary>
typedef CMap<int, int, PHONE_NUMBERS, PHONE_NUMBERS> CPhone_NumbersMap;