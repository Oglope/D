#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/shm.h>


union semun { /* Определяем union semun */
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
	struct seminfo *__buf;

};

int binary_semaphore_allocation(key_t, int sem_flags);
int binary_semaphore_deallocate(int semid);
int binary_semaphore_initialize(int semid);
int binary_semaphore_initialize_0(int semid);
int binary_semaphore_take(int semid);
int binary_semaphore_free(int semid);
