#include "Database.h"
#include "Environment.h"
#include "LoggerSingleton.h"
#include "Student.h"
#include "Teacher.h"
#include <vector>

int main()
{
	Database database("MSSQLSERVER_CONN_STRING");
	std::println("Status BD: {}", database.getIsConnected());

	return 0;
}