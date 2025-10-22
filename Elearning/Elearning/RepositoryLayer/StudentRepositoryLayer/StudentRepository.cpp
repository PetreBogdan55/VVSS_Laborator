#include "StudentRepository.h"

StudentRepository::StudentRepository(Database& db)
	:m_db{db}
{
}

std::optional<Student> StudentRepository::getStudentById(int id)
{
	return std::optional<Student>();
}

std::optional<std::vector<Student>> StudentRepository::getAllStudents()
{
	std::vector<Student> students;
	if (!m_db.getIsConnected()) {
		LoggerSingleton::getLoggerInstance()->log("Database is not connected",
			Logger::Level::Error);
		return std::nullopt;
	}

	SQLHANDLE stmt;
	SQLAllocHandle(SQL_HANDLE_STMT, m_db.getConnHandle(), &stmt);
	SQLRETURN ret;
	SQLWCHAR query[] = L"SELECT * FROM dbo.Student";

	ret = SQLPrepare(stmt, query, SQL_NTS);
	if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
		LoggerSingleton::getLoggerInstance()->log("Failed to prepare statement",
			Logger::Level::Error);
		return std::nullopt;
	}

	ret = SQLExecute(stmt);
	if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
		LoggerSingleton::getLoggerInstance()->log("Failed to execute statement",
			Logger::Level::Error);
		return std::nullopt;
	}

	Student student;
	SQLINTEGER id, studyYear;
	SQLWCHAR firstName[100], lastName[100], email[100],
		address[500], phone[10], matriculationNumber[10];

	while (SQLFetch(stmt) == SQL_SUCCESS) {
		SQLGetData(stmt, 1, SQL_C_SLONG, &id, 0, nullptr);
		SQLGetData(stmt, 2, SQL_C_WCHAR, firstName, sizeof(firstName), nullptr);
		SQLGetData(stmt, 3, SQL_C_WCHAR, lastName, sizeof(lastName), nullptr);
		// ...
		SQLGetData(stmt, 8, SQL_C_SLONG, &studyYear, 0, nullptr);

		student.setID(id);
		student.setFirstName(std::string(firstName, firstName + wcslen(firstName)));
		student.setLastName(std::string(lastName, lastName + wcslen(lastName)));
		// ...
		student.setStudyYear(studyYear);

		students.push_back(student);
	}

	return students;
}
