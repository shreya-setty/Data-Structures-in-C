#include <stdio.h>
struct student
{
  char name[20];
  char usn[11];
  int marks[3];
};
typedef struct student st;
int main(int argc, char* argv[])
{
    st s[4];
    FILE *fp;
    if(argc==1)
    {
        printf("CLA value is zero");
        return 0;
    }
    fp=fopen(argv[1], "w+");

    for(int i=0; i<4; i++)
    {
        printf("enter values\n");
        scanf("%s%s%d%d%d",s[i].name, s[i].usn, &(s[i].marks[0]),
	     &(s[i].marks[1]), &(s[i].marks[2]));
    }
    fwrite(s, sizeof(s), 4, fp);
    fseek(fp, 0, SEEK_SET);
    fread(s, sizeof(s), 4, fp);
    for(int i=0; i<4; i++)
    {
        printf("%s\t%s\t%d\t%d\t%d\n",s[i].name, s[i].usn, s[i].marks[0],
	     s[i].marks[1], s[i].marks[2]);
    }


    //printf("enter index of append value\n");
    //int u;
    //scanf("%d\n", u);
    fseek(fp, sizeof(st)*(-2), SEEK_CUR);
    fseek(fp, 31, SEEK_CUR);
    int m[3];
    fread(m,sizeof(int),3,fp);
    for(int i=0; i<3; i++)
    {
        m[i]+=10;
        printf("values being appended %d\n", m[i]);
    }
     fseek(fp,-12,SEEK_CUR);
     fwrite(m,sizeof(int),3,fp);
     

    fseek(fp,0,SEEK_SET);
    printf("after appending values\n");
    fread(s, sizeof(s), 4, fp);
    for(int i=0; i<4; i++)
    {
        printf("%s\t%s\t%d\t%d\t%d\n",s[i].name, s[i].usn, s[i].marks[0],
	     s[i].marks[1], s[i].marks[2]);
    }
    fclose(fp);
    return 0;
}
