#include"student.h"
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

string Capitalize_first_letter(string text) /// viết hoa chữ cái đầu của mỗi từ
{
	for (int x = 1; x < text.length(); x++)
	{
		if(text[x - 1] != ' ' && text[x] != ' ')
			text[x] = text[x] - 'A' + 'a';
	}
	return text;
}

void initStudent(student *&St) /// cái hàm này sẽ tạo ra cái list ST chứa toàn bộ tải khoản và mật khẩu của học sinh.
{
    string s = "20CTT";
    student *cur = NULL;
    for(char i = '1' ; i <= '2' ; i++)
    {
        /// đọc 2 file
        string path = s + i + ".csv";
        ifstream cin(path);
        /// truy cập vào từng file
        string temp;
        /// truy cập các dòng
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
            //cerr << words[2] << " " << words[4] << "\n";
            string Date[4];
            cnt = 1;
            for(int i = 0 ; i < words[4].size() ; i++)
            {
                if(words[4][i] == '/')
                {
                    cnt++;
                    if(cnt == 2 && words[4][i + 2] == '/')
                         Date[cnt].push_back('0');
                }
                else
                {
                    if(cnt == 1 && words[4][1] == '/')
                        Date[cnt].push_back('0');
                    Date[cnt].push_back(words[4][i]);
                }
            }
            //cerr << Date[2] << "\n";
            if(St == NULL)
            {
                St = new student;
                cur = St;
            }
            else
            {
                cur -> next = new student;
                cur = cur -> next;
            }
            words[3] = Capitalize_first_letter(words[3]);
            cur -> username = words[2];
            cur -> password = Date[2] + Date[1] + Date[3];
            cur -> name = words[3];
            //cout << cur -> username << " " << cur -> password << endl;
        }
        cin.close();
    }
}
