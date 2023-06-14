#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

class RegularStudent : public Student 
{
public:
    double disciplineScore;

    RegularStudent(std::string studentID, std::string name, std::string faculty, double avgScore, double disciplineScore);
    //double getScholarship();
    void input() override;
    void display() override;
    double getScholarship() override;
    static int countRegularStudentsWithDisciplineScoreOf100(std::vector<Student*> students);
    static double getAvgOfRegularStudentsWithScholarships(std::vector<Student*> students);
    static void printRegularStudentsWithHighestAvgScore(std::vector<Student*> students);
};