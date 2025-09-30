#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    if (num_of_students < MAX_STUDENTS) {
        students[num_of_students] = Student(name, id, midterm, final);
        num_of_students++;
    }

}

void StudentManager::deleteStudent(int id) {
    int idx = findStudentByID(id);
    if (idx != -1) {
        for (int i = idx; i < num_of_students - 1; ++i) {
            students[i] = students[i + 1];
        }
        num_of_students--;
    }
}

void StudentManager::modifyStudent(const Student& student) {
    int idx = findStudentByID(student.getID());
    if (idx != -1) {
        students[idx].updateRecord(student.getName().c_str(), student.getRecord().getMidterm(), student.getRecord().getFinal());
    }
}

int StudentManager::findStudentByID(int id) const {
    if (num_of_students == 0) return -1;
    for (int i = 0; i < num_of_students; ++i) {
        if (students[i].getID() == id) {
            return i;
        }

}}

int StudentManager::findBestStudentInMidterm() const {
    if (num_of_students == 0) return -1;
    int best_idx = 0;
    for (int i = 0; i < num_of_students; ++i) {
        if (students[i].getRecord().getMidterm() > students[best_idx].getRecord().getMidterm()) {
            best_idx = i;
        }
    }
    return students[best_idx].getID();
}

int StudentManager::findBestStudentInFinal() const {
    if (num_of_students == 0) return -1;
    int best_idx = 0;
    for (int i = 0; i < num_of_students; ++i) {
        if (students[i].getRecord().getFinal() > students[best_idx].getRecord().getFinal()) {
            best_idx = i;
        }
    }
    return students[best_idx].getID();
}

int StudentManager::findBestStudent() const {
    if (num_of_students == 0) return -1;
    int best_idx = 0;
    for (int i = 0; i < num_of_students; ++i) {
        if (students[i].getRecord().getTotal() > students[best_idx].getRecord().getTotal()) {
            best_idx = i;
        }
    }
    return students[best_idx].getID();
}

float StudentManager::getMidtermAverage() const {
    if (num_of_students == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < num_of_students; ++i) {
        sum += students[i].getRecord().getMidterm();
    }
    return sum / num_of_students;
}

float StudentManager::getFinalAverage() const {
    if (num_of_students == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < num_of_students; ++i) {
        sum += students[i].getRecord().getFinal();
    }
    return sum / num_of_students;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    if (num_of_students == 0) return 0.0f;
    return (getMidtermAverage() + getFinalAverage());
}

