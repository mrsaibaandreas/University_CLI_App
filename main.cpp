#include <iostream>
#include <list>
#include <string>
#include <vector>

class Grade {
private :
    double grade;
public:
    Grade(double _grade) {
        grade = _grade;
    }

    double return_grade() {
        return grade;
    }

};

class Class {
public:
    std::string name;
    int nr_of_classes;

    double display_grades();
    double total_grade();
    bool did_he_pass();

    Class(int _name, int _nr_of_classes, std::vector<Grade> _grades) {
        name = _name;
        nr_of_classes = _nr_of_classes;
        grades = _grades;
    }

private:
    std::vector<Grade> grades;

};
double Class::display_grades() {
    std::cout << name;
    for(Grade grade : grades )
        std::cout << grade.return_grade() << " ";
}
double Class::total_grade() {
    double sum = 0;
    for(Grade grade : grades)
        sum += grade.return_grade();
    return sum / nr_of_classes;
}
bool Class::did_he_pass() {
    double sum = 0;
    for(Grade grade : grades)
        sum += grade.return_grade();
    if( sum / nr_of_classes > 5)
        return true;
    else
        return false;
}

class Student {
public:
    std::string name;
    std::vector<Class> classes;

    bool operator>(const Student
    &rhs) const;

    Student(std::string name_, std::vector<Class> _classes) {
        classes = _classes;
        name = name_;
    }

};

inline
bool Student::operator>(const Student &rhs) const { return name < rhs.name; }

class University {
public:
    std::list<Student> students;

    int get_nr_of_students();

    void display();

    void add_student(Student student);

    University() {
        nr_of_students = 0;
        std::cout << nr_of_students;
    }

    ~University() {
        std::cout << "Deconstruct University";
    }

    void increment();

private:
    static int nr_of_students;


};

bool sortByName(const Student &lhs, const Student &rhs) { return lhs.name < rhs.name; }

int University::nr_of_students = 0;

void University::increment() {
    nr_of_students++;
}

void University::add_student(Student student) {

    students.push_back(student);
    increment();
};

void University::display() {
    std::list<Student>::iterator it;
    for (it = students.begin(); it != students.end(); it++) {
        std::cout << it->name << std::endl;
    }
}

int main() {
    University uni;
//    Student student("blabla");
//    Student stu("afa");
//    Student st1("ccas");
//    uni.add_student(student);
//    uni.add_student(stu);
//    uni.add_student(st1);
//    uni.students.sort(std::greater<Student>());
//    uni.display();
    return 0;
}
//add university class
//              : display() d
//              : add_student() d
//              :
//add student class
//              : display_classes d
//              : medie aritmetica d

//add clases class
//              : display_grades
//              : return grades