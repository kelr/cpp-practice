#include "SinglyLinkedList.h"


int main(void)
{
    SinglyLinkedList list = SinglyLinkedList();
    Node* input = new Node;
    input->data = 1;

    list.push_back(input);
    list.push_back(input);
    list.push_back(input);
    list.push_back(input);
    list.print();

    delete input;

    return 0;
}