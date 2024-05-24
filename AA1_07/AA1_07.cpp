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

    fList.Insert(4, 0);
    fList.Insert(8, 3);
    fList.Insert(8, 8);
    std::cout << fList << "\n"; // 4 2 3 

    ForwardList fList2;
    fList2.PushBack(3);
    fList2.PushBack(15);
    fList2.PushBack(20);
    fList2.PushBack(21);
    if (fList == fList2)
    {
        std::cout << "Equal" << "\n";
    }
    else
    {
        std::cout << "Non Equal" << "\n";
    }

    ForwardList fList3;
    fList3.PushBack(3);
    fList3.PushBack(15);
    fList3.PushBack(20);
    fList3.PushBack(21);
    if (fList2 == fList3)
    {
        std::cout << "Equal" << "\n";
    }
    else
    {
        std::cout << "Non Equal" << "\n";
    }
}