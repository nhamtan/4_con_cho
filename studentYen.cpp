
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
        cur->daySt[0].time="S1(07:30)";
        cur->daySt[1].dayInWeek="FRI";
        cur->daySt[1].time="S1(07:30)";
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
        cur->daySt[0].time="S2(09:30)";
        cur->daySt[1].dayInWeek="WED";
        cur->daySt[1].time="S2(09:30)";
        cur->next= new Datacourse;
        cur=cur->next;
        //-------------------
        cur->id="MTH251";
        cur->name="Calculus 1";
        cur->teacherName ="Nguyen Huu Anh";
        cur->numOfCredits =4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="TUE";
        cur->daySt[0].time="S2(09:30)";
        cur->daySt[1].dayInWeek="THIR";
        cur->daySt[1].time="S2(09:30)";
        cur->next= new Datacourse;
        cur=cur->next;


        cur->id="CM101";
        cur->name="Communication Management";
        cur->teacherName ="Duong Nguyen Vu";
        cur->numOfCredits =4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="SAT";
        cur->daySt[0].time="C1(13:30)";
        cur->daySt[1].dayInWeek="SAT";
        cur->daySt[1].time="C2(15:30)";


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
        cur->daySt[0].time="C1(13:30)";
        cur->daySt[1].dayInWeek="WED";
        cur->daySt[1].time="C2(15:30)";
        cur->next= new Datacourse;
        cur=cur->next;
        cur->id="MTH252";
        cur->name="Calculus 2";
        cur->teacherName ="Nguyen Huu Anh";
        cur->numOfCredits = 4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="TUE";
        cur->daySt[0].time="S2(09:30)";
        cur->daySt[1].dayInWeek="THIR";
        cur->daySt[1].time="S2(09:30)";
        cur->next= new Datacourse;
        cur=cur->next;
        cur->id="PH212";
        cur->name="General Physics 2";
        cur->teacherName ="Nguyen Huu Nha";
        cur->numOfCredits = 4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="THIR";
        cur->daySt[0].time="C1(13:30)";
        cur->daySt[1].dayInWeek="FRI";
        cur->daySt[1].time="C1(13:30)";
         cur->next= new Datacourse;
        cur=cur->next;



        //-------------------

        cur->id="CS162";
        cur->name="Introduction to Computer Science 2";
        cur->teacherName ="Dinh Ba Tien";
        cur->numOfCredits = 4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="MON";
        cur->daySt[0].time="S1(07:30)";
        cur->daySt[1].dayInWeek="FRI";
        cur->daySt[1].time="S1(07:30)";

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
        cur->daySt[0].time="S1(07:30)";
        cur->daySt[1].dayInWeek="WED";
        cur->daySt[1].time="S2(09:30)";

         cur->next= new Datacourse;
        cur=cur->next;
        cur->id="BA00030";
        cur->name="Military Education";
        cur->teacherName ="Ngo Quang Huy ";
        cur->numOfCredits =4;
        cur->maxSt=50;
         cur->daySt[0].dayInWeek ="TUE";
        cur->daySt[0].time="C1(13:30)";
        cur->daySt[1].dayInWeek="TUE";
        cur->daySt[1].time="C2(15:30)";

         cur->next= new Datacourse;
        cur=cur->next;
        cur->id="BAA00102";
        cur->name="Marxist-Leninist Political Economics";
        cur->teacherName ="Ngo Tuan Phuong";
        cur->numOfCredits = 2;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="TUE";
        cur->daySt[0].time="C1(13:30)";
        cur->daySt[1].dayInWeek="TUE";
        cur->daySt[1].time="C2(15:30)";

       cur->next= new Datacourse;
        cur=cur->next;
        cur->id="BA00101";
        cur->name="Marxist-Leninist Philosophy";
        cur->teacherName ="Ngo Quang Huy";
        cur->numOfCredits =3;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="TUE";
        cur->daySt[0].time="C1(13:30)";
        cur->daySt[1].dayInWeek="TUE";
        cur->daySt[1].time="C2(15:30)";


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

bool checkEnrollingStu(student *st, string cid) {                            //check if student enroll in the course cid
    course* c = st->semST->cs;
    while(c!=nullptr) {
        if(cid.compare(c->id) == 0)
            return 1;
        c = c->next;
    }
    return 0;

}

