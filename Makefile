CXX = g++
CXX_FLAGS = -std=c++17 -Wall -g

all: examheap

examheap: examheap.cpp heap.cpp heap.h
	$(CXX) $(CXX_FLAGS) -o examheap examheap.cpp heap.cpp

clean:
	rm -f examheap
