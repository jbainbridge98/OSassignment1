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

double avg_time = 0;

int main(int argc, char *argv[]) {

  long uid;
  struct timeval start, end;
  double temp;

    for(int i = 1; i < 2001; i++){
      gettimeofday(&start, NULL);
      if(i == 0){
        printf("Starting...\n");
      }

        uid = syscall(SYS_getuid);
        printf("User ID: %ld\n", uid);

      if(i == 2000){
        printf("Ending...\n");
      }
      gettimeofday(&end, NULL);
      double seconds = (end.tv_sec - start.tv_sec);
      temp = ((seconds * 1000000) + end.tv_usec) - start.tv_usec;
      avg_time = (avg_time + temp);
    }
    avg_time = avg_time / 2000;
    // Remember to place your final calculated average time
    // per system call into the avg_time variable

    printf("Average time per system call is %f microseconds\n", avg_time);

    return 0;
}
