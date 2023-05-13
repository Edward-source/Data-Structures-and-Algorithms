/* =============================================================================
 |   Project   :  DATA STRUCTURES AND ALGORITHS IN C
 |
 |   Author    :  EDWARD TLADI
 |   Language  :  ANSI C LANG
 |   To Compile:  gcc main.c 
 |
 |   Date      :  05 /04/2023
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  Learning Link list in C 
 |
 |    Algorithm:  OUTLINE THE APPROACH USED BY THE PROGRAM TO SOLVE THE
 |      PROBLEM.
 |
 |   Required Features Not Included: 
 |
 |   Known Bugs:  
 |
 *=========================================================================== */



/* ____________ STANDATE INCLUDES ________________*/
#include <stdio.h>
#include <time.h>


/* ____________ PROJECT INCLUDES _________________*/
#include "speed.h"
#include "acceleration.h"
#include "../linked_list/linked_list.h"

/* ____________     MACROS       _________________*/
#define EXIT_SUCCESS 0


int 
main(void)
{
    int before = time(NULL);

    Node* list = NULL;

    Initialize_Node(list);
    int isEmpty = is_empty(list);
    printf("Is empty ? : %d\n", isEmpty);
    
    int after = time(NULL);

    
    printf("%d milliseconds elapsed\n", (after - before)*1000);

    return EXIT_SUCCESS;
}