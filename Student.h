#pragma once
#include<iostream>
#include<bits/stdc++.h>
#include"course.h"
using namespace std;

#ifndef _student_h_
#define _student_h_

struct student{
    string password;
    string username;
    string name;
    course * myCourse =nullptr;
    student *next ;
};
void initStudent(student *&St);
void convertCourse(student*& st,Datacourse *&cs);
void convert(course *& myCourse,Datacourse *cs);
#endif // _student_h_
