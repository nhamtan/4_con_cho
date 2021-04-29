
#include"Student.h"
#include"course.h"
#include"Staff.h"
#include "login.h"
#include <bits/stdc++.h>
#include<ctime>
using namespace std;


void deleteCourse(schoolYear *&sy)
{
    while(true)
    {
    cout<<"0.Break"<<endl;
    cout <<"1.Delete course in semester 1"<<endl;
    cout<<"2.Delete course in semester 2"<<endl;
    cout<<"3.Delete course in semester 3"<<endl;
    cout <<"Enter your choice : ";
    int choice;
    cin >>choice;
    semester *cur=sy->sem;
    if(choice ==1)
    {
         while(cur->cs)
        {
            Datacourse *tmp= cur->cs;
            cur->cs=cur->cs->next;
            delete tmp;
        }
    }
    else if(choice ==2)
    {
        cur=cur->next;
        while(cur->cs)
        {
             Datacourse *tmp= cur->cs;
            cur->cs=cur->cs->next;
            delete tmp;
        }
    }
    else if(choice==3)
    {
        cur=cur->next->next;
        while(cur->cs)
        {
             Datacourse *tmp= cur->cs;
            cur->cs=cur->cs->next;
            delete tmp;
        }
    }
    else if(choice ==0) return;
    else cout <<"Please input again"<<endl;
    }

}

