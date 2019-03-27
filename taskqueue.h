#ifndef EVENTLOOP_TASKQUEUE_H 

#define EVENTLOOP_TASKQUEUE_H

typedef struct TaskNode TaskNode;

/**
 * A function that gets called when an event occured that could change the state of the task
 */
typedef void (*taskfn)(void*);

/**
 * The task queue itself.
 * It is implemented as a linked list
 */
typedef struct TaskQueue {
   TaskNode* tasks_head;
   TaskNode* tasks_tail;
} TaskQueue;

/**
 * A node that represents a Task on the task queue
 */
typedef struct TaskNode {
   taskfn fn;
   void* data;
   TaskNode* prev;
   TaskNode* next;   
} TaskNode;

/**
 * Create an empty queue
 */
TaskQueue* create_queue();

/**
 * Add a new task to the queue
 * @param q the task queue to which the task must be added
 * @param task the task that must be added. Please note that
 * the user is responsible for managing the memory assiocated with 
 * the task
 */
void enqueue(TaskQueue*, TaskNode*);

/**
 * Get the first element of the queue
 * @param q the task queue of which the task must be lifted
 * @return a task node
 */
TaskNode* dequeue(TaskQueue*);

#endif
