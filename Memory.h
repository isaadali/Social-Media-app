#ifndef MEMORY_H
#define MEMORY_H
#pragma once
#include"post.h"
class Memory: public Post
{
    Post* Ptr;
    int id;
public:
    void ShareMemory(int i,Post *ptr);
    void ShowMemory(Post* &p);
    int GetMemoryId();
    ~Memory();
};
#endif // MEMORY_H
