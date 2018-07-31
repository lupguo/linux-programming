#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
    struct stat statbuf;
    mode_t modes;

    stat("b.log", &statbuf);

    printf("%hu", statbuf.st_mode);
}
