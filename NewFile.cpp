#include <iostream>
#include <string>
#include <vector>

class Course {
public:
    Course(std::string name, int code) : name(name), code(code) {}

    std::string getName() const {
        return name;
    }

    int getCode() const {
        return code;
    }

private:
    std::string name;
    int code;
};

class Student {
public:
    Student(std::string name, int id) : name(name), id(id) {}

    void enrollCourse(const Course& course) {
        enrolledCourses.push_back(course);
    }

    void displayCourses() const {
        std::cout << "Enrolled Courses for " << name << ":" << std::endl;
        for (const Course& course : enrolledCourses) {
            std::cout << course.getName() << " (Code: " << course.getCode() << ")" << std::endl;
        }
    }

private:
    std::string name;
    int id;
    std::vector<Course> enrolledCourses;
};

int main() {
    Course math("Mathematics", 101);
    Course physics("Physics", 102);

    Student alice("Alice", 1);
    alice.enrollCourse(math);
    alice.enrollCourse(physics);

    Student bob("Bob", 2);
    bob.enrollCourse(physics);

    alice.displayCourses();
    bob.displayCourses();

    return 0;
}

