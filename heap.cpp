// heap.cpp
// Diba Mirza
// Henry Li

#include "heap.h"
#include <iostream>
using std::cout;

void bubbleDown(std::vector<int>& v, int idx) {
    int n = v.size();
    while (true) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;
        if (left < n && v[left] < v[smallest]) smallest = left;
        if (right < n && v[right] < v[smallest]) smallest = right;
        if (smallest == idx) break;
        std::swap(v[idx], v[smallest]);
        idx = smallest;
    }
}

void bubbleUp(std::vector<int>& v, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (v[idx] < v[parent]) {
            std::swap(v[idx], v[parent]);
            idx = parent;
        } else {
            break;
        }
    }
}

// Builds a heap from the range [start, end) using the heapify algorithm
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
    vdata = std::vector<int>(start, end);
    int n = vdata.size();
    for (int i = (n / 2) - 1; i >= 0; i--) {
        bubbleDown(vdata, i);
    }
}

// Pushes a value into the heap, then ensures the heap is correctly arranged
void Heap::push(int value){
    vdata.push_back(value);
    bubbleUp(vdata, vdata.size() - 1);
}

// Pops the minimum value off the heap (but does not return it)
void Heap::pop(){
    if (vdata.empty()) return;
    vdata[0] = vdata.back();
    vdata.pop_back();
    if (!vdata.empty()) bubbleDown(vdata, 0);
}

// Returns the minimum element in the heap
int Heap::top(){
    return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
    return vdata.empty();
}

    