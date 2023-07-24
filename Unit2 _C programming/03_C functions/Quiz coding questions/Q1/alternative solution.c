#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char usernames[][20] = {"abdelrhman" , "mahmoud", "nour", "aliaa", "esraa"};

    char username[20];
    printf("Enter Username: ");
    scanf("%s", &username);

    int i = 0;
    int size = sizeof(usernames) / 20;
    for(i = 0; i < size; i++){
        if(!stricmp(username, usernames[i])){
            printf("valid username, welcome!!\n");
            system("pause");
            return 1;
        }
    }
    printf("invalid username\n");
    system("pause");
    return 0;
}