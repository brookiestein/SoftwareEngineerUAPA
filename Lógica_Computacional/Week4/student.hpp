#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>

class Student
{	 
public:
	 explicit Student(const std::string &name);

	 enum class CONDITION { APPROVED = 0, FAILED };
	 
	 void addQualification(double qualification);
	 void setAverage(double average);
	 void setCondition(CONDITION condition);
	 std::string conditionToString(CONDITION condition) const;
	 
	 std::string name() const;
	 const std::vector<double> &qualifications() const;
	 double average() const;
	 CONDITION condition() const;
private:
	 std::string m_name;
	 std::vector<double> m_qualifications;
	 int m_addedQualifications;
	 double m_average;
	 CONDITION m_condition;
};

#endif // STUDENT_HPP
