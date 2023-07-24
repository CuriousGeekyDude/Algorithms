#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>

class heap
{
    public:
        //Constructor calls is_heap function 
        heap(const std::vector<int>& input) : Heap(input), ordered_array(input) {};

        void build_max_heap();

        void heapSort();

    private:
        std::vector<int> Heap;
        std::vector<int> ordered_array;

        int parent_node(int index);
        int left_child(int index);
        int right_child(int index);

        void max_heapify(int index);

};


#endif