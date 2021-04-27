#pragma once
#include<iostream>
#include<bits/stdc++.h>
#include"course.h"
#include"Student.h"

using namespace std;

#ifndef _student_h_
#define _student_h_

struct timeViewTotalMark
{
    int day = 27;
    int month=4;
    int year=2021;
};
struct student{
    string password;
    string username;
    string name;
    int enrolledCourse =0;
    semester4Student *semST =nullptr;
    student *next ;
    string cls;
<<<<<<< HEAD
    int totalMark4St ; /// lam 1 ham tinh rieng cai nay
    timeViewTotalMark time;
=======
    float totalMark4St ; /// lam 1 ham tinh rieng cai nay
    /* formula: average score of semester (totalMark4St)
    = sum of (total mark of each course*number of credits of that course)/number of courses
    */
>>>>>>> aaf8844ac0632e461764877c4e8f34cea30567f2
};
void initStudent(student *&St);
void createASchoolYear(schoolYear *&sy);
void inputDataSemester1(Datacourse *&cs);
void inputDataSemester2(Datacourse *&cs);
void inputDataSemester3 (Datacourse *&cs);




#endif // _student_h_
