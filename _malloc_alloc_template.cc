
#if 0
#include <new>
#define _THROW_BAD_ALLOC throw bad_alloc
#elif !define(_THROW_BAD_ALLOC)
#include<iostream.h>
#define _THROW_BAD_ALLOC std::cerr << "out of memory" << std::endl; exit(1);
#endif

template <int inst>

class _malloc_alloc_template
{
	private:
		// 以下函数将用来处理内存不足的情况
		// oom:out of memory
		static void *oom_malloc(size_t);
		static void *oom_realloc(void *, size_t);
		static void (*_malloc_alloc_oom_handler)();
	public:
		static void * allocate(size_t n)
		{
			void *result = malloc(n);  // 第一级配置器直接使用malloc()
			// 以下无法满足需求时,改用oom_malloc()
			if(0 == result)
				result = oom_malloc(n);
			return result;
		}

		static void deallocate(void *p, size_t) { free(p); }

		static void * reallocate(void *p, size_t, size_t new_sz)
		{
			void *result = realloc(p, new_sz);
			// 以下无法满足需求时,改用oom_realloc()
			if(0 == result)
				result = oom_realloc(p, new_sz);
			return result;
		}
		
		// 以下仿真C++的set_new_handler().换句话说,你可以通过它
		// 指定你自己的out-of-memory handler
		static void (* set_malloc_handler(void (*f)()))() // ?
		{
			// f1 = void (*f)() 
			// void (* set_malloc_handler(f1))()
			// f2 = set_malloc_handler(f1)
			// void (*f2)()
			void (*old)() = _malloc_alloc_oom_handler;
			_malloc_alloc_oom_handler = f;
			return(old);
		}
};

template <int inst>
void (*_malloc_alloc_template<inst>::_malloc_alloc_oom_handler)() = 0;

template <int inst>
void * _malloc_alloc_template<inst>::oom_malloc(size_t n)
{
	void (* my_malloc_handler)();
	void *result;

	for(;;)
	{
		my_malloc_handler = _malloc_alloc_oom_handler;
		if(0 == my_malloc_handler)
			_THROW_BAD_ALLOC;
		(*my_malloc_handler)();
		result = malloc(n);
		if(result)
			return(result);
	}
}

template <int inst>
void * _malloc_alloc_template<inst>::oom_realloc(void *p, size_t n)
{
	void (* my_malloc_handler)();
	void *result;
	
	for(;;)
	{
		my_malloc_handler = _malloc_alloc_oom_handler;
		if(0 == my_malloc_handler)
			_THROW_BAD_ALLOC;
		(*my_malloc_handler)();
		result = realloc(p, n);
		if(result)
			return(result);
	}
}

// 注意,以下直接将参数inst指定为0
typedef _malloc_alloc_template<0> malloc_alloc;
