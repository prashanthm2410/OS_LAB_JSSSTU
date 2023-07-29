//PARENT.C cc parent.c -lrt
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>

void main(){
	int fd, n;
	int buffer[25];
	int *shared_memory;
	
	fd = shm_open("chandan",O_CREAT|O_RDWR, 0666);
	ftruncate(fd,1024); //allocating 1024 bytes of memory to shared memory
	shared_memory = (int*)mmap(NULL, 1024, PROT_WRITE, MAP_SHARED, fd, 0);
	
	printf("Enter n>> ");
	scanf("%d",&n);
	char nstr[20];
	sprintf(nstr, "%d", n);
	
	if (fork()==0){
		execlp("./child","child",nstr,NULL);
	}
	else{
		wait(NULL);
		
		for(int i=0;i<n;i++){
			printf("%d ",shared_memory[i]);
		}
		printf("\n");
		
		shm_unlink("chandan");
	
	}
}
//CHILD.C cc child.c -lrt -o child
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>

void main(int argc, char* argv[]){
	int fd, n;
	int buffer[25];
	int *shared_memory;
	
	fd = shm_open("chandan",O_RDWR, 0666);
	
	shared_memory = (int*)mmap(NULL, 1024, PROT_WRITE, MAP_SHARED, fd, 0);
	
	n = atoi(argv[1]);
	
	buffer[0] = 0;
	buffer[1] = 1;
	for(int i=2; i<n;i++){
		buffer[i] = buffer[i-1] + buffer[i-2];
	}
	for(int i=0;i<n;i++) 
		shared_memory[i]=buffer[i];
}
