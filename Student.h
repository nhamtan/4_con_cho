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
    course * myCourse =nullptr;
    student *next ;
};
void initStudent(student *&St);

#endif // _student_h_
