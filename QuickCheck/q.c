/* A simple queue as a circular buffer */

#include <stdlib.h>
#include <stdio.h>

typedef struct queue
{
  int inp;  /* input pointer */
  int outp; /* output pointer */
  int size; /* size of the buffer */
  int *buf;
} Queue;

/* Create  a new queue of size n */
Queue *new(int n)
{
  /* create the buffer */
  int *buff = malloc((n+1)*sizeof(int));
  Queue q = {0, 0, n+1, buff};
  Queue *qptr = malloc(sizeof(Queue)); /* why not simply: return &q; ? aha, because q is local?  */
  *qptr = q;
  return qptr;
}

int put (Queue *q, int n)
{
  q->buf[q->inp] = n;
  q->inp = (q->inp + 1) % q->size; /* modulo size of circular buffer */
  return n;
}

int get (Queue *q)
{
  int ans = q -> buf[q->outp];
  q->outp = (q->outp + 1) % q ->size;
  return ans;
}

int size(Queue *q)
{
  return (q->inp - q->outp) % q->size;
}
/*
int main() 
{
  Queue *q = new(3);
  printf("size: %d\n", size(q));
  
  put(q, 1);
  put(q, 1);
  put(q, 1);
  printf("size: %d\n", size(q));
}
*/