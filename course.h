#pragma once
#include <bits/stdc++.h>
using namespace std;

struct markCourse
{
    float midMark;
    float finalMark;
    float otherMark;
    int totalMark; ///cai total m lam 1 ham tinh rieng nha
};
struct date
{
    int day,month,year;
};
struct timeStudying
{
    string dayInWeek;
    string time;
};
struct Datacourse{
    string id;
    string name;
    string teacherName;
    int numOfCredits;
    int maxSt = 50;
    timeStudying daySt[2];
    Datacourse* next;
};

struct course
{
    string id;
    string name;
    string teacherName;
    int numOfCredits;
    int maxSt = 50;
    timeStudying daySt[2];
    bool enrolled =false;
    markCourse mark;
    course* next;
};
struct semester4Student
{
    course *cs =nullptr;
    date startDate;
    date endDate;
    semester4Student *next;
};
struct semester
{
    Datacourse *cs=nullptr;
    date startDate;
    date endDate;
    semester *next;
};
struct schoolYear
{
    date startYear;
    date endYear;
    semester * sem =nullptr;
    schoolYear *next;
};



