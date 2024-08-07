#include "round_robin.h"

void execute_queue(real_time_task_queue* queue) {

	while (!is_queue_empty(queue)) {

		queue_node* node = pop_task_node(queue);
		real_time_task* current_task = node->task;

		//calculate the current quantum
		double quantum = SCHED_LATENCY * (current_task->weight / queue->total_weights);
		//checking the quantum calculated with the minimum quantum
		if (quantum < MIN_QUANTUM)
			quantum = MIN_QUANTUM;
		current_task->quantum = quantum;

		double delta_exec = 0;
		while (current_task->remaining_time > 0 && delta_exec < current_task->quantum) {
			//may it is more correct after the while?
			current_task->remaining_time--;
			delta_exec++;
		}

		current_task->execution_time += node->task->quantum;

		//check why the loop finished
		if (node->task->remaining_time <= 0) {
			queue->total_weights -= current_task->weight;

			free_queue_node(node);
		}
		else {
			push_task_node(queue, node);
		}
	}
}