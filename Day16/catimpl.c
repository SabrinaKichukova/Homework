#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    char buff[BUFSIZ];
    size_t bytes;
    int fd;
    

    if(argc <= 1){
            
        while(bytes = read(STDIN_FILENO,buff,BUFSIZ) > 0 ){
        write(STDOUT_FILENO,buff,bytes);
          
        }

    } else {
        for (int i = 0; i < argc; i++){
            fd = open(argv[i],O_RDONLY);
            if(fd == -1){
                perror("Error: ");
                return 1;
            }
        
            while ((bytes = read(fd,buff,BUFSIZ)) > 0){
                write(STDOUT_FILENO,buff,bytes);
            }
        close(fd);
        }
    }
    return 0;
}
