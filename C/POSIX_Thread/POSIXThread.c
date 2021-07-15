/*
 ============================================================================
 Name        : POSIXThread.c
 Author      : Séb T
 Description : POSIX Thread in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "unistd.h"
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* threadFunction(void* arg);

int main(void) {
	puts("!!!Multi-Thread!!!");
	// Threads IDs
	pthread_t threadsId[8];
	int* localsIds = malloc(sizeof(int)*8);

	// Configuration of POSIX threads
	pthread_attr_t threadAttributes;
	pthread_attr_init(&threadAttributes);
	pthread_attr_setdetachstate(&threadAttributes, PTHREAD_CREATE_JOINABLE);

	// Loop to execute every threads
	for (int i = 0; i < 8; i++) {
		localsIds[i] = i;

		pthread_create(threadsId+i, &threadAttributes, &threadFunction, localsIds+i);
	}

	pthread_attr_destroy(&threadAttributes);

	// Wait for the endings of every threads
	for (int i = 0; i < 8; i++) {
		pthread_join(threadsId[i], 0);
	}

	 free(localsIds);

	return 0;
}

//POSIX thread function
void* threadFunction(void* arg) {
	int localId = *((int*)arg);

	// Modify the scheduler
	struct sched_param params;
	params.sched_priority = 80 + localId; // 80 use for high priority
	pthread_setschedparam(pthread_self(), SCHED_FIFO, &params);

	// Verify the changes
	int policy;
	pthread_getschedparam(pthread_self(), &policy, &params);

	pthread_mutex_lock(&mutex);
	printf("Thread number : %d starts priority : %d \n", localId, params.sched_priority);
	pthread_mutex_unlock(&mutex);

	for (int i = 0; i < 500000000; i++){}

	pthread_mutex_lock(&mutex);
	printf("Thread number : %d ends \n", localId);
	pthread_mutex_unlock(&mutex);

	return 0;
}

