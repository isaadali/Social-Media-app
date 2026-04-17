#ifndef ACTIVITY_H
#define ACTIVITY_H

#pragma once
#include<QString>
class Activity
{
    int type;
    QString value;
public:
    Activity();
    QString GetActivity(const  int& a);
};

#endif // ACTIVITY_H
