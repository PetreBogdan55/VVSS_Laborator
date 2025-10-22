#include "Database.h"

#define SQL_RETURN_CODE_LEN 1000

Database::Database(const std::string& connStringKey)
	:m_isConnected{false}, m_sqlEnvHandle{NULL},
	m_sqlConnHandle{NULL}, m_sqlStmtHandle{NULL}
{
	m_connString = Environment::getInstance()
		->getValue(connStringKey);
	if (m_connString.empty())
	{
		LoggerSingleton::getLoggerInstance()
			->log("Invalid connection string",
				Logger::Level::Error);
	}
	else {
		connectToDatabase();
	}
}

Database::~Database()
{
	disconnectDatabase();
}

void Database::connectToDatabase()
{
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &m_sqlEnvHandle))
	{
		LoggerSingleton::getLoggerInstance()->log("Allocation error", Logger::Level::Error);
		disconnectDatabase();
		return;
	}

	if (SQL_SUCCESS != SQLSetEnvAttr(m_sqlEnvHandle, SQL_ATTR_ODBC_VERSION,
		(SQLPOINTER)SQL_OV_ODBC3, 0))
	{
		LoggerSingleton::getLoggerInstance()->log("Allocation error", Logger::Level::Error);
		disconnectDatabase();
		return;
	}

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, m_sqlEnvHandle,
		&m_sqlConnHandle))
	{
		LoggerSingleton::getLoggerInstance()->log("Allocation error", Logger::Level::Error);
		disconnectDatabase();
		return;
	}

	LoggerSingleton::getLoggerInstance()->
		log("Attempting connection to SQL Server...",
		Logger::Level::Info);

	const std::wstring connString(m_connString.begin(),
		m_connString.end());
	auto sql_conn_status = SQLDriverConnect(m_sqlConnHandle,
		NULL,
		(SQLWCHAR*)connString.c_str(),
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT);
	switch (sql_conn_status) {
	case SQL_SUCCESS:
		m_isConnected = true;
		LoggerSingleton::getLoggerInstance()->
			log("Successfully connected to SQL Server\n", Logger::Level::Info);
			break;
	case SQL_SUCCESS_WITH_INFO:
		m_isConnected = true;
		LoggerSingleton::getLoggerInstance()->
			log("Successfully connected to SQL Server\n", Logger::Level::Info);
			break;
	case SQL_INVALID_HANDLE:
		LoggerSingleton::getLoggerInstance()->log("Could not connect to SQL Server\n",
			Logger::Level::Error);
		disconnectDatabase();
		break;
	case SQL_ERROR:
		LoggerSingleton::getLoggerInstance()->log("Could not connect to SQL Server\n",
			Logger::Level::Error);
		disconnectDatabase();
		break;
	default:
		break;
	}
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, m_sqlConnHandle,
		&m_sqlStmtHandle))
	{
		LoggerSingleton::getLoggerInstance()->log("Allocation error", Logger::Level::Error);
		disconnectDatabase();
		return;
	}
}

void Database::disconnectDatabase()
{
	m_isConnected = false;
	SQLFreeHandle(SQL_HANDLE_STMT, m_sqlStmtHandle);
	SQLDisconnect(m_sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, m_sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, m_sqlEnvHandle);
	LoggerSingleton::getLoggerInstance()->log("Disconnected from database!",
		Logger::Level::Info);
}

SQLHANDLE Database::getConnHandle() const
{
	return m_sqlConnHandle;
}

SQLHANDLE Database::getStmtHandle() const
{
	return m_sqlStmtHandle;
}

SQLHANDLE Database::getEnvHandle() const
{
	return m_sqlEnvHandle;
}

bool Database::getIsConnected() const
{
	return m_isConnected;
}

void Database::setStmtHandle(const SQLHANDLE& handle)
{
	m_sqlStmtHandle = handle;
}