void viewScoreboardOfCourse(student *st, string cid) {

    int n=0;
    int colWidth=15;
    cout << "SCOREBOARD" << endl << endl;
    cout << "Course: " << cid << endl << endl;
    cout << setfill('-') << setw(7*colWidth) << "-" << endl;
    cout << setfill(' ') << fixed;
    cout << setw(colWidth) << "No" << setw(colWidth) << "Student ID" << setw(colWidth) << "Student Full Name"
         << setw(colWidth) << "Total Mark" << setw(colWidth) << "Final Mark" << setw(colWidth)
         << setw(colWidth) << "Midterm Mark" << setw(colWidth) << "Other Mark" << endl;
    cout << setfill('-') << setw(7*colWidth) << "-" << endl;
    cout << setfill(' ') << fixed;
    while(st != nullptr) {
        if(checkEnrollingStu(st, cid)) {
            course* c = st->semST->cs;
            while(cid.compare(c->id) != 0) c = c->next;
            cout << setprecision(0) << setw(colWidth) << ++n << setw(colWidth) << st->username << setw(colWidth) << st->name
                 << setw(colWidth) << c->mark.totalMark << setw(colWidth) << c->mark.finalMark
                 << setw(colWidth) << c->mark.midMark << setw(colWidth) << c->mark.otherMark;
        }
        st = st->next;
    }
}


void viewScoreboardOfClass (student *st,semester *sem, int semNo, string cls) {

    int no = 0;
    int colWidth = 15;
    Datacourse* c = sem->cs;

    cout << "SCOREBOARD" << endl << endl;
    cout << "Class: " << cls << endl << endl;

    cout << setfill('-') << setw(15*colWidth) << "-" << endl;
    cout << setfill(' ') << fixed;

    cout << setw(colWidth) << "No" << setw(colWidth) << "Student ID" << setw(colWidth) << "Student Full Name";
    while (c!= nullptr) {
            cout << setw(colWidth) << c->name;
            c = c->next;
    }
    cout << setw(colWidth) << "GPA of Semester" << setw(colWidth) << "Overall GPA" << endl;

    cout << setfill('-') << setw(15*colWidth) << "-" << endl;
    cout << setfill(' ') << fixed;

    while(st!=nullptr) {
        if (cls.compare(st->cls)==0) {
            cout << setprecision(0) << setw(colWidth) << ++no << setw(colWidth) << st->username << setw(colWidth) << st->name;

            semester4Student* s = st->semST;
            for(int i = 1; i < semNo; i++) s = s->next;                   // get to the right semester

            Datacourse* c = sem->cs;

            // print out mark of courses in the semester
            while (c!=nullptr) {

            course* stcs = s->cs;

            while(stcs!=nullptr) {
                bool check = 0;
                if (c->id.compare(stcs->id) == 0) {
                    cout << setw(colWidth) << stcs->mark.totalMark;      // if enrolled course, print out total mark
                    check = 1;
                    break;
                }
                if(!check) cout << setw(colWidth) << "-";                 // if not enrolled course, print out -
                stcs = stcs->next;
            }
            c = c->next;
            }
            cout << setw(colWidth) << s->semGPA << setw(colWidth) << st->overallGPA << endl;
        }
        st = st->next;
    }
}

bool canEnroll() {
    date startEnroll, closeEnroll;
    ifstream fin;
    loadEnrollmentDate(fin, startEnroll, closeEnroll);

     time_t now = time(0);
   tm *ltm = localtime(&now);

   date cur;

    cur.year =1900 + ltm->tm_year;
    cur.month =1 + ltm->tm_mon;
    cur.day = ltm->tm_mday ;

    if (isBefore(startEnroll, cur) && isBefore(cur, closeEnroll))
        return true;
    else
        return false ;

}

bool isBefore(date d1, date d2) {
    if (d1.year < d2.year) return 1;
    else if (d1.year == d2.year) {
        if(d1.month < d2.month)
            return 1;
        else if (d1.month == d2.month)
            if (d1.day <= d2.day)
            return 1;
    }
    return 0;
}

void inputEnrollmentDate (date &startEnroll, date &closeEnroll, ofstream &fout) {
    cout << "Input Enrollment Duration" << endl;
    cout << "Open Date (dd mm yyyy): " ;
    cin >> startEnroll.day >> startEnroll.month >> startEnroll.year;
    cout << "Close Date (dd mm yyyy): ";
    cin >> closeEnroll.day >> closeEnroll.month >> closeEnroll.year;

    fout.open("EnrollmentDate.txt");
    if(fout.is_open()) {
        fout << startEnroll.day << " " << startEnroll.month << " " << startEnroll.year << " "
             << closeEnroll.day << " " << closeEnroll.month << " " << closeEnroll.year;
    }
    fout.close();
}

void loadEnrollmentDate(ifstream &fin, date &startEnroll, date &closeEnroll) {
    fin.open("EnrollmentDate.txt");
    if(fin.is_open()) {
        fin >> startEnroll.day >> startEnroll.month >> startEnroll.year >> closeEnroll.day >> closeEnroll.month >> closeEnroll.year;
    }
    fin.close();
}














