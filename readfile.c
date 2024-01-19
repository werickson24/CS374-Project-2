#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){
    int fd = open(argv[1], O_RDONLY);

    char *fread[2048];
    int freadlen = read(fd, fread, 2048);

    write(1, fread, freadlen);
    close(fd);
}
