#include"staff.h"
#include<bits/stdc++.h>
using namespace std;



void initStaff(staff *&Sf) /// cái hàm này sẽ tạo ra một list Sf chứa toàn bộ tải khoản và mật khẩu của staff.
{
    string path = "Staffs.csv";
    ifstream cin(path.c_str());
    string temp;
    getline(cin , temp);
    staff *cur;
    while(getline(cin , temp))
    {
        string words[7];
        int cnt = 1;
        for(int i = 0 ; i < temp.size() ; i++)
        {
            if(temp[i] == ',')
                cnt++;
            else
                words[cnt].push_back(temp[i]);
        }
        if(Sf == NULL)
        {
            Sf = new staff;
            cur = Sf;
        }
        else
        {
            cur -> next = new staff;
            cur = cur -> next;
        }
        cur -> username = words[3];
        cur -> password = words[2];
        cur -> name = words[4]  + " " + words[3];
    }
    cin.close();
}

