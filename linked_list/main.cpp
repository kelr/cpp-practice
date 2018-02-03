#include "SinglyLinkedList.h"

int main(void)
{
    SinglyLinkedList<int> list;
    list.push_back(1);

    //list.push_back(2);

    //list.push_back(3);

    //list.push_back(4);
    list.print();

    list.pop_back();
    list.print();

    //list.push_head(7);
    //list.print();

    return 0;
}