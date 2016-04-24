/*
Given a Sorted Doubly Linked List and a Binary Search Tree , Check if they are identical or not .
The DLL will have nodes of type node_dll
Note :
A DLL can be represented as a BST in many forms ,And if a dll and any one of the forms is given as input you
need to return 1 otherwise 0. 

->Dont Create an Extra Array ,or else your solution would receive 20% Cut in the Marks you got .

Examples :

Example 0:
DLL:1->5->8
BST(All 3 return 1):
    5         8      1
   / \       /        \
  1   8     5          5
           /            \
          1              8
Returns 1
    8
   / \
  5   1
Returns 0
Example 1:
DLL : 1->5
BST : 
5
 \
 10
Returns 0

Example 2:
DLL:1->3->5-9->11
BST:
    5
   / \
  1   11
   \  /      
    3 9

Returns 1

Example 3:
DLL: 1->5->7->10->12->15->20
BST:
        10
        /\
       5  15
      /\  / \
     1  7 12 20
Returns 1

Note 2 :
Unequal Length BST and DLL should return 0;
Return -1 for NULL inputs

Difficulty : Medium +
*/
#include <stdlib.h>
#include <stdio.h>

struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};
struct node{
	int data;
	struct node *left;
	struct node *right;
};

static int z = 0;

void search1(struct node *root, int n)
{
	if (root->data == n)
	{
		z = 1;
		return;
	}

	else if (root->left != NULL || root->right != NULL)
	{
		if (root->left != NULL)
			search1(root->left, n);
		if (root->right != NULL)
			search1(root->right, n);
	}
}


int lengthDLL(struct node_dll *head)
{
	int i = 0;

	struct node_dll *temp;
	temp = (struct node_dll*)malloc(sizeof(struct node_dll));
	temp = head;

	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return i + 1;
}

void nodesintree(struct node *root)
{
	if (root != NULL)
	{
		if (root->left != NULL)
			z++;
		if (root->right != NULL)
			z++;
	}

	if (root->left != NULL || root->right != NULL)
	{
		if (root->left != NULL)
			nodesintree(root->left);
		else if (root->right != NULL)
			nodesintree(root->right);
	}

}

int checkBST(struct node *root)
{
	if (root != NULL)
		{
			if (root->left != NULL)
			if (root->left->data > root->data)
				return -1;

			else if (root->right != NULL)
			 if (root->right->data < root->data)
				return -1;
		}

	if (root->left != NULL || root->right != NULL)
	{
		if (root->left != NULL)
			checkBST(root->left);
		else if (root->right != NULL)
			checkBST(root->right);
	}

}
int is_identical(struct node_dll *head, struct node *root){

	if (head == NULL || root == NULL)
		return -1;

	int l1 = lengthDLL(head);
	z = 1;
	nodesintree(root);

	if (l1 !=z)
		return -1;


	int check = 0;
	check = checkBST(root);

	if (check == -1)
		return 0;

	int d;
	struct node_dll *temp;
	temp = (struct node_dll*)malloc(sizeof(struct node_dll));
	temp = head;

	for (int i = 0; i < l1; i++)
	{
		d = temp->data;
		z = 0;
		search1(root, d);
		if (z == 0)
		{
			return 0;
			break;
		}
		temp = temp->next;
    }

	return 1;
}