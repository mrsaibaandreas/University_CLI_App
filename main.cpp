#include <iostream>
#include <list>
#include <string>

class Student {
public:
    std::string name;

    bool operator>(const Student &rhs) const;

    Student(std::string name_) {
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
    Student student("blabla");
    Student stu("afa");
    Student st1("ccas");
    uni.add_student(student);
    uni.add_student(stu);
    uni.add_student(st1);
    uni.students.sort(std::greater<Student>());
    uni.display();
    return 0;
}
