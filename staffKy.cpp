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
