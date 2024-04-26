#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)
typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
}NODE;
NODE *root; // struct node *root=NULL;
NODE* create_node(int value);
void in_order(NODE* trav);
void pre_order(NODE* trav);
void post_order(NODE* trav);
void add_node(int value);
void clear(NODE*trav);
void freelist();
int main(void)
{
    printf("\n tree =");
    add_node(9);
    add_node(5);
    add_node(13);
    add_node(25);
    add_node(3);
    add_node(10);
    add_node(6);
    add_node(23);
    add_node(27);
    printf("\n inorder trav =");
    in_order(root);
    
    
    printf("\n ");
    printf("\n postorder trav =");
    
    post_order(root);
    
    printf("\n ");
    printf("\n preorder trav =");
    pre_order(root);

    printf("\n ");
    freelist();
    return 0;
}
NODE* create_node(int value)
{
    NODE *newnode= (NODE*)malloc(1*sizeof(NODE));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;   
}
void add_node(int value)
{
    NODE * newnode= create_node(value);
    if(root==NULL)
        root= newnode;
    else
    {
        NODE *trav=root;
        while(1) // while(true) infinite
        {
            if(value<trav->data)
            {
                if ( trav->left==NULL)
                {
                    trav->left= newnode;
                    break;// out of while loop
                }
                else
                    trav=trav->left;
            }   
            else
            {
                if ( trav->right==NULL)
                {
                    trav->right= newnode;
                    break;// out of while loop
                }
                else
                    trav=trav->right;
            }
        }

    }
    return;
}
void in_order(NODE* trav) // LVR   asc
{
   if( trav==NULL)
        return;
    else
        in_order(trav->left);// Left
        printf("%d-->",trav->data); // Visit
        in_order(trav->right); // right    
}
void pre_order(NODE* trav)  // VLR
{
    if( trav==NULL)
        return;
    else
        printf("%d-->",trav->data); // Visit
    pre_order(trav->left);// Left
    pre_order(trav->right); // right
}
void post_order(NODE* trav)// LRV
{
   if( trav==NULL)
        return;
    else
        post_order(trav->left);// Left
    post_order(trav->right); // right
    printf("%d-->",trav->data); // Visit
}
void clear(NODE*trav)
{
    if( trav==NULL)
        return;
    else
        clear(trav->left);// Left
        clear(trav->right); // right
         printf("\n deleted node =%d", trav->data);
        free(trav); // free Node
         trav=NULL;
}
void freelist()
{
    clear(root);
    root=NULL;
    printf("\n memory is freed");
}

//AVL trees were invented by Adelson-Velskii and Landis in 1962.
// An AVL tree is a balanced binary search tree where every node in the tree satisfies the following 
//invariant: the height difference between its left and right children is at most 1.
// Hence, all sub-trees of an AVL tree are themselves AVL.


//

/*
What is an AVL Tree?
 
An AVL tree is a type of binary search tree. Named after it's inventors Adelson, Velskii, and Landis, 
  AVL trees have the property of dynamic self-balancing in addition to all the other properties exhibited by binary 
 search trees.

 */