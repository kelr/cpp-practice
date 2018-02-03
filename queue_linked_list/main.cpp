#include "QueueLinkedList.h"
#include <assert.h>

int main(void)
{
    QueueLinkedList<int>* queue = new QueueLinkedList<int>;

    assert(queue->is_empty());

    queue->enqueue(5);

    assert(!queue->is_empty());

    queue->enqueue(6);
    queue->enqueue(7);
    queue->enqueue(8);

    queue->print();

    queue->dequeue();

    queue->print();

    queue->dequeue();
    queue->dequeue();
    queue->dequeue();

    assert(queue->is_empty());
    
    queue->dequeue();

    assert(queue->is_empty());

    delete(queue);

    return 0;
}