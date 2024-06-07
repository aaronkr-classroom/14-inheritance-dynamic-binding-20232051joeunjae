

#include "Core.h"
#include "grade.h"
#include "read_hw.cpp"

using namespace std;

istream& read_hw(istream& in, vector<double>& hw);

string Core::getName() const { return name; }
double Core::grade() const {
	return ::grade(midterm, final, homework);
}

istream& Core::read_common(istream& in) {
	in >> name>> midterm >> final;

	return in;
}

istream& Core::read(istream& in) {
	read_common(in);
		read_hw(in, homework);
	return in;

}
bool compare(const Core& c1, const Core& c2) {
	return c1.getName() < c2.getName();
}
bool compare_grades(const Core& c1, const Core& c2) {
	return c1.grade() < c2.grade(); //가상함수 사용
}