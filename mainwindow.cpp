#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    totalPost = 0;
    memory = false;
    totaluser = 10;
    totalPost = 0;
    share=false;

    user = new User * [totaluser];
    for (int i = 0; i < totaluser; i++)
    {
        user[i] = new User;
    }
    user[0]->Input(111, "saad ali");
    user[1]->Input(222, "adnan");
    user[2]->Input(333, "hamza");
    user[3]->Input(444, "rohan");
    user[4]->Input(555, "Ikram");
    user[5]->Input(666, "Saad sohail");
    user[6]->Input(777, "Subhan");
    user[7]->Input(888, "Jamshaid");
    user[8]->Input(999, "Umair");
    user[9]->Input(100, "Sohaib");

    // Initialize pages
    totalpage = 5;
    page = new Page * [totalpage];
    for (int i = 0; i < totalpage; i++)
    {
        page[i] = new Page;
    }
    page[0]->PageOwner(10, "Food Fusion");
    page[1]->PageOwner(11, "Love birds");
    page[2]->PageOwner(12, "Cocktail");
    page[3]->PageOwner(13, "Budgie");
    page[4]->PageOwner(14, "Say no to Plastic");

    // Set up friendships
    user[0]->AddFriend(3);
    user[0]->AddFriend(2);
    user[0]->AddFriend(1);
    user[1]->AddFriend(0);
    user[1]->AddFriend(4);
    user[1]->AddFriend(5);
    user[2]->AddFriend(6);
    user[2]->AddFriend(7);
    user[2]->AddFriend(8);
    user[3]->AddFriend(2);
    user[3]->AddFriend(9);
    user[3]->AddFriend(8);
    user[4]->AddFriend(5);
    user[4]->AddFriend(3);
    user[4]->AddFriend(1);
    user[5]->AddFriend(0);
    user[5]->AddFriend(7);
    user[5]->AddFriend(8);
    user[6]->AddFriend(3);
    user[6]->AddFriend(4);
    user[6]->AddFriend(5);
    user[7]->AddFriend(9);
    user[7]->AddFriend(8);
    user[7]->AddFriend(0);
    user[8]->AddFriend(1);
    user[8]->AddFriend(2);
    user[8]->AddFriend(3);
    user[9]->AddFriend(0);
    user[9]->AddFriend(7);
    user[9]->AddFriend(6);

    // Set up page likes
    user[0]->AddLikePage(10);
    //user[0]->AddLikePage(4);
    user[1]->AddLikePage(11);
    //user[1]->AddLikePage(6);
    user[2]->AddLikePage(12);
    //user[2]->AddLikePage(7);
    user[3]->AddLikePage(14);
    //user[3]->AddLikePage(8);
    user[4]->AddLikePage(13);
    //user[4]->AddLikePage(5);
    user[5]->AddLikePage(12);
    //user[5]->AddLikePage(8);
    user[6]->AddLikePage(11);
    //user[6]->AddLikePage(5);
    user[7]->AddLikePage(14);
    // user[7]->AddLikePage(6);
    user[8]->AddLikePage(13);
    //  user[8]->AddLikePage(8);
    user[9]->AddLikePage(11);
    //    user[9]->AddLikePage(5);


    // Set current date
    time_t now = time(0);
    struct tm local_time;
    localtime_s(&local_time, &now);
    year = local_time.tm_year + 1900;
    month = local_time.tm_mon + 1;
    date = local_time.tm_mday;
    page[0]->AddPost(10, "kashmiri tea", totalPost, post,date,month,year,2);
    post[totalPost - 1]->SetPostMessage("Please try it!!");
    user[0]->Addpost(444, "I am having fun", totalPost, post,  date-1, month, year,3);
    post[totalPost - 1]->SetPostMessage("You should come here");
    user[0]->Addpost(111, "I am alright!", totalPost, post, date - 2, month, year,3);
    post[totalPost - 1]->SetPostMessage("Your prayers save me");
    // Add comments to posts
    user[0]->Pluscomment("I will try it", 0,111,post, totalPost);
    page[1]->CommentPlus("It looks tasty", 0,10,post, totalPost);

    user[0]->Addpost(111, "Success", totalPost, post, date , month , year-2, 3);
    post[totalPost - 1]->SetPostMessage("Got A in toughest Exam !");
     user[0]->Pluscomment("Congratulations!", totalPost - 1, 333, post, totalPost);
    user[0]->Addpost(222, "I will go to mountains", totalPost, post, date - 1, month-1, year,3);
    post[totalPost - 1]->SetPostMessage("I wish you all also go there");
    user[0]->Pluscomment("I hope you are enjoying it", totalPost - 1, 333, post, totalPost);
    user[0]->Addpost(333, "I am alright!", totalPost, post, date - 2, month, year-1,3);
    post[totalPost - 1]->SetPostMessage("I wish you all are right!");
    user[0]->Pluscomment("I also wanna go there", totalPost-1, 777, post, totalPost);
    // giving every post a page like
    for (int i = 0; i < totalPost; i++)
    {
        post[i]->AddPostLike(12);
    }


}

