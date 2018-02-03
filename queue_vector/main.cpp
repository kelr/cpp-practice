#include "QueueVector.h"
#include <assert.h>

int main(void)
{
    QueueVector<int>* v = new QueueVector<int>;

    assert(v->is_empty());
    v->enqueue(5);
    assert(!v->is_empty());
    v->print();

    v->enqueue(6);
    v->print();

    int data = v->dequeue();
    assert(data == 5);
    v->print();

    int data2 = v->dequeue();
    assert(data2 == 6);
    v->print();

    assert(v->is_empty());

    return 0;
}
