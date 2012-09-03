#define _GNU_SOURCE // pthread_getattr_np()
#define _POSIX_C_SOURCE 200112L // pthread_attr_getstack()
#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>

void *start_routine(void *args)
{
	pthread_attr_t attr;
	pthread_getattr_np(pthread_self(), &attr);

	void *stack_addr;
	size_t stack_size;
	pthread_attr_getstack(&attr, &stack_addr, &stack_size);

	void *stack_end = (char *)stack_addr + stack_size - 1;
	printf("Thread stack start: %p, end: %p\n", stack_addr, stack_end);

	pthread_attr_destroy(&attr);
	return NULL;
}

int main()
{
	start_routine(NULL);

	return 0;
}
