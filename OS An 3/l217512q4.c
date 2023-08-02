/*Question # 4: [Marks:10]
Consider the following code for a simple Stack:
class Stack {
private:
int* a; // array for stack
int max; // max size of array
int top; // stack top
public:
Stack(int m) {
a = new int[m]; 
max = m; 
top = 0;
}
void push(int x) {
while (top == max); // if stack is full then wait
a[top] = x;
++top;
}
int pop() {
while (top == 0); // if stack is empty then wait
int tmp = top;
--top;
return a[tmp];
}
};
Assuming the functions push and pop can execute concurrently, synchronize the code using semaphores. Also, replace the busy waiting with proper waiting*/

// 21L-7512 ABDULLAH DAR OS AN 3 Q4

class Stack{
private:
int *a;
int max;
int top;
sem_t full;
sem_t empty;

public:

Stack(int m)
{
	a = new int[m];
	max = m;
	top = 0;
	sem_init(&full,0,0);
	sem_init(&empty,0,m);
}

void push(int x)
{
	sem_wait(&empty);
	a[top] = x;
	++top;
	sem_post(&full);
}

int pop()
{
	sem_wait(&full);
	--top;
	int temp = a[top];
	sem_post(&empty);
	return temp;
}
};
//-- END --  
