#include "QueueLinkedList.h"
#include <assert.h>

int main(void)
{
    QueueLinkedList<int>* queue = new QueueLinkedList<int>;

    queue->print();

    assert(queue->is_empty());

    queue->enqueue(5);

    queue->print();

    assert(!queue->is_empty());

    queue->enqueue(6);
    queue->print();
    queue->enqueue(7);
    queue->print();
    queue->enqueue(8);
    queue->print();
    queue->dequeue();
    queue->print();
    queue->dequeue();
    queue->print();
    queue->dequeue();
    queue->print();
    queue->dequeue();
    queue->print();

    assert(queue->is_empty());
    
    queue->dequeue();
    queue->print();

    assert(queue->is_empty());

    delete(queue);

    return 0;
}