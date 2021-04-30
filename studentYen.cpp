
#include <bits/stdc++.h>
#include"course.h"
#include"Student.h"
#include"login.h"
#include"Staff.h"
using namespace std;

void inputDataSemester1(Datacourse *&cs)
{

        //--------------
        cs=new Datacourse;
        Datacourse *cur = cs;
        cur->id="CS161";
        cur->name="Introduction to Computer Science 1";
        cur->teacherName ="DinhBaTien";
        cur->numOfCredits =4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="WED";
        cur->daySt[0].time="S1";
        cur->daySt[1].dayInWeek="FRI";
        cur->daySt[1].time="S1";
        cur->next= new Datacourse;
        cur=cur->next;
        //-------------------
        //cur=new Datacourse;
        cur->id="PH211";
        cur->name="General Physics 1";
        cur->teacherName ="Vu Thi Hanh Thu";
        cur->numOfCredits =4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="MON";
        cur->daySt[0].time="S2";
        cur->daySt[1].dayInWeek="WED";
        cur->daySt[1].time="S2";
        cur->next= new Datacourse;
        cur=cur->next;
        //-------------------
        cur->id="MTH251";
        cur->name="Calculus 1";
        cur->teacherName ="Nguyen Huu Anh";
        cur->numOfCredits =4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="TUE";
        cur->daySt[0].time="S2";
        cur->daySt[1].dayInWeek="THIR";
        cur->daySt[1].time="S2";
        cur->next= new Datacourse;
        cur=cur->next;


        cur->id="CM101";
        cur->name="Communication Management";
        cur->teacherName ="Duong Nguyen Vu";
        cur->numOfCredits =4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="SAT";
        cur->daySt[0].time="C1";
        cur->daySt[1].dayInWeek="SAT";
        cur->daySt[1].time="C2";


}

void inputDataSemester2(Datacourse *&cs)
{

        //-------------------
        cs=new Datacourse;
         Datacourse *cur=cs;
        cur->id="BAA00004";
        cur->name="Introduction to Laws";
        cur->teacherName ="Duong Kim The Nguyen";
        cur->numOfCredits = 3;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="WED";
        cur->daySt[0].time="C1";
        cur->daySt[1].dayInWeek="WED";
        cur->daySt[1].time="C2";
        cur->next= new Datacourse;
        cur=cur->next;
        cur->id="MTH252";
        cur->name="Calculus 2";
        cur->teacherName ="Nguyen Huu Anh";
        cur->numOfCredits = 4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="TUE";
        cur->daySt[0].time="S2";
        cur->daySt[1].dayInWeek="THIR";
        cur->daySt[1].time="S2";
        cur->next= new Datacourse;
        cur=cur->next;
        cur->id="PH212";
        cur->name="General Physics 2";
        cur->teacherName ="Nguyen Huu Nha";
        cur->numOfCredits = 4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="THIR";
        cur->daySt[0].time="C1";
        cur->daySt[1].dayInWeek="FRI";
        cur->daySt[1].time="C1";
         cur->next= new Datacourse;
        cur=cur->next;



        //-------------------

        cur->id="CS162";
        cur->name="Introduction to Computer Science 2";
        cur->teacherName ="Dinh Ba Tien";
        cur->numOfCredits = 4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="MON";
        cur->daySt[0].time="S1";
        cur->daySt[1].dayInWeek="FRI";
        cur->daySt[1].time="S1";

}
void inputDataSemester3 (Datacourse *&cs)
{

         //------------------
        cs=new Datacourse;
         Datacourse *cur=cs;
        cur->id="BA00021";
        cur->name="Physical Education 1";
        cur->teacherName ="Nguyen Van Hung";
        cur->numOfCredits = 2;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="WED";
        cur->daySt[0].time="S1";
        cur->daySt[1].dayInWeek="WED";
        cur->daySt[1].time="S2";

         cur->next= new Datacourse;
        cur=cur->next;
        cur->id="BA00030";
        cur->name="Military Education";
        cur->teacherName ="Ngo Quang Huy ";
        cur->numOfCredits =4;
        cur->maxSt=50;
         cur->daySt[0].dayInWeek ="TUE";
        cur->daySt[0].time="C1";
        cur->daySt[1].dayInWeek="TUE";
        cur->daySt[1].time="C2";

         cur->next= new Datacourse;
        cur=cur->next;
        cur->id="BAA00102";
        cur->name="Marxist-Leninist Political Economics";
        cur->teacherName ="Ngo Tuan Phuong";
        cur->numOfCredits = 2;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="TUE";
        cur->daySt[0].time="C1";
        cur->daySt[1].dayInWeek="TUE";
        cur->daySt[1].time="C2";

       cur->next= new Datacourse;
        cur=cur->next;
        cur->id="BA00101";
        cur->name="Marxist-Leninist Philosophy";
        cur->teacherName ="Ngo Quang Huy";
        cur->numOfCredits =3;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="TUE";
        cur->daySt[0].time="C1";
        cur->daySt[1].dayInWeek="TUE";
        cur->daySt[1].time="C2";


}

void viewStudentsInClass20CTT1(ifstream fin) {
    fin.open("StudentsClass20CTT1.txt");
    if(fin.is_open()) {
        string line;
        while(getline(fin, line))
            cout << line <<endl;
    }
    else cout << "Fail to open file.";
    fin.close();
}

void viewStudentsInClass20CTT2(ifstream fin) {
    fin.open("StudentsClass20CTT2.txt");
    if(fin.is_open()) {
        string line;
        while(getline(fin, line))
            cout << line <<endl;
    }
    else cout << "Fail to open file.";
    fin.close();
}

void viewScoreboardOfCourse(student *st, string cid) {

    int n=0;
    int colWidth=15;
    cout << "SCOREBOARD" << end << endl;
    cout << "Course: " << cid << endl << endl;
    cout << setfill('-') << setw(3*colWidth) << "-" << endl;
    cout << setfill(' ') << fixed;
    cout << setw(colWidth) << "No" << setw(colWidth) << "Student ID" << setw(colWidth) << "Student Full Name"
         << setw(colWidth) << "Total Mark" << setw(colWidth) << "Final Mark" << setw(colWidth)
         << setw(colWidth) << "Midterm Mark" << setw(colWidth) << "Other Mark" << endl;
    while(st != nullptr) {
        if(isEnrolledCourse(st, cid)) {
            course* c = st->semST->cs;
            while(!strcmp(c.id, cid)) c = c->next;
            cout << setprecision(0) << setw(colWidth) << n++ << setw(colWidth) << st->username << setw(colWidth) << st->name
                 << setw(colWidth) << c->mark->totalMark << setw(colWidth) << c->mark->finalMark
                 << setw(colWidth) << c->mark->midMark << setw(colWidth) << c->mark->otherMark;
        }
        st = st->next;
    }
}



