
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

void studentInClass(student * st)
{

        cout <<"Enter class that you want to view : "<<endl;
        string s;
        cin >> s;
        student *cur =st;
        while(cur)
        {
            if(cur->cls ==s)
            {
                cout << cur->name <<endl;
            }
            cur=cur->next;
        }

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

    student * cur=st;
    while(cur)
    {
        semester4Student * curSE= cur->semST;
        while(curSE)
        {
            course * tmp = curSE->cs;
            while(tmp)
            {
                if(tmp->id == cid && tmp->enrolled )
                {
                    cout <<"--------------------"<<endl;
                    cout <<cur->name<<endl;
                    cout <<"Midterm Mark : "<< tmp->mark.midMark<<endl;
                    cout <<"Final Mark : "<<tmp->mark.finalMark<<endl;
                    cout <<"Other Mark : "<<tmp->mark.otherMark<<endl;
                    cout <<"Total Mark : "<<tmp->mark.totalMark<<endl;
                }
                tmp=tmp->next;
            }
            curSE=curSE->next;
        }
        cur=cur->next;
    }
}


void viewScoreClas(student *&st, schoolYear *&sy)         //View scoreboard of class interface
{
     while(true)
            {

            semester * cur =sy->sem;
            cout <<"0.Break"<<endl;
            cout <<"1.View scoreBoard of semester 1"<<endl;
             cout <<"1.View scoreBoard of semester 2"<<endl;
              cout <<"1.View scoreBoard of semester 3"<<endl;
              string choice1;
              cout <<"Enter your choice : ";
              cin >> choice1;

              if(choice1 == "1")
              {
                  if(cur==nullptr)
                  {
                      cout <<endl;
                      cout <<"NO SEMESTER 1"<<endl;
                      cout <<endl;
                  }
                  cout <<"Enter the ID of class that you want to view scoreBoard : ";
                string s;
                cin >> s;
                viewScoreboardOfClass(st,sy->sem,1,s);

              }
              else if(choice1 =="2")
              {
                  if(cur==nullptr)
                  {
                      cout <<endl;
                      cout <<"NO SEMESTER 1"<<endl;
                      cout <<endl;
                  }
                  if(cur->next==nullptr)
                  {
                      cout <<endl;
                      cout <<"NO SEMESTER 2"<<endl;
                      cout <<endl;
                  }
                  cout <<"Enter the ID of class that you want to view scoreBoard : ";
                string s;
                cin >> s;
                 viewScoreboardOfClass(st,sy->sem,2,s);
              }
              else if(choice1=="3")
              {
                  if(cur==nullptr)
                  {
                      cout <<endl;
                      cout <<"NO SEMESTER 1"<<endl;
                      cout <<endl;
                  }
                  if(cur->next==nullptr)
                  {
                      cout <<endl;
                      cout <<"NO SEMESTER 2"<<endl;
                      cout <<endl;
                  }
                  if(cur->next==nullptr)
                  {
                      cout <<endl;
                      cout <<"NO SEMESTER 3"<<endl;
                      cout <<endl;
                  }
                    cout <<"Enter the ID of class that you want to view scoreBoard : ";
                string s;
                cin >> s;
                 viewScoreboardOfClass(st,sy->sem,3,s);
              }
              else if(choice1 =="0") break;
              else{
                cout <<"Please enter again your choice"<<endl;
              }


        }
}
void viewScoreboardOfClass (student *st,semester *sem, int semNo, string cls) {


    int no = 0;
    int colWidth = 30;
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
                if(!check) cout << setw(colWidth) ;                 // if not enrolled course, print out -
                stcs = stcs->next;
            }
            c = c->next;
            }
            cout << setw(colWidth) << s->semGPA << setw(colWidth) << st->overallGPA << endl << endl << endl;
        }
        st = st->next;
    }

}

bool canEnroll() {                             // check if the current time is the registration duration or not
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














