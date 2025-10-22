#pragma once

#define byte win_byte_override

#include "Environment.h"
#include "LoggerSingleton.h"
#include <Windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <iostream>

class Database
{
public:
	Database(const std::string& connStringKey);
	~Database();

private:
	void connectToDatabase();
	void disconnectDatabase();

public:
	SQLHANDLE getConnHandle() const;
	SQLHANDLE getStmtHandle() const;
	SQLHANDLE getEnvHandle() const;
	bool getIsConnected() const;
	void setStmtHandle(const SQLHANDLE& handle);


private:
	SQLHANDLE m_sqlConnHandle;
	SQLHANDLE m_sqlStmtHandle;
	SQLHANDLE m_sqlEnvHandle;
	bool m_isConnected;
	std::string m_connString;

};

