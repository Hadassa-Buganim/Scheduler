
#ifndef RB_TREE_H
#define RB_TREE_H

#include <stdlib.h>

#include "task.h"

#define BLACK 0
#define RED 1

typedef struct rb_node {
	task* task;
	char color;
	struct rb_node* left;
	struct rb_node* right;
	struct rb_node* parent;
}rb_node;


typedef struct {
	int num_of_tasks;
	rb_node* root;
	rb_node* most_left;
	long double total_weights;
}rb_tree;


rb_tree* initial_rb_tree();

//insert task to the rb_tree
void rb_tree_task_arrival(rb_tree* tree, task* task);

void add_node_to_tree(rb_node* root, rb_node* node);

void rotate_tree(rb_node* node);

void change_colors_hierarchical(rb_node* grandfather);

//rotation

// left right rotation
void left_right_rotation(rb_node* node);

void right_left_rotation(rb_node* node);

void left_rotation(rb_node* node);

void right_rotation(rb_node* node);

void change_colors_after_rotation(rb_node* node);
//remvoe task from the rb_tree

//free tree
void free_struct_rb_tree(rb_tree* tree);

void free_rb_tree(rb_node* node);






#endif // !RB_TREE_H