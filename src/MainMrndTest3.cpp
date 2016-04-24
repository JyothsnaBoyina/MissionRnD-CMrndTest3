#include <stdio.h>
#include "FunctionHeadersMrndTest3.h"
#include <stdlib.h>"
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct enode{
	char data[6];
	struct enode *left;
	struct enode *right;
};

struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};

static int y = 0;

void printArray(int *arr, int len){
	for (int i = 0; i < len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void printDLL(struct node_dll *root){
	while (root != NULL){
		printf("%d ", root->data);
		root = root->next;
	}
	printf("\n");
}

void printBST(struct node * root){
	if (root != NULL){
		printBST(root->left);
		printf("%d ", root->data);
		printBST(root->right);
	}
}



/*struct node *newNode_spec(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node * constructBinaryTree_spec(int *arr, int len){
	struct node *root = NULL;
	struct node *nodes[2005];
	for (int i = 0; i < len; i++){
		nodes[i] = newNode_spec(arr[i]);
	}
	int mid = (len / 2);
	for (int i = 0; i < mid; i++){
		struct node *curnode = nodes[i];
		struct node *leftnode = nodes[(i * 2) + 1];
		struct node *rightnode = nodes[(i * 2) + 2];
		if (curnode->data != -999){
			if (leftnode->data != -999){
				curnode->left = leftnode;
			}
			if (rightnode->data != -999){
				curnode->right = rightnode;
			}
		}
	}
	root = nodes[0];
	return root;
} */





void in(struct node  *root, int *arr){

	if (root != NULL&& arr != NULL)
	{
		in(root->left, arr);
		arr[y] = root->data;
		y++;
		in(root->right, arr);

	}
}
void inorder(struct node *root, int *arr){

	y = 0;
	if (root != NULL&& arr != NULL)
		in(root, arr);

}

void nodesintree1(struct node *root)
{
	if (root != NULL)
		y++;
	if (root->left != NULL)
		y++;
	if (root->right != NULL)
		y++;

	if (root->left != NULL || root->right != NULL)
	{
		if (root->left != NULL)
			nodesintree1(root->left);
		else if (root->right != NULL)
			nodesintree1(root->right);
	}

}

/*void test_Problem1_spec(int *arr, int len, int actual_len, int ans){
	struct node *root = constructBinaryTree_spec(arr, len);
	y = 0;
	nodesintree1(root);
	printf("\t %d\t", y);
	int results[7];
	inorder(root, results);

	for (int i = 0; i < 7; i++)
		printf(" in order element is : %d \n", results[i]);

	int actual = get_missing_value(root, actual_len);

	printf("acrual is : %d\t", actual);
	//Assert::AreEqual(ans, actual, L"Failed sample 0 for NULL case in P1", 1, 2);

} */

struct node_dll *newNode_DLL_spec(int key)
{
	struct node_dll *temp = (struct node_dll *)malloc(sizeof(struct node_dll));
	temp->data = key;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
struct node_dll * make_dll_spec(int *arr, int len){
	struct node_dll *root = newNode_DLL_spec(arr[0]);
	struct node_dll *temp = root;
	for (int i = 1; i < len; i++){
		struct node_dll *cur = newNode_DLL_spec(arr[i]);
		temp->next = cur;
		cur->prev = temp;
		temp = temp->next;
	}
	return root;
}
struct node *newNode_spec(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * add_node_spec(struct node *root, int data){
	if (root == NULL) return newNode_spec(data);

	if (data < root->data)
		root->left = add_node_spec(root->left, data);
	else if (data > root->data)
		root->right = add_node_spec(root->right, data);

	return root;
}

struct node * make_bst_spec(int *arr, int len){
	struct node *root = NULL;
	for (int i = 0; i < len; i++){
		root = add_node_spec(root, arr[i]);
	}
	return root;
}

void test_Problem2_spec(int *arr, int *arr_bst, int len1, int len2, int ans){
	
		struct node_dll * head = make_dll_spec(arr, len1);
		struct node *root = make_bst_spec(arr_bst, len2);
		int check = is_identical(head, root);

		printf("check is : %d \t", check);
		
		/*Assert::AreEqual(ans, check, L"Failed for Problem3", 1, 2);
		delete_tree(root);
	}
	catch (System::Exception ^e){
		Assert::AreEqual(1, 2, L"Exception maybe Nullpointer occured", 1, 2);
	} */

}

int main(){
	//Test here

	/*int arr[] = { 1, 2, 3, 5, 0, -999, -999 };
	int len = 7;
	int actual_len = 5;
	int ans = 4;
	test_Problem1_spec(arr, len, actual_len, ans); */


	int arr[5] = { 1, 2, 3, 4, 5 };
	int bst_arr[5] = { 5, 3, 2, 1, 4 };
	int len1 = 5;
	int len2 = 5;
	int ans = 1;
	test_Problem2_spec(arr, bst_arr, len1, len2, ans);
	bst_arr[0] = 999;
	test_Problem2_spec(arr, bst_arr, len1, len2, 0);
	
};