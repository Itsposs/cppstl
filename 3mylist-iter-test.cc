

#include "3mylist-iter.h"


void test() {
	List<int> mylist;

	for (int i = 0; i < 5; ++i) {
		mylist.insert_front(i);
		mylist.insert_end(i + 2);
	}
	mylist.display();

	ListIter<ListItem<int>> begin(mylist.front());
	ListIter<ListItem<int>> end;
	ListIter<ListItem<int>> iter;

	iter = find(begin, end, 3);
	if (iter == end)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found" << std::endl;

	iter = find(begin, end, 7);
	if (iter == end)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found" << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}

