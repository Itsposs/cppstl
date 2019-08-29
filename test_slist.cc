
#include <ext/slist>
#include <stdexcept>
#include <string>
#include <cstdlib>  // abort()
#include <cstdio> // snprintf()
#include <iostream>
#include <ctime>

namespace jj10
{
	void test_slist(long& value)
	{
		std::cout << "\ntest_slist()......\n";

		_gnu_cxx::slist<std::string> c;
		char buf[10];

		clock_t timeStart = clock();
		for(long i = 0; i < value; ++i)
		{
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_front(std::string(buf));
			}
			catch(exception& p) {
				std::cout << "i=" << " " << p.what() << std::endl;
				abort();
			}
		}
		std::cout << "milli-seconds: " << (clock() - timeStart) << std::endl;
	}
}

