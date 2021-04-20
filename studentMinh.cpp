
#include"Student.h"
#include"course.h"
#include "login.h"
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
        for (int i=1;i<=15;i++)
        {
            convert(cur1,tmp);
            cur1=cur1->next;
            tmp=tmp->next;
        }
        cur=cur->next;
    }
}

void displayCourse(Datacourse *&cs)
{
    cout <<"Information of all courses"<<endl;
    cout <<"---------------------------"<<endl;
    Datacourse *cur=cs;
    int count =1;
    while (count <6)
    {
        cout <<"Name : "<< cur->name<<endl;
        cout <<"Id : "<< cur->id<<endl;
        cout <<"Teacher name : "<< cur->teacherName<<endl;
        cout << "Number of credits : "<< cur->numOfCredits<<endl;
        cout << "Time study in week : " << cur->daySt[0].dayInWeek <<" - " << cur->daySt[0].time << " and " <<cur->daySt[1].dayInWeek <<" - "<<cur->daySt[1].time<<endl;
        cout << "Maximum of students : "<< cur->maxSt<<endl;
        cout <<"----------"<<endl;
        cur=cur->next;
        count ++;
    }
}
void enrollCourse(student *&st ,Datacourse *datacs)
{
    displayCourse(datacs);
    //0 .break
    //1. enroll
    int choice ;
    while(true)
    {
        cout << "0.Break the enrollment"<<endl;
        cout <<"1.Enroll the course"<<endl;
        cout <<"Enter your choice : ";
        cin >> choice;
        if(choice == 0) break;
        else if (choice ==1)
        {
            while(true)
            {
                string tmp;
                cout <<"Break the enrollment,Please Enter 'break' "<<endl;
                cout <<"Enroll The course, Please Enter the ID of Course" <<endl;
                cin >> tmp;
                if(tmp =="break")
                {
                    break;
                }
                else
                {
                    course * cur = st->myCourse;
                    while(cur)
                    {
                        if (tmp== cur->id)
                        {
                            if(cur->enrolled) cout <<"This course was enrolled"<<endl;
                            else
                            {
                                cur->enrolled =true;
                                cout <<"Done" <<endl;
                                break;
                            }
                        }
                        else cur =cur->next;
                    }
                }
            }
        }
    }

}
void displayEnrolledCourse(student *st)
{
    course*cur= st->myCourse;
    while(cur)
    {
        if(cur->enrolled)
        {
            cout <<"Name : "<< cur->name<<endl;
            cout <<"Id : "<< cur->id<<endl;
            cout <<"Teacher name : "<< cur->teacherName<<endl;
            cout << "Number of credits : "<< cur->numOfCredits<<endl;
            cout << "Time study in week : " << cur->daySt[0].dayInWeek <<" - " << cur->daySt[0].time << " and " <<cur->daySt[1].dayInWeek <<" - "<<cur->daySt[1].time<<endl;
            cout << "Maximum of students : "<< cur->maxSt<<endl;
            cout <<"----------"<<endl;
        }
        cur=cur->next;
    }
}
void deleteCourseEnrolled(student *&st)
{
    course *cur =st->myCourse;
    while(cur)
    {
        cur->enrolled =false;
        cur=cur->next;
    }
}



















