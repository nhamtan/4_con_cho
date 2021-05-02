#include"login.h"
#include <bits/stdc++.h>
using namespace std;



student* isStudent(student *St , string username)
{
    while(St != NULL)
    {
        if(St -> username == username)
            return St;
        St = St -> next;
    }
    return NULL;
}

staff* isStaff(staff *Sf , string username)
{
    while(Sf != NULL)
    {
        if(Sf -> username == username)
            return Sf;
        Sf = Sf -> next;
    }
    return NULL;
}

void login(student *&St , staff *&Sf,schoolYear *&sy)
{

    initStudent(St);
    initStaff(Sf);
    string s;
    while(true)
    {
    cout <<"0.Exit"<<endl;
    cout <<"1.Log in"<<endl;
    cout <<"Enter your choice : ";
    string s;
    cin >> s;
    if(s == "0" ) return;
    else if(s == "1")
    {
    while(true)
    {

        string username;
        cout << "username: ";
        cin >> username;
        cout << "password: ";
        string password;
        cin >> password;
        student *a = isStudent(St , username);
        staff *b = isStaff(Sf , username);
        if((a == NULL && b == NULL))
        {
            cout << "Sai tai khoan hoac mat khau vui long nhap lai" << "\n";
        }
        else if(a != NULL)
        {
            if(a -> password != password)
            {
                cout << "Sai tai khoan hoac mat khau vui long nhap lai" << "\n";
            }
            else
            {
                cout << "Welcome student " << a -> name << "\n";
                a -> login = true;
                /// add thêm giao diện của học sinh vào bằng hàm.

    functionStudent(St,sy);

        system("pause");
        system("cls");
                a -> login = false;

                break;
            }
        }
        else
        {
            if(b -> password != password)
            {
                cout << "Sai tai khoan hoac mat khau vui long nhap lai" << "\n";
            }
            else
            {
                cout << "Welcome staff " << b -> name << "\n";
                /// add thêm giao diện của staff vào bằng hàm.


                functionStaff(St,sy);

                        system("pause");
        system("cls");



                break;
            }
        }
    }
    }
    else cout <<"Enter again"<<endl;
    }
}

void exportCourse(student *Stt , string name)
{
    ofstream fo(name + ".csv");
    //cerr << "..............." << endl;
    fo << ",,,,,,,,,," << name << endl;
    fo << "No,Student ID,Student Full Name" << endl;
    int cnt = 0;
    student *St = Stt;
    while(St != NULL)
    {
        auto *temp1 = St -> semST;
        while(temp1 != NULL)
        {
            course *temp = temp1 -> cs;
            while(temp != NULL)
            {
                if(temp -> id == name && temp -> enrolled == true)
                    fo << (++cnt) << "," << St -> username << "," << St -> name << endl;
                temp = temp -> next;
            }
            temp1 = temp1 -> next;
        }
        St = St -> next;
    }
    fo.close();
}

void exportCourseScore(student *Stt , string name)
{
    ofstream fo(name + "Scoreboard.csv");
    //cerr << "..............." << endl;
    fo << ",,,,,,,,,," << name << endl;
    fo << "No,Student ID,Student Full Name,Total Mark,Final Mark,Midterm Mark,Other Mark" << endl;
    int cnt = 0;
    student *St = Stt;
    while(St != NULL)
    {
        auto *temp1 = St -> semST;
        while(temp1 != NULL)
        {
            course *temp = temp1 -> cs;
            while(temp != NULL)
            {
                if(temp -> id == name && temp -> enrolled == true)
                    fo << (++cnt) << "," << St -> username << "," << St -> name << endl;
                temp = temp -> next;
            }
            temp1 = temp1 -> next;
        }
        St = St -> next;
    }
    fo.close();
    cout << "Done" << endl;
}

float fromStringToFloat(string s) /// đổi string sang float
{
    float temp = 1;
    float ret = 0;
    bool ok = false;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == '.')
            ok = true;
        else if(s[i] >= '0' && s[i] <= '9')
        {
            if(ok == true)
            {
                temp /= 10;
                ret = ret  + temp * (s[i] - 48);
            }
            else
            {
                ret = ret * 10 + (s[i] - 48);
            }
        }
    }
    return ret;
}


void assignMark(student *st , string name)
{
    ifstream fi(name +"Scoreboard.csv");
    string s;
    getline(fi , s);
    getline(fi , s);
    while(getline(fi , s))
    {
        string words[10];
        int cnt = 1;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == ',')
                cnt++;
            else
                words[cnt].push_back(s[i]);
        }
        student *temp = st;
        //cerr << "=====" << endl;
        while(temp != NULL)
        {
            if(temp -> username == words[2])
            {
                auto temp1 = temp -> semST;
                while(temp1 != NULL)
                {
                    //cerr << ";;" << endl;
                    course *temp2 = temp1 -> cs;
                    while(temp2 != NULL)
                    {
                        //cerr << temp2 -> id << " " << name << endl;
                        if(temp2 -> id == name)
                        {
                            temp2 -> mark.totalMark = fromStringToFloat(words[4]);
                            temp2 -> mark.finalMark = fromStringToFloat(words[5]);
                            temp2 -> mark.midMark = fromStringToFloat(words[6]);
                            temp2 -> mark.otherMark = fromStringToFloat(words[7]);
                            //cerr << temp -> username << " " << fromStringToFloat(words[4]) << " " << fromStringToFloat(words[5]) << " " << words[6] << " " << words[7] << endl;
                        }
                        temp2 = temp2 -> next;
                    }
                    temp1 = temp1 -> next;
                }
            }
            temp = temp -> next;
        }
    }
    cout << "Done" << endl;
    fi.close();
}