void createASchoolYear(schoolYear *&sy)
{
    sy=new schoolYear;
    schoolYear * cur=sy;
    cout <<"Please input the start and end of the year"<<endl;
    cout <<"Input the Start day - month - year of the year" <<endl;
    cin >> cur->startYear.day >> cur->startYear.month>> cur->startYear.year;
    cout << "Input the End day - month - year of the year"<<endl;
    cin >> cur->endYear.day>> cur->endYear.month >> cur->endYear.year ;
    if(sy) cout <<"yes";
    else cout <<"No";
}
void createSemester(schoolYear *&sy,student *&st)
{
    if(sy->sem==nullptr)
        sy->sem = new semester;
    int choice;
    cout <<"1.Create a semester 1"<<endl;
    cout <<"2.Create a semester 2"<<endl;
    cout <<"3.Create a semester 3"<<endl;
    cout <<"Enter your choice : "<<endl;
    cin >> choice;
    if(choice==1)
    {
        semester * cur=sy->sem;
        cout <<"Please input the start and end of the semester 1"<<endl;
        cout <<"Input the Start day - month -year of the semester 1 : " <<endl;
        cin >> cur->startDate.day >> cur->startDate.month >> cur->startDate.year;
        cout <<"Input the end day - month -year of the semester 1"<<endl;
        cin >> cur->endDate.day >> cur->endDate.month >> cur->endDate.year;
        cout <<"Information about courses of this semester 1 : " <<endl;
        inputDataSemester1(cur->cs);
        displayCsSem1(sy);
        cout <<"Input the data of Course DONE "<<endl;
        convertData1(st,sy);
    }
    else if(choice ==2)
    {
        sy->sem->next = new semester;
        semester * cur=sy->sem->next;
        cout <<"Please input the start and end of the semester 2"<<endl;
        cout <<"Input the Start day - month -year of the semester 2" <<endl;
        cin >> cur->startDate.day >> cur->startDate.month >> cur->startDate.year;
        cout <<"Input the end day - month -year of the semester 2"<<endl;
        cin >> cur->endDate.day >> cur->endDate.month >> cur->endDate.year;
        cout <<"Information about courses of this semester 2 :" <<endl;
        inputDataSemester2(cur->cs);
        displayCsSem2(sy);
        cout <<"Input the data of Course DONE "<<endl;
        convertData2(st,sy);
    }
    else if(choice ==3)
    {
        sy->sem->next->next = new semester;
        semester * cur=sy->sem->next->next;
        cout <<"Please input the start and end of the semester 3"<<endl;
        cout <<"Input the Start day - month -year of the semester 3" <<endl;
        cin >> cur->startDate.day >> cur->startDate.month >> cur->startDate.year;
        cout <<"Input the end day - month -year of the semester 3"<<endl;
        cin >> cur->endDate.day >> cur->endDate.month >> cur->endDate.year;
        cout <<"Information about courses of this semester 3 :" <<endl;
        inputDataSemester3(cur->cs);
        displayCsSem3(sy);
        cout <<"Input the data of Course DONE "<<endl;
        convertData3(st,sy);
    }

}
void convertData3(student *&st,schoolYear *&sy)
{
     student * curSt =st;
    while(curSt)
    {

        curSt->semST->next->next= new semester4Student;
        semester4Student *curSe= curSt->semST->next->next;
        curSe->cs = new course;
        course *cur= curSe->cs;
        Datacourse * cur2= sy->sem->next->next->cs;
        while(cur2)
        {
                cur->id=cur2->id;
                cur->name= cur2->name;
                cur->numOfCredits=cur2->numOfCredits;
                cur->maxSt=cur2->maxSt;
                cur->daySt[0].dayInWeek= cur2->daySt[0].dayInWeek;
                cur->daySt[0].time=cur2->daySt[0].time;
                cur->daySt[1].dayInWeek= cur2->daySt[1].dayInWeek;
                cur->daySt[1].time=cur2->daySt[1].time;
                if(cur2)
                {
                    cur->next= new course;
                    cur=cur->next;
                }
            cur2=cur2->next;
        }
        curSt=curSt->next;
    }
}
void convertData2(student *&st, schoolYear *&sy)
{
     student * curSt =st;
    while(curSt)
    {

        curSt->semST->next= new semester4Student;
        semester4Student *curSe= curSt->semST->next;
        curSe->cs = new course;
        course *cur= curSe->cs;
        Datacourse * cur2= sy->sem->next->cs;
        while(cur2)
        {
                cur->id=cur2->id;
                cur->name= cur2->name;
                cur->numOfCredits=cur2->numOfCredits;
                cur->maxSt=cur2->maxSt;
                cur->daySt[0].dayInWeek= cur2->daySt[0].dayInWeek;
                cur->daySt[0].time=cur2->daySt[0].time;
                cur->daySt[1].dayInWeek= cur2->daySt[1].dayInWeek;
                cur->daySt[1].time=cur2->daySt[1].time;
                if(cur2)
                {
                    cur->next= new course;
                    cur=cur->next;
                }
            cur2=cur2->next;
        }
        curSt=curSt->next;
    }
}
void convertData1(student *&st,schoolYear *&sy)
{
    student * curSt =st;
    while(curSt)
    {

        curSt->semST= new semester4Student;
        semester4Student *curSe= curSt->semST;
        curSe->cs = new course;
        course *cur= curSe->cs;
        Datacourse * cur2= sy->sem->cs;
        while(cur2)
        {
                cur->id=cur2->id;
                cur->name= cur2->name;
                cur->numOfCredits=cur2->numOfCredits;
                cur->maxSt=cur2->maxSt;
                cur->daySt[0].dayInWeek= cur2->daySt[0].dayInWeek;
                cur->daySt[0].time=cur2->daySt[0].time;
                cur->daySt[1].dayInWeek= cur2->daySt[1].dayInWeek;
                cur->daySt[1].time=cur2->daySt[1].time;
                if(cur2)
                {
                    cur->next= new course;
                    cur=cur->next;
                }
            cur2=cur2->next;
        }
        curSt=curSt->next;
    }
}


