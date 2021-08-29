#pragma once

#include "ConnectionProps.h"

class DBConnection
{
public:
	static DBConnection& GetInstance();

	void operator=(DBConnection const&) = delete;

	HRESULT CreateConnection();

	void CloseConnection();

	CDataSource& GetDataSource();

private:
	DBConnection(void) {}

	static DBConnection instance;

	CDataSource dataSource;
};