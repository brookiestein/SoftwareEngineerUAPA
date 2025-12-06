#include <algorithm>
#include <format>
#include <print>
#include <string>

#include "input.hpp"
#include "student.hpp"
#include "variadictable.hpp"

constexpr const int MAX_STUDENTS = 5;
constexpr const int MAX_QUALIFICATIONS = 3;

std::vector<Student> getStudents();
void printStudents(const std::vector<Student> &students);

int main()
{
	 std::vector<Student> students = getStudents();

	 for (Student &student : students) {
		  // Calculate this student's average.
		  double sum = 0;
		  const std::vector<double> &qualifications = student.qualifications();
		  std::for_each(qualifications.begin(), qualifications.end(), [&sum] (double qualification) {
			   sum += qualification;
		  });

		  student.setAverage(sum / qualifications.size());

		  // Determine whether this student is approved or has failed.
		  if (student.average() < 70)
			   student.setCondition(Student::CONDITION::FAILED);
		  else
			   student.setCondition(Student::CONDITION::APPROVED);
	 }

	 printStudents(students);
}

std::vector<Student> getStudents()
{
	 std::vector<Student> students;
	 Input input;

	 for (int i {}; i < MAX_STUDENTS; ++i) {
		  std::string name = input.getString(
			   std::format("Introduce el nombre del estudiante #{}", (i + 1))
		  );

		  Student student(name);
		  for (int j {}; j < MAX_QUALIFICATIONS; ++j) {
			   double qualification = 0.0;

			   // Keep iterating while the user doesn't enter a valid number.
			   while (true) {
					double q = input.getNumber(
						 std::format("Introduce la calificación #{} del estudiante {}", (j + 1), name)
					);

					if (q < 0) {
						 std::println("La calificación introducida no es válida.");
						 continue;
					}

					qualification = q;
					break;
			   }

			   student.addQualification(qualification);
		  }

		  students.push_back(student);
	 }

	 return students;
}

void printStudents(const std::vector<Student> &students)
{
	 VariadicTable<std::string, double, std::string> table({"Nombre", "Promedio", "Condición"}, 10);

	 for (const Student &student : students) {
		  table.addRow(
			   student.name(),
			   student.average(),
			   student.conditionToString(student.condition())
		  );
	 }

	 table.print(std::cout);
}
