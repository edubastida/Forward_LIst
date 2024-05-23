#include "ForwardList.h"

int main()
{
	ForwardList f;
	f.PushBack(1);
	f.PushBack(2);
	f.PushBack(3);
	f.PushBack(1);
	f.PushBack(5);
	f.Erase(1);
}