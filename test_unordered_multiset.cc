
#include "util.h"
#include <list>
#include <stdexcept>
#include <string>
#include <cstdlib> // abort()
#include <cstdio>  // snprintf()
#include <iostream>
#include <ctime>
#include <algorithm> // sort()

namespace jj08
{
	void test_unordered_multiset(long& value)
	{
		std::cout << "\ntest_unordered_multiset()......\n";

		std::unordered_multiset <std::string> c;
		char buf[10];

		clock_t timeStart = clock();
		for(long i = 0; i < value; ++i)
		{
			try {
				snprintf(buf, 10, "%d", rand());
				c.insert(std::string(buf);
			}
			catch(exception& p) {
				std::cout << "i" << i << " " << p.what() << std::endl;
				abort();
			}
		}
		std::cout << "milli-seconds : " << (clock() - timeStart) << std::endl;
		std::cout << "unordered_multiset.size()= " << c.size() << std::endl;
		std::cout << "unordered_multiset.max_size()= " << c.max_size() << std::endl;
		std::cout << "unordered_multiset.bucket_count()= " << c.bucket_count() << std::endl;
		std::cout << "unordered_multiset.load_factor()= " << c.load_factor() << std::endl;
		std::cout << "unordered_multiset.max_load_factor()= " << c.max_load_factor() << std::endl;
		std::cout << "unordered_multiset.max_bucket_count()= " << c.max_bucket_count() << std::endl;
		
		for(unsigned i = 0; i < 20; ++i) {
			std::cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements.\n";
		}
	}
}
