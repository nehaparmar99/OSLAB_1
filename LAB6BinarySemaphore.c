#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
int a, b;
sem_t sem;
void inputno(void *ptr){
    for (;;){
        printf("%s", (char *)ptr);
        scanf("%d %d", &a, &b);
        sem_post(&sem);
        usleep(100 * 1000);
    }
}
void outputsum(void *ptr){
    for (;;){
        sem_wait(&sem);
        printf("%s %d\n", (char *)ptr, a + b);
    }
}
int main()
{
    pthread_t thread1;
    pthread_t thread2;
    char *Msg1 = "Enter 2 numbers\n";
    char *Msg2 = "Sum of the numbers = ";
    sem_init(&sem, 0, 0);
    pthread_create(&thread1, NULL, (void *)inputno, (void *)Msg1);
    pthread_create(&thread2, NULL, (void *)outputsum, (void *)Msg2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Wait For Both Thread to finish\n");
    sem_destroy(&sem);
    return 0;
}
