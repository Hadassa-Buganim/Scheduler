
#include <math.h>
#include "RealTimeTask.h"
#define DEFULT_WEIGHT 1024
struct real_time_task* create_real_time_task(int priority, double execution_time) {
    ID++;
    struct real_time_task* new_task = (struct real_time_task*)malloc(sizeof(struct real_time_task));
    new_task->id = ID;
    new_task->remaining_time = execution_time;
    new_task->weight = (DEFULT_WEIGHT / pow(1.25, priority));
    return new_task;
}
void free_real_time_task(struct real_time_task* real_time_task) {
    free(real_time_task);
}