MainWindow::~MainWindow()
{
    delete ui;
    for(int i=0;i<totalPost;i++)
    {
        delete post[i];
    }
    delete[]post;
    for(int i=0;i<totaluser;i++)
    {
        delete user[i];
    }
    delete[]user;
    for(int i=0;i<totalpage;i++)
    {
        delete page[i];
    }
    delete[]page;
    delete[]ownerid;
    delete l;
    l=nullptr;

}

void MainWindow::on_loginButton_clicked()
{
    bool found=true;
   QString mo = ui->userid->text();
     currentid=mo.toInt();
   QString qStr = "Welcome ";
   currentuser+=qStr;

    for (int i = 0; i < totaluser; i++)
    {
        if ((user[i]->finduser(currentid)))
        {
            found=false;
             no = i;
            currentuser += user[i]->GetName();
            break;
        }
    }
    if(found==false)
    {
        ui->username->setText(currentuser);
        ui->stackedWidget->setCurrentIndex(2);
        ui->userid->clear();

    }else
    {
        QMessageBox::critical(this, "Error", "Enter Correct User Id ");

    }

}


void MainWindow::on_menuButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_friendButton_clicked()
{
    ui->friendlist->clear(); // Clear previous entries

    user[no]->GetAllPage(page);
    user[no]->SetTotalPage(totalpage);
    user[no]->viewlikepage();

    int** dummy;
    user[no]->s(dummy);

    for (int i = 0; i < user[no]->Getfriends(); i++) {
        QString name = user[*dummy[i]]->GetName();
        int p=user[*dummy[i]]->GetUserId();
        QString displayText = QString("%1 (ID: %2)").arg(name).arg(p);


        ui->friendlist->addItem(displayText);
    }

    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_userpageButton_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_likepageButton_clicked()
{
    // Clear the like pages list before adding new entries
    ui->likepagelist->clear();
    int **page_id;
    user[no]->GetPageIds(page_id);
    int tlikepages=user[no]->GetLikePages();
    for (int i = 0; i < tlikepages; i++)
    {
        for (int j = 0; j < totalpage; j++)
        {

            if (*page_id[i] == page[j]->GetPageID())
            {
               QString pageName = page[j]->GetPageName();
                int pageID = page[j]->GetPageID();
                QString displayText = QString("%1 (ID: %2)").arg(pageName).arg(pageID);
                ui->likepagelist->addItem(displayText);
            }

        }
    }



    // Switch UI screen
    ui->stackedWidget->setCurrentIndex(5);

}


void MainWindow::on_pushButton_clicked()
{
 ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_postButton_clicked()
{
    ui->listWidget->clear();
    ui->listWidget_2->clear();
    ui->lineEdit->clear();

    QString userInput = QInputDialog::getText(nullptr, "Enter post no", "Please enter post no");
    int p_no=userInput.toInt()-1;
    QString post_name;
    QString post_message;
    if(p_no<totalPost)
    {
    for (int i = 0; i < totalPost; i++)
    {
        if (p_no ==i)
        {
            if (post[i]->GetPostId() > 100)
            {
                for (int j = 0; j < totaluser; j++)
                {
                    bool found = false;
                    if (post[i]->GetPostId() == user[j]->GetUserId())
                    {
                        found = 1;
                      post_name= user[j]->GetName() ;
                    }
                    if (found)
                    {   break;}
                }
                 post_message=  post[i]->GetPostMessage() ;
            }
            else
                {
                    for (int j = 0; j < totalpage; j++)
                    {
                        bool found = false;
                        if (post[i]->GetPostId() == page[j]->GetPageID())
                        {
                            found = 1;
                            post_name= page[j]->GetPageName() ;
                        }
                        if (found)
                        {
                            break;
                        }
                    }
                    post_message=  post[i]->GetPostMessage() ;
                }
            int d,m,y;
                post[p_no]->GetDate(d,m,y);
            post[p_no]->SetPageNO(totalpage);
            post[p_no]->SetUserNo(totaluser);
            post[p_no]->GetUser(user);
            post[p_no]->GetPage(page);
            QString discript=post_name+" "+post[p_no]->GetPostName();
            ui->lineEdit_2->setText(discript);
            ui->postname->setText(post_name);
            QListWidgetItem *item = new QListWidgetItem(post_message);
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            item->setSizeHint(QSize(item->sizeHint().width(), 50)); // adjust height as needed
            ui->listWidget->addItem(item);

                QString cc;
                post[p_no]->DisplayComment(cc);
                ui->listWidget_2->addItem(cc);
                QString dateText = QString("%1/%2/%3").arg(d).arg(m).arg(y);
                ui->lineEdit->setText(dateText);

            }
        }
    ui->stackedWidget->setCurrentIndex(6);
    }
    else
    {
        QMessageBox::critical(this, "Error", "The post does not exist ");
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::on_pushButton_3_clicked()
{
    QString userInput = QInputDialog::getText(nullptr, "Enter post no", "Please enter post no");
    int p_no=userInput.toInt()-1;
    if(p_no<totalPost){
     post[p_no]->AddPostLike(currentid );
     QMessageBox::information(this, "Done", "OK, it's done!");
    }else
    {
        QMessageBox::critical(this, "Error", "The post does not exist ");
    }


}






void MainWindow::on_pushButton_4_clicked()
{
    QString userInput = QInputDialog::getText(nullptr, "Enter post no", "Please enter post no");
    int p_no=userInput.toInt()-1;
    if(p_no>totalPost){
       QMessageBox::critical(this, "Error", "The post does not exist ");
    }
    else
    {
        QString result;

        int* likeids;
        post[p_no]->GetLikeIds(likeids);
        int totallikes = post[p_no]->getTotalPostLikes();

        for (int i = 0; i < totalPost; i++)
        {
            if (p_no == i)
            {
                for (int i = 0; i < totallikes; i++)
                {
                    if (likeids[i] < 100)
                    {
                        for (int j = 0; j < totalpage; j++)
                        {
                            if (likeids[i] == page[j]->GetPageID())
                            {


                                result += QString("p%1 - %2\n")
                                .arg(page[j]->GetPageID())
                                    .arg((page[j]->GetPageName()));
                                break;
                            }
                        }
                    }
                    else
                    {
                        for (int j = 0; j < totaluser; j++)
                        {
                            if (likeids[i] == user[j]->GetUserId())
                            {

                                result += QString("u%1 - %2\n")
                                .arg(user[j]->GetUserId())
                                    .arg((user[j]->GetName()));
                                break;
                            }
                        }
                    }
                }
            }
        }

        // Display the result
        QMessageBox::information(this, "Likes", result);

    }
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->listWidget_3->clear();
    QString result,post_message;
    for (int i = 0; i < totalPost; i++)
    {
        int dd, mm, yy;
        post[i]->GetDate(dd, mm, yy);
        if ((dd == date || dd == date - 1) && (mm == month) && (yy == year))
        {
            if (post[i]->GetPostId() > 100)
            {
                for (int j = 0; j < totaluser; j++)
                {
                    bool found = false;
                    if (post[i]->GetPostId() == user[j]->GetUserId())
                    {
                        found = 1;
                        result= user[j]->GetName() +" ";
                    }
                    if (found)
                    {   break;}
                }
                post_message=  post[i]->GetPostMessage() ;
            }
            else
            {
                for (int j = 0; j < totalpage; j++)
                {
                    bool found = false;
                    if (post[i]->GetPostId() == page[j]->GetPageID())
                    {
                        found = 1;
                        result= page[j]->GetPageName()+" " ;
                    }
                    if (found)
                    {
                        break;
                    }
                }
                post_message=  post[i]->GetPostMessage() ;
            }
            QString discript=post[i]->GetPostName();
            result +=discript  + "\n";
            result+=post_message+"\t";
            int dd, mm, yy;
            post[i]->GetDate(dd, mm, yy);
            QString dss = QString("%1/%2/%3").arg(dd).arg(mm).arg(yy);
            result+=dss;
            post[i]->SetPageNO(totalpage);
            post[i]->SetUserNo(totaluser);
            post[i]->GetUser(user);
            post[i]->GetPage(page);
            QString cc;
            post[i]->DisplayComment(cc);
            ui->listWidget_3->addItem(result);
            ui->listWidget_3->addItem(cc);


        }
    }
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_6_clicked()
{
    QString userInput = QInputDialog::getText(nullptr, "Enter post no", "Please enter post no");
    int p_no=userInput.toInt()-1;
    if(p_no>totalPost){
        QMessageBox::critical(this, "Error", "The post does not exist ");
    }
    else
    {
        QString a= QInputDialog::getText(nullptr, "Type comment", "Comment ");
        user[1]->Pluscomment(a, p_no, currentid, post, totalPost);
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    QString p_message;
    bool found=false;
ui->listWidget_7->clear();
    for (int i = 0; i < totalPost; i++)
    {
        if (post[i]->GetPostId() == currentid)
        {
            QString result;
            if(currentid>100){
            for (int j = 0; j < totaluser; j++)
            {
                if (currentid == user[j]->GetUserId()) {
                    result += user[j]->GetName() + " ";
                }
            }
            }
            else {
                for (int j = 0; j < totalpage; j++) {
                    if (currentid == page[j]->GetPageID()) {
                        result += page[j]->GetPageName() + " ";
                    }
                }
            }
            post[i]->SetPageNO(totalpage);
            post[i]->SetUserNo(totaluser);
            post[i]->GetUser(user);
            post[i]->GetPage(page);
            p_message =post[i]->GetPostMessage();
            QString discript=post[i]->GetPostName();
            result +=discript  + "\n";
            result+=p_message+"\t";
            int dd, mm, yy;
            post[i]->GetDate(dd, mm, yy);
            QString dss = QString("%1/%2/%3").arg(dd).arg(mm).arg(yy);
            result+=dss;
            found=true;
            QString cc;
            post[i]->DisplayComment(cc);
            ui->listWidget_7->addItem(result);
            ui->listWidget_7->addItem(cc);
        }
    }
    if(!found)
    {
          QMessageBox::critical(this, "Error", "The post does not exist ");
    }else
    {
        ui->stackedWidget->setCurrentIndex(9);
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->listWidget_5->clear();

    QString qr = "We hope you enjoy looking back and sharing your memories on Facebook, from the most recent "
                 "to those long ago\n";
    qr+="On this day \n";
    ui->listWidget_5->addItem(qr);

    for (int i = 0; i < totalPost; i++)
    {
        int dd, mm, yy;
        post[i]->GetDate(dd, mm, yy);

        if (dd == date && mm == month && yy != year)
        {
            QString result;

            QString post_message;

            // Add user/page name
            int postId = post[i]->GetPostId();
            if (postId > 100)  // User post
            {
                for (int j = 0; j < totaluser; j++)
                {
                    if (postId == user[j]->GetUserId())
                    {
                        result += user[j]->GetName();
                        break;
                    }
                }
            }
            else  // Page post
            {
                for (int j = 0; j < totalpage; j++)
                {
                    if (postId == page[j]->GetPageID())
                    {
                        result += page[j]->GetPageName();
                        break;
                    }
                }
            }

            // Post details
            QString description = post[i]->GetPostName();
            post_message = post[i]->GetPostMessage();
            result += "\n" + description + "\n" + post_message + "\t";

            QString dss = QString("%1/%2/%3").arg(dd).arg(mm).arg(yy);
            result += dss;
            QString cc;
            post[i]->DisplayComment(cc);

            // Display post and its comments
            ui->listWidget_5->addItem(result);
            ui->listWidget_5->addItem(cc);
        }
    }

    ui->label_8->setText("Memories");
    ui->stackedWidget->setCurrentIndex(8);
}



void MainWindow::on_pushButton_12_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_9_clicked()
{
    QString about = QInputDialog::getText(this, "About", "What is post about");

    user[0]->Addpost(currentid, about, totalPost, post, date, month, year, 3);

        QString message = QInputDialog::getText(this, "About", "What do you wanna say");
post[totalPost - 1]->SetPostMessage(message);
}


void MainWindow::on_pushButton_11_clicked()
{
    share=1;
    QString about = QInputDialog::getText(this, "About", "What is post about");

    user[0]->Addpost(currentid, about, totalPost, post, date, month, year, 4);

    QString message = QInputDialog::getText(this, "About", "What do you wanna say");
    post[totalPost - 1]->SetPostMessage(message);
      mem.ShareMemory(totalPost - 1,post[totalPost-1]);
}


void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->listWidget_6->clear();


    QString post_message;    // For message text
    QString result;          // For combined output (name + post + date)

    // Normal post (not memory)
    for (int i = 0; i < totalPost; i++) {
        if (post[i]->GetPostId() == currentid) {

            // Find the post owner name
            if (currentid > 100) {
                for (int j = 0; j < totaluser; j++) {
                    if (currentid == user[j]->GetUserId()) {
                        result += user[j]->GetName() + " ";
                        break;
                    }
                }
            } else {
                for (int j = 0; j < totalpage; j++) {
                    if (currentid == page[j]->GetPageID()) {
                        result += page[j]->GetPageName() + " ";
                        break;
                    }
                }
            }

            // Setup for comment display
            post[i]->SetPageNO(totalpage);
            post[i]->SetUserNo(totaluser);
            post[i]->GetUser(user);
            post[i]->GetPage(page);

            post_message = post[i]->GetPostMessage();
            QString description = post[i]->GetPostName();

            result += description + "\n";
            result += post_message + "\t";

            int dd, mm, yy;
            post[i]->GetDate(dd, mm, yy);
            QString dateString = QString("%1/%2/%3").arg(dd).arg(mm).arg(yy);
            result += dateString+"\n";
            QString cc;
            post[i]->DisplayComment(cc);
            result+=cc;

        }
    }

    ui->listWidget_6->addItem(result);
    ui->label_9->setText("TimeLine");
    ui->stackedWidget->setCurrentIndex(10);

}


void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

