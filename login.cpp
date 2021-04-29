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
    cout <<"0. Exit"<<endl;
    cout <<"1.Log in"<<endl;
    cout <<"Enter your choice : ";
    int type;
    cin >> type;
    if(type == 0 ) return;
    else if(type ==1)
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
                /// add thêm giao diện của học sinh vào bằng hàm.

    functionStudent(St,sy);

        system("pause");
        system("cls");


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

void exportCourse(student *St , string name)
{
    ofstream fo(name + ".csv");
    while(St != NULL)
    {
        while(St -> semST != NULL)
        {
            while(St -> semST -> cs != NULL)
            {
                course *temp = St -> semST -> cs;
                if(temp -> name == name && temp -> enrolled == true)
                {
                    fo << St -> name << " " << St -> username << endl;
                }
                St -> semST -> cs = St -> semST -> cs -> next;
            }
            St -> semST = St -> semST -> next;
        }
        St = St -> next;
    }
    fo.close();
}
