#ifndef TASK_H
#define TASK_H



typedef struct {
	int id;
	int nice;
	long double weight;
	double vruntime;
	double slice;
	double execution_time;
	double remaining_time;
}task;


#endif // !TASK_H

