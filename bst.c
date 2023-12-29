#include <stdio.h>
#include <stdlib.h>
// BST Structure
typedef struct binary_tree
{
    struct binary_tree *LEFT;
    int INFO;
    struct binary_tree *RIGHT;
} NODE;
// Insertion of BST Function
void insertion_bst(NODE **root, int value)
{
    NODE *ptr, *loc1, *loc2;
    ptr = (NODE *)malloc(sizeof(NODE));
    ptr->INFO = value;
    ptr->RIGHT = NULL;
    ptr->LEFT = NULL;
    if (*root == NULL)
    {
        *root = ptr;
    }
    else
    {
        loc1 = NULL;
        loc2 = *root;
        while (loc2 != NULL)
        {
            loc1 = loc2;
            if (value > loc2->INFO)
            {
                loc2 = loc2->RIGHT;
            }
            else
            {
                if (value < loc2->INFO)
                {
                    loc2 = loc2->LEFT;
                }
                else
                {
                    printf("\nDuplicate Entry");
                    return;
                }
            }
        }
        if (value > loc1->INFO)
            loc1->RIGHT = ptr;
        else
            loc1->LEFT = ptr;
    }
}
// In-Order traversal function of BST
void inorder(NODE *root)
{
    if (root != NULL)
    {
        inorder(root->LEFT);
        printf(" %d ", root->INFO);
        inorder(root->RIGHT);
    }
}
// Pre-Order traversal function of BST
void preorder(NODE *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->INFO);
        preorder(root->LEFT);
        preorder(root->RIGHT);
    }
}
// Post-Order traversal function of BST
void postorder(NODE *root)
{
    if (root != NULL)
    {
        postorder(root->LEFT);
        postorder(root->RIGHT);
        printf(" %d ", root->INFO);
    }
}
// Delete function of BST
void delete(NODE **root, int value)
{
    NODE *p, *q, *rp, *f, *s;
    p = *root;
    q = NULL;
    while (p != NULL && p->INFO != value)
    {
        q = p;
        if (value < p->INFO)
            p = p->LEFT;
        else
            p = p->RIGHT;
    }
    if (p == NULL)
        return;
    if (p->LEFT == NULL)
        rp = p->RIGHT;
    else if (p->RIGHT == NULL)
        rp = p->LEFT;
    else
    {
        f = p;
        rp = p->RIGHT;
        s = rp->LEFT;
        while (s != NULL)
        {
            f = rp;
            rp = s;
            s = s->LEFT;
        }
        if (f != p)
        {
            f->LEFT = rp->RIGHT;
            rp->RIGHT = p->RIGHT;
        }
        rp->LEFT = p->LEFT;
    }
    if (q == NULL)
        *root = rp;
    else
    {
        if (p == q->RIGHT)
            q->RIGHT = rp;
        else
            q->LEFT = rp;
    }
    free(p);
}
// Main function
int main()
{
    printf("\n Name - Aditya Raj");
    NODE *root;
    int ch, value;
    root = NULL;
    while (1)
    {
        printf("\n");
        printf("\n1. Insert NODE in BST.");
        printf("\n2. In-order Traversal in BST.");
        printf("\n3. Pre-order Traversal in BST.");
        printf("\n4. Post-order Traversal in BST.");
        printf("\n5. Delete a Node in BST");
        printf("\n6. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value : ");
            scanf("%d", &value);
            insertion_bst(&root, value);
            break;
        case 2:
            printf("In-order:");
            inorder(root);
            break;
        case 3:
            printf("Pre-order:");
            preorder(root);
            break;
        case 4:
            printf("Post-order:");
            postorder(root);
            break;
        case 5:
            printf("Enter tree value to delete : ");
            scanf("%d", &value);
            delete (&root, value);
            break;
        case 6:
            exit(0);
        }
    }
}