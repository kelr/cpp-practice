#include "SinglyLinkedList.h"

int main(void)
{
    SinglyLinkedList<int> list;
    list.push_back(1);

    list.push_back(2);

    list.push_back(3);

    list.push_back(4);
    list.print();

    list.pop_back();
    list.print();

    list.push_head(7);
    list.print();

    list.pop_head();

    std::cout << "head: " << list.get_head() << std::endl;

    std::cout << "tail: " <<  list.get_tail() << std::endl;

    std::cout << "size: " << list.get_size() << std::endl;

    std::cout << "isempty: " << list.is_empty() << std::endl;

    list.remove_first_encounter(1);

    list.print();

    list.insert(77,1);

    list.print();

    std::cout << "data at pos 1: " << list.get_data_at(1) << std::endl;

    list.remove(1);

    list.print();

    //list.reverse()

    return 0;
}