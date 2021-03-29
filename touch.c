#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc == 1){
        printf("Usage: touch [file name]");
    }else{
        int i;
        char cmd[1024] = "";
        for(i = 1; i <argc ; i++){
            if(i == 1){
                strcat(cmd, "copy NULL > ");
            }else{
                strcat(cmd, " & copy NULL > ");
            }
            strcat(cmd, argv[i]);
        }
        system(cmd);
    }
}