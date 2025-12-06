#include "student.hpp"

Student::Student(const std::string &name)
	 : m_name(name)
	 , m_addedQualifications(0)
{
	 m_qualifications.reserve(3);
}

void Student::addQualification(double qualification)
{
	 if (++m_addedQualifications > 3)
		  return;
	 m_qualifications.push_back(qualification);
}

void Student::setAverage(double average)
{
	 m_average = average;
}

void Student::setCondition(CONDITION condition)
{
	 m_condition = condition;
}

std::string Student::conditionToString(CONDITION condition) const
{
	 switch (condition)
	 {
	 case CONDITION::APPROVED:
		  return "Aprobado";
	 case CONDITION::FAILED:
		  return "Reprobado";
	 }
}

std::string Student::name() const
{
	 return m_name;
}

const std::vector<double> &Student::qualifications() const
{
	 return m_qualifications;
}

double Student::average() const
{
	 return m_average;
}

Student::CONDITION Student::condition() const
{
	 return m_condition;
}
