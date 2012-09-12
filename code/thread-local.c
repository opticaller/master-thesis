#include <pthread.h>
#include <sched.h>

#include <stdio.h>
#include <stdlib.h>

#define THREADS 4
pthread_t threads[THREADS];

__thread int thread_id;
__thread int thread_count = 0;

void *start_routine(void *args)
{
	thread_id = (int) args;

	int i;
	for(i = 0; i < 4; ++i) {
		printf("%d: %d\n", thread_id, thread_count++);
		sched_yield();
	}

	return NULL;
}

int main()
{
	int i;
	for(i = 0; i < THREADS; ++i)
		pthread_create(&threads[i], NULL, start_routine, (void *)i);

	pthread_exit(0);
	return 0;
}
