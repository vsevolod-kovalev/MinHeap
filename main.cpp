#include "MinHeap.h"
int main() {
    MinHeap heap;
    heap.push(23);
    heap.push(2);
    heap.push(21);
    heap.push(18);
    heap.push(17);
    heap.push(3);
    heap.push(2);
    heap.push(15);
    heap.push(105);
    heap.push(12);
    heap.push(14);
    heap.push(102);
    heap.push(101);
    heap.push(105);
    heap.push(100);
    heap.push(94);
    heap.push(1);
    heap.pop();
    heap.pop();
    heap.pop();
    heap.pop();
    heap.pop();
    // MinHeap::print(heap.getHeap());
    std::vector<int> v {1,100,20,40,5,1000,994};
    MinHeap::heapify(v);
    MinHeap::print(v);
    return 0;
}