void enrollCourse(student *&st ,schoolYear *sy)
{
    int choice ;
    while(true)
    {
        cout << "0.Break the enrollment"<<endl;
        cout <<"1.View course"<<endl;
        cout <<"2.Enroll the course"<<endl;
        cout <<"3.View Enrolled course"<<endl;
        cout <<"4.Remove enrolled course"<<endl;
        cout <<"Enter your choice : ";
        cin >> choice;
        if(choice == 0) return;
        else if (choice ==2)
        {
            semester4Student *curSE= st->semST;
            int choiceSe;
            cout <<"1.Enroll semester 1"<<endl;
            cout <<"2.Enroll semester 2"<<endl;
            cout<<"3.Enroll semester 3"<<endl;
            cout <<"Input your choice : ";
            cin >> choiceSe;
            if(choiceSe==1)
            {
                cout <<"WELCOME TO ENROLL SEMESTER 1"<<endl;

                while(true)
            {
                if(st->enrolledCourse ==5)
                {
                    cout <<"You only enroll maximum 5 course"<<endl;
                    cout <<"-------------"<<endl;
                    break;
                }
                string tmp;
                cout <<"Break the enrollment,Please Enter 'break' "<<endl;
                cout <<"Enroll The course, Please Enter the ID of Course" <<endl;
                cin >> tmp;
                bool checkID =false;
                if(tmp =="break")
                {
                    break;
                }
                else
                {
                    course *cur = curSE->cs;
                    while(cur)
                    {
                        if (tmp== cur->id)
                        {
                            if(cur->enrolled)
                            {
                                cout <<"This course was enrolled"<<endl;
                                break;
                            }
                            else
                            {
                                cur->enrolled =true;
                                st->enrolledCourse ++;
                                cout <<"Done" <<endl;
                                checkID=true;
                                break;
                            }
                        }
                        cur =cur->next;
                    }
                }
                if(!checkID)
                {
                    cout <<"Wrong ID"<<endl;
                    cout <<"----------"<<endl;
                }
            }

            }
            else if(choiceSe ==2)
            {

                cout <<"WELCOME TO ENROLL SEMESTER 2"<<endl;
                curSE=curSE->next;
                while(true)
            {
                if(st->enrolledCourse ==5)
                {
                    cout <<"You only enroll maximum 5 course"<<endl;
                    cout <<"-------------"<<endl;
                    break;
                }
                string tmp;
                cout <<"Break the enrollment,Please Enter 'break' "<<endl;
                cout <<"Enroll The course, Please Enter the ID of Course" <<endl;
                cin >> tmp;
                bool checkID =false;
                if(tmp =="break")
                {
                    break;
                }
                else
                {
                    course *cur = curSE->cs;
                    while(cur)
                    {
                        if (tmp== cur->id)
                        {
                            if(cur->enrolled)
                            {
                                cout <<"This course was enrolled"<<endl;
                                break;
                            }
                            else
                            {
                                cur->enrolled =true;
                                st->enrolledCourse ++;
                                cout <<"Done" <<endl;
                                checkID=true;
                                break;
                            }
                        }
                        cur =cur->next;
                    }
                }
                if(!checkID)
                {
                    cout <<"Wrong ID"<<endl;
                    cout <<"----------"<<endl;
                }
            }
            }
            else if(choiceSe ==3)
            {
                cout <<"WELCOME TO ENROLL SEMESTER 3"<<endl;
              curSE=curSE->next->next;
                while(true)
            {
                if(st->enrolledCourse ==5)
                {
                    cout <<"You only enroll maximum 5 course"<<endl;
                    cout <<"-------------"<<endl;
                    break;
                }
                string tmp;
                cout <<"Break the enrollment,Please Enter 'break' "<<endl;
                cout <<"Enroll The course, Please Enter the ID of Course" <<endl;
                cin >> tmp;
                bool checkID =false;
                if(tmp =="break")
                {
                    break;
                }
                else
                {
                    course *cur = curSE->cs;
                    while(cur)
                    {
                        if (tmp== cur->id)
                        {
                            if(cur->enrolled)
                            {
                                cout <<"This course was enrolled"<<endl;
                                break;
                            }
                            else
                            {
                                cur->enrolled =true;
                                st->enrolledCourse ++;
                                cout <<"Done" <<endl;
                                checkID=true;
                                break;
                            }
                        }
                        cur =cur->next;
                    }
                }
                if(!checkID)
                {
                    cout <<"Wrong ID"<<endl;
                    cout <<"----------"<<endl;
                }
            }
            }

        }
        else if(choice ==1)
            displayCourse(st,sy);
        else if(choice ==3)
        {
            cout <<"1.Semester 1"<<endl;
            cout <<"2.Semester 2"<<endl;
            cout <<"3.Semester 3"<<endl;
            cout <<"Input your choice : ";
            int choice;
            cin >> choice;
            semester4Student *cur=st->semST;
            if(choice ==1)
            {
                displayEnrollCourse(st);
            }
            else if(choice ==2)
            {
                cur=cur->next;
                displayEnrollCourse(st);

            }
            else if(choice ==3)
            {
                cur=cur->next->next;
                displayEnrollCourse(st);
            }
        }
        else if(choice ==4)
        {
            semester4Student *curSE=st->semST;
            cout <<"1.Remove the course from semester 1";
            cout <<"2.Remove the course from semester 2";
            cout <<"3.Remove the course from semester 3";
            int choiceSE;
            cout <<"Input your choice : ";
            cin>> choiceSE;

            if(choiceSE ==1)
            {
                 while(true)
            {

                 if(st->enrolledCourse ==0)
                {
                    cout <<"You removed all course,you dont have any course enrolled"<<endl;
                    cout <<"-------------"<<endl;
                    break;
                }
                string tmp;
                cout <<"Break the enrollment,Please Enter 'break' "<<endl;
                cout <<"To remove the enrolled course, Please enter the ID of enrolled course" <<endl;
                cin >> tmp;
                bool checkID =false;
                if(tmp =="break")
                {
                    break;
                }
                else
                {
                    course *cur= curSE->cs;
                    while(cur)
                    {
                        if(tmp == cur->id  && cur->enrolled ==true)
                        {
                            cout <<"Done";
                            cur->enrolled =false;
                            st->enrolledCourse --;
                            checkID =true;
                            break;
                        }
                        cur=cur->next;
                    }
                }
                if(checkID ==false)
                {
                    cout <<"Wrong ID"<<endl;
                    cout <<"---------------"<<endl;
                }
            }
            }
            else if(choice ==2)
            {
                curSE=curSE->next;
                 while(true)
            {

                 if(st->enrolledCourse ==0)
                {
                    cout <<"You removed all course,you dont have any course enrolled"<<endl;
                    cout <<"-------------"<<endl;
                    break;
                }
                string tmp;
                cout <<"Break the enrollment,Please Enter 'break' "<<endl;
                cout <<"To remove the enrolled course, Please enter the ID of enrolled course" <<endl;
                cin >> tmp;
                bool checkID =false;
                if(tmp =="break")
                {
                    break;
                }
                else
                {
                    course *cur= curSE->cs;
                    while(cur)
                    {
                        if(tmp == cur->id  && cur->enrolled ==true)
                        {
                            cout <<"Done";
                            cur->enrolled =false;
                            st->enrolledCourse --;
                            checkID =true;
                            break;
                        }
                        cur=cur->next;
                    }
                }
                if(checkID ==false)
                {
                    cout <<"Wrong ID"<<endl;
                    cout <<"---------------"<<endl;
                }
            }
            }
            else if(choice ==3)
            {
                curSE=curSE->next->next;
                 while(true)
            {

                 if(st->enrolledCourse ==0)
                {
                    cout <<"You removed all course,you dont have any course enrolled"<<endl;
                    cout <<"-------------"<<endl;
                    break;
                }
                string tmp;
                cout <<"Break the enrollment,Please Enter 'break' "<<endl;
                cout <<"To remove the enrolled course, Please enter the ID of enrolled course" <<endl;
                cin >> tmp;
                bool checkID =false;
                if(tmp =="break")
                {
                    break;
                }
                else
                {
                    course *cur= curSE->cs;
                    while(cur)
                    {
                        if(tmp == cur->id  && cur->enrolled ==true)
                        {
                            cout <<"Done";
                            cur->enrolled =false;
                            st->enrolledCourse --;
                            checkID =true;
                            break;
                        }
                        cur=cur->next;
                    }
                }
                if(checkID ==false)
                {
                    cout <<"Wrong ID"<<endl;
                    cout <<"---------------"<<endl;
                }
            }
            }
        }
        else
        {
            cout <<"Please input again your choice"<<endl;
            cout <<"------------------";
        }

    }
}

