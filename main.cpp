#include"student.h"
#include"staff.h"
#include"login.h"
#include"course.h"
#include <bits/stdc++.h>
using namespace std;

student *St;
staff *Sf;

int main()
{
    schoolYear * sy = nullptr;
    login(St ,Sf,sy);
    createASchoolYear(sy);
    createSemester(sy, St);
    updateCourse(sy, St);

}
