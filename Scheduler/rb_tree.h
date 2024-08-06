
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
void insert_task(rb_tree* tree, task* task);

void add_node(rb_node* root, rb_node* node);

void check_and_changes_colors(rb_node* node);

void change_colors_to_black(rb_node* grandfather);

//rotation

// left right rotation
void left_right_rotation(rb_node* node);

void left_left_rotation(rb_node* node);

void right_left_rotation(rb_node* node);

void right_right_rotation(rb_node* node);

void left_rotation(rb_node* node);

void right_rotation(rb_node* node);
//remvoe task from the rb_tree






#endif // !RB_TREE_H