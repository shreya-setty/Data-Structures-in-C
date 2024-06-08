#include <stdio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
  char name[20];
  char usn[11];
  int marks[3];
};
struct randomaccess
{
    char usn[12];
    long int rl;
};
typedef struct randomaccess ra;
typedef struct student st;
void sort (st * s, const int n);
void sortra(ra* r, int n);
void search(ra* r, FILE* fp);
int main ()
{
  FILE *fp;
  st s[10];
  ra r[4];
  printf ("enter number of students\n");
  int n;
  scanf ("%d", &n);
  fp = fopen ("d", "w");
  for (int i = 0; i < n; i++)
    {
      printf ("Enter the details\n");
      scanf ("%s%s%d%d%d", s[i].name, s[i].usn, &(s[i].marks[0]),
	     &(s[i].marks[1]), &(s[i].marks[2]));
	  strcpy(r[i].usn,s[i].usn);
	  r[i].rl = ftell(fp);
	  fwrite(&s[i],sizeof(st),1,fp);
    }
  sort (s, n);
  fwrite (s, sizeof (st), n, fp);
    fclose(fp);
  for(int i=0; i<n; i++)
    printf("%s\t%ld\n",r[i].usn,r[i].rl);
    sortra (r,n);
    search(r, fp);
  fp = fopen ("d", "r");
  fread (s, sizeof (st), n, fp);
  fseek(fp,0,SEEK_SET);
  printf("%ld\n", ftell(fp));
  fseek(fp,0,SEEK_END);
  printf("%ld\n", ftell(fp));
  fclose (fp);
  fp=fopen("main.c","r");
  printf("main c %ld\n", ftell(fp));
  fseek(fp,0,SEEK_END);
  printf("main c %ld\n", ftell(fp));
  fclose(fp);
  printf("seek");
  char u[11];
  scanf("%s",u);
  fp=fopen("d","r");
  fseek(fp,sizeof(st)*(atoi(u)-1),SEEK_SET);
  st t;
  fread (&t, sizeof (st), 1, fp);
  printf ("%s\t%s\t%d\t%d\t%d\n", t.name, t.usn, t.marks[0],
	      t.marks[1], t.marks[2]);
  fclose(fp);      
  return 0;
}

void sort (st * s, const int n)
{
  st *temp = NULL;
  temp = (st *) malloc (sizeof (st));
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      {
	if (strcmp (s[i].usn, s[j].usn) > 0)
	  {
	    memcpy (temp, &(s[i]), sizeof (st));
	    memcpy (&(s[i]), &(s[j]), sizeof (st));
	    memcpy (&(s[j]), temp, sizeof (st));
	  }
      }
      for (int i = 0; i < n; i++)
    {
      printf ("%s\t%s\t%d\t%d\t%d\n", s[i].name, s[i].usn, s[i].marks[0],
	      s[i].marks[1], s[i].marks[2]);
    }  
    return;
}

void sortra (ra* r, int n)
{
   ra *temp = NULL;
  temp = (ra *) malloc (sizeof (ra));
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      {
	if (strcmp (r[i].usn, r[j].usn) > 0)
	  {
	    memcpy (temp, &(r[i]), sizeof (ra));
	    memcpy (&(r[i]), &(r[j]), sizeof (ra));
	    memcpy (&(r[j]), temp, sizeof (ra));
	  }
      } 
      
}

void search(ra* r, FILE* fp)
{
  char s[11];
  printf("for random access");
  scanf("%s",s);
  fp=fopen("d","r");
  fseek(fp,sizeof(ra)*(atoi(s)-1),SEEK_SET);
  ra x;
  fread (&x, sizeof (ra), 1, fp);
  printf ("%s\t%ld\n",x.usn, x.rl);
  fclose(fp);      
  return;
}
