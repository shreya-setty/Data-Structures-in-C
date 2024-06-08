#include <stdio.h>
#include<string.h>
int main()
{
    FILE *fp= NULL;
    fp= fopen("d.txt","w");
    char a[30]={"RNSIT"};
    fwrite(a,(strlen(a)+1),1,fp);
    fclose(fp);
    char b[30];
    fp= fopen("d.txt","r");
    fread(b+2,6,1,fp);
    printf("%s", b+2);
    fclose(fp);

    return 0;
}
