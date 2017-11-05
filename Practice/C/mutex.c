#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex  = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

void * functionCount1();
void * functionCount2();

int count = 0;
#define COUNT_DONE 200


int main() {

	pthread_t t1, t2;

	pthread_create(&t1, NULL, &functionCount1, NULL);

	pthread_create(&t2, NULL, &functionCount2, NULL);

	pthread_join(t1, NULL);

	pthread_join(t2, NULL);

	return 0;

}

void * functionCount1() {

	for(;;) {

		pthread_mutex_lock(&count_mutex);

		if(count % 2 != 0) {

			pthread_cond_wait(&condition_var, &count_mutex);

		}

		count++;

		printf("Counter value functionCount1: %d\n", count);

		pthread_cond_signal(&condition_var);

		if(count >= COUNT_DONE-1) {

			pthread_mutex_unlock(&count_mutex);

			return(NULL);

		}

		pthread_mutex_unlock(&count_mutex);
	}
}


void * functionCount2() {

	for(;;) {

		pthread_mutex_lock(&count_mutex);

		if(count % 2 == 0) {

			pthread_cond_wait(&condition_var, &count_mutex);

		}

		count++;

		printf("Counter value functionCount2: %d\n", count);

		pthread_cond_signal(&condition_var);

		if(count >= COUNT_DONE-1) {

			pthread_mutex_unlock(&count_mutex);

			return(NULL);

		}

		pthread_mutex_unlock(&count_mutex);
	}



}	
