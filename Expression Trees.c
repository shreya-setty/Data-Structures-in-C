#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define a node structure
struct node {
    char info;
    struct node *llink, *rlink;
};

typedef struct node nd;

// Function to create an expression tree from a postfix expression
nd *create(char *postfix) {
    nd *temp, *st[20];
    int i, top = -1;

    // Loop through each character in the postfix expression
    for (i = 0; postfix[i] != '\0'; i++) {
        // Allocate memory for a new node
        temp = (nd *)malloc(sizeof(nd));
        temp->info = postfix[i];
        temp->rlink = temp->llink = 0;

        // If the character is an operand, push it to the stack
        if (isalnum(postfix[i])) {
            st[++top] = temp;
        } else { // If the character is an operator
            // Pop two nodes from the stack and set them as children of the operator node
            temp->rlink = st[top--];
            temp->llink = st[top--];
            // Push the operator node back to the stack
            st[++top] = temp;
        }
    }

    // The final node on the stack is the root of the expression tree
    return st[top--];
}

// Function for preorder traversal of the tree
void preorder(nd *r) {
    if (r) {
        printf("%c ", r->info);
        preorder(r->llink);
        preorder(r->rlink);
    }
}

// Function for inorder traversal of the tree
void inorder(nd *r) {
    if (r) {
        inorder(r->llink);
        printf("%c ", r->info);
        inorder(r->rlink);
    }
}

// Function for postorder traversal of the tree
void postorder(nd *r) {
    if (r) {
        postorder(r->llink);
        postorder(r->rlink);
        printf("%c ", r->info);
    }
}

// Main function
int main() {
    nd *root = 0;

    // Example postfix expressions
    // char postfix[] = "632-5*+2^3+";
    char postfix[] = "ab/cd*+et*+y-";
    // char postfix[] = "63+";

    // Create the expression tree from the postfix expression
    root = create(postfix);

    // Print the traversals of the expression tree
    printf("Inorder traversal of Expression tree is\n");
    inorder(root);
    printf("\n");

    printf("Preorder traversal of Expression tree is\n");
    preorder(root);
    printf("\n");

    printf("Postorder traversal of Expression tree is\n");
    postorder(root);
    printf("\n");

    return 0;
}
