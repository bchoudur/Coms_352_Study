#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <stdio.h>

struct shared_data{
	int a;
	int b;
};

int main(){
	int shmid = shmget(IPC_PRIVATE, sizeof(struct shared_data), S_IRUSR|S_IWUSR);
	struct shared_data *p = shmat(shmid, NULL, 0);
	p->a = 0;
	p->b = 0;

	if(fork() == 0){
		while(1){
			if(p->a == 0){
				p->b = 1;
				p->a = 2;
				printf("%d\n", p->b);
			}
		}
	}else{
		while(1){
			if(p->a > 0){
				p->b = 2;
				p->a = 1;
				printf("%d\n", p->b);
			}
		}
	}
}