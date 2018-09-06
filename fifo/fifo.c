#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

main(){
	int fd;

	char *myFifo = "fifo1";

	mkfifo(myFifo, 0666);

	char arr1[80], arr2[80];
	while(1){
		fd = open(myFifo, O_WRONLY);

		fgets(arr2, 80, stdin);

		//Write an input arr2 on FIFO
		write(fd, arr2, strlen(arr2)+1);
		close(fd);

		fd = open(myFifo, O_RDONLY);

		//Read from FIFO
		read(fd, arr1, sizeof(arr1));

		//Print the read message
		printf("User2: %s\n", arr1);
		close(fd);
	}
	return 0;
}

