/* ____________ STANDATE INCLUDES ________________*/
#include <stdio.h>
#include <time.h>


/* ____________ PROJECT INCLUDES _________________*/
#include "speed.h"
#include "acceleration.h"

/* ____________     MACROS       _________________*/
#define EXIT_SUCCESS 0

int 
main(void)
{
    int before = time(NULL);
    float x = 10.0,y =70.0, v = 0.0, a = 0.0;

    get_speed(&x,&y,&v);
    get_acceleration(&v,&y, &a);
    printf("The speed is   : %f\n", v);
    printf("The Acceleration is  : %f\n", a);

    int after = time(NULL);

    printf("%d milliseconds elapsed\n", (after - before)*1000);

    return EXIT_SUCCESS;
}