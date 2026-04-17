#ifndef POST_H
#define POST_H
#pragma once
#include"comments.h"
//#include"user.h"
#include "Date.h"
//#include"page.h"
#include <QString>
#include"Activity.h"
//class Date;
class User;
class Page;
class comment;
class Post
{
    int Id;
    QString message;
    QString description;
    int nooflikes;
    int* userid;
    User** user;
    Page** page;
    Comment** comment;
    Date date;
    int* commentid;
    int maxcomment, currentcomment;
    int tuser, tpage;
    Activity act;
public:
    Post();
    Post(int id, const QString& a, int d, int m, int y, const QString& b);
    void GetUser(User** l);
    void GetPage(Page** p);
    void GetLikeIds(int*& l);
    bool check(int o);
    void Description(QString  a);
    void PostInput(int id);
    void AddPostLike(int l);
    int getTotalPostLikes();
    int GetPostId();
    QString GetPostName();
    void PlusComment(QString a,int z);
    void AddDate(const int& d, const int& m, const int& y);

    void SetUserNo(int l);
    void SetPageNO(int l);
    void GetDate(int& d, int& m, int& y);
   QString Getactivity(int u);
    void SetPostMessage(QString a);
   QString GetPostMessage();
    void DisplayComment(QString &displayText);
   ~Post();
};
#endif // POST_H
