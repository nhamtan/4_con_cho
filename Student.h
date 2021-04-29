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
    timeViewTotalMark time;
    float totalMark4St ; /// lam 1 ham tinh rieng cai nay
};
void initStudent(student *&St);
void createASchoolYear(schoolYear *&sy);
void inputDataSemester1(Datacourse *&cs);
void inputDataSemester2(Datacourse *&cs);
void inputDataSemester3 (Datacourse *&cs);
void convertData(student *&st ,schoolYear *& sy);
void  functionStaff(student *& st, schoolYear *& sy);
void createSemester(schoolYear *&sy,student *&st);
void deleteCourse(schoolYear *&sy);
void enrollCourse(student *&st ,schoolYear *sy);
void displayCourse(student *&st,schoolYear *&sy);
void displayEnrollCourse(student *&st);
void updateCourse(schoolYear *& sy, student *&st);
void viewToTalMark(student *st);
void  functionStaff(student *& st, schoolYear *& sy);
void functionStudent(student *&st, schoolYear *& sy);
void displayCsSem3(schoolYear *sy);
void displayCsSem2(schoolYear *sy);
void displayCsSem1(schoolYear *sy);








#endif // _student_h_
