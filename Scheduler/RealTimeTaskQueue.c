#pragma once
#include <stdlib.h>
#include "RealTimeTaskQueue .h"

void push_task_node(struct real_time_task_queue* real_time_task_queue,struct queue_node* real_time_node) {

    //struct queue_node* new_node = create_queue_node(priority, execution_time);
    if (real_time_task_queue->rear) {
        real_time_task_queue->rear->next = real_time_node;
    }
    else {
        real_time_task_queue->front = real_time_node;
    }
    real_time_task_queue->rear = real_time_node;
    real_time_task_queue->num_of_tasks++;
    real_time_task_queue->total_weights += real_time_node->task->weight;
}

struct queue_node* pop_task_node(struct real_time_task_queue* real_time_task_queue) {
    if (!real_time_task_queue->front) return NULL;
    struct queue_node* queue_node = real_time_task_queue->front;
    queue_node->next = NULL;
    real_time_task_queue->front = real_time_task_queue->front->next;
    if (!real_time_task_queue->front) {
        real_time_task_queue->rear = NULL;
    }
    return queue_node;
}

