#include<iostream>

using namespace std;

struct node
{
	int data;
	node * left = nullptr;
	node * right = nullptr;
};

struct node * newNode(int key)
{
	node * temp = new node;
	temp->data = key;
	temp->left = nullptr;
	temp->right = nullptr;

	return temp;
}

void reverseOrder(node* root,int & sum){
    if(root == nullptr)
    return;

    reverseOrder(root->right,sum);

    int temp = root->data;
    root->data = sum;
    sum = sum + temp;

    reverseOrder(root->left,sum);

}

void inorder(node * root)
{
	if(root == nullptr)
	{
		return;
	}

	inorder(root->left);

	cout<<root->data<<" ";

	inorder(root->right);
}

int main()
{
	node *root = newNode(11);
    root->left = newNode(2);
    root->right = newNode(29);
    root->left->left = newNode(1);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    root->right->right = newNode(40);
    root->right->right->left = newNode(35);

    int sum = 0;

    reverseOrder(root,sum);

    inorder(root);

    cout<<endl;

    return 0;


}