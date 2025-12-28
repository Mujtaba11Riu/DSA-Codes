#include"Tree.h"
#include<iostream>
using namespace std;

//........................Tree Node implementation................

TreeNode::TreeNode(int key)
{
	this->key = key;
	right = NULL;
	left = NULL;
}
int TreeNode::getKey()
{
	return key;
}
void TreeNode::setKey(int key)
{
	this->key = key;
}
TreeNode* TreeNode::getRight()
{
	return right;
}
TreeNode* TreeNode::getLeft()
{
	return left;
}
void TreeNode::setRight(TreeNode* right)
{
	this->right = right;
}
void TreeNode::setLeft(TreeNode* left)
{
	this->left = left;
}


//....................... Tree Implementation .....................

Tree::Tree()
{
	root = NULL;
}
bool Tree::isEmpty()
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
TreeNode* Tree::findParent(int key)
{
	TreeNode* temp = root;
	TreeNode* parent = NULL;
	if (isEmpty())
	{
		return NULL;
	}
	else 
	{
		while (temp != NULL)
		{
			if (temp->getKey() == key)
			{
				cout << "Duplication Not Allowed. Exiting the function";
				return NULL;
			}
			else if (temp->getKey() > key)
			{
				parent = temp;
				temp = temp->getLeft();
			}
			else if (temp->getKey() < key)
			{
				parent = temp;
				temp = temp->getRight();
			}
		}// end of loop
		return parent;
	}
}
TreeNode* Tree::findParent2(int key)
{
	TreeNode* temp = root;
	TreeNode* parent = NULL;
	if (isEmpty())
	{
		return NULL;
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->getKey() == key)
			{
				return parent;
			}
			else if (temp->getKey() > key)
			{
				parent = temp;
				temp = temp->getLeft();
			}
			else if (temp->getKey() < key)
			{
				parent = temp;
				temp = temp->getRight();
			}
		}// end of loop
		//return parent;
	}
}
void Tree::insert(int key)
{
	

	if (isEmpty())
	{
		TreeNode* newNode = new TreeNode(key);
		root = newNode;
	}
	else
	{
		TreeNode* parent = findParent(key); //finding place to insert
		if (parent != NULL)
		{
			TreeNode* newNode = new TreeNode(key); //creating new node

			if (parent->getKey() > key)
			{
				parent->setLeft(newNode);
			}
			else if (parent->getKey() < key)
			{
				parent->setRight(newNode);
			}
		}
	}
}


void Tree::display()
{
	inorder(root);
}
void Tree::inorder(TreeNode* n)
{
	if (n != NULL)
	{
		inorder(n->getLeft());
		cout << n->getKey() << endl;
		inorder(n->getRight());
	}
}
TreeNode* Tree::search(int key)
{
	TreeNode* target = root;

	
	if (isEmpty())
	{
		return NULL;
	}
	else
	{
		while (target != NULL)
		{
			if (target->getKey() == key)
			{
				return target;
			}
			else if (target->getKey() > key)
			{
				target = target->getLeft();
			}
			else if (target->getKey() < key)
			{

				target = target->getRight();
			}
		}
		// end of loop
		return target;
	}
}






void Tree::removeNode(int toRemove)
{
	TreeNode* target = search(toRemove);
	
	if (target == NULL)
	{
		cout << "Not found" << endl;
		return;
	}
	else
	{
		TreeNode* parent = findParent2(toRemove);
		if (target->getLeft() == NULL && target->getRight() == NULL) 
		{
			if (parent->getLeft() == target)
			{
				parent->setLeft(NULL);
				delete target;
			}
			else
			{
				parent->setRight(NULL);
				delete target;
			}

		} //end of if

		else if (target->getLeft() == NULL || target->getRight() == NULL)
		{
			if (parent->getLeft() == target)
			{
				if (target->getLeft() == NULL)
				{
					parent->setLeft(target->getRight());
					delete target;
				}
				else
				{
					parent->setLeft(target->getLeft());
					delete target;
				}
			}
			else if (parent->getRight() == target)
			{
				if (target->getLeft() == NULL)
				{
					if (target->getLeft() == NULL)
					{
						parent->setRight(target->getRight());
						delete target;
					}
					else
					{
						parent->setRight(target->getLeft());
						delete target;
					}
				}
				else
				{

				}
			}
		
		
		
		}
		else
		{
			cout << "Two child case" << endl;
			cout << "Parent is: " << parent->getKey();
		}
	}
}