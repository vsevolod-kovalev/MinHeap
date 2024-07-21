#include <iostream>

#ifndef MINHEAP_H
#define MINHEAP_H

class MinHeap {
    std::vector<int> heap;
    public:
        MinHeap() { heap.push_back(0); }
        void push(const int& value) {
            heap.push_back(value);
            size_t idx = heap.size() - 1;
            while (idx > 1) {
                if (heap[idx] < heap[idx / 2]) {
                    std::swap(heap[idx], heap[idx / 2]);
                    idx /= 2;
                } else {
                    break;
                }
            }
        }
        void pop() {
            if (heap.size() == 1) {
                return;
            }
            heap[1] = heap.back();
            heap.pop_back();
            size_t idx = 1;
            while (idx * 2 < heap.size()) {
                size_t min_child_idx = idx * 2;
                if (idx * 2 + 1 < heap.size() && (heap[min_child_idx + 1] < heap[min_child_idx])) {
                    ++min_child_idx;
                }
                if (heap[idx] <= heap[min_child_idx]) {
                    break;
                }
                std::swap(heap[idx], heap[min_child_idx]);
                idx = min_child_idx;
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