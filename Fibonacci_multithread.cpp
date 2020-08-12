#include<iostream>
#include<pthread.h>
void* fibonacci(void*);
using namespace std;
int n;
void* fibonnacci(void* arg)
{
int c, first = 0, second = 1, next;
for ( c = 0 ; c <n; c++ )
{
if ( c <= 1 )
next = c;
else
{
next = first + second;
first = second;
second = next;
}
cout << next << endl;
}
}

int main()
{
pthread_t t;
cout << "Enter the number of terms of Fibonacci series you want" << endl;
cin >> n;
cout << "First " << n << " terms of Fibonacci series are :- " << endl;
pthread_create (&t , NULL , fibonacci,(void*)&n);
return 0;
}
