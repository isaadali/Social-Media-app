#include"Date.h"
Date::Date(int d,int m,int y)
{
    date = d, month = m, year = y;
}
void Date::AddDate(const int& d, const int& m, const int& y)
{
    date = d, month = m, year = y;
}
int Date::GetDate()
{
    return date;
}
int Date::GetMonth()
{
    return month;
}
int Date::GetYear()
{
    return year;
}
