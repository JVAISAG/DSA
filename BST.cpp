#include <iostream>

class Node
{
public:
  int data;

  Node *left, *right;
};

Node *create(int data)
{
  Node *node = new Node();
  node->data = data;
  node->left = node->right = nullptr;

  return node;
}

Node *insertLeft(Node *root, int data)
{
  Node *temp = root;

  if (root->left == nullptr)
  {
    root->left = create(data);
  }
  else
  {
    while (temp->left != nullptr)
    {
      temp = temp->left;
    }
    temp->left = create(data);
  }

  return temp->left;
}

Node *insertRight(Node *root, int data)
{
  Node *temp = root;

  if (root->right == nullptr)
  {
    root->right = create(data);
  }
  else
  {
    while (temp->right != nullptr)
    {
      temp = temp->right;
    }
    temp->right = create(data);
  }

  return temp->right;
}

bool isBST(Node *root);
Node *Search(Node *root, int key);
Node *InsertBST(Node *root, int key);

void inorder(Node *root)
{
  if (root != nullptr)
  {
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
  }
}
void preorder(Node *root)
{
  if (root != nullptr)
  {
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
}
void postorder(Node *root)
{
  if (root != nullptr)
  {
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
  }
}
Node* inorderPre(Node*root){
  root = root->left;
  while (root->right!=nullptr)
  {
    root = root->right;
  }
  return root;
}
Node* deleteNode(Node *root,int key){
  Node *ipre;
  if (root==nullptr)
  {
    return 0;
  }
  if (root->right == nullptr && root->left == nullptr)
  {
    free(root);
    return 0;
  }
  
  
  
  if (key<root->data){
    deleteNode(root->left,key);
  }

  else if(key>root->data){
    deleteNode(root->right,key);
  }
  else{
    ipre = inorderPre(root);
    root->data = ipre->data;
    root->left = deleteNode(root->left,ipre->data);
  }
  

  
}
int main()
{
  Node *root = new Node();

  root->data = 10;
  insertLeft(root, 7);
  insertRight(root, 15);
  insertLeft(root->left, 5);
  insertRight(root->left->left, 6);
  insertRight(root->left, 9);
  insertLeft(root->right, 11);
  insertRight(root->right, 16);
  InsertBST(root, 8);

  std::cout << "Inorder : " << std::endl;
  inorder(root);
  std::cout << std::endl;

  std::cout << "Preorder : " << std::endl;
  preorder(root);
  std::cout << std::endl;

  std::cout << "Postorder : " << std::endl;
  postorder(root);
  std::cout << std::endl;

  deleteNode(root,9);
  std::cout<<"Modified : "<<std::endl;
  std::cout << "Inorder : " << std::endl;
  inorder(root);
  std::cout << std::endl;  
  




  // std::cout << isBST(root) << std::endl;

  // std::cout << Search(root, 16)->data << std::endl;

  return 0;
}

bool isBST(Node *root)
{
  static Node *prev = nullptr;

  if (root == nullptr)
  {
    return true;
  }

  else if (root != nullptr)
  {
    if (!isBST(root->left))
    {
      return false;
    }

    if (prev != nullptr && root->data <= prev->data)
    {
      return false;
    }

    prev = root;

    return isBST(root->right);
  }
}

Node *InsertBST(Node *root, int key)
{
  Node *prev = nullptr;
  Node *newNode = create(key);

  while (root != nullptr)
  {
    prev = root;

    if (root->data == key)
    {
      return root;
    }
    if (root->data > key)
    {
      root = root->left;
    }

    else
    {
      root = root->right;
    }
  }
  if (prev->data > key)
  {
    prev->left = newNode;
    return root;
  }
  else
  {
    prev->right = newNode;
    return root;
  }
}