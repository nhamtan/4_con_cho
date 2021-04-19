#include"login.h"
#include <bits/stdc++.h>
using namespace std;



student* isStudent(student *&St , string username)
{
    while(St != NULL)
    {
        if(St -> username == username)
            return St;
        St = St -> next;
    }
    return NULL;
}

staff* isStaff(staff *&Sf , string username)
{
    while(Sf != NULL)
    {
        if(Sf -> username == username)
            return Sf;
        Sf = Sf -> next;
    }
    return NULL;
}

void login(student *&St , staff *&Sf)
{
    initStudent(St);
    initStaff(Sf);
    string s;
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








                break;
            }
        }
        system("pause");
        system("cls");
    }

}

