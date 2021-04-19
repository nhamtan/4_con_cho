#include <bits/stdc++.h>

using namespace std;


 string id;
    string name;
    string teacherName;
    int numOfCredits;
    int maxSt = 50;
    timeStudying daySt[2];
    Datacourse* next;
    void input(string  )
void inputData4Course (Datacourse *&cs) // ham nay de tao data cho course
{

    Datacourse *cur = cs;
    for (int i=0;i<5;i++)
    {
        cur=new Datacourse;
        cur->id="CS161";
        cur->name="Introduction to Computer Science 1";
        cur->teacherName ="DinhBaTien";
        cur->numOfCredits =4;
        cur->maxSt=50;
        cur->daySt[0].dayInWeek ="MON";
        cur->daySt[0].time="S1";
        cur->daySt[1].dayInWeek="FRI";
        cur->daySt[1].time="S1";
    }
}
