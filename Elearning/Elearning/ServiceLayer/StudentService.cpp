#include "StudentService.h"

StudentService::StudentService(StudentDomain& domain)
	:m_domain(domain)
{

}

double StudentService::calculateAverageMark(int studentID)
{
	if (studentID <= 0)
		return -1;
	m_domain.calculateAverageMark(studentID);
}