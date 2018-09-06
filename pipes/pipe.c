#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char *message = "This is a message!";

main(){
  char buf[1024];
  int fd[2];
  pipe(fd); //Creates pipe
  if(fork() != 0){
    write(fd[1], message, strlen(message)+1);
  }else{
    read(fd[0], buf, 1024);
    printf("Got this from parent!: %s\n", buf);
  }
}
