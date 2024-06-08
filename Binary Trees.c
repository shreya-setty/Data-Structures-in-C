#include<stdlib.h>
#include<stdio.h>
#include <string.h>
struct node
{
  struct node *llink;
  char info[5];
  struct node *rlink;
};
typedef struct node nd;
nd *insert_node (nd *);
void levelorder (nd *);
void preorder (nd *);
void postorder (nd *);
void inorder (nd *);
void it_inorder (nd *);
int
main ()
{
  nd *root = 0;


  root = insert_node (root);

  printf ("Iterative inorder \n");

  it_inorder (root);

  printf ("\n");

  printf ("Level order \n");

  levelorder (root);

  printf ("\n");
//printf ("%s\n", (((root->rlink)->rlink)->rlink)->info);

  printf ("Preorder\n");

  preorder (root);

  printf ("\n");

  printf ("postorder \n");

  postorder (root);

  printf ("\n");

  printf ("inorder\n");

  inorder (root);


}

void
preorder (nd * r)
{
  if (r)
    {
      printf ("%s ", r->info);
      preorder (r->llink);
      preorder (r->rlink);
    }
}

nd *
insert_node (nd * f)
{

  nd *t, *p, *c;



  int i, j, n;



  char str[5];



  FILE *fp;



  fp = fopen ("databt", "r");



  if (fp == 0)


    {


      printf ("Exit");


      exit (1);


    }



  printf ("Reading no of nodes in tree\n");
  fscanf (fp, "%d", &n);
  t = (nd *) malloc (sizeof (nd));



  printf ("Reading root value\n");



  fscanf (fp, "%s", t->info);



  t->llink = t->rlink = 0;



  f = t;



  for (i = 0; i < n; i++)



    {



      t = (nd *) malloc (sizeof (nd));






      fscanf (fp, "%s", t->info);



      t->llink = t->rlink = 0;




      fscanf (fp, "%s", str);



      for (p = 0, c = f, j = 0; j < strlen (str); j++)



	{



	  p = c;



	  if (str[j] == 'L')



	    c = c->llink;



	  else



	    c = c->rlink;



	}


      if (str[strlen (str) - 1] == 'L')	// checking the last character
	p->llink = t;
      else
	p->rlink = t;

    }


  return f;



}

void
postorder (nd * r)
{
  if (r)
    {
      postorder (r->llink);
      postorder (r->rlink);
      printf ("%s ", r->info);
    }
}

void
inorder (nd * r)
{
  if (r)
    {
      inorder (r->llink);
      printf ("%s ", r->info);
      inorder (r->rlink);
    }
}

void
it_inorder (nd * r)
{
  nd *c;
  nd *st[20];			// stack of pointers of type nd
  int top = -1;
  if (!r)
    {
      printf ("Tree is empty\n");
      return;
    }
  c = r;
  for (;;)
    {
      while (c != 0)
	{
	  st[++top] = c;	// storing nodes info on stack
	  c = c->llink;
	}
      if (top != -1)
	{
	  c = st[top--];
	  printf ("%s ", c->info);
	  c = c->rlink;
	}
      else
	return;
    }
}


void
levelorder (nd * root)
{
  int f = 0, r = -1;
  nd *c, *q[20] = { 0 };
  if (!root)
    {
      printf ("Binary tree is empty\n");
      return;
    }
  q[++r] = root;
  for (;;)
    {
      c = q[f++];
      if (c)
	{
	  printf ("%s ", c->info);
	  if (c->llink)
	    q[++r] = c->llink;
	  if (c->rlink)
	    q[++r] = c->rlink;
	}
      else
	break;
    }
}
