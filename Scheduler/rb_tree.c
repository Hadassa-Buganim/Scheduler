#include "rb_tree.h"

rb_tree* initial_rb_tree() {

	rb_tree* tree = (rb_tree*)malloc(sizeof(rb_tree));
	tree->root = tree->most_left = NULL;
	tree->num_of_tasks = 0;
	tree->total_weights = 0;

	return tree;
}

//insert task to the rb_tree
void insert_task(rb_tree* tree, task* task) {

	if (task == NULL) {
		//how will the wrrors be handled?
	}

	if (tree == NULL) {
		//ERROR
	}

	tree->total_weights += task->weight;
	tree->num_of_tasks++;

	//create new node
	rb_node* node = (rb_node*)malloc(sizeof(rb_node));
	if (node == NULL) {
		//Alocation failed
		exit(1);
	}
	node->color = RED;
	node->left = node->right = node->parent = NULL;

	//TODO lock the tree

	//if the tree is empty, 
	if (tree->root == NULL) {
		task->vruntime = 0;
		node->task = task;
		node->color = BLACK;
		tree->most_left = node;
	}
	else {
		//the tree is not empty

		task->vruntime = tree->most_left->task->vruntime + 1;

		//insert the node to the tree
		add_node(tree->root, node);

		//check the colors
		if (node->parent->color == RED) {

			//check uncle's color
			if (node->parent->left == node) {
				//node is a left child
				if (node->parent->right->color == RED) {

				}
				else {
					//rotate the tree
				}
			}
			else {
				//node is a right child
				if (node->parent->left->color == BLACK) {

				}
				else {
					//rotate the tree
				}
			}
		}

	}
}

void add_node(rb_node* root, rb_node* node) {

	if (root == NULL)
		return;

	//if the node smaller
	if (root->task->vruntime > node->task->vruntime) {

		if (root->left != NULL) {
			add_node(root->left, node);
		}
		else {
			root->left = node;
			node->parent = root;
		}
	}
	else {
		//the node is bigger;
		if (root->right != NULL) {
			add_node(root->right, node);
		}
		else {
			root->right = node;
			node->parent = root;
		}
	}


}

void check_and_changes_colors(rb_node* node) {

	//TODO adding validators of not null nodes

	rb_node* node_parent = node->parent;
	if (node_parent->parent == NULL) {
		//node_parent is a root
		//it is forced the node_parent color is black - so this condition never be true
	}

	rb_node* grandfather = node_parent->parent;

	//if node_parent is a left child
	if (grandfather->left == node_parent) {

		//if uncle's node is a red node
		if (grandfather->right->color == RED) {
			change_colors_to_black(grandfather);
		}
		else {
			//need to rotate the tree.

			//if node is a left child
			if (node_parent->left == node) {
				//left left rotation (LL)
			}
			else {
				//left right rotation (LR)
			}
		}
	}
	else {
		//node_parent is a right child

		//if uncle's node is a red node
		if (grandfather->left->color == RED) {
			change_colors_to_black(grandfather);
		}
		else {
			//need to rotate
			//if node is a left child
			if (node_parent->left == node) {
				//right left rotation (RL)
			}
			else {
				//right right rotation (RR)
			}
		}
	}


}

void change_colors_to_black(rb_node* grandfather) {

	grandfather->left->color = grandfather->right->color = BLACK;

	if (grandfather->parent != NULL && grandfather->parent->color == RED) {
		check_and_changes_colors(grandfather);
	}
}

//rotation
// left right rotation
void left_right_rotation(rb_node* node) {

	left_rotation(node);
	right_rotation(node);
}

void left_left_rotation(rb_node* node) {

	right_rotation(node);
	right_rotation(node);
}

void right_left_rotation(rb_node* node) {

	right_rotation(node);
	left_rotation(node);
}

void right_right_rotation(rb_node* node) {

	left_rotation(node);
	left_rotation(node);
}

void left_rotation(rb_node* node) {
	rb_node* grandfather = node->parent->parent;
	int is_parent_left = grandfather->left == node->parent;
	node->parent->parent = node;
	node->parent->right = node->left;
	node->parent->right->parent = node->parent;
	node->left = node->parent;
	node->left->parent = node;//check it
	node->parent = grandfather;
	if (is_parent_left)
		grandfather->left = node;
	else
		grandfather->right = node;
}

void right_rotation(rb_node* node) {

	rb_node* grandfather = node->parent->parent;
	int is_parent_left = grandfather->left == node->parent;
	node->parent->parent = node;
	node->parent->left = node->right;
	node->right->parent = node->parent;
	node->right = node->parent;
	node->right->parent = node;
	node->parent = grandfather;
	if (is_parent_left)
		grandfather->left = node;
	else
		grandfather->right = node;
}
//remvoe task from the rb_tree