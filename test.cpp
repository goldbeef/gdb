/*************************************************************************
    > File Name: test.c
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年04月12日 星期三 21时24分22秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

void sigintHandle(int signo)
{
    printf("sigintHandle: signo[%d]\n", signo);
}

int func(int n)
{
    int sum = 0, i;
    for (i = 0; i < 100; i++)
    {
        sum += i;
    }
    return sum;
}

int func(int m, int n)
{
    int sum;
    sum = m + n;
    return sum;
}

class CTest
{
public:
    CTest() { }

    ~CTest() { }

    int max(int val1, int val2)
    {
        int maxVal;
        if (val1 >= val2)
        {
            maxVal = val1;
        }
        else
        {
            maxVal = val2;
        }
        return maxVal;
    }
    
    int max(int val1, int val2, int val3)
    {
        int maxVal;
        if (val1 >= val2)
        {
            maxVal = val1;
        }
        else
        {
            maxVal = val2;
        }
        return maxVal;
    }
};

void* threadRoutine(void* arg)
{
    while(1)
    {
        int j, sum = 0;
        for (j = 0; j < 100; j++)
        {
            sum += j;
        }

        int *ptr = &sum;
        //printf("sum[%d]\n", sum);
        //printf("func[%d]\n", func(100));
        func(100);

        CTest ctest;
        int maxVal = ctest.max(10, 5);
        
        ctest.max(1,2,3);
        func(10, 6);
        system("echo hello");
        sleep(3);
    }
}

int main(int argc, char *argv[])
{
    if (SIG_ERR == signal(SIGINT, sigintHandle))
    {
        printf("signal error\n");
        return -1;
    }

    pthread_t threadId;
    
    int ret =  pthread_create(&threadId, NULL, threadRoutine, NULL);
    if (ret != 0)
    {
        printf("pthread_create error\n");
        return -1;
    }
    
    while(1)
    {
        sleep(5);
    }
    return 0;
}
