#include <stdlib.h>
#include "taskqueue.h"

/**
 * Create an empty queue
 */
TaskQueue* create_queue() {
   return (TaskQueue*) calloc(1, sizeof(TaskQueue));
}

/**
 * Add a new task to the queue
 * @param q the task queue to which the task must be added
 * @param task the task that must be added. Please note that
 * the user is responsible for managing the memory assiocated with 
 * the task
 */
void enqueue(TaskQueue* q, TaskNode* task) {
   if (q->tasks_head == NULL) {
      q->tasks_head = task;
      task->prev = NULL;
   } else {
      TaskNode* last = q->tasks_tail;
      last->next = task;
      task->prev = last;
   }

   q->tasks_tail = task;
   task->next = NULL;
}

/**
 * Get the first element of the queue
 * @param q the task queue of which the task must be lifted
 * @return a task node
 */
TaskNode* dequeue(TaskQueue* q) {
   TaskNode* first = q->tasks_head;
   if (first->next == NULL) {
      q->tasks_tail = NULL;
   } else {
      first->next->prev = NULL;
   }

   q->tasks_head = first->next;
   first->next = NULL;
   return first;
}
