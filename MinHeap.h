#include <iostream>

#ifndef MINHEAP_H
#define MINHEAP_H

class MinHeap {
    std::vector<int> heap;
    public:
        MinHeap() : heap(0) {}
        void push(const int& value) {
            heap.push_back(value);
            size_t idx = heap.size() - 1;
            while (idx > 0) {
                if (heap[idx] < heap[idx / 2]) {
                    std::swap(heap[idx], heap[idx / 2]);
                    idx /= 2;
                } else {
                    break;
                }
            }
        }
        void print() {
            size_t nodes_in_level = 1;
            size_t current_idx = 1;
            size_t current_load = nodes_in_level;
            while (current_idx < heap.size()) {
                std::cout << heap[current_idx] << " ";
                --current_load;
                if (current_load == 0) {
                    nodes_in_level *= 2;
                    current_load = nodes_in_level;
                    std::cout << std::endl;
                }
                ++current_idx;
            }
            if (current_load > 0) {
                std::cout << std::endl;
            }
        }






};

#endif // MINHEAP_H