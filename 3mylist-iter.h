

#include "3mylist.h"

#ifndef 3MYLIST-ITER_H_
#define 3MYLIST-ITER_H_

template <typename Item>
struct ListIter {

	Item *ptr;
	ListIter(Item *p = 0) : ptr(p) { }


	Item& operator*() const { return *ptr; }
	Item* operator->() const { return ptr; }


	ListIter& operator++() { ptr = ptr -> next; return *this; }
	ListIter operator++(int) { ListIter tmp = *this; ++*this; return tmp; }

	bool operator==(const ListIter &i) const { return ptr == i.ptr; }
	bool operator!=(const ListIter &i) const { return ptr != i.ptr; }
};

#endif // 3mylist-iter.h
