#include "iuser.h"
#include"page.h"
#include<string>
using namespace std;
User::User()
{
    id = -1;
    name ="";
    temppage = NULL;
    likepages = 0;
    pageId = 0;
    pageid = nullptr;
    user = nullptr;
    friends = nullptr;
    id = -1;
    totalfriends = 0;
    t_post=0;
}

void User::GetAllPage(Page** p) // get all pages so that access only like pages
{
    temppage = p;
}
//void GetUsers(User** l) //
//{
//	user = l;
//} // dont know why i made it
void User::Input(int id,QString fname)
{
    name=fname;
    this->id = id;
}
void User::GetPageIds(int**& p)
{
    p = pageid;
}
bool User::finduser(int m)
{
    if (id == m)
    {
        return true;
    }
    return false;
}
void User::s(int**& f)
{
    f = friends;
}
int User::Getfriends()
{
    return totalfriends;
}
int User::GetUserId()
{
    return id;
}
QString User::GetName()
{
    return name;
}
void User::AddFriend(int p)
{
    if (totalfriends == 0)
    {

        int** temp;
        temp = new  int* [totalfriends + 1];
        for (int i = 0; i < totalfriends + 1; i++)
        {
            temp[i] = new int;
        }
        *temp[totalfriends] = p;
        totalfriends++;
        friends = temp;
    }
    else
    {
        int** temp;
        temp = new  int* [totalfriends + 1];

        for (int i = 0; i < totalfriends; i++)
        {
            temp[i] = new int;
            *temp[i] = *friends[i];
        }
        temp[totalfriends] = new int;
        *temp[totalfriends] = p;
        totalfriends++;
        delete[]friends;
        friends = temp;
    }
}
int User::GetLikePages()
{
    return likepages;
}
void User::SetTotalPage(int p)
{
    totalpage = p;
}
void User::viewlikepage()
{

    for (int i = 0; i < likepages; i++)
    {
        for (int j = 0; j < totalpage; j++)
        {
            bool found = false;
            if (*pageid[i] == temppage[i]->GetPageID())
            {
                found = true;
            //    cout << "p" << temppage[i]->GetPageID() << "-" << temppage[i]->GetPageName();
            }
            if (found)
                break;
        }
    }

}

void User::AddLikePage(int p_id)
{
    if (likepages == 0)
    {
        likepages++;
        pageId = p_id;
        pageid = new int* [likepages];
        pageid[0] = new int;
        *pageid[0] = p_id;
    }
    else
    {
        int** temp;
        temp = new int* [likepages + 1];
        for (int i = 0; i < likepages; i++)
        {
            temp[i] = new int;
            *temp[i] = *pageid[i];
        }
        temp[likepages] = new int;
        *temp[likepages] = p_id;
        likepages++;
        delete[]pageid;
        pageid = temp;
    }

}
void User::Addpost(int a, QString b, int& total, Post**& p, const int& d, const int& m, const int& y,const int &u)
{

    t_post=total+1;
    Post** temp = new Post * [total + 1];
    QString chartemp;
    chartemp = p[0]->Getactivity(u);


    for (int i = 0; i < total; i++) {
        temp[i] = p[i];
    }


    temp[total] = new Post(a, b, d, m, y,chartemp);


    delete[] p;


    p = temp;
    total++;
}
void User::Pluscomment(QString a,int postno,int ID,Post**p,int t)
{
    for (int i = 0; i < t; i++)
    {
        if (postno==i)
            p[postno]->PlusComment(a, ID);
    }

}
User::~User() {

    for (int i = 0; i < totalfriends; i++) {
        delete[] friends[i];
    }
    delete[] friends;

    delete[] user;
    for (int i = 0; i < totalpage; i++) {
        delete pageid[i];
    }
    delete[] pageid;

    delete[] temppage;   // Array of page pointers
   for (int i = 0; i < t_post; i++) {
       delete post[i];
    }
    delete[] post;       // Array of Post pointers
}

