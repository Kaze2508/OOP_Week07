#include <iostream>
#include <string>
#include "Regular.h"
#include "Student.h"

RegularStudent::RegularStudent(std::string studentID, std::string name, std::string faculty, double avgScore, double disciplineScore) : Student(studentID, name, faculty, avgScore) 
{
    this->disciplineScore = disciplineScore;
}

//double RegularStudent::getScholarship() 
//{
//    if (disciplineScore >= 85) 
//    {
//        if (avgScore >= 9.5) 
//        {
//            return 1500000;
//        }
//        else if (avgScore >= 8.5) 
//        {
//            return 1200000;
//        }
//        else if (avgScore >= 7.5) 
//        {
//            return 1000000;
//        }
//    }
//    return 0;
//}

void RegularStudent::input()
{
    Student::input();
    std::cout << "Enter discipline score: ";
    std::cin >> disciplineScore;
}

void RegularStudent::display()
{
    Student::display();
    std::cout << "Discipline Score: " << disciplineScore << std::endl;
}

double RegularStudent::getScholarship()
{
    if (disciplineScore >= 85) 
    {
        if (avgScore >= 9.5) 
        {
            return 1500000;
        }
        else if (avgScore >= 8.5) 
        {
            return 1200000;
        }
        else if (avgScore >= 7.5) 
        {
            return 1000000;
        }
    }
    return 0;
}

int RegularStudent::countRegularStudentsWithDisciplineScoreOf100(std::vector<Student*> students) 
{
    int count = 0;
    for (Student* student : students) 
    {
        RegularStudent* regularStudent = dynamic_cast<RegularStudent*>(student);
        if (regularStudent != nullptr && regularStudent->disciplineScore == 100) 
        {
            count++;
        }
    }
    return count;
}

double RegularStudent::getAvgOfRegularStudentsWithScholarships(std::vector<Student*> students) 
{
    double total = 0;
    int count = 0;
    for (Student* student : students) 
    {
        RegularStudent* regularStudent = dynamic_cast<RegularStudent*>(student);
        if (regularStudent != nullptr && regularStudent->getScholarship() > 0) 
        {
            total += regularStudent->avgScore;
            count++;
        }
    }
    return count > 0 ? total / count : 0;
}

void RegularStudent::printRegularStudentsWithHighestAvgScore(std:: vector<Student*> students) 
{
    double highestAvgScore = 0;
    for (Student* student : students) 
    {
        RegularStudent* regularStudent = dynamic_cast<RegularStudent*>(student);
        if (regularStudent != nullptr && regularStudent->avgScore > highestAvgScore) 
        {
            highestAvgScore = regularStudent->avgScore;
        }
    }

    for (Student* student : students) 
    {
        RegularStudent* regularStudent = dynamic_cast<RegularStudent*>(student);
        if (regularStudent != nullptr && regularStudent->avgScore == highestAvgScore) 
        {
            regularStudent->display();
        }
    }
}