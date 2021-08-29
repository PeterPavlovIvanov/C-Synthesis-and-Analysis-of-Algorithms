#pragma once

///<summary>клас наследник на CTypedPtrArray - има поведение като масив от елементи, с функции за освобождаване на памет</summary>
template<typename T>
class MemoryArray : public CTypedPtrArray<CPtrArray, T*>
{
	//Constructors
public:
	MemoryArray()
	{

	}
	~MemoryArray()
	{
		DeleteAllItems();
	}

	//Methods
public:
	///<summary>Трие всички елементи в масива</summary>
	void DeleteAllItems()
	{
		for (int i = 0; i < GetCount(); i++)
		{
			delete GetAt(i);
		}
		RemoveAll();
	}

	///<summary>Трие елемент в масива по индекс</summary>
	///<param "nIndex">Индекс на елемента</param>
	void DeleteByIndex(int nIndex)
	{
		delete GetAt(nIndex);
		RemoveAt(nIndex);
	}
};