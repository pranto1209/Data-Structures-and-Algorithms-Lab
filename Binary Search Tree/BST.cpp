 #include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int key;
    node *left, *right;
};

node *newNode(int item)
{
    node *temp=new node();
    temp->key=item;
    temp->left=temp->right=NULL;
    return temp;
}

node *insert(node *anode, int key)
{
    if(anode==NULL) return newNode(key);
    if(key < anode->key) anode->left=insert(anode->left, key);
    else if(key > anode->key) anode->right=insert(anode->right, key);
    return anode;
}

node *Search(node *root, int key)
{
    if(root==NULL || root->key==key) return root;
    if(root->key<key) return Search(root->right, key);
    return Search(root->left, key);
}

void InorderTraverse(node *root)
{
    if(root!=NULL){
        InorderTraverse(root->left);
        cout<<root->key<<" ";
        InorderTraverse(root->right);
    }
}

void PreorderTraverse(node *root)
{
    if(root!=NULL){
        cout<<root->key<<" ";
        PreorderTraverse(root->left);
        PreorderTraverse(root->right);
    }
}

void PostorderTraverse(node *root)
{
    if(root!=NULL){
        PostorderTraverse(root->left);
        PostorderTraverse(root->right);
        cout<<root->key<<" ";
    }
}

int main()
{
    /* Let us create following BST
          50
    	/	 \
       30	 70
     / \     / \
    20 40   60 80 */
    node *root=NULL;
    root=insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout<<"Inorder Traversal: ";
    InorderTraverse(root);
    cout<<endl;

    cout<<"Preorder Traversal: ";
    PreorderTraverse(root);
    cout<<endl;

    cout<<"Postorder Traversal: ";
    PostorderTraverse(root);
    cout<<endl;

    int num;
    cout<<"Enter a data for search: ";
    cin>>num;
    if(Search(root, num)) cout<<"Found";
    else cout<<"Not found";

    return 0;
}
