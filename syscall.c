/* syscall.c
 *
 * Group Members Names and NetIDs:
 *   1. Jackson Bainbridge jdb343
 *   2. Michael Rucando mwr72
 *
 * ILab Machine Tested on: top
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>

double avg_time = 0;

int main(int argc, char *argv[]) {

  clock_t time;
  unsigned cpu, node;

  time = clock();
    for(int i = 0; i < 2000; i++){
      if(i == 0){
        printf("Starting...\n");
      }

        syscall(SYS_getcpu, &cpu, &node, NULL);
        printf("CPU CORE: %u, NUMA NODE: %u\n", cpu, node);

      if(i == 1999){
        printf("Ending...\n");
      }

    }

    time = clock() - time;
    avg_time = ((double)time)/CLOCKS_PER_SEC;
    // Remember to place your final calculated average time
    // per system call into the avg_time variable

    printf("Average time per system call is %f microseconds\n", avg_time);

    return 0;
}
