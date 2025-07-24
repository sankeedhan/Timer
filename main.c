#include <stdio.h>
#include <time.h>

void print_result(unsigned long int result)
{
    unsigned int h = result / 3600;
    unsigned int m = (result % 3600) / 60;
    unsigned int s = result % 60;

    printf("Total Elapsed: %02u:%02u:%02u\n", h, m, s);
}

int main(void)
{
    unsigned long int result = 0;
    time_t start_time = time(NULL);
    int not_stop = 0;
    int not_repet = 0;
    printf("%s", ctime(&start_time));
    while (1)
    {
        int i;
        scanf("%d", &i);
        if (i == not_repet)
        {
            printf("No further action allowed.\n");
            continue;
        }
        if ((i == 3) && (not_stop))
        {
            printf("Timer already stopped. No further action allowed.\n");
            continue;
        }

        if (i == 1)
        {
            time_t pause_time = time(NULL);
            result = (pause_time - start_time) + result;
            printf("Pausing...\n");
            // printf("%s", ctime(&pause_time));
            print_result(result);
            not_stop = 1;
            not_repet = 1;
        }
        else if (i == 2)
        {
            start_time = time(NULL);
            printf("Starting...\n");
            not_stop = 0;
            not_repet = 2;
            // printf("%s", ctime(&start_time));
        }
        else if (i == 3)
        {

            time_t reset_time = time(NULL);
            result = (reset_time - start_time) + result;
            // printf("%s", ctime(&reset_time));
            print_result(result);
            printf("Stoping...\n");
            not_repet = 3;
            break;
        }
        else
        {
            printf("Check the input...\n");
        }
    }
    // time_t z = time(NULL);
    // result = z - t;
    // printf("%s", ctime(&z));
    // printf("%d\n", i);
    // printf("%s", ctime(&result));
}