#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

class TransferStudent : public Student 
{
public:
    int numAbsences;

    TransferStudent(std::string studentID, std::string name, std::string faculty, double avgScore, int numAbsences);
    //double getScholarship();
    void input() override;
    void display() override;
    double getScholarship() override;
    static int countTransferStudentsWithNoAbsences(std::vector<Student*> students);
    static bool hasTransferStudentsWithAvgScoreOf9OrHigherAndNoAbsences(std::vector<Student*> students);
};