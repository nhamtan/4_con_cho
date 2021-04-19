#include"student.h"
#include"staff.h"
#include <bits/stdc++.h>
using namespace std;


#ifndef _login_h_
#define _login_h_

struct loginUser
{
    string username;
    string pass;
};
void login(student *&St , staff *&Sf);
student* isStaff(student *&Sf , string username);
student* isStudent(student *&St , string username);

#endif





