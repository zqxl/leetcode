#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>

/*构造一个队列结构*/
typedef struct
{
	int* data;
	int front;
	int rear;
}Myqueue;

/*队列的初始化*/
void initqueue(Myqueue* q, int maxSize)
{
	q->data = (int*)malloc(sizeof(int) * maxSize);
	q->front = 0;
	q->rear = 0;
}

/*入队*/
void Enqueue(Myqueue* q, int x)
{
	q->data[q->rear++] = x;
}

/*出队*/
int Dequeue(Myqueue* q)
{
	return q->data[q->front++];
}

/*队列为空，返回1，非空返回0*/
int is_queue_empty(Myqueue* q)
{
	return q->rear == q->front ? 1 : 0;
}

/*回到队列的首位*/
void queuetop(Myqueue* q)
{
	q->front = 0;
	q->rear = 0;
}

/*构造一个栈的结构，其中队列q1用来入栈， 队列q2用来出栈*/
typedef struct
{
	Myqueue* q1;
	Myqueue* q2;
} MyStack;

/** Initialize your data structure here. */
/*初始化栈*/
MyStack* myStackCreate(int maxSize)
{
	MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
	stack->q1 = (Myqueue*)malloc(sizeof(Myqueue));
	initqueue(stack->q1, maxSize);
	stack->q2 = (Myqueue*)malloc(sizeof(Myqueue));
	initqueue(stack->q2, maxSize);
	return stack;
}

/** Push element x onto stack. */
/*把元素x放入栈中，这是队列q1的工作*/
void myStackPush(MyStack* obj, int x)
{
	Enqueue(obj->q1, x);
}

/** Removes the element on top of the stack and returns that element. */
/*我这里的做法是先把队列q1中除开最后一个元素其余的全部的元素都并入队列q2中，然后把q1中的仅剩的那一个元素返回，这就满足了栈的
后入先出的原则了，接着再把队列q2中的元素全部又并回给q1，这里的队列q2其实就负责周转而已，到后来它又变回空的，和初始状态一样*/
int myStackPop(MyStack* obj)
{
	int tmp;
	if (is_queue_empty(obj->q1)) //首先就要判断q1是否为空，q1是负责入栈工作的（虽然出栈也有它份，但出栈不全是它），它都空了，那还pop个鬼
	{
		return 0;
	}
	else
	{
		while (obj->q1->front != obj->q1->rear - 1) //保留q1的最后的一个元素，其余全给q2.
		{
			Enqueue(obj->q2, Dequeue(obj->q1));
		}
		tmp = Dequeue(obj->q1); //q1的最后的一个元素给tmp
		queuetop(obj->q1);      //q1回到顶部
		while (!is_queue_empty(obj->q2)) //把q2中的全部元素又还给q1
		{
			Enqueue(obj->q1, Dequeue(obj->q2));
		}
	}
	return tmp;
}

/** Get the top element. */
/*回到栈的顶部，其实就是回到q1的最后那里，因为入栈的操作全给q1负责了*/
int myStackTop(MyStack* obj)
{
	return obj->q1->data[obj->q1->rear - 1];
}

/** Returns whether the stack is empty. */
/*是不是空，看q1就行了，因为q1负责入栈操作*/
bool myStackEmpty(MyStack* obj)
{
	return is_queue_empty(obj->q1);
}

void myStackFree(MyStack* obj)
{
	free(obj->q1->data);
	free(obj->q1);
	free(obj->q2->data);
	free(obj->q2);
	free(obj);
}

