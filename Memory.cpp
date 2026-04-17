#include"Memory.h"
void Memory::ShareMemory(int i,Post *ptr)
{
    Ptr = ptr;
    id = i;

}
int Memory::GetMemoryId()
{
    return id;
}
void Memory::ShowMemory(Post*& p)
{
    p = Ptr;
}
Memory::~Memory() {
     delete Ptr;
}
