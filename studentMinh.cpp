#pragma once
#include"Student.h"
#include <bits/stdc++.h>

using namespace std;


void convert(course *& myCourse,Datacourse *cs)
{
    myCourse =new course;
    myCourse->id = cs->id;
    myCourse->name=cs->name;
    myCourse->numOfCredits =cs->numOfCredits;
    myCourse->maxSt=50;
    myCourse->daySt[0].dayInWeek=cs->daySt[0].dayInWeek;
    myCourse->daySt[0].time=cs->daySt[0].time;
    myCourse->daySt[1].dayInWeek=cs->daySt[1].dayInWeek;
    myCourse->daySt[1].time=cs->daySt[1].time;
    myCourse->next =nullptr;
    return;

}
void convertCourse(student*& st,Datacourse *&cs)
{
    student *cur=st;
    while(cur)
    {
        course * cur1= cur->myCourse;
        Datacourse *tmp=cs;
        for (int i=1;i<=5;i++)
        {
            convert(cur1,tmp);
            cur1=cur1->next;
            tmp=tmp->next;
        }
        cur=cur->next;
    }
