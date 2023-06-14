#include "Student.h"
#include "Regular.h"
#include "Transfer.h"
#include <iostream>
#include <algorithm>

Student::Student(std::string studentID, std::string name, std::string faculty, double avgScore)
{
    this->studentID = studentID;
    this->name = name;
    this->faculty = faculty;
    this->avgScore = avgScore;
}

void Student::display()
{
    std::cout << "Student ID: " << studentID << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Faculty: " << faculty << std::endl;
    std::cout << "Average Score: " << avgScore << std::endl;
}

void Student::input() 
{
    std::cout << "Enter student ID: ";
    std::cin >> studentID;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter faculty: ";
    std::cin >> faculty;
    std::cout << "Enter average score: ";
    std::cin >> avgScore;
}

double Student::getScholarship() 
{
    return 0;
}

double Student::getTotalScholarships(std::vector<Student*> students) 
{
    double total = 0;
    for (Student* student : students) 
    {
        total += student->getScholarship();
    }
    return total;
}

bool Student::compareID(Student* a, Student* b) 
{
    return a->studentID < b->studentID;
}

void Student::sortID(std::vector<Student*>& students) 
{
    sort(students.begin(), students.end(), compareID);
}

void Student::addStudent(std::vector<Student*>& students) 
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

void Student::deleteByID(std::vector<Student*>& students) 
{
    std::string studentIDToDelete;
    std::cout << "Enter student ID to delete: ";
    std::cin >> studentIDToDelete;

    for (auto it = students.begin(); it != students.end(); it++) 
    {
        if ((*it)->studentID == studentIDToDelete) 
        {
            delete* it;
            students.erase(it);
            break;
        }
    }
}

void Student::searchStudents(std::vector<Student*> students) 
{
    int searchType;
    std::cout << "Enter search type (1 for student ID, 2 for name, 3 for department, 4 for average score, 5 for scholarship): ";
    std::cin >> searchType;

    if (searchType == 1) 
    {
        std::string studentIDToSearch;
        std::cout << "Enter student ID to search for: ";
        std::cin >> studentIDToSearch;

        for (Student* student : students) 
        {
            if (student->studentID == studentIDToSearch) 
            {
                student->display();
            }
        }
    }
    else if (searchType == 2) 
    {
        std::string nameToSearch;
        std::cout << "Enter name to search for: ";
        std::cin.ignore();
        getline(std::cin, nameToSearch);

        for (Student* student : students) 
        {
            if (student->name == nameToSearch) 
            {
                student->display();
            }
        }
    }
    else if (searchType == 3) 
    {
        std::string facultyToSearch;
        std::cout << "Enter department to search for: ";
        std::cin.ignore();
        getline(std::cin, facultyToSearch);

        for (Student* student : students) 
        {
            if (student->faculty == facultyToSearch) 
            {
                student->display();
            }
        }
    }
    else if (searchType == 4) 
    {
        double avgScoreToSearch;
        std::cout << "Enter average score to search for: ";
        std::cin >> avgScoreToSearch;

        for (Student* student : students) 
        {
            if (student->avgScore == avgScoreToSearch) 
            {
                student->display();
            }
        }
    }
    else if (searchType == 5) 
    {
        double scholarshipToSearch;
        std::cout << "Enter scholarship amount to search for: ";
        std::cin >> scholarshipToSearch;

        for (Student* student : students) 
        {
            if (student->getScholarship() == scholarshipToSearch) 
            {
                student->display();
            }
        }
    }
}