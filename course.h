
#include <bits/stdc++.h>
using namespace std;

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
    course cs[7];
    date startDate;
    date endDate;
    string year2021="20202021";
};
