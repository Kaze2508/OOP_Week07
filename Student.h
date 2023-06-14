#pragma once
#include <iostream>
#include <string>
#include <vector>

class Student 
{
public:
    std::string studentID;
    std::string name;
    std::string faculty;
    double avgScore;

    Student(std::string studentID, std::string name, std::string faculty, double avgScore);
    virtual void input();
    virtual void display();
    virtual double getScholarship();
    static double getTotalScholarships(std::vector<Student*> students);
    static bool compareID(Student* a, Student* b);
    static void sortID(std::vector<Student*>& students);
    static void addStudent(std::vector<Student*>& students);
    static void deleteByID(std::vector<Student*>& students);
};