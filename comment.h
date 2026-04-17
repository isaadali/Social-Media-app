#ifndef COMMENTS_H
#define COMMENTS_H
#pragma once
//#include <iostream>
#include <QString>

class Comment {
  QString comment;
    int userid;
public:
    Comment();
    void AddComment(QString  a);
    void SetCommentUserId(int a);
    int GetCommentUserId();
    //void DisplayComment();
    QString GetComment();

};


#endif // COMMENTS_H
