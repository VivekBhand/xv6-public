typedef struct queueNode {
    struct queueNode *nextSlot;
} queueNode;

typedef struct queue{
  struct queueNode *end;
  struct queueNode *start;
}Queue;

#define NULL_QUEUE 0