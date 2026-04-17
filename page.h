#ifndef PAGE_H
#define PAGE_H

#pragma once
#include<QString>
class Post;
class Page
{
    Page** temppage;
    int Id;
    QString title;

    int totallikes;

    int noofposts;
public:
    Page();
    void GetAllPage(Page** p);
    void PageOwner(int id,QString a);
    int GetPageID();
    QString GetPageName();
    void AddPost(int a,QString b,int &total,Post**&p, const int& d, const int& m, const int& y,const int &u);
    void CommentPlus(QString a, int postno, int ID, Post** p,const int &t);
    ~Page();
};


#endif // PAGE_H
