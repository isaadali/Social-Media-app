#include"Activity.h"
//#include<QString>
Activity::Activity()
{
    value = nullptr;
    type = 0;
}
QString Activity::GetActivity(const  int& a)
{
    if (a == 1)
    {
        value="feeling";
         return value;
    }else if(a==2)
    {
        value="making";
         return value;
    }
    else if(a==3){
         value="shared";
        return value;
    }
    else if (a == 4)
    {
         value=" shared memory";
        return value;
    }
    else {
         value="shared";
        return value;
    }

}
