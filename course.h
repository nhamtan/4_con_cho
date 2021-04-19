#pragma once
#include"Student.h"
#include"Staff.h"
#include <bits/stdc++.h>
using namespace std;

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
    course* next;
};
struct semester
{
    Datacourse *cs=nullptr;
    date startDate;
    date endDate;
    string year2021="20202021";
};
