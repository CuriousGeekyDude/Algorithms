#include "Heap.hpp"
#include <string>
#include <cmath>
#include <iostream>
#include <utility>


int heap::parent_node(int index)
{
    if(index < 0) {
        return -1;
    }
    if(index%2 == 0) {
        return (index/2) - 1;
    }
    else {
        return index/2;
    }
}

int heap::left_child(int index)
{
    if(index < 0) {
        return -1;
    }

    if(Heap.size() <= static_cast<std::size_t>(2*index+1)) {
        return index;
    }

    return 2*index + 1;
}

int heap::right_child(int index)
{
    if(index < 0) {
        return -1;
    }
    if(Heap.size() <= static_cast<std::size_t>(2*index+2)) {
        return index;
    }

    return 2*index+2;
}


void heap::max_heapify(int index)
{
    if(index < 0 || Heap.size() <= static_cast<std::size_t>(index)) {
        return;
    }

    int right_index = right_child(index);
    int left_index = left_child(index);
    int largest_index = index;

    if(right_index == left_index) {
        return;
    }

    if(Heap[index] < Heap[left_index]) {
        largest_index = left_index;
    }
    
    if(Heap[largest_index] < Heap[right_index]) {
        largest_index = right_index;
    }

    if(largest_index != index) {
        std::swap(Heap[largest_index], Heap[index]);
        max_heapify(largest_index);
    }
}   


void heap::build_max_heap()
{
    int index_of_last_non_leaf = Heap.size()/2;
    --index_of_last_non_leaf;

    for(; 0 <= index_of_last_non_leaf; --index_of_last_non_leaf) {
        max_heapify(index_of_last_non_leaf);
    }

}

void heap::heapSort()
{
    build_max_heap();

    if(Heap.size() == 0) {
        return;
    }

    for(int i = Heap.size()-1; 1 <= i; --i) {
        ordered_array[i] = Heap[0];
        std::swap(Heap[i], Heap[0]);
        Heap.resize(i);
        build_max_heap();
    }
    ordered_array[0] = Heap[0];

    for(auto item : ordered_array) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


