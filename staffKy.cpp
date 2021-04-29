#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include"course.h"
#include"Student.h"
#include"login.h"
#include"Staff.h"
using namespace std;

void viewStudentsOfCourse(student *&st, schoolYear *&sy)
{
    student *headStu=st;
    semester *curSemSy=sy->sem;
    Datacourse *cur=sy->sem->cs;
    while (curSemSy!=nullptr)
    {
        while (cur!=nullptr)
        {
            cout<<cur->id<<endl;
            student *curStu=headStu;
            while (curStu!=nullptr)
            {
                semester4Student *curSem=curStu->semST;
                while (curSem!=nullptr)
                {
                    course *stuCs=curStu->semST->cs;
                    while (stuCs!=nullptr)
                    {
                        if (cur->id.compare(stuCs->id)==0 && stuCs->enrolled==true)
                        {
                            cout<<curStu->name<<endl;
                            cout<<curStu->username<<endl;
                            cout<<curStu->password<<endl;
                        }
                        stuCs=stuCs->next;
                    }
                    curSem=curSem->next;
                }
                curStu=curStu->next;
            }
            cout<<'\n'<<"******************"<<'\n';
            cur=cur->next;
        }
        curSemSy=curSemSy->next;
    }
}

void viewListOfClass (student *&st)
{
    student *head=st;
    if (head==nullptr) return;
    else
    {
        string x=head->cls;
        cout<<x<<endl;
        student *cur=head->next;
        while (cur!=nullptr)
         {
             if (cur->cls.compare(x)==0)
                continue;
             else if (x=="0") break;
             else
             {
                 cout<<cur->cls<<endl;
                 x="0";
                 break;
             }
             cur=cur->next;
         }
    }
}

bool isEnrolledCourse(student *&st, string cid)
{
    student *cur=st;
    course *c=cur->semST->cs;
    while (c!=nullptr)
    {
        if (c->id.compare(cid)!=0)
            continue;
        else if (c->id.compare(cid)==0 && c->enrolled==true)
            return true;
    }
    return false;
}

void viewEnrolledCourseShort(student *&st)
{
    semester4Student *cur1=st->semST;
    cout <<'\t'<<"---------------------------"<<endl;
    course * cur = cur1->cs;
    while(cur)
    {
        if(cur->enrolled)
            cout <<cur->id<<endl;
        cur=cur->next;
    }
}

void separateStars()
{
    cout << endl;
    cout<<setfill('*');
    cout << setw(50) <<'*'<< endl;
    cout << endl;
}

