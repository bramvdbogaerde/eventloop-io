/**
 * This file defines some structs that can be used as data for serveral types of tasks.
 *
 * The runtime assumes that the first field of the struct always contains the type of the task.
 * It tries to match that against the enum TaskType
 */

#ifndef EVENTLOOP_TASKS_H

#define EVENTLOOP_TASKS_H

/**
 * An enum containing the types of tasks that exist in our system
 */
typedef enum TaskType {
   /**
    * The read task
    */
   IO_READ,

   /**
    * The write task
    */
   IO_WRITE
} TaskType;

/**
 * The states a read call can be in
 */
typedef enum ReadState {
   /**
    * The call is waiting for input, this is the point where the call would normally block
    */
   WAITING_FOR_INPUT,

   /**
    * The call is finished. So the task is not necessary anymore
    */
   FINISHED
} ReadState;

/**
 * A generic TaskData type.
 * This struct is used for fetching the type field of the other tasks.
 * When the the type is correctly identified the runtime will cast it the correct struct
 */
struct TaskData {
   /**
    * The type of the task
    */
   TaskType type;
}

struct ReadTask {
   /**
    * Mandatory field, by construction the field should contain IO_READ.
    */
   TaskType type;

   /**
    * The current state of the read command
    */
   ReadState state;

   /**
    * The number of bytes the read needs to be available
    * in case the state is WAITING_FOR_INPUT
    */
   int number_of_bytes_needed;
}

#endif
