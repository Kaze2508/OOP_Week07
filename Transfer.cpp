#include <iostream>
#include <string>
#include "Transfer.h"
#include "Student.h"

TransferStudent::TransferStudent(std::string studentID, std::string name, std::string faculty, double avgScore, int numAbsences) : Student(studentID, name, faculty, avgScore) 
{
    this->numAbsences = numAbsences;
}

//double TransferStudent::getScholarship() 
//{
//    if (numAbsences <= 3) 
//    {
//        if (avgScore >= 9) 
//        {
//            return 1500000;
//        }
//        else if (avgScore >= 8) 
//        {
//            return 1200000;
//        }
//        else if (avgScore >= 7) 
//        {
//            return 1000000;
//        }
//    }
//    return 0;
//}

void TransferStudent::input()
{
    Student::input();
    std::cout << "Enter number of absences: ";
    std::cin >> numAbsences;
}

void TransferStudent::display()
{
    Student::display();
    std::cout << "Number of Absences: " << numAbsences << std::endl;
}

double TransferStudent::getScholarship()
{
    if (numAbsences <= 3) 
    {
        if (avgScore >= 9) 
        {
            return 1500000;
        }
        else if (avgScore >= 8) 
        {
            return 1200000;
        }
        else if (avgScore >= 7) 
        {
            return 1000000;
        }
    }
    return 0;
}

int TransferStudent::countTransferStudentsWithNoAbsences(std::vector<Student*> students) 
{
    int count = 0;
    for (Student* student : students) 
    {
        TransferStudent* transferStudent = dynamic_cast<TransferStudent*>(student);
        if (transferStudent != nullptr && transferStudent->numAbsences == 0) 
        {
            count++;
        }
    }
    return count;
}

bool TransferStudent::hasTransferStudentsWithAvgScoreOf9OrHigherAndNoAbsences(std::vector<Student*> students) 
{
    for (Student* student : students) 
    {
        TransferStudent* transferStudent = dynamic_cast<TransferStudent*>(student);
        if (transferStudent != nullptr && transferStudent->avgScore >= 9 && transferStudent->numAbsences == 0) 
        {
            return true;
        }
    }
    return false;
}