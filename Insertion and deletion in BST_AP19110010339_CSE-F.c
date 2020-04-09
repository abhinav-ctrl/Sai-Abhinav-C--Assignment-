/* Insertion and deletion in Binary search tree */
#include <stdio.h>
#include <stdlib.h>
struct treen {
        int data;
        struct treen *left, *right;
  };
struct treen *root = NULL;
struct treen* createNode(int data) 
{
        struct treen *newNode;
        newNode = (struct treen *) malloc(sizeof (struct treen));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return(newNode);
}
void insertion(struct treen **node, int data) {
        if (*node == NULL) 
        {
           *node = createNode(data);
        } else if (data < (*node)->data) 
        {
                insertion(&(*node)->left, data);
        } else if (data > (*node)->data) 
        {
                insertion(&(*node)->right, data);
        }
  }
void deletion(struct treen **node, struct treen **parent, int data) 
{
       struct treen *tmpNode, *tmpParent;
        if (*node == NULL)
                return;
        if ((*node)->data == data) 
        {
            if (!(*node)->left && !(*node)->right) 
            {
                        if (parent) 
                        {
                                
                                if ((*parent)->left == *node)
                                        (*parent)->left = NULL;
                                else
                                        (*parent)->right = NULL;
                                free(*node);
                        } else 
                        {
                               
                            free(*node);
                        }
                
            } else if (!(*node)->right && (*node)->left) {
                        tmpNode = *node;
                        (*parent)->right = (*node)->left;
                        free(tmpNode);
                        *node = (*parent)->right;
                } else if ((*node)->right && !(*node)->left) {
                        tmpNode = *node;
                        (*parent)->left = (*node)->right;
                        free(tmpNode);
                        (*node) = (*parent)->left;
                } else if (!(*node)->right->left) {
                        tmpNode = *node;
                        (*node)->right->left = (*node)->left;
                        (*parent)->left = (*node)->right;
                        free(tmpNode);
                        *node = (*parent)->left;
                } else {
                        tmpNode = (*node)->right;
                        while (tmpNode->left) {
                                tmpParent = tmpNode;
                                tmpNode = tmpNode->left;
                        }
                        tmpParent->left = tmpNode->right;
                        tmpNode->left = (*node)->left;
                        tmpNode->right =(*node)->right;
                        free(*node);
                        *node = tmpNode;
                }
        } else if (data < (*node)->data) {
                deletion(&(*node)->left, node, data);
        } else if (data > (*node)->data) {
               deletion(&(*node)->right, node, data);
        }
}
void traverse(struct treen *node) {
        if (node != NULL) {
                traverse(node->left);
                printf("%3d", node->data);
                traverse(node->right);
        }
        return;
  }

  int main() {
        int data, ch;
        while (1) {
                printf("1. Insertion in Binary Search Tree\n");
                printf("2. Deletion in Binary Search Tree\n");
                printf("3. Inorder traversal\n4. Exit\n");
                printf("Enter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                while (1) {
                                printf("Enter your data:");
                                scanf("%d", &data);
                                insertion(&root, data);
                                printf("Continue Insertion(0/1):");
                                scanf("%d", &ch);
                                if (!ch)
                                        break;
                                }
                                break;
                        case 2:
                                printf("Enter your data:");
                                scanf("%d", &data);
                                deletion(&root, NULL, data);
                                break;
                        case 3:
                                printf("Inorder Traversal:\n");
                                traverse(root);
                                printf("\n");
                                break;
                        case 4:
                                exit(0);
                        default:
                                printf("u've entered wrong option\n");
                                break;
                }
        }
        return 0;

  }

