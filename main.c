#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


void print_logo();
void print_result(unsigned long int result);



void 
print_logo(void)
{
    printf("████████╗██╗███╗   ███╗███████╗██████╗\n");
    printf("╚══██╔══╝██║████╗ ████║██╔════╝██╔══██╗\n");
    printf("   ██║   ██║██╔████╔██║█████╗  ██████╔╝\n");
    printf("   ██║   ██║██║╚██╔╝██║██╔══╝  ██╔══██╗\n");
    printf("   ██║   ██║██║ ╚═╝ ██║███████╗██║  ██║\n");
    printf("   ╚═╝   ╚═╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝\n");
}

void 
print_result(unsigned long int result)
{
    unsigned int h = result / 3600;
    unsigned int m = (result % 3600) / 60;
    unsigned int s = result % 60;
    printf("Total Elapsed: %02u:%02u:%02u\n", h, m, s);
}
int
log_file_write(const char *data)
{
    char *copy_data = malloc((strlen(data)+1));
    strcpy(copy_data,data);
    FILE *file_name;
    file_name = fopen("/var/log/timer.log","a+");
    if (file_name == NULL)
    {
        printf("The file is can write.");
        return 0;
    }
    fputs(copy_data,file_name);
    fclose(file_name);
    free(copy_data);
    return 1;
}

int 
main(void)
{
    print_logo();
    unsigned long int result = 0;
    time_t start_time = time(NULL);
    int not_stop = 0;
    int start = 0;
    int not_repet = 0;
    char *log_data=ctime(&start_time);
    printf("%33s", log_data);
    log_file_write(log_data);
    while (1)
    {
        int i;
        printf(">");
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
            start = 1;
        }
        else if (i == 2)
        {
            if (start)
            {
                start_time = time(NULL);
                printf("Starting...\n");
                not_stop = 0;
                not_repet = 2;
            } else
            {
                printf("Timer already started. No further action allowed.\n");
                continue;
            }
            
            
            
            // printf("%s", ctime(&start_time));
        }
        else if (i == 3)
        {
            printf("Stoped.\n");
            time_t reset_time = time(NULL);
            result = (reset_time - start_time) + result;
            // printf("%s", ctime(&reset_time));
            print_result(result);
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