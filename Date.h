#ifndef DATE_H
#define DATE_H
#pragma once
class Date {
    int date;
    int month;
    int year;

public:
    Date(int d, int m, int y);
    void AddDate(const int& d, const int& m, const int& y);
    int GetDate();
    int GetMonth();
    int GetYear();
};
#endif // DATE_H
