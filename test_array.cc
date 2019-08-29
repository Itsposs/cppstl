#include "util.h"
#include <ctime>
#include <cstdlib>  // qsort,bsearch,NULL
#include <array>
#include <iostream>

namespace jj01
{
	void test_array()
	{
		std::cout << "\ntest_array()...........\n";

		std::array<long, ASIZE> c;

		clock_t timeStart = clock();

		for(long i = 0; i < ASIZE; ++i)
		{
			c[i] = rand();
		}
		std::cout << "milli-seconds: " << (clock() - timeStart) << std::endl;
		std::cout << "array.size()= "  << c.size()  << std::endl;
		std::cout << "array.max_size()= " << c.max_size() << std::endl;
		std::cout << "array.front()= " << c.front() << std::endl;
		std::cout << "array.back()= "  << c.back()  << std::endl;
		std::cout << "array.data()= "  << c.data()  << std::endl;
		
		long target = util::get_a_target_long();

		timeStart = clock();
		qsort(c.data(), ASIZE, sizeof(long), util::compareLongs);
		long* pItem = (long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), util::compareLongs);
		std::cout << "qsort() + bsearch(),milli-seconds : " << (clock() - timeStart)<< std::endl;
		if(pItem != NULL)
			std::cout << "found, " << *pItem << std::endl;
		else
			std::cout << "not found! " << std::endl;
	}

}
