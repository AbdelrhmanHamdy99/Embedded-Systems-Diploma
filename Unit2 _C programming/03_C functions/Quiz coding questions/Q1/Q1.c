#include <stdio.h>
#include <stdlib.h>
/*case sensitive*/
int main(){
    char usernames[][20] = {"abdelrhman" , "mahmoud", "nour", "aliaa", "esraa"};

    char username[20];
    printf("Enter Username: ");
    scanf("%s", &username);

    int i = 0, j;
    int size = sizeof(usernames) / 20;
    for(i = 0; i < size; i++){
        j = 0;
        while(username[j] == usernames[i][j] && username[j] != 0 && usernames[i][j] != 0 )
            j++;
        if( username[j] == 0 && usernames[i][j] == 0){
            printf("valid username, welcome!!\n");
            system("pause");
            return 1;
        }
    }
    printf("invalid username\n");
    system("pause");
    return 0;
}