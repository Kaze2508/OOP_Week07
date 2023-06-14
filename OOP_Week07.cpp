#include <iostream>
#include "Regular.h"
#include "Student.h"
#include "Transfer.h"
#include <vector>

int main(int argc, char* argv[])
{
    std::vector<Student*> students;
    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    for (int i = 0; i < numStudents; i++) 
    {
        int studentType;
        std::cout << "Enter student type (1 for regular, 2 for transfer): ";
        std::cin >> studentType;

        if (studentType == 1) 
        {
            RegularStudent* regularStudent = new RegularStudent("", "", "", 0, 0);
            regularStudent->input();
            students.push_back(regularStudent);
        }
        else if (studentType == 2) 
        {
            TransferStudent* transferStudent = new TransferStudent("", "", "", 0, 0);
            transferStudent->input();
            students.push_back(transferStudent);
        }
    }

    for (Student* student : students) 
    {
        student->display();
        std::cout << "Scholarship: " << student->getScholarship() << std::endl;
    }

    int numRegularStudentsWithDisciplineScoreOf100 = RegularStudent::countRegularStudentsWithDisciplineScoreOf100(students);
    std::cout << "Number of regular students with discipline score of 100: " << numRegularStudentsWithDisciplineScoreOf100 << std::endl;

    int numTransferStudentsWithNoAbsences = TransferStudent::countTransferStudentsWithNoAbsences(students);
    std::cout << "Number of transfer students with no absences: " << numTransferStudentsWithNoAbsences << std::endl;

    double totalScholarships = Student::getTotalScholarships(students);
    std::cout << "Total scholarships: " << totalScholarships << std::endl;

    double avgOfRegularStudentsWithScholarships = RegularStudent::getAvgOfRegularStudentsWithScholarships(students);
    std::cout << "Average score of regular students with scholarships: " << avgOfRegularStudentsWithScholarships << std::endl;

    bool hasTransferStudentsWithAvgScoreOf9OrHigherAndNoAbsences = TransferStudent::hasTransferStudentsWithAvgScoreOf9OrHigherAndNoAbsences(students);
    std::cout << "Has transfer students with average score of 9 or higher and no absences: " 
        << (hasTransferStudentsWithAvgScoreOf9OrHigherAndNoAbsences ? "Yes" : "No") << std::endl;

    std::cout << "Regular students with highest average score:" << std::endl;
    RegularStudent::printRegularStudentsWithHighestAvgScore(students);

    Student::sortID(students);

    std::cout << "Students sorted by ascending student ID:" << std::endl;
    for (Student* student : students) 
    {
        student->display();
    }

    Student::addStudent(students);

    std::cout << "Students after adding new student:" << std::endl;
    for (Student* student : students) 
    {
        student->display();
    }

    return 0;
}
