#include<iostream>
#include<string>
using namespace std;

class Student {
private:
	string* name;
	int* id;
	string* courses;
	static int totalStudents;

public:
	
	Student() {
		name = new string("");
		id = new int(0);
		courses = new string[3];
		totalStudents++;
	}

	
	Student(string n, int i) {
		name = new string(n);
		id = new int(i);
		courses = new string[3];
		totalStudents++;
	}

	
	Student(const Student& other) {
		name = new string(*other.name);
		id = new int(*other.id);
		courses = new string[3];
		for (int i = 0; i < 3; i++) {
			courses[i] = other.courses[i];
		}
	}

	~Student() {
		delete name;
		delete id;
		delete[] courses;
		totalStudents--;
	}


	void setName(string n) {
		*name = n;
	}

	void setId(int i) {
		*id = i;
	}

	void setCourses(string c1, string c2, string c3) {
		courses[0] = c1;
		courses[1] = c2;
		courses[2] = c3;
	}


	string getName() const {
		return *name;
	}

	int getId() const {
		return *id;
	}

	string* getCourses() const {
		return courses;
	}


	void viewDetails() const {
		cout << "Student Details:\n";
		cout << "Name: " << *name << "\nID: " << *id << "\nCourses:\n";
		for (int i = 0; i < 3; i++) {
			cout << i + 1 << ". " << courses[i] << endl;
		}
	}


	friend istream& operator>>(istream& in, Student& s) {
		cout << "Enter Name: ";
		in >> *s.name;
		cout << "Enter ID: ";
		in >> *s.id;
		cout << "Enter 3 Courses:\n";
		for (int i = 0; i < 3; i++) {
			cout << "Course " << i + 1 << ": ";
			in >> s.courses[i];
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, const Student& s) {
		out << "Name: " << *s.name << "\nID: " << *s.id << "\nCourses:\n";
		for (int i = 0; i < 3; i++) {
			out << i + 1 << ". " << s.courses[i] << "\n";
		}
		return out;
	}

	bool operator==(const Student& other) const {
		return *id == *other.id;
	}

	
	static int getTotalStudents() {
		return totalStudents;
	}
};

int Student::totalStudents = 0;

class Course {
private:
	string courseName;
	int credits;
	static int totalCourses;

public:
	
	Course() : courseName(""), credits(0) {
		totalCourses++;
	}

	
	Course(string name, int cr) : courseName(name), credits(cr) {
		totalCourses++;
	}

	
	~Course() {
		totalCourses--;
	}

	void setCourseName(string name) {
		courseName = name;
	}

	void setCredits(int cr) {
		credits = cr;
	}

	string getCourseName() const {
		return courseName;
	}

	int getCredits() const {
		return credits;
	}

	void viewDetails() const {
		cout << "Course Details:\n";
		cout << "Course Name: " << courseName << "\nCredits: " << credits << endl;
	}

	friend istream& operator>>(istream& in, Course& c) {
		cout << "Enter Course Name: ";
		in >> c.courseName;
		cout << "Enter Credits: ";
		in >> c.credits;
		return in;
	}

	friend ostream& operator<<(ostream& out, const Course& c) {
		out << "Course Name: " << c.courseName << "\nCredits: " << c.credits;
		return out;
	}

	int operator+(const Course& other) const {
		return credits + other.credits;
	}

	static int getTotalCourses() {
		return totalCourses;
	}
};

int Course::totalCourses = 0;

int main() {
	Student s1("Qaim", 101);
	s1.setCourses("Math", "Physics", "Chemistry");
	s1.viewDetails();

	Student s2 = s1; 
	s2.setName("Aiza");
	s2.viewDetails();

	
	Course c1("Math", 3);
	Course c2("Physics", 4);

	c1.viewDetails();
	c2.viewDetails();

	int totalCredits = c1 + c2;
	cout << "Total Credits: " << totalCredits << endl;

	if (s1 == s2) {
		cout << "Students have the same ID." <<endl;
	}
	else {
		cout << "Students have different IDs." << endl;
	}

	Student s3;
	cout << "Enter details for a new student:" << endl;
	cout << endl;
	cin >> s3;
	cout << endl;
	cout << "Details of the new student:" << endl << s3;
	cout << endl;
	Course c3;
	cout << "Enter details for a new course:" << endl;
	cin >> c3;
	cout << endl;
	cout << "Details of the new course:" << endl << c3;
	cout << endl;
	cout << "Total Students: " << Student::getTotalStudents() << endl;
	cout << "Total Courses: " << Course::getTotalCourses() << endl;

	return 0;
}
