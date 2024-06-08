Here is the properly indented version of your code:

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *llink;
    int info;
    struct node *rlink;
};

typedef struct node nd;

void inorder(nd *r) {
    if (r) {
        inorder(r->llink);
        printf("%d ", r->info);
        printf("\n");
        inorder(r->rlink);
    }
}

nd *Insert(nd *root, int key) {
    nd *cur = root, *prev = 0;
    nd *t = (nd *)malloc(sizeof(nd));
    t->info = key;
    t->llink = t->rlink = 0;
    if (!cur)
        return t;
    while (cur) {
        if (t->info == cur->info) {
            printf("Redundancy\n");
            free(t);
            return root;
        }
        prev = cur;
        if (t->info < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    if (t->info < prev->info)
        prev->llink = t;
    else
        prev->rlink = t;
    return root;
}

void iterSearch(nd *root, int key) {
    if (!root) {
        printf("BST empty\n");
        return;
    }
    while (root) {
        if (key == root->info) {
            printf("Search successful\n");
            return;
        }
        if (key < root->info)
            root = root->llink;
        else
            root = root->rlink;
    }
    printf("Unsuccessful search\n");
}

void recurSearch(nd *root, int key) {
    if (!root) {
        printf("Unsuccessful search\n");
        return;
    }
    if (key == root->info) {
        printf("Successful search\n");
        return;
    }
    if (key < root->info)
        return recurSearch(root->llink, key);
    return recurSearch(root->rlink, key);
}

nd *deletenode(nd *root, int key) {
    nd *cur, *parent, *q, *suc;
    if (!root) {
        printf("BST empty\n");
        return root;
    }
    parent = 0;
    cur = root;

    // Searching for the existence of key value
    while (cur) {
        // If cur = 0; condition is false control will be out of while
        if (key == cur->info) {
            printf("Successful search\n");
            break;
        }
        parent = cur;
        if (key < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }

    if (!cur) {
        printf("Key not found\n");
        return root;
    }

    // Key found and deletion in progress
    if (!cur->llink)  // Left subtree is empty
        q = cur->rlink;
    else if (!cur->rlink)  // Right subtree is empty
        q = cur->llink;
    else {  // Both llink and rlink not empty
        // A pointer is obtained for the inorder successor of the node to
        // be deleted (i.e cur)
        suc = cur->rlink;
        while (suc->llink)
            suc = suc->llink;
        // Suc is pointing to the inorder successor of cur and suc->llink is null.
        // Suc->llink will hold the address of left subtree of cur.
        suc->llink = cur->llink;
        // q is pointing to right subtree of the node to be deleted (cur)
        q = cur->rlink;
    }

    // This condition is true when root not is deleted
    if (!parent)
        return q;

    // Connecting the parent of cur with q
    if (cur == parent->llink)
        parent->llink = q;
    else
        parent->rlink = q;

    free(cur);
    return root;
}

int main() {
    nd *root = 0;
    int ch, i, key;
    FILE *fp;
    fp = fopen("data1", "r");
    for (;;) {
        printf("1. Insert\n2. Iterative Search\n3. Recursive Search\n");
        printf("4. Inorder\n5. Delete a node\n6. Exit\n");
        printf("Enter choice ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                fscanf(fp, "%d", &ch);
                for (i = 0; i < ch; i++) {
                    fscanf(fp, "%d", &key);
                    root = Insert(root, key);
                }
                break;
            case 2:
                printf("Enter info to be searched\n");
                scanf("%d", &key);
                iterSearch(root, key);
                break;
            case 3:
                printf("Enter information to be searched\n");
                scanf("%d", &key);
                recurSearch(root, key);
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                printf("Enter information to be deleted\n");
                scanf("%d", &ch);
                root = deletenode(root, ch);
                break;
            case 6:
                return 0;
        }
    }
}
```
