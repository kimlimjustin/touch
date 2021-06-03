#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    if(argc == 1){
        printf("Usage: touch [file name]");
    }else{
        int i;
        FILE *fPtr;
        for(i = 1; i <argc ; i++){
            char *arg = strdup(argv[i]);

            char path[1024] = "";
            char *ptr = strtok(dirname(argv[i]), "/");
            while(ptr != NULL){
                if(strcmp(path, "")) {
                    strcat(path, "\\\\");
                }
                strcat(path, ptr);
                char cmd[1024] = "mkdir ";
                strcat(cmd, path);

                struct stat sb;
                if(!(stat(path, &sb) == 0 && S_ISDIR(sb.st_mode))){
                    system(cmd);
                }
                ptr = strtok(NULL, "/");
            }
            fPtr = fopen(arg, "w");
            fputs("", fPtr);
            fclose(fPtr);
        }
    }
}