
#include "util.h"
#include <list>
#include <stdexcept>
#include <string>
#include <cstdlib> // abort()
#include <cstdio>  // snprintf()
#include <iostream>
#include <ctime>
#include <algorithm> // sort()

namespace jj07
{
	void test_multimap(long& value)
	{
		std::cout << "\ntest_multimap()......\n";

		std::multimap <long, std::string> c;
		char buf[10];

		clock_t timeStart = clock();
		for(long i = 0; i < value; ++i)
		{
			try {
				snprintf(buf, 10, "%d", rand());
				c.insert(std::pair<long, std::string>(i, buf));
			}
			catch(exception& p) {
				std::cout << "i" << i << " " << p.what() << std::endl;
				abort();
			}
		}
		std::cout << "milli-seconds : " << (clock() - timeStart) << std::endl;
		std::cout << "multimap.size()= " << c.size() << std::endl;
		std::cout << "multimap.max_size()= " << c.max_size() << std::endl;
		//std::cout << "list.front()= " << c.front() << std::endl;
		//std::cout << "list.back()= " << c.back() << std::endl;
		//std::cout << "list.data()= " << c.data() << std::endl;
		//std::cout << "list.capacity()= " << c.capacity() << std::endl;
		
		std::string target = util::get_a_target_string();
		timeStart = clock();
		auto pItem = c.find(target);
		//auto pItem = ::find(c.begin(), c.end(), target);
		std::cout << "c.find(),milli-seconds: " << (clock() - timeStart) << std::endl;
		
		if(pItem != c.end())
			std::cout << "found,value=" << (*pItem).second << std::endl;
		else
			std::cout << "not found!" << std::endl;

		//timeStart = clock();
		//c.sort();
		//sort(c.begin(), c.end());
		//std::cout << "c.sort(),milli-seconds: " << (clock() - timeStart) << std::endl;
	}
}
