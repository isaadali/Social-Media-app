#include "Post.h"
#include"Date.h"
#include"iuser.h"
Post::Post()
    : date(1, 1, 2000), Id(0), nooflikes(0), maxcomment(10), currentcomment(0),
    userid(nullptr), comment(nullptr), commentid(nullptr), user(nullptr), page(nullptr), tpage(0), tuser(0) ,message(""),description(""){

}

Post:: Post(int id, const QString& a, int d, int m, int y, const QString& b)
    : date(d, m, y), Id(id), nooflikes(0), maxcomment(10), currentcomment(0),
    tpage(0), tuser(0) {


        description = b;
        description+=" ";
        description +=a;

}

QString Post::GetPostMessage()
{
    return message;
}

void Post::SetPostMessage(QString a)
{
    message=a;
    // message = new char  [strlen(a) + 1];
    // strcpy_s(message, strlen(a) + 1, a);
}
void Post::GetUser(User** l) {
    user = l;
}

void Post::GetPage(Page** p) {
    page = p;
}
void Post::SetUserNo(int l)
{
    tuser = l;
}
void Post::SetPageNO(int l)
{
    tpage = l;
}
void Post::GetLikeIds(int*& l) {
    l = userid;
}

bool Post::check(int o) {
    for (int i = 0; i < nooflikes; i++) {
        if (userid[i] == o) {
            return true;
        }
    }
    return false;
}

void Post::Description(QString  a) {
    description=a;

}



void Post::PostInput(int id) {
    Id = id;
}

void Post::AddPostLike(int l) {
    bool checklike = check(l);
    if (!checklike) {
        int* temp = new int[nooflikes + 1];
        for (int i = 0; i < nooflikes; i++) {
            temp[i] = userid[i];
        }
        temp[nooflikes] = l;
        delete[] userid;
        userid = temp;
        nooflikes++;
    }
    else {
        int* temp = new int[nooflikes - 1];
        int m = 0;
        for (int i = 0; i < nooflikes; i++) {
            if (userid[i] != l) {
                temp[m++] = userid[i];
            }
        }
        delete[] userid;
        userid = temp;
        nooflikes--;
    }
}

int Post::getTotalPostLikes() {
    return nooflikes;
}

int Post::GetPostId() {
    return Id;
}

QString Post::GetPostName() {
    return description;
}

void Post::PlusComment(QString a,int z) {

    Comment** temp = new Comment * [currentcomment + 1];

    // Copy existing comments to new array
    for (int i = 0; i < currentcomment; i++) {
        temp[i] = new Comment;
        temp[i]->AddComment(comment[i]->GetComment());
        temp[i]->SetCommentUserId(comment[i]->GetCommentUserId());
    }
    temp[currentcomment] = new Comment;
    temp[currentcomment]->AddComment(a);
    temp[currentcomment]->SetCommentUserId(z);

    currentcomment++; // Increment count

    // Free old memory before replacing the comment array
    for (int i = 0; i < currentcomment - 1; i++) {
        delete comment[i]; // Properly delete each old comment
    }
    //delete[] comment;

    // Update comment array with new allocated memory
    comment = temp;
}

void Post:: DisplayComment(QString &displayText)
{
    for (int i = 0; i < currentcomment; i++) {
        int temp = comment[i]->GetCommentUserId();

        if (temp > 100)
        { // If the comment is from a user
            for (int j = 0; j < tuser; j++) {
                if (temp == user[j]->GetUserId()) {
                    displayText += user[j]->GetName() + " wrote: "+"  ";
                    break;
                }
            }
        }
        else { // If the comment is from a page
            for (int j = 0; j < tpage; j++) {
                if (temp == page[j]->GetPageID()) {
                    displayText += page[j]->GetPageName() + " wrote:" +"  ";
                    break;
                }
            }
        }

        displayText += comment[i]->GetComment() + "\n"; // Append comment text
    }
}
void Post::GetDate(int &d,int &m,int &y)
{
    d = date.GetDate();
    m = date.GetMonth();
    y = date.GetYear();
}

QString Post::Getactivity(int u)
{
    QString temp;
    temp=act.GetActivity(u);
    return temp;
}
Post::~Post() {

    for (int i = 0; i < currentcomment; i++) {
        delete comment[i];
    }
    delete[] comment;

    delete[] userid;
    delete[] commentid;

    // Delete associated User and Page pointers
    delete[] user;
    delete[] page;
}


