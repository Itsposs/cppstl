#include "util.h"
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib> // abort()
#include <cstdio>  // snprintf()
#include <iostream>
#include <ctime>
#include <algorithm> // sort()

namespace jj02
{
	void test_vector(long& value)
	{
		std::cout << "\ntest_vector()......\n";

		std::vector<std::string> c;
		char buf[10];

		clock_t timeStart = clock();
		for(long i = 0; i < value; ++i)
		{
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_back(std::string(buf));
			}
			catch(exception& p) {
				std::cout << "i" << i << " " << p.what() << std::endl;
				// 曾经最高i=58389486 then std::bad_alloc
				abort();
			}
		}
		std::cout << "milli-seconds : " << (clock() - timeStart) << std::endl;
		std::cout << "vector.size()= " << c.size() << std::endl;
		std::cout << "vector.front()= " << c.front() << std::endl;
		std::cout << "vector.back()= " << c.back() << std::endl;
		std::cout << "vector.data()= " << c.data() << std::endl;
		std::cout << "vector.capacity()= " << c.capacity() << std::endl;
		
		std::string target = util::get_a_target_string();
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		std::cout << "::find(),milli-seconds: " << (clock() - timeStart) << std::endl;
		if(pItem != c.end())
			std::cout << "found, " << *pItem << std::endl;
		else
			std::cout << "not found!" << std::endl;

		timeStart = clock();
		sort(c.begin(), c.end());
		std::string* pItem = (std::string*)bsearch(&target, (c.data()), c.size(), sizeof(std::string));
		std::cout << "sort() + bsearch(),milli-seconds: " << (clock() - timeStart) << std::endl;
	    if(pItem != c.end())
			std::cout << "found, " << *pItem << std::endl;
		else
			std::cout << "not found!" << std::endl;

	}
}
