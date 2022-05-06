#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
volatile sig_atomic_t flag = 0;

void sigHandler(int sig)
{
    flag = 1;
}

int main()
{
    int count = 0;
    int randNum;
    signal(SIGINT, sigHandler);
    while (1)
    {
        randNum = 100 + (int)(rand() * (1000 - 100 + 1.0) / (1.0 + RAND_MAX));
        printf("白って%d色あんねん\n", randNum);
        count++;
        if (flag)
        {
            printf("%d 人のアンミカ\n", count);
            flag = 0;
            exit(1);
        }
    }
    return 0;
}