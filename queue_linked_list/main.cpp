#include QueueLinkedList.h
#include <assert.h>

int main(void)
{
    QueueLinkedList<int>* queue = new QueueLinkedList<int>;

    assert(queue->is_empty);

    queue->enqueue(5);

    assert(!queue->is_empty);

    
}