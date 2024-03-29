//
// Created by admin on 5/13/2021.
//

#ifndef LAB_7___HEAPS_AND_RECURSIVE_SORTS_HEAP_HPP
#define LAB_7___HEAPS_AND_RECURSIVE_SORTS_HEAP_HPP

#include <algorithm>
#include <stdexcept>
#include <iostream>

typedef enum {
	BASE_1 = 0,
	BASE_0 = 1,
} HeapBase_t;

typedef enum {
	LEAF_LEFT = 0,
	LEAF_RIGHT,
} HeapLeaf_t;

class Heap {
private:
	// Note: our heap will be implemented as base 1 to simplify indices expressions
	int *heap = nullptr;
	int size;
	int length;
	int height;
	HeapBase_t root;
	bool open;

	// Heapify the array.
	void vHeapify();

	void vSiftUp(int position);

	void vSiftDown(int position);

	// DEPRECATED: Similar to vSiftDownMax, except it catches eq values as it goes
	void vReplaceDown(int position);

	int xGetLeft(int position);

	int xGetRight(int position);

	int xGetParent(int position);

	void vResizeArray(int size);

public:
	explicit Heap(int size = 10, HeapBase_t baseType = BASE_0);

	~Heap();

	// adds a new item to the heap
	void addItem(int value);

	// removes and returns the smallest item from the heap
	int getItem();

	void vDumpArray();

};


#endif //LAB_7___HEAPS_AND_RECURSIVE_SORTS_HEAP_HPP
