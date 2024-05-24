#include "ForwardList.h"

int main()
{
    ForwardList fList;

    fList.PushFront(1);
    fList.PushFront(2);
    fList.PushBack(3);
    fList.PushBack(4);
    std::cout << fList << "\n"; // 2 1 3 4

    fList.PopBack();
    std::cout << fList << "\n"; // 2 1 3 

    fList.PopFront();
    std::cout << fList << "\n"; // 1 3 

    fList.PushFront(1);
    fList.PushFront(2);
    fList.PushFront(1);
    std::cout << fList << "\n"; // 1 2 1 1 3 
    fList.Erase(1);
    std::cout << fList << "\n"; // 2 3 

    fList.Insert(4, 2);
    std::cout << fList << "\n"; // 4 2 3 

}