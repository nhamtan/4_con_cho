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
    course * myCourse =nullptr;
    student *next ;
};
void initStudent(student *&St);
void convert(course *& myCourse,Datacourse *cs);
void convertCourse(student*& st,Datacourse *&cs);
void displayCourse(Datacourse *&cs);
void enrollCourse(student *&st ,Datacourse *datacs);
void displayEnrolledCourse(student *st);


#endif // _student_h_
