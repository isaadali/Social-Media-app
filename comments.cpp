#include"comments.h"
#include <QString>

Comment::Comment()
{
    comment = "";
}
void Comment::SetCommentUserId(int a)
{
    userid = a;
}
void Comment::AddComment(QString a)
{
    comment=a;

}
int Comment::GetCommentUserId()
{
    return userid;
}
QString Comment::GetComment()
{
    return comment;
}
