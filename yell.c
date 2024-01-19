#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

//yell.h
int cat_fd(int fd);

//yell.c
int main(int argc, char **argv){
    int fd; //File Discriminator

    if(argc == 1){
        cat_fd(0);
    }else{
        for(int i = 1; i < argc; i++){
            fd = open(argv[i], O_RDONLY);
            cat_fd(fd);
            close(fd);
        }
    }
    return 0;
}

int cat_fd(int fd){
    int fd_read_len = 0;
    do{
        char fd_read[2048];
        fd_read_len = read(fd, fd_read, 2048); //returns >0 for length, else 0 or -1 for faliure
        if(fd_read_len > 0){

            //string to upper
            for(int i = 0; i < fd_read_len; i++){
                fd_read[i] = toupper(fd_read[i]);
            }

            write(1, fd_read, fd_read_len);
        }
    }while(fd_read_len > 0);
    return 0;
}

