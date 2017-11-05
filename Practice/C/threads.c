#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int g = 0;

void * myThread(void * vargp) {

	// sleep(1);

	int *myid = (int *)vargp;

	static int s = 0;

	// ++s; ++g;

	// printf("Hello from thread!\n");

	printf("ThreadID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g);

	return NULL;

}

void * printNumbers(void * vargp) {

	int *num = (int *)vargp;

	printf("0%d", *num);

	return NULL;

}

int main() {

	pthread_t tid1, tid2, tid3; 

	int i;

	/*

	printf("Before thread:\n");

	pthread_create(&tid, NULL, myThread, NULL);

	pthread_join(tid, NULL);

	printf("After thread:\n");

	for (i = 0; i < 3; i++) {

		pthread_create(&tid, NULL, myThread, (void *)&i);

		pthread_join(tid, NULL);

	}

	pthread_exit(NULL);

	*/

	for(i = 1; i < 7; i++) {

		//pthread_create(&tid1, NULL, printNumbers, (void *)&i);

		//pthread_join(tid1, NULL);

		if (i % 2 == 0) { 

			pthread_create(&tid2, NULL, printNumbers, (void *)&i); 
			
			pthread_join(tid2, NULL); 
		}

		else { 
			
			pthread_create(&tid3, NULL, printNumbers, (void *)&i); 

			pthread_join(tid3, NULL); 

		}

		

	}

	printf("\n");
	
	pthread_exit(NULL);

	return 0;

}
