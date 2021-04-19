#pragma once
#include<bits/stdc++.h>
using namespace std;

#ifndef _staff_h_
#define _staff_h_

struct staff{
    string password;
    string username;
    string name;
    staff *next ;
};
void initStaff(staff *&sf);
#endif // staff_h_


