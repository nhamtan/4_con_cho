#include <bits/stdc++.h>

using namespace std;

void inputData4Course (Datacourse *&cs) // ham nay de tao data cho course
{

        Datacourse *cur = cs;
        //--------------
        cur=new Datacourse;
        cur->id="CS161";
        cur->name="Introduction to Computer Science 1";
        cur->teacherName ="DinhBaTien";
        cur->numOfCredits =4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="WED";
        cur->daySt[0].time="S1";
        cur->daySt[1].dayInWeek="FRI";
        cur->daySt[1].time="S1";
        cur->next=nullptr;
        cur=cur->next;
        //-------------------
        cur=new Datacourse;
        cur->id="PH211";
        cur->name="General Physics 1";
        cur->teacherName ="Vu Thi Hanh Thu";
        cur->numOfCredits =4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="MON";
        cur->daySt[0].time="S2";
        cur->daySt[1].dayInWeek="WED";
        cur->daySt[1].time="S2";
        cur->next=nullptr;
        cur=cur->next;
        //-------------------
        cur=new Datacourse;
        cur->id="MTH251";
        cur->name="Calculus 1";
        cur->teacherName ="Nguyen Huu Anh";
        cur->numOfCredits =4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="TUE";
        cur->daySt[0].time="S2";
        cur->daySt[1].dayInWeek="THIR";
        cur->daySt[1].time="S2";
        cur->next=nullptr;
        cur=cur->next;
        //-------------------
        cur=new Datacourse;
        cur->id="CM101";
        cur->name="Communication Management";
        cur->teacherName ="Duong Nguyen Vu";
        cur->numOfCredits =4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="SAT";
        cur->daySt[0].time="C1";
        cur->daySt[1].dayInWeek="SAT";
        cur->daySt[1].time="C2";
        cur->next=nullptr;
        cur=cur->next;
        //-------------------
        cur=new Datacourse;
        cur->id="BA00101";
        cur->name="Marxist-Leninist Philosophy";
        cur->teacherName ="Ngo Quang Huy";
        cur->numOfCredits =3;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="TUE";
        cur->daySt[0].time="C1";
        cur->daySt[1].dayInWeek="TUE";
        cur->daySt[1].time="C2";
        cur->next=nullptr;
        cur=cur->next;
        //-------------------
        cur=new Datacourse;
        cur->id="BAA00004";
        cur->name="Introduction to Laws";
        cur->teacherName ="Duong Kim The Nguyen";
        cur->numOfCredits = 3;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="WED";
        cur->daySt[0].time="C1";
        cur->daySt[1].dayInWeek="WED";
        cur->daySt[1].time="C2";
        cur->next=nullptr;
        cur=cur->next;
        //-------------------
        cur=new Datacourse;
        cur->id="BA00021";
        cur->name="Physical Education 1";
        cur->teacherName ="Nguyen Van Hung";
        cur->numOfCredits = 2;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="WED";
        cur->daySt[0].time="S1";
        cur->daySt[1].dayInWeek="WED";
        cur->daySt[1].time="S2";
        cur->next=nullptr;
        cur=cur->next;
        //-------------------
        cur=new Datacourse;
        cur->id="BA00030";
        cur->name="Military Education";
        cur->teacherName =" ";
        cur->numOfCredits =4;
        cur->maxSt=50;
        cur->next=nullptr;
        cur=cur->next;
        //-------------------
        cur=new Datacourse;
        cur->id="BAA00102";
        cur->name="Marxist-Leninist Political Economics";
        cur->teacherName ="Ngo Tuan Phuong";
        cur->numOfCredits = 2;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="TUE";
        cur->daySt[0].time="C1";
        cur->daySt[1].dayInWeek="TUE";
        cur->daySt[1].time="C2";
        cur->next=nullptr;
        cur=cur->next;
        //-------------------
        cur=new Datacourse;
        cur->id="CS162";
        cur->name="Introduction to Computer Science 2";
        cur->teacherName ="Dinh Ba Tien";
        cur->numOfCredits = 4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="MON";
        cur->daySt[0].time="S1";
        cur->daySt[1].dayInWeek="FRI";
        cur->daySt[1].time="S1";
        cur->next=nullptr;
        cur=cur->next;
        //-------------------
        cur=new Datacourse;
        cur->id="MTH252";
        cur->name="Calculus 2";
        cur->teacherName ="Nguyen Huu Anh";
        cur->numOfCredits = 4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="TUE";
        cur->daySt[0].time="S2";
        cur->daySt[1].dayInWeek="THIR";
        cur->daySt[1].time="S2";
        cur->next=nullptr;
        cur=cur->next;
        // ---------------
        cur=new Datacourse;
        cur->id="PH212";
        cur->name="General Physics 2";
        cur->teacherName ="Nguyen Huu Nha";
        cur->numOfCredits = 4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="THIR";
        cur->daySt[0].time="C1";
        cur->daySt[1].dayInWeek="FRI";
        cur->daySt[1].time="C1";
        cur->next=nullptr;
        cur=cur->next;
        //-------------------
        cur=new Datacourse;
        cur->id="PH212";
        cur->name="General Physics 2";
        cur->teacherName ="Nguyen Huu Nha";
        cur->numOfCredits = 4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="THIR";
        cur->daySt[0].time="C1";
        cur->daySt[1].dayInWeek="FRI";
        cur->daySt[1].time="C1";
        cur->next=nullptr;
        cur=cur->next;
        //-------------------

}
