#include"page.h"
#include"post.h"
Page::Page()
{
    noofposts = 0;
    temppage = nullptr;
    Id = 0;
    title = "";

    totallikes = 0;

}
void Page::GetAllPage(Page** p)
{
    temppage = p;
}
void Page::PageOwner(int id,QString a)
{
    title=a;
    Id = id;
}
int Page::GetPageID()
{
    return Id;
}
QString Page::GetPageName()
{
    return title;
}
void Page::AddPost(int a,QString b, int& total, Post**& p,const int &d,const int &m,const int& y,const int &u)
{

    Post** temp = new Post * [total + 1];
    QString chartemp;
    Post q;
    chartemp = q.Getactivity(u);
    for (int i = 0; i < total; i++) {
        temp[i] = p[i];
    }


    temp[total] = new Post(a, b, d, m, y,chartemp);


    delete[] p;


    p = temp;
    total++;
}
void Page:: CommentPlus(QString a, int postno, int ID, Post** p,const int &t)
{
    for (int i = 0; i < t; i++)
    {
        if (postno == i)
            p[postno]->PlusComment(a, ID);
    }
}
Page::~Page() {



     delete[] temppage;
}


