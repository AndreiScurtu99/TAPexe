#include "LSIcoadaDinamica.h"

int main() {
    Coada queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.print(); 

    queue.dequeue();
    queue.print(); 

    return 0;
}