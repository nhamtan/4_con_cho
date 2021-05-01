#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
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
        if (c->id.compare(cid)==0 && c->enrolled==true)
            return true;
        c=c->next;
    }
    return false;
}

void viewEnrolledCourseShort(student *&st)
{
    semester4Student *cur1=st->semST;
    cout <<'\t'<<"-----------------------"<<endl;
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

void averageScoreSemes(student *&st)
{
    student *stu=st;
    semester4Student *sem=stu->semST;
    course *c=stu->semST->cs;
    while (stu!=nullptr)
    {
        while (sem!=nullptr)
        {
            float num=0;
            while (c!=nullptr)
            {
                if (c->enrolled==true)
                {
                    sem->semGPA+=((c->mark).totalMark * c->numOfCredits);
                    num+=c->numOfCredits;
                }
                c=c->next;
            }
            sem->semGPA/=num;
            sem->semGPA=roundf(sem->semGPA * 10)/10;
            sem=sem->next;
        }
        stu=stu->next;
    }
}

void GPAschoolyear(student *&st)
{
    student *stu=st;
    semester4Student *sem=stu->semST;
    while (stu!=nullptr)
    {
        int count=0;
        while (sem!=nullptr)
        {
            count++;
            stu->overallGPA+=sem->semGPA;
            sem=sem->next;
        }
        stu->overallGPA/=count;
        stu->overallGPA=roundf(stu->overallGPA * 10)/10;
        stu=stu->next;
    }
}

void modifyScoreSem(student *&st)
{
    semester4Student *sem=st->semST;
    string cid;
    cout<<"Update mark of course"<<endl;
    cout<<endl;
    cout<<"Enter course's ID: ";
    cin.ignore();
    getline(cin, cid);

    while (isEnrolledCourse(st, cid)==false)
    {
        cout<<"Please enter course's ID again"<<endl;
        getline(cin, cid);
    }
    cout<<"You have entered correct course's ID"<<endl;
    cout<<endl;

    markCourse m=sem->cs->mark;
    cout<<"Which mark you want to update?"<<endl;
    cout<<endl;
    cout<<"0.Exit"<<endl;
    cout<<"1.Midterm"<<endl;
    cout<<"2.Final"<<endl;
    cout<<"3.Other"<<endl;
    cout<<endl;
    cout<<"Enter your choice: "<<endl;
    int score1;
    cin>>score1;
    while (true)
    {
        if (score1==1)
        {
            float mid1;
            cout<<"Enter midterm score: ";
            cin>>mid1;
            while (mid1==m.midMark)
            {
                cout<<"You have entered the same midterm score. Please enter again."<<endl;
                cin>>mid1;
            }
            m.midMark=mid1;
            cout<<"Updated midterm score: "<<m.midMark<<endl;
            separateStars();
            cout<<"DONE"<<endl;
            break;
         }
         else if (score1==2)
         {
            float final1;
            cout<<"Enter final score: ";
            cin>>final1;
            while (final1==m.finalMark)
            {
                cout<<"You have entered the same midterm score. Please enter again."<<endl;
                cin>>final1;
            }
            m.finalMark=final1;
            cout<<"Updated final score: "<<m.finalMark<<endl;
            cout<<"DONE"<<endl;
            separateStars();
            break;
         }
         else if (score1==3)
         {
            float other1;
            cout<<"Enter other score: "<<endl;
            cin>>other1;
            while (other1==m.otherMark)
            {
                cout<<"You have entered the same other mark. Please enter again."<<endl;
                cin>>other1;
            }
            m.otherMark=other1;
            cout<<"Updated other score: "<<m.otherMark<<endl;
            separateStars();
            cout<<"DONE"<<endl;
            break;
         }
         else
         {
             cout<<"Break"<<endl;
             break;
         }
    }
    cout<<"Student's score this course: "<<m.totalMark<<endl;
    cout<<"Student's score this semester: "<<sem->semGPA<<endl;
}

void updateScore (student *&st)
{
    cout <<"Update student's result"<<endl;
    while(true)
    {
        cout<<"Please enter student's class and ID you would like to update his or her result"<<endl;
        string clas, sid;
        getline(cin, clas);
        getline(cin, sid);
        student *cur=st;
        while (cur!=nullptr)
        {
            if (cur->cls.compare(clas)==0 && cur->username.compare(sid)!=0) cur=cur->next;
            else if (cur->cls.compare(clas)!=0 && cur->username.compare(sid)!=0) cur=cur->next;
        }
        cout <<"0.Break"<<endl;
        cout <<"1.Update student's result in semester 1"<<endl;
        cout <<"2.Update student's result in semester 2"<<endl;
        cout <<"3.Update student's result in semester 3"<<endl;
        cout<<"Enter your choice : "<<endl;
        int choice1;
        cin>>choice1;
        semester4Student *sem=cur->semST;
        if (choice1==0)
        {
            cout<<"Break"<<endl;
            break;
        }
        else if (choice1==1)
        {
            course * c = sem->cs;
            cout<<"List of enrolled courses"<<endl;
            cout<<endl;
            while(c!=nullptr)
            {
                if(c->enrolled)
                    cout <<c->id<<endl;
                c=c->next;
            }
            modifyScoreSem(cur);
            break;
        }
        else if (choice1==2)
        {
            sem=sem->next;
            course * c = sem->cs;
            cout<<"List of enrolled courses"<<endl;
            cout<<endl;
            while(c!=nullptr)
            {
                if(c->enrolled)
                    cout <<c->id<<endl;
                c=c->next;
            }
            modifyScoreSem(cur);
            break;
        }
        else if (choice1==3)
        {
            sem=sem->next->next;
            course * c = sem->cs;
            cout<<"List of enrolled courses"<<endl;
            cout<<endl;
            while(c!=nullptr)
            {
                if(c->enrolled)
                    cout <<c->id<<endl;
                c=c->next;
            }
            modifyScoreSem(cur);
            break;
        }
        cout<<'\n'<<"Student's average score this schoolyear: "<<cur->overallGPA<<endl;
        separateStars();
    }
}

void convertToUpper(string &c)
{
    for (int i = 0; i < c.length(); i++)
    {
        if (islower(c[i]))
            c[i]=toupper(c[i]);
    }
}
