#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <string.h> 
#include <signal.h> 

int vuln(char *Data) {
if(Data[0] == 'C')
{
    printf("It is bugggggggggggg!\n");
    raise(SIGSEGV);
}
else if(Data[0] == 'F')
{
    printf("It is paht2!\n");
}
else{
    printf("It is path3!\n");
}
return 0;
}

int main(int argc, char *argv[])
{
printf("%d",argc);
char ptr[20];
if(argc>1){
    FILE *fp = fopen(argv[1], "r");
    fgets(ptr, sizeof(ptr), fp);
    fclose(fp);
    }
else{
    fgets(ptr, sizeof(ptr), stdin);
    }
vuln(ptr);
}

