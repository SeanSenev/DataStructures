
#include <iostream>
using namespace std;

class TreeNode {
public:
	int value;
	TreeNode *right;
	TreeNode *left;

	TreeNode() {
		value = 0;
		right = NULL;
		left = NULL;
	}
};

class BST {
public:
	TreeNode *root;

	BST() {
		root = NULL;
	}
	//functions that a BST (binary search tree) must perform 
	// 1. search for a value 
	void searchBST(int key, TreeNode *start) {
		//check to see if you found it (anchor value)
		if (start == NULL) {
			cout << "Couldn't find value" << endl;
			return;
		}
		else if (key == start->value){
			cout << "Found it" << endl;
			return;
		} else {
			if (key > start->value) {
				searchBST(key, start->right);
			} else {
				searchBST(key, start->left);
			}
		}
	}
	// 2. add new value to the tree 
	void addNodeBST(int key) {
		//start by searching for this value
		// if you find it, don't add it we don't want duplicates
		//if you don't find it add it where it should go
		TreeNode *slow, *fast;
		slow = fast = root; //start off at the beginning at the tree
		if (root == NULL) {
			root = new TreeNode; //this value is set to zero automatically
			root->value = key;
			return;
		}
		else {
			//use fast to find this key
			//if fast falls off the tree, then this value doesn't exist
			// at this point we want slow to point at the parent of this node we want 		
			while (fast != NULL) {
				if (fast->value == key) {
					cout << "duplicate- will not add" << endl;
					return;
				}
				else if
					(key > fast->value) {
					slow = fast;
					fast = fast->right;
				}
				else {
					slow = fast;
					fast = fast->left;
				}

			}
		} //at this point fast should have fallen off

		TreeNode *temp = new TreeNode;
		temp->value = key;
		//should I go left or right
		if (key < slow->value) {
			slow->left = temp;
		}
		else {
			slow->right = temp;
		}
	}
	// 3. delete values from the tree 
	void deleteNodeBST(int key, TreeNode *start) {
		//a) go find that node
		// start= root key- find it and delete it
			TreeNode *slow, *fast; //slow is parent, fast is the node you're looking for
			slow = fast = start;
		if (start == NULL) {
			cout << "Empty tree, nothing to delete" << endl;
			return;
		}
		else {
			//fast should find value- slow should point to parent 
			while (fast != NULL || fast->value != key) {
				if (fast->value == key) {
					cout << "looks like I found it, will try to delete.." << endl;
					break;
				}
				else if(key > fast->value) {
					slow = fast;
					fast = fast->right;
				}
				else {
					slow = fast;
					fast = fast->left;
				}
			} // now let's see if we found the value or not
			if(fast == NULL) { 
				cout << "Could not find it, will not delete" << endl; 
				return;
			}
		
			else {
				//looks like this value exists. fast points to value and slow points to parent
				//b) figure out what kind of node it is
				// case 1: leaf node (has no children)

			if (fast->left == NULL && fast->right == NULL) {
				if (slow->left == fast) {
					delete fast;
					slow->left = NULL;
				}
				else {
					delete fast;
					slow->right = NULL;
				}
			}
			// case 2: exactly one child
			else if ((fast->left == NULL && fast->right != NULL) || (fast->left != NULL && fast->right == NULL)) {

				if (slow->right == fast) { //the value you want to delete is to the right of the grand parent
					if (fast->right != NULL) {
						//lone child is to right of fast
						slow->right = fast->right; //set grand parent = grand child 
						delete fast;
					}
					else {
						//lone child is to left
						slow->right = fast->left;
						delete fast;
					}
				}
				else if (slow->left == fast) { //the node you want to delete with one child is to the left of grand parent 
					if (fast->right != NULL) {
						//lone child is to right of fast
						slow->left = fast->right; //set grand parent = grand child 
						delete fast;
					}
					else {
						//lone child is to left
						slow->left = fast->left;
						delete fast;
					}
				}
			}
			// case 3: 2 children
			else {
				int replace = minValRSubTree(fast->right);
				deleteNodeBST(replace, fast);
				fast->value = replace;
			}
		}
	}
}
	
	
	//keep this outside the delete functions
	int minValRSubTree(TreeNode *start){

		TreeNode *temp = start;
		while (temp->left != NULL) {
			temp = temp->left;
		}
		return temp->value;
	}

	void inorder(TreeNode *start) {
		if (start == NULL) {
			return;
		}
		else {
			inorder(start->left);
			cout << start->value << " " << endl;
			inorder(start->right);
		}
	}
	void preorder(TreeNode *start) {
		if (start == NULL) {
			return;
		}
		else {
			cout << start->value << " " << endl;
			preorder(start->left);
			preorder(start->right);
		}
	}
	
	void postorder(TreeNode *start) {
		if (start == NULL) {
			return;
		}
		else {
			inorder(start->left);
			inorder(start->right);
			cout << start->value << " " << endl;
		}
	}
};

int main()
{
	BST myTree;
	int choice, value;
	while (1) {
		cout << "Press 1 to add BST" << endl;
		cout << "Press 2 to search" << endl;
		cout << "Press 3 to delete" << endl;
		cout << "Press 4 for in order" << endl;
		cout << "press 5 for pre-order" << endl;
		cout << "Press 6 for post-order" << endl;
		cin >> choice;

		switch (choice) {
		case 1: cout << "Add what? " << endl;
			cin >> value;
			myTree.addNodeBST(value);
			break;

		case 2: cout << " What are you looking for?" << endl;
			cin >> value;
			myTree.searchBST(value, myTree.root);
			break;

		case 3: cout << "What value do you want to delete" << endl;
			cin >> value;
			myTree.deleteNodeBST(value, myTree.root);
			break;

		case 4: myTree.inorder(myTree.root);
			break;

		case 5: myTree.preorder(myTree.root);
			break;

		case 6: myTree.postorder(myTree.root);
			break;

		}
	}
	return 1;
}

