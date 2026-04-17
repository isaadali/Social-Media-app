#ifndef USER_H
#define USER_H

#pragma once
//#include<iostream>
#include <QString>
#include "page.h"
#include"post.h"
class User
{
private:
    int id;
    QString name;
    int totalfriends;
    int** friends;
    User** user;
    int** pageid;
    Page** temppage;
    Post** post;
    int likepages;
    int pageId;
    int totalpage;
    int t_post;
public:
    User();
    void SetTotalPage(int p);
    void GetPageIds(int**& p);
    void GetAllPage(Page** p);
    void Input(int id,QString fname);
    bool finduser(int m);           // Match by user ID
    void s(int**& f);               // Get pointer to friends array
    int Getfriends();               // Get number of friends
    int GetUserId();                // Get user ID
   QString GetName();               // Get user name
    void AddFriend(int p);          // Add a friend by ID
    int GetLikePages();             // Get number of liked pages
    void viewlikepage();            // Display liked pages
    void AddLikePage(int p_id);
    void Addpost(int a, QString b, int& total, Post**&, const int& d, const int& m, const int& y,const int &u);
    void Pluscomment(QString a,int postno, int ID,Post**p,int t);
    ~User();
};

#endif // USER_H
