

#ifndef 3MYLIST_H_
#define 3MYLIST_H_

template <typename T>
class ListItem {
	public:
		T value() const { return _value; }
		ListItem* next() const { return _next; }
	private:
		T _value;
		ListItem *_next;
};


template <typename T>
class List {
	public:
		void insert_front(T value);
		void insert_end(T value);
		void display(std::ostream &os = std::cout) const;
	private:
		ListItem<T> *_end;
		ListItem<T> *_front;
		long _size;
		
};


#endif  // 3mylist.h
