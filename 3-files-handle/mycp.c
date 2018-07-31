/**
 *  copy file twice.
 *
 */

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    char block[1024];
    int in, out;
    int nread;

    char file1[] = "mycp.a";
    char file2[] = "mycp.b";

    in  = open(file1, O_RDONLY);
    out = open(file2, O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);

    while ( (nread = read(in, block, sizeof(block))) > 0 ) {
        write (out , block, nread);
    }

    exit(0);
}
