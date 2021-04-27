
#include"Student.h"
#include"course.h"
#include"Staff.h"
#include "login.h"
#include <bits/stdc++.h>
#include<ctime>
using namespace std;


void deleteCourse(Datacourse *&cs)
{
    while(cs)
    {
        Datacourse *tmp= cs;
        cs=cs->next;
        delete tmp;
    }
}

void createASchoolYear(schoolYear *&sy)
{
    schoolYear * cur =new schoolYear;
    cout <<"Please input the start and end of the year"<<endl;
    cout <<"Input the Start day - month -year of the year" ;
    cin >> cur->startYear.day >> cur->startYear.month>> cur->startYear.year;
    cout << "Input the End day - month -year of the year";
    cin >> cur->endYear.day>> cur->endYear.month >> cur->endYear.year ;
    cur->next=nullptr;
    return;
}
void createSemester(schoolYear *&sy)
{
    semester *cur=sy->sem;
    int choice;
    cout <<"1.Create a semester 1"<<endl;
    cout <<"2.Create a semester 2"<<endl;
    cout <<"3.Create a semester 3"<<endl;
    cin >> choice;
    if(choice==1)
    {
        cout <<"Please input the start and end of the semester 1"<<endl;
        cout <<"Input the Start day - month -year of the semester 1" ;
        cin >> sy->sem->startDate.day >> sy->sem->startDate.month >> sy->sem->startDate.year;
        cout <<"Input the end day - month -year of the semester 1";
        cin >> sy->sem->endDate.day >> sy->sem->endDate.month >> sy->sem->endDate.year;
        cout <<"Information about courses of this semester 1 :" <<endl;
        displayCourse(cur->cs);
        inputDataSemester1(cur->cs);
        cout <<"Input the data of Course DONE "<<endl;
    }
    else if(choice ==2)
    {
        cur=cur->next;
        cout <<"Please input the start and end of the semester 2"<<endl;
        cout <<"Input the Start day - month -year of the semester 2" ;
        cin >> sy->sem->startDate.day >> sy->sem->startDate.month >> sy->sem->startDate.year;
        cout <<"Input the end day - month -year of the semester 2";
        cin >> sy->sem->endDate.day >> sy->sem->endDate.month >> sy->sem->endDate.year;
        cout <<"Information about courses of this semester 2 :" <<endl;
        displayCourse(cur->cs);
        inputDataSemester2(cur->cs);
        cout <<"Input the data of Course DONE "<<endl;
    }
    else if(choice ==3)
    {
        cur=cur->next->next;
        cout <<"Please input the start and end of the semester 3"<<endl;
        cout <<"Input the Start day - month -year of the semester 3" ;
        cin >> sy->sem->startDate.day >> sy->sem->startDate.month >> sy->sem->startDate.year;
        cout <<"Input the end day - month -year of the semester 3";
        cin >> sy->sem->endDate.day >> sy->sem->endDate.month >> sy->sem->endDate.year;
        cout <<"Information about courses of this semester 3 :" <<endl;
        displayCourse(cur->cs);
        inputDataSemester3(cur->cs);
        cout <<"Input the data of Course DONE "<<endl;
    }
}


void convertData(student *&st ,schoolYear *& sy)
{
    student *curST=st;
    while(curST)
    {
        semester4Student * curSEM = curST->semST;
        semester *curSEMSY = sy->sem;
        while(curSEMSY)
        {
            curSEM = new semester4Student;
            course *cur = curSEM->cs;
            Datacourse *cur2=sy->sem->cs;
            while(cur2)
            {
                cur=new course;
                cur->id=cur2->id;
                cur->name= cur2->name;
                cur->numOfCredits=cur2->numOfCredits;
                cur->maxSt=cur2->maxSt;
                cur->daySt[0].dayInWeek= cur2->daySt[0].dayInWeek;
                cur->daySt[0].time=cur2->daySt[0].time;
                cur->daySt[1].dayInWeek= cur2->daySt[1].dayInWeek;
                cur->daySt[1].time=cur2->daySt[1].time;
                cur->next=nullptr;
                cur=cur->next;
                cur2=cur2->next;
            }
            curSEM->next=nullptr;
            curSEM=curSEM->next;
            curSEMSY=curSEMSY->next;
        }
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
        {
            semester * cur = sy->sem;
            cout <<"1.Semester 1"<<endl;
            cout <<"2.Semester 2"<<endl;
            cout <<"3.Semester 3"<<endl;
            cout <<"Input your choice : ";
            int choice;
            cin >> choice;
            if(choice ==1)
            {
                displayCourse(cur->cs);
            }
            else if(choice ==2)
            {

                cur=cur->next;
                displayCourse(cur->cs);
            }
            else if(choice ==3)
            {
                cur=cur->next->next;
                displayCourse(cur->cs);
            }
        }
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
                displayEnrolledCourse(cur);
            }
            else if(choice ==2)
            {
                cur=cur->next;
                displayEnrolledCourse(cur);

            }
            else if(choice ==3)
            {
                cur=cur->next->next;
                displayEnrolledCourse(cur);
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
                    convertData(st,sy);
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
                    convertData(st,sy);
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
                    convertData(st,sy);
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























