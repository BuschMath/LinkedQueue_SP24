#include "LinkedQueue.h"

int main() {
    LinkedQueue<int> queue;

    std::cout << "Enqueueing elements 10, 20, 30" << std::endl;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Current front element: " << queue.peek() << std::endl;
    std::cout << "Dequeuing: " << queue.dequeue() << std::endl;
    std::cout << "New front element after dequeue: " << queue.peek() << std::endl;

    std::cout << "The queue size is: " << queue.getSize() << std::endl;

    return 0;
}
