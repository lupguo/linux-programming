//
// Created by Terry on 2018/7/31.
//

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir(char *dir, int depth) {

    DIR *dp;

    struct dirent *entry;
    struct stat statbuf;

    if ((dp = opendir(dir)) == NULL) {
        fprintf(stderr, "cannot open directory: %s \n", dir);
    }

    chdir(dir);
    while ((entry = readdir(dp)) != NULL) {

        //非..和.目录
        if (strcmp(entry->d_name, "..") == 0 || strcmp(entry->d_name, ".") == 0) {
            continue;
        }
        printf("%*s%s\n", depth, "", entry->d_name);

        //查看文件是否子目录，有则继续遍历
        lstat(entry->d_name, &statbuf);
        if(S_ISDIR(statbuf.st_mode)) {
            printdir(entry->d_name, depth+4);
        }
    }
    chdir("..");
}

int main(void){
    printf("Directory scan of /home: \n");
    printdir("/data/c", 0);
    printf("done. \n");
    exit(0);
}