void displayCourse(student *&st,schoolYear *&sy)
{
    while(true)
    {
         cout <<"0.Break"<<endl;
        cout<<"1.View course in semester 1"<<endl;
        cout <<"2.View course in semester 2"<<endl;
        cout <<"3.View course in semester 3"<<endl;
        int choice;
        cout <<"Enter your choice : ";
        cin >> choice;
        semester *cur1= sy->sem;
        if(choice ==0)
        {
            break;
        }
        else if(choice ==1)
        {
            cout <<"Information of all courses in semester 1"<<endl;
            cout <<"---------------------------"<<endl;
            Datacourse *cur=cur1->cs;
            while(cur)
            {
                cout <<"Name : "<< cur->name<<endl;
                cout <<"Id : "<< cur->id<<endl;
                cout <<"Teacher name : "<< cur->teacherName<<endl;
                cout << "Number of credits : "<< cur->numOfCredits<<endl;
                cout << "Time study in week : " << cur->daySt[0].dayInWeek <<" - " << cur->daySt[0].time << " and " <<cur->daySt[1].dayInWeek <<" - "<<cur->daySt[1].time<<endl;
                cout << "Maximum of students : "<< cur->maxSt<<endl;
                cout <<"----------"<<endl;
                cur=cur->next;
            }
        }
        else if(choice ==2)
        {
            cur1=cur1->next;
            cout <<"Information of all courses in semester 2"<<endl;
            cout <<"---------------------------"<<endl;
            Datacourse *cur=cur1->cs;
            while(cur)
            {
                cout <<"Name : "<< cur->name<<endl;
                cout <<"Id : "<< cur->id<<endl;
                cout <<"Teacher name : "<< cur->teacherName<<endl;
                cout << "Number of credits : "<< cur->numOfCredits<<endl;
                cout << "Time study in week : " << cur->daySt[0].dayInWeek <<" - " << cur->daySt[0].time << " and " <<cur->daySt[1].dayInWeek <<" - "<<cur->daySt[1].time<<endl;
                cout << "Maximum of students : "<< cur->maxSt<<endl;
                cout <<"----------"<<endl;
                cur=cur->next;
            }

        }
        else if(choice ==3)
        {
            cur1=cur1->next->next;
            cout <<"Information of all courses in semester 3"<<endl;
            cout <<"---------------------------"<<endl;
            Datacourse *cur=cur1->cs;
            while(cur)
            {
                cout <<"Name : "<< cur->name<<endl;
                cout <<"Id : "<< cur->id<<endl;
                cout <<"Teacher name : "<< cur->teacherName<<endl;
                cout << "Number of credits : "<< cur->numOfCredits<<endl;
                cout << "Time study in week : " << cur->daySt[0].dayInWeek <<" - " << cur->daySt[0].time << " and " <<cur->daySt[1].dayInWeek <<" - "<<cur->daySt[1].time<<endl;
                cout << "Maximum of students : "<< cur->maxSt<<endl;
                cout <<"----------"<<endl;
                cur=cur->next;
            }
        }
        else
        {
            cout <<"Please enter again your choice"<<endl;
            cout<<endl;
        }


    }
}

