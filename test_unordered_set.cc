
#include "util.h"
#include <list>
#include <stdexcept>
#include <string>
#include <cstdlib> // abort()
#include <cstdio>  // snprintf()
#include <iostream>
#include <ctime>
#include <algorithm> // sort()

namespace jj15
{
	void test_unordered_set(long& value)
	{
		std::cout << "\ntest_unordered_set()......\n";

		std::unordered_set <long, std::string> c;
		char buf[10];

		clock_t timeStart = clock();
		for(long i = 0; i < value; ++i)
		{
			try {
				snprintf(buf, 10, "%d", rand());
				c.insert(std::string(buf));
			}
			catch(exception& p) {
				std::cout << "i" << i << " " << p.what() << std::endl;
				abort();
			}
		}
		std::cout << "milli-seconds : " << (clock() - timeStart) << std::endl;
		std::cout << "unordered_set.size()= " << c.size() << std::endl;
		std::cout << "unordered_set.max_size()= " << c.max_size() << std::endl;
		std::cout << "unordered_set.bucket_count()= " << c.bucket_count() << std::endl;
		std::cout << "unordered_set.load_factor()= " << c.load_factor() << std::endl;
		std::cout << "unordered_set.max_load_factor()= " << c.max_load_factor() << std::endl;
		std::cout << "unordered_set.max_bucket_count()= " << c.max_bucket_count() << std::endl;
		
		for(unsigned i = 0; i < 20; ++i) {
			std::cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements.\n";
		}
	}
}
