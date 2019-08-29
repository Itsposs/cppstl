
#include "util.h"
#include <list>
#include <stdexcept>
#include <string>
#include <cstdlib> // abort()
#include <cstdio>  // snprintf()
#include <iostream>
#include <ctime>
#include <algorithm> // sort()

namespace jj18
{
	void test_queue(long& value)
	{
		std::cout << "\ntest_queue()......\n";

		std::queue<std::string> c;
		char buf[10];

		clock_t timeStart = clock();
		for(long i = 0; i < value; ++i)
		{
			try {
				snprintf(buf, 10, "%d", rand());
				c.push(std::string(buf));
			}
			catch(exception& p) {
				std::cout << "i" << i << " " << p.what() << std::endl;
				abort();
			}
		}
		std::cout << "milli-seconds : " << (clock() - timeStart) << std::endl;
		std::cout << "queue.size()= " << c.size() << std::endl;
		std::cout << "queue.front()= " << c.front() << std::endl;
		std::cout << "queue.back()= " << c.back() << std::endl;
		c.pop();
		std::cout << "queue.size()= " << c.size() << std::endl;
		std::cout << "queue.front()= " << c.front() << std::endl;
		std::cout << "queue.back()= " << c.back() << std::endl;
		//std::cout << "stack.size()= " << c.size() << std::endl;
		//std::cout << "stack.top()= " << c.top() << std::endl;
	}
}
