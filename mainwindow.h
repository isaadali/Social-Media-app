#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"iuser.h"
#include"page.h"
#include"post.h"
#include"Memory.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void Run();
    ~MainWindow();

private slots:
    void on_loginButton_clicked();

    void on_menuButton_clicked();

    void on_friendButton_clicked();

     void on_userpageButton_clicked();

     void on_likepageButton_clicked();

     void on_pushButton_clicked();

     void on_postButton_clicked();

    void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();





     void on_pushButton_4_clicked();

     void on_pushButton_5_clicked();

     void on_pushButton_6_clicked();

     void on_pushButton_7_clicked();

     void on_pushButton_8_clicked();



     void on_pushButton_12_clicked();

     void on_pushButton_14_clicked();

     void on_pushButton_9_clicked();

     void on_pushButton_11_clicked();

     void on_pushButton_15_clicked();

     void on_pushButton_10_clicked();

     void on_pushButton_16_clicked();

 private:
    Ui::MainWindow *ui;
    User** user;
    Post*l;
    bool share;
    int no;
    QString currentuser;
    int* ownerid;
    int currentid;
   QString command;
    int totaluser;
    int totalpage;
    Page** page;
    Post** post;
    int totalPost;
    int date, month, year;
    Memory mem;
    bool memory ;


};
#endif // MAINWINDOW_H
