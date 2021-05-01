
#include"Student.h"
#include"course.h"
#include"Staff.h"
#include "login.h"
#include <bits/stdc++.h>
#include<ctime>
using namespace std;



void createASchoolYear(schoolYear *&sy) ///done
{
    sy=new schoolYear;
    schoolYear * cur=sy;
    cout <<"Please input the start and end of the year"<<endl;
    cout <<"Input the Start day - month - year of the year" <<endl;
    cin >> cur->startYear.day >> cur->startYear.month>> cur->startYear.year;
    cout << "Input the End day - month - year of the year"<<endl;
    cin >> cur->endYear.day>> cur->endYear.month >> cur->endYear.year ;
}
void createSemester(schoolYear *&sy,student *&st) ///done
{

    int choice;
    cout <<"1.Create a semester 1"<<endl;
    cout <<"2.Create a semester 2"<<endl;
    cout <<"3.Create a semester 3"<<endl;
    cout <<"Enter your choice : "<<endl;
    cin >> choice;
    if(choice==1)
    {
        if(sy->sem==nullptr)
        sy->sem = new semester;
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
        if(sy->sem==nullptr)
        {
            cout <<"You must create semester 1 first"<<endl;
            cout <<endl;
            return;
        }
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
        if(sy->sem ==nullptr)
        {
            cout <<"You must create semester 2 first"<<endl;
            cout <<endl;
            return;
        }
        if(sy->sem->next ==nullptr)
        {
            cout <<"You must create semester 2 first"<<endl;
            cout <<endl;
            return;
        }
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
void convertData3(student *&st,schoolYear *&sy)///done
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
void convertData2(student *&st, schoolYear *&sy)///done
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
void convertData1(student *&st,schoolYear *&sy)///done
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

void removeEnrolledCourse(student * &st)
{
    semester4Student *curSE=st->semST;
            cout <<"1.Remove the course from semester 1"<<endl;
            cout <<"2.Remove the course from semester 2"<<endl;
            cout <<"3.Remove the course from semester 3"<<endl;
            int choiceSE;
            cout <<"Input your choice : ";
            cin>> choiceSE;

            if(choiceSE ==1)
            {
                if(curSE ==nullptr)
                {
                    cout <<endl;
                    cout <<"NO SEMESTER 1"<<endl;
                    cout <<endl;
                    return;
                }
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
            else if(choiceSE ==2)
            {
                if(curSE ==nullptr)
                {
                    cout <<endl;
                    cout <<"NO SEMESTER 1"<<endl;
                    cout <<endl;
                    return;
                }
                if(curSE ->next==nullptr)
                {
                    cout <<endl;
                    cout <<"NO SEMESTER 2"<<endl;
                    cout <<endl;
                    return;
                }
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
            else if(choiceSE ==3)
            {
                if(curSE ==nullptr)
                {
                    cout <<endl;
                    cout <<"NO SEMESTER 1"<<endl;
                    cout <<endl;
                    return;
                }
                if(curSE->next ==nullptr)
                {
                    cout <<endl;
                    cout <<"NO SEMESTER 2"<<endl;
                    cout <<endl;
                    return;
                }
                if(curSE->next->next ==nullptr)
                {
                    cout <<endl;
                    cout <<"NO SEMESTER 3"<<endl;
                    cout <<endl;
                    return;
                }
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
void enrollCourse(student *&st ,schoolYear *sy) /// done
{
    int choice ;
    while(true)
    {
        cout << "0.Break the enrollment"<<endl;
        cout <<"1.View course"<<endl;
        cout <<"2.Enroll the course"<<endl;
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
                if(curSE ==nullptr)
                {
                    cout <<endl;
                    cout <<"NO SEMESTER 1"<<endl;
                    cout <<endl;
                    return;
                }
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

                if(curSE ==nullptr)
                {
                    cout <<endl;
                    cout <<"NO SEMESTER 1"<<endl;
                    cout <<endl;
                    return;
                }
                if(curSE->next ==nullptr)
                {
                    cout <<endl;
                    cout <<"NO SEMESTER 2"<<endl;
                    cout <<endl;
                    return;
                }
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
                if(curSE ==nullptr)
                {
                    cout <<endl;
                    cout <<"NO SEMESTER 1"<<endl;
                    cout <<endl;
                    return;
                }
                if(curSE->next ==nullptr)
                {
                    cout <<endl;
                    cout <<"NO SEMESTER 2"<<endl;
                    cout <<endl;
                    return;
                }
                if(curSE->next->next ==nullptr)
                {
                    cout <<endl;
                    cout <<"NO SEMESTER 3"<<endl;
                    cout <<endl;
                    return;
                }
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
        else
        {
            cout <<"Please input again your choice"<<endl;
            cout <<"------------------";
        }

    }
}

void displayCourse(student *&st,schoolYear *&sy) ///done
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
            if(cur1 ==nullptr)
            {
                cout <<"NO SEMESTER 2"<<endl;
                cout <<"-------------"<<endl;
                continue;
            }
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
            if(cur1->next ==nullptr)
            {
                cout <<"NO SEMESTER 3"<<endl;
                cout <<"--------------"<<endl;
                continue;
            }
            cur1=cur1->next->next;
            if(cur1 ==nullptr)
            {
                cout <<"NO SEMESTER 3"<<endl;
                cout <<"--------------"<<endl;
                continue;
            }
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

void displayCsSem1(schoolYear * sy) ///done
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
void displayCsSem2(schoolYear *sy) ///done
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
void displayCsSem3(schoolYear *sy) ///done
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
void displayEnrollCourse(student *&st) /// done
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
            if(cur1 ==nullptr)
            {
                cout <<endl;
                cout<<"NO SEMESTER 1"<<endl;
                cout <<endl;
                return;
            }
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

            if(cur1 ==nullptr)
            {
                cout <<endl;
                cout<<"NO SEMESTER 1"<<endl;
                cout <<endl;
                return;
            }
            if(cur1->next ==nullptr)
            {
                cout <<endl;
                cout<<"NO SEMESTER 2"<<endl;
                cout <<endl;
                return;

            }
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
            if(cur1 ==nullptr)
            {
                cout <<endl;
                cout<<"NO SEMESTER 1"<<endl;
                cout <<endl;
                return;
            }
            if(cur1->next ==nullptr)
            {
                cout <<endl;
                cout<<"NO SEMESTER 2"<<endl;
                cout <<endl;
                return;
            }
            if(cur1->next->next==nullptr)
            {
                cout <<endl;
                cout<<"NO SEMESTER 3"<<endl;
                cout <<endl;
                return;
            }
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
        }
    }
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
            semester *head1= sy->sem;
            semester *cur1=head1;
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
                if(head1 ==nullptr)
                {
                    cout<<endl;
                    cout <<"You need to create a semester 1 first"<<endl;
                    cout <<endl;
                    break;
                }
                cout<<"-------------------------"<<endl;
                cout <<"Enter ID of course that you want to update information ";
                string s;
                cin >> s;
                Datacourse *cur =cur1->cs;
                while(cur)
                {
                    if(cur->id == s)
                    {

                        while(true)
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
                            if(choice2 ==0) break;
                            else if(choice2 ==1)
                            {
                                cout<<"ID : "<<cur->id<<endl;
                                cout <<"Enter new ID : ";
                                string cid;
                                cin.ignore();
                                getline(cin,cid);
                                while (cur->id.compare(cid)==0)
                                {
                                    cout<<"You have entered the same course's ID. Please input again."<<endl;
                                    getline(cin, cid);
                                }
                                cur->id=cid;
                                cout <<"DONE"<<endl;
                                cout <<endl;
                                convertData1(st,sy);
                            }
                            else if(choice2==2)
                            {
                                cout <<"The name of course : "<<cur->name<<endl;
                                cout<<"Enter new name of course : ";
                                string cname;
                                cin.ignore();
                                getline(cin, cname);
                                while (cur->name.compare(cname)==0)
                                {
                                    cout<<"You have entered the same course's name. Please input again."<<endl;
                                    getline(cin, cname);
                                }
                                cur->name=cname;
                                cout<<"DONE"<<endl;
                                cout <<endl;
                                convertData1(st,sy);
                            }
                            else if(choice2==3)
                            {
                                cout <<"The name of teacher : "<< cur->teacherName<<endl;
                                cout <<"Enter new name of teacher : ";
                                string lecturer;
                                cin.ignore();
                                getline(cin, lecturer);
                                while (cur->teacherName.compare(lecturer)==0)
                                {
                                    cout<<"You have entered the same teacher's name. Please input again."<<endl;
                                    getline(cin, lecturer);
                                }
                                cur->teacherName=lecturer;
                                cout <<"Done"<<endl;
                                cout<<endl;
                                convertData1(st,sy);
                            }
                            else if(choice2==4)
                            {
                                cout<<"The number of credits of "<<cur->name <<" : "<<cur->numOfCredits<<endl;
                                cout<<"Enter new credits : "<<endl;
                                int cre;
                                cin >> cre;
                                while (cre==cur->numOfCredits)
                                {
                                    cout<<"You have entered the same number of credits. Please input again"<<endl;
                                    cin>>cre;
                                }
                                cur->numOfCredits=cre;
                                cout<<"DONE"<<endl;
                                cout<<endl;
                                convertData1(st,sy);
                            }
                            else if(choice2==5)
                            {
                                cout <<"Max student of course : "<<cur->maxSt;
                                cout <<"Enter new max Students in course : ";
                                int maxStu;
                                cin >> maxStu;
                                while (maxStu==cur->maxSt)
                                {
                                    cout<<"You have entered the same number of maximum students. Please input again"<<endl;
                                    cin>>maxStu;
                                }
                                cur->maxSt=maxStu;
                                cout<<"DONE"<<endl;
                                cout<<endl;
                                convertData1(st,sy);
                            }
                            else if (choice2==6)
                            {
                                cout<<"Schedule of course: ";
                                cout<<cur->daySt[0].dayInWeek <<" - " << cur->daySt[0].time << " and " <<cur->daySt[1].dayInWeek <<" - "<<cur->daySt[1].time<<endl;
                                cout <<"Enter new schedule of course : ";
                                string d1, t1, d2, t2;
                               // getline(cin, )
                            }
                            else
                            {
                                cout <<"Please choose again"<<endl;
                            }
                        }
                        break;
                    }
                    cur=cur->next;
                }
                if(cur==nullptr) cout <<"No match the ID"<<endl;
                cout <<endl;
            }
            else if(choice1 ==2)
            {

                  if(head1 ==nullptr)
                {
                    cout <<endl;
                    cout <<"NO SEMESTER 2"<<endl;
                    cout <<"You need to create a semester 1 first"<<endl;
                    cout <<"-------------"<<endl;
                    cout <<endl;
                    continue;
                }
                  if(head1->next ==nullptr)
                {
                    cout <<endl;
                    cout <<"NO SEMESTER 2"<<endl;
                    cout <<"You need to create a semester 2 first"<<endl;
                    cout <<endl;
                    continue;
                }
                cout<<"-------------------------"<<endl;
                cout <<"Enter ID of course that you want to update information ";
                string s;
                cin >> s;

                cur1=head1->next;
                Datacourse *cur =cur1->cs;
                while(cur)
                {
                    if(cur->id == s)
                    {

                        while(true)
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
                            if(choice2 ==0) break;
                            else if(choice2 ==1)
                            {
                                cout<<"ID : "<<cur->id<<endl;
                                cout <<"Enter new ID : ";
                                string cid2;
                                cin.ignore();
                                getline(cin,cid2);
                                while (cur->id.compare(cid2)==0)
                                {
                                    cout<<"You have entered the same course's ID. Please input again."<<endl;
                                    getline(cin, cid2);
                                }
                                cur->id=cid2;
                                cout <<"DONE"<<endl;
                                cout <<endl;
                                convertData2(st,sy);
                            }
                            else if(choice2==2)
                            {
                                cout <<"The name of course : "<<cur->name<<endl;
                                cout<<"Enter new name of course : ";
                                string cname2;
                                cin.ignore();
                                getline(cin, cname2);
                                while (cur->name.compare(cname2)==0)
                                {
                                    cout<<"You have entered the same course's name. Please input again."<<endl;
                                    getline(cin, cname2);
                                }
                                cur->name=cname2;
                                cout<<"DONE"<<endl;
                                cout <<endl;
                                convertData2(st,sy);
                            }
                            else if(choice2==3)
                            {
                                cout <<"The name of teacher : "<< cur->teacherName<<endl;
                                cout <<"Enter new name of teacher : ";
                                string lecturer2;
                                cin.ignore();
                                getline(cin, lecturer2);
                                while (cur->teacherName.compare(lecturer2)==0)
                                {
                                    cout<<"You have entered the same teacher's name. Please input again."<<endl;
                                    getline(cin, lecturer2);
                                }
                                cur->teacherName=lecturer2;
                                cout <<"Done"<<endl;
                                cout<<endl;
                                convertData2(st,sy);
                            }
                            else if(choice2==4)
                            {
                                cout<<"The number of credits of "<<cur->name <<" : "<<cur->numOfCredits<<endl;
                                cout<<"Enter new credits : "<<endl;
                                int cre2;
                                cin >> cre2;
                                while (cre2==cur->numOfCredits)
                                {
                                    cout<<"You have entered the same number of credits. Please input again"<<endl;
                                    cin>>cre2;
                                }
                                cur->numOfCredits=cre2;
                                cout<<"DONE"<<endl;
                                cout<<endl;
                               convertData2(st,sy);
                            }
                            else if(choice2==5)
                            {
                                cout <<"Max student of course : "<<cur->maxSt;
                                cout <<"Enter new max Students in course : ";
                                int maxStu2;
                                cin >> maxStu2;
                                while (maxStu2==cur->maxSt)
                                {
                                    cout<<"You have entered the same number of maximum students. Please input again"<<endl;
                                    cin>>maxStu2;
                                }
                                cur->maxSt=maxStu2;
                                cout<<"DONE"<<endl;
                                cout<<endl;
                               convertData2(st,sy);
                            }
                            else
                            {
                                cout <<"Please choose again"<<endl;
                            }

                        }
                        break;
                    }
                    cur=cur->next;

                }
                 if(cur==nullptr)
                    cout <<"No match the ID"<<endl;
                  cout <<endl;

            }
            else if(choice1 ==3)
            {
                if(head1 == nullptr)
                {
                    cout <<endl;
                    cout <<"NO SEMESTER 3"<<endl;
                    cout <<"You need to create semester 1 first"<<endl;
                    cout <<endl;
                    continue;
                }
                if(head1->next==nullptr )
                {
                    cout <<endl;
                    cout <<"NO SEMESTER 3"<<endl;
                    cout <<"you need to create a semester 2 first"<<endl;
                    cout <<endl;
                    continue;
                }
                 if(head1->next->next==nullptr )
                {
                    cout <<endl;
                    cout <<"NO SEMESTER 3"<<endl;
                    cout <<"you need to create a semester 3 first"<<endl;
                    cout <<endl;
                    continue;
                }

                cout<<"-------------------------"<<endl;
                cout <<"Enter ID of course that you want to update information ";
                string s;
                cin >> s;
                cur1=head1->next->next;
                Datacourse *cur =cur1->cs;
                while(cur)
                {
                    if(cur->id == s)
                    {

                        while(true)
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
                            if(choice2 ==0) break;
                            else if(choice2 ==1)
                            {
                                cout<<"ID : "<<cur->id<<endl;
                                cout <<"Enter new ID : ";
                                string cid3;
                                cin.ignore();
                                getline(cin,cid3);
                                while (cur->id.compare(cid3)==0)
                                {
                                    cout<<"You have entered the same course's ID. Please input again."<<endl;
                                    getline(cin, cid3);
                                }
                                cur->id=cid3;
                                cout <<"DONE"<<endl;
                                cout <<endl;
                               convertData3(st,sy);
                            }
                            else if(choice2==2)
                            {
                                cout <<"The name of course : "<<cur->name<<endl;
                                cout<<"Enter new name of course : ";
                                string cname3;
                                cin.ignore();
                                getline(cin, cname3);
                                while (cur->name.compare(cname3)==0)
                                {
                                    cout<<"You have entered the same course's name. Please input again."<<endl;
                                    getline(cin, cname3);
                                }
                                cur->name=cname3;
                                cout<<"DONE"<<endl;
                                cout <<endl;
                               convertData3(st,sy);
                            }
                            else if(choice2==3)
                            {
                                cout <<"The name of teacher : "<< cur->teacherName<<endl;
                                cout <<"Enter new name of teacher : ";
                                string lecturer3;
                                cin.ignore();
                                getline(cin, lecturer3);
                                while (cur->teacherName.compare(lecturer3)==0)
                                {
                                    cout<<"You have entered the same teacher's name. Please input again."<<endl;
                                    getline(cin, lecturer3);
                                }
                                cur->teacherName=lecturer3;
                                cout <<"Done"<<endl;
                                cout<<endl;
                                convertData3(st,sy);
                            }
                            else if(choice2==4)
                            {
                                cout<<"The number of credits of "<<cur->name <<" : "<<cur->numOfCredits<<endl;
                                cout<<"Enter new credits : "<<endl;
                                int cre3;
                                cin >> cre3;
                                while (cre3==cur->numOfCredits)
                                {
                                    cout<<"You have entered the same number of credits. Please input again"<<endl;
                                    cin>>cre3;
                                }
                                cur->numOfCredits=cre3;
                                cout<<"DONE"<<endl;
                                cout<<endl;
                                convertData3(st,sy);
                            }
                            else if(choice2==5)
                            {
                                cout <<"Max student of course : "<<cur->maxSt;
                                cout <<"Enter new max Students in course : ";
                                int maxStu3;
                                cin >> maxStu3;
                                while (maxStu3==cur->maxSt)
                                {
                                    cout<<"You have entered the same number of maximum students. Please input again"<<endl;
                                    cin>>maxStu3;
                                }
                                cur->maxSt=maxStu3;
                                cout<<"DONE"<<endl;
                                cout<<endl;
                                convertData3(st,sy);
                            }

                            else
                            {
                                cout <<"Please choose again"<<endl;
                            }

                        }
                        break;
                    }

                    cur=cur->next;
                }
                if(cur==nullptr) cout <<"No match the ID"<<endl;
                cout <<endl;
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
    cout <<"Your total mark : " <<st->overallGPA<<endl;

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
        cout <<"2.View Enrolled Course"<<endl;
        cout <<"3.Remove Enrolled Course"<<endl;
        cout <<"4.View Total Marl"<<endl;
        cout <<"Enter your choice : ";
        int choice;
        cin >>choice;
        if(choice ==0)
        {
            return;
        }
        else if(choice ==1)
        {
            if(canEnroll())
                enrollCourse(st,sy);
            else
                cout << "Can not enroll course now." << endl << "Please re-enter other choice: "<<endl;
        }
        else if(choice ==2)
        {
            displayEnrollCourse(st);
        }
        else if(choice ==3)
        {
            removeEnrolledCourse(st);
        }
        else if(choice ==4)
        {
            enrollCourse(st,sy);
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
    cout <<"7.View list of classes"<<endl;
    cout <<"8.View list of students in class"<<endl;
    cout <<"9. View students in a course"<<endl;

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
        deleteACourse(sy,st);
        cout <<"DONE"<<endl;
    }
    else if(choice ==6)
    {
        exportListStudent(st);
    }
    else if(choice ==7)
    {

    }
    else if(choice ==8)
    {

    }
    else if(choice ==9)
    {

    }


}
}