void displayCsSem1(schoolYear * sy)
{
    semester * cur1= sy->sem;
    Datacourse *cur=cur1->cs;
    while(cur)
    {
                cout <<"Name : "<< cur->name<<endl;
                cout <<"Id : "<< cur->id<<endl;
                cout <<"Teacher name : "<< cur->teacherName<<endl;
                cout << "Number of credits : "<< cur->numOfCredits<<endl;
                cout << "Time study in week : " << cur->daySt[0].dayInWeek <<" - " << cur->daySt[0].time << " and " <<cur->daySt[1].dayInWeek <<" - "<<cur->daySt[1].time<<endl;
                cout << "Maximum of students : "<< cur->maxSt<<endl;
                cout <<"----------"<<endl;
                cur=cur->next;
    }
}
void displayCsSem2(schoolYear *sy)
{
    semester * cur1= sy->sem;
    cur1=cur1->next;
    Datacourse *cur=cur1->cs;
    while(cur)
    {
                cout <<"Name : "<< cur->name<<endl;
                cout <<"Id : "<< cur->id<<endl;
                cout <<"Teacher name : "<< cur->teacherName<<endl;
                cout << "Number of credits : "<< cur->numOfCredits<<endl;
                cout << "Time study in week : " << cur->daySt[0].dayInWeek <<" - " << cur->daySt[0].time << " and " <<cur->daySt[1].dayInWeek <<" - "<<cur->daySt[1].time<<endl;
                cout << "Maximum of students : "<< cur->maxSt<<endl;
                cout <<"----------"<<endl;
                cur=cur->next;
    }
}
void displayCsSem3(schoolYear *sy)
{
    semester * cur1= sy->sem;
    cur1=cur1->next->next;
    Datacourse *cur=cur1->cs;
    while(cur)
    {
                cout <<"Name : "<< cur->name<<endl;
                cout <<"Id : "<< cur->id<<endl;
                cout <<"Teacher name : "<< cur->teacherName<<endl;
                cout << "Number of credits : "<< cur->numOfCredits<<endl;
                cout << "Time study in week : " << cur->daySt[0].dayInWeek <<" - " << cur->daySt[0].time << " and " <<cur->daySt[1].dayInWeek <<" - "<<cur->daySt[1].time<<endl;
                cout << "Maximum of students : "<< cur->maxSt<<endl;
                cout <<"----------"<<endl;
                cur=cur->next;
    }
}
void displayEnrollCourse(student *&st)
{
    while(true)
    {
        cout <<"0.Break"<<endl;
        cout<<"1.View Enrolled course in semester 1"<<endl;
        cout <<"2.View Enrolled course in semester 2"<<endl;
        cout <<"3.View Enrolled course in semester 3"<<endl;
        int choice;
        cout <<"Enter your choice : ";
        cin >> choice;
        semester4Student *cur1=st->semST;
        if(choice ==0)
        {
            break;
        }
        else if(choice ==1)
        {
            cout <<"Information of all courses enrolled in semester 1"<<endl;
            cout <<"---------------------------"<<endl;
            course * cur = cur1->cs;
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
        else if(choice ==2)
        {
            cur1=cur1->next;
            cout <<"Information of all courses enrolled in semester 2"<<endl;
            cout <<"---------------------------"<<endl;
            course * cur = cur1->cs;
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
        else if(choice ==3)
        {
            cur1=cur1->next->next;
            cout <<"Information of all courses enrolled in semester 3"<<endl;
            cout <<"---------------------------"<<endl;
            course * cur = cur1->cs;
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
        else
        {
            cout <<"Please enter again your choice"<<endl;
            cout<<endl;
        }       }
    }

void updateCourse(schoolYear *& sy, student *&st)
{
    cout <<"1.View Course"<<endl;
    cout <<"2.Update Course"<<endl;
    cout<<"Enter your choice : ";
    int choice;
    cin >> choice;
    if(choice ==1)
    {
        displayCourse(st,sy);
        return;
    }
    if(choice ==2)
    {
        while(true)
        {
            semester *cur1= sy->sem;
            cout <<"0.Break"<<endl;
            cout <<"1.Update Information course in semester 1"<<endl;
            cout <<"2.Update Information course in semester 2"<<endl;
            cout <<"3.Update Information course in semester 3"<<endl;
            cout<<"Enter your choice : "<<endl;
            int choice1;
            cin>> choice1;

            if(choice1 ==0 ) break;
            else if(choice1 ==1)
            {
                cout<<"-------------------------"<<endl;
                cout <<"Enter ID of course that you want to update information ";
                string s;
                cin >> s;
                Datacourse *cur =cur1->cs;
                while(cur)
                {
                    if(cur->id == s)
                    {
                        cout<<"Name of the course that you want to update : "<<cur->name<<endl;
                        cout <<endl;
                        cout<<"0.break"<<endl;
                        cout <<"1.Update ID"<<endl;
                        cout <<"2.Update Name of course"<<endl;
                        cout <<"3.Update name of teacher"<<endl;
                        cout <<"4.Update the number of credits"<<endl;
                        cout <<"5.Update maximum student in course"<<endl;
                        cout <<"6.Update time studying"<<endl;
                        cout<<"Enter your choice : "<<endl;
                        int choice2;
                        cin >>choice2;
                        while(true)
                        {
                            if(choice2 ==0) break;
                            else if(choice2 ==1)
                            {
                                cout<<"ID : "<<cur->id<<endl;
                                cout <<"Enter new ID : ";
                                cin >> cur->id;
                                cout <<"DONE"<<endl;
                                cout <<endl;
                            }
                            else if(choice2==2)
                            {
                                cout <<"The name of course : "<<cur->name<<endl;
                                cout<<"Enter new name of course : ";
                                cin >> cur->name;
                                cout<<"DONE"<<endl;
                                cout <<endl;
                            }
                            else if(choice2==3)
                            {
                                cout <<"The name of teacher : "<< cur->teacherName<<endl;
                                cout <<"Enter new name of teacher : ";
                                cin >> cur->teacherName;
                                cout <<"Done"<<endl;
                                cout<<endl;
                            }
                            else if(choice2==4)
                            {
                                cout<<"The number of credits of "<<cur->name <<" : "<<cur->numOfCredits<<endl;
                                cout<<"Enter new credits : ";
                                cin >> cur->numOfCredits;
                                cout<<"DONE"<<endl;
                                cout<<endl;
                            }
                            else if(choice2==5)
                            {
                                cout <<"Max student of course : "<<cur->maxSt;
                                cout <<"Enter new max Students in course : ";
                                cin >> cur->maxSt;
                                cout<<"DONE"<<endl;
                                cout<<endl;
                            }
                            else
                            {
                                cout <<"Please choose again"<<endl;
                            }
                        }
                    }
                    break;
                    convertData1(st,sy);
                }
            }
            else if(choice1 ==2)
            {
                cout<<"-------------------------"<<endl;
                cout <<"Enter ID of course that you want to update information ";
                string s;
                cin >> s;
                Datacourse *cur =cur1->cs;
                while(cur)
                {
                    if(cur->id == s)
                    {
                        cout<<"Name of the course that you want to update : "<<cur->name<<endl;
                        cout <<endl;
                        cout<<"0.break"<<endl;
                        cout <<"1.Update ID"<<endl;
                        cout <<"2.Update Name of course"<<endl;
                        cout <<"3.Update name of teacher"<<endl;
                        cout <<"4.Update the number of credits"<<endl;
                        cout <<"5.Update maximum student in course"<<endl;
                        cout <<"6.Update time studying"<<endl;
                        cout<<"Enter your choice : "<<endl;
                        int choice2;
                        cin >>choice2;
                        while(true)
                        {
                            if(choice2 ==0) break;
                            else if(choice2 ==1)
                            {
                                cout<<"ID : "<<cur->id<<endl;
                                cout <<"Enter new ID : ";
                                cin >> cur->id;
                                cout <<"DONE"<<endl;
                                cout <<endl;
                            }
                            else if(choice2==2)
                            {
                                cout <<"The name of course : "<<cur->name<<endl;
                                cout<<"Enter new name of course : ";
                                cin >> cur->name;
                                cout<<"DONE"<<endl;
                                cout <<endl;
                            }
                            else if(choice2==3)
                            {
                                cout <<"The name of teacher : "<< cur->teacherName<<endl;
                                cout <<"Enter new name of teacher : ";
                                cin >> cur->teacherName;
                                cout <<"Done"<<endl;
                                cout<<endl;
                            }
                            else if(choice2==4)
                            {
                                cout<<"The number of credits of "<<cur->name <<" : "<<cur->numOfCredits<<endl;
                                cout<<"Enter new credits : ";
                                cin >> cur->numOfCredits;
                                cout<<"DONE"<<endl;
                                cout<<endl;
                            }
                            else if(choice2==5)
                            {
                                cout <<"Max student of course : "<<cur->maxSt;
                                cout <<"Enter new max Students in course : ";
                                cin >> cur->maxSt;
                                cout<<"DONE"<<endl;
                                cout<<endl;
                            }
                            else
                            {
                                cout <<"Please choose again"<<endl;
                            }
                        }
                    }
                    break;
                    convertData2(st,sy);
                }
            }
            else if(choice1 ==3)
            {
                cout<<"-------------------------"<<endl;
                cout <<"Enter ID of course that you want to update information ";
                string s;
                cin >> s;
                Datacourse *cur =cur1->cs;
                while(cur)
                {
                    if(cur->id == s)
                    {
                        cout<<"Name of the course that you want to update : "<<cur->name<<endl;
                        cout <<endl;
                        cout<<"0.break"<<endl;
                        cout <<"1.Update ID"<<endl;
                        cout <<"2.Update Name of course"<<endl;
                        cout <<"3.Update name of teacher"<<endl;
                        cout <<"4.Update the number of credits"<<endl;
                        cout <<"5.Update maximum student in course"<<endl;
                        cout <<"6.Update time studying"<<endl;
                        cout<<"Enter your choice : "<<endl;
                        int choice2;
                        cin >>choice2;
                        while(true)
                        {
                            if(choice2 ==0) break;
                            else if(choice2 ==1)
                            {
                                cout<<"ID : "<<cur->id<<endl;
                                cout <<"Enter new ID : ";
                                cin >> cur->id;
                                cout <<"DONE"<<endl;
                                cout <<endl;
                            }
                            else if(choice2==2)
                            {
                                cout <<"The name of course : "<<cur->name<<endl;
                                cout<<"Enter new name of course : ";
                                cin >> cur->name;
                                cout<<"DONE"<<endl;
                                cout <<endl;
                            }
                            else if(choice2==3)
                            {
                                cout <<"The name of teacher : "<< cur->teacherName<<endl;
                                cout <<"Enter new name of teacher : ";
                                cin >> cur->teacherName;
                                cout <<"Done"<<endl;
                                cout<<endl;
                            }
                            else if(choice2==4)
                            {
                                cout<<"The number of credits of "<<cur->name <<" : "<<cur->numOfCredits<<endl;
                                cout<<"Enter new credits : ";
                                cin >> cur->numOfCredits;
                                cout<<"DONE"<<endl;
                                cout<<endl;
                            }
                            else if(choice2==5)
                            {
                                cout <<"Max student of course : "<<cur->maxSt;
                                cout <<"Enter new max Students in course : ";
                                cin >> cur->maxSt;
                                cout<<"DONE"<<endl;
                                cout<<endl;
                            }
                            else
                            {
                                cout <<"Please choose again"<<endl;
                            }
                        }
                    }
                    break;
                    convertData3(st,sy);
                }
            }
            else
            {
                cout <<"Please enter your choice again"<<endl;
            }

        }
    }
}
void viewToTalMark(student *st)
{
    int day1=st->time.day;
    int month1=st->time.month;
    int year1=st->time.year;


    time_t now = time(0);
   tm *ltm = localtime(&now);

    int year2 =1900 + ltm->tm_year;
    int month2 =1 + ltm->tm_mon;
    int day2= ltm->tm_mday ;
    if(year2 < year1)
    {

        cout <<"You can't view your total mark"<<endl;
        return;
    }
    else if(year1 == year2)
    {
        if(month2 < month1)
        {
            cout <<"You can't view your total mark"<<endl;
            return;
        }
        else if(month2 == month1 && day2 < day1)
        {
            cout <<"You can't view your total mark"<<endl;
            return;
        }

    }
    cout <<"Your total mark : " <<st->totalMark4St<<endl;

}
void exportListStudent(student *&st)
{
    while(true)
    {
        cout <<"0.Break"<<endl;
        cout <<"1.Export list students in course"<<endl;
        cout<<"Enter your choice : "<<endl;
        int choice;
        cin >> choice;
        if(choice ==0) return;
        else if(choice ==1)
        {
            cout <<"Enter your ID of course that you want to export to CSV file : ";
            string id;
            cin >> id;
            exportCourse(st,id);
        }
        else cout <<"Please enter a again your choice"<<endl;
    }
}
void functionStudent(student *&st, schoolYear *& sy)
{
    while(true)
    {
        cout <<"0.Log Out"<<endl;
        cout <<"1.Enroll course"<<endl;
        cout <<"Enter your choice : ";
        int choice;
        cin >>choice;
        if(choice ==0)
        {
            return;
        }
        else if(choice ==1)
        {
            enrollCourse(st,sy);
        }
        else if(choice ==2)
        {

        }
    }
}
void  functionStaff(student *& st, schoolYear *& sy)
{
    while(true)
    {
    cout<<"0.Log out"<<endl;
    cout<<"1.Create a schoolyear"<<endl;
    cout<<"2.Create semester"<<endl;
    cout <<"3.View course"<<endl;
    cout <<"4.Update course information"<<endl;
    cout<<"5.Delete course"<<endl;
    cout <<"6.Export the list of students in course"<<endl;
    cout <<"Enter your choice : ";
    int choice;
    cin>>choice;
    if(choice ==0)
    {
        return;
    }
    else if(choice==1)
    {
        createASchoolYear(sy);
    }
    else if(choice==2)
    {
        createSemester(sy,st);
    }
    else if(choice ==3)
    {
        cout<<"Welcome to view course"<<endl;
        cout<<"   ----------------    "<<endl;
        displayCourse(st,sy);
    }
    else if(choice ==4)
    {
        updateCourse(sy,st);
    }
    else if(choice==5)
    {
        deleteCourse(sy);
        cout <<"DONE"<<endl;
    }
    else if(choice ==6)
    {
        exportListStudent(st);
    }


}
}





















