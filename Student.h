#pragma once
#include<iostream>
#include<bits/stdc++.h>
#include"course.h"
#include"Student.h"

using namespace std;

#ifndef _student_h_
#define _student_h_


struct student{
    string password;
    string username;
    string name;
    int enrolledCourse =0;
    semester4Student *semST =nullptr;
    student *next ;
};
void initStudent(student *&St);
void createASchoolYear(schoolYear *&sy);
void inputDataSemester1(Datacourse *&cs);
void inputDataSemester2(Datacourse *&cs);
void inputDataSemester3 (Datacourse *&cs);




#endif // _student_h_