void deleteACourse(schoolYear *&sy,student *&st) ///done
{
        cout <<"1.View Course"<<endl;
        cout <<"2.Delete course"<<endl;
        cout <<"Enter your choice : ";
        int choice;
        cin>> choice;

        if(choice ==1)
        {
            displayCourse(st,sy);
            return;
        }
        if(choice ==2)
        {
            while(true)
            {

                semester * cur = sy->sem;
                cout <<"0.Break"<<endl;
                cout <<"1.Delete a course in semester 1"<<endl;
                cout <<"2.Delete a course in semester 2"<<endl;
                cout <<"3.Delete a course in semester 3"<<endl;
                cout <<"Enter your choice : ";
                int choice1;
                cin >> choice1;
                if(choice1 == 0) return;
                else if(choice1 ==1)
                {
                    if(cur ==nullptr)
                    {
                        cout <<endl;
                        cout <<"You need to create semester 1 first"<<endl;
                        cout <<endl;
                        return;
                    }
                    cout <<"-----------------------"<<endl;
                    cout <<"Enter ID of course that you want to delete : ";
                    string tm;
                    cin >> tm;
                    Datacourse * cur1= cur->cs;
                    if(cur1->id == tm)
                    {
                        Datacourse * tmp = cur1->next;
                            cur1->next = tmp->next;
                            delete tmp;
                            deleteCourseStudent1(st);
                            convertData1(st,sy);
                            return;
                    }
                    while(cur1->next)
                    {

                        if(tm == cur1->next->id)
                        {
                            Datacourse * tmp = cur1->next;
                            cur1->next = tmp->next;
                            delete tmp;
                            deleteCourseStudent1(st);
                            convertData1(st,sy);
                            return;
                        }
                        cur1=cur1->next;
                    }
                    if(cur1->next==nullptr) cout<<"ID no match"<<endl;
                }
                else if(choice1 ==2)
                {
                    if(cur==nullptr)
                    {
                        cout <<endl;
                        cout <<"You need to create semester 1 first"<<endl;
                        cout <<endl;
                        return;
                    }
                    if(cur->next==nullptr)
                    {
                        cout <<endl;
                        cout<<"You need to create semester 2 first"<<endl;
                        cout <<endl;
                        return;
                    }
                    cout <<"-----------------------"<<endl;
                    cout <<"Enter ID of course that you want to delete : ";
                    string s;
                    cin >> s;
                    cur=cur->next;
                    Datacourse * cur1 = cur->cs;
                    if(cur1->id ==s)
                    {
                        Datacourse * tmp = cur1->next;
                            cur1->next = tmp->next;
                            delete tmp;
                            deleteCourseStudent2(st);
                            convertData2(st,sy);
                            break;
                    }
                    while(cur1->next)
                    {
                        if(cur1->next->id == s)
                        {
                            Datacourse * tmp = cur1->next;
                            cur1->next = tmp->next;
                            delete tmp;
                            deleteCourseStudent2(st);
                            convertData2(st,sy);
                            break;
                        }
                        cur1=cur1->next;
                    }
                    if(cur1->next ==nullptr)
                    {
                        cout<<"ID no match"<<endl;
                    }
                }
                else if(choice1 ==3)
                {
                    if(cur==nullptr)
                    {
                        cout <<endl;
                        cout <<"You need to create semester 1"<<endl;
                        cout <<endl;
                        return;
                    }
                     if(cur->next==nullptr)
                    {
                        cout <<endl;
                        cout<<"You need to create semester 2 first"<<endl;
                        cout <<endl;
                        return;
                    }
                    if(cur->next->next ==nullptr)
                    {
                        cout <<endl;
                        cout <<"You need to create a semester 3 first"<<endl;
                        cout <<endl;
                        return;
                    }
                    cur=cur->next->next;
                    cout <<"-----------------------"<<endl;
                    cout <<"Enter ID of course that you want to delete : ";
                    string s;
                    cin >> s;
                    Datacourse * cur1 = cur->cs;
                    if(cur1->id==s)
                    {
                        Datacourse * tmp = cur1->next;
                            cur1->next = tmp->next;
                            delete tmp;
                            deleteCourseStudent2(st);
                            convertData2(st,sy);
                            break;
                    }
                    while(cur1->next)
                    {
                        if(cur1->next->id == s)
                        {
                            Datacourse * tmp = cur1->next;
                            cur1->next = tmp->next;
                            delete tmp;
                            deleteCourseStudent3(st);
                            convertData3(st,sy);
                            break;
                        }
                        cur1=cur1->next;
                    }
                    if(cur1->next ==nullptr)
                    {
                        cout<<"ID no match"<<endl;
                    }

                }

            }

        }
}
void deleteCourseStudent1(student *& st)
{
    student * tmp =st;
    while(tmp)
    {
        semester4Student * cur = tmp->semST;
        course * head= cur->cs;
        while(head)
        {
            course * tp=head;
            head=head->next;
            delete tp;
        }
        tmp =tmp->next;
    }
}
void deleteCourseStudent2(student *& st)
{
    student * tmp =st;
    while(tmp)
    {
        semester4Student * cur = tmp->semST;
        cur=cur->next;
        course * head= cur->cs;
        while(head)
        {
            course * tp=head;
            head=head->next;
            delete tp;
        }
        tmp =tmp->next;
    }
}
void deleteCourseStudent3(student *& st)
{
    student * tmp =st;
    while(tmp)
    {
        semester4Student * cur = tmp->semST;
        cur=cur->next->next;
        course * head= cur->cs;
        while(head)
        {
            course * tp=head;
            head=head->next;
            delete tp;
        }
        tmp =tmp->next;
    }
}




















