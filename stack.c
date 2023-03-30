#include "stack.h"

/*   createEmptyStack function Description:
 * - This function takes a reference to a stacks type
 * - Initialize this stack with Zeros
 * - Initialize the top with -1
 *   Return:
 * - Nothing to return
 */

 void createEmptyStack(ST_stack_t *stack)
 {
    for (uint8_t i =0; i < STACK_SIZE ; i++)
    {
        stack->elements[i] = 0;
        stack->top         = -1;
    }
 }

 /*  Push function Description:
 * - This function takes a reference to the stack and data to store
 * - Stores the data passed into the stack
 *   Return:
 * - returns -1 if the stack is full
 * - returns 0 otherwise
 */

 int8_t push(ST_stack_t *stack, uint8_t data)
 {
     if(stack->top == 9)
     {
         return -1;
     }
     else
     {
         stack->top += 1;
         stack->elements[stack->top] = data;
         return 0;
     }
 }

 /*  Pop function Description:
 * - This function takes a reference to the stack
 * - Stores the data popped from the stack in a data variable
 *   Return:
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */

 int8_t pop(ST_stack_t *stack, uint8_t *data)
 {
    if(stack->top == -1)
    {
        return -2;
    }
    else
    {
        *data = stack->elements[stack->top] ;
        stack->top -= 1;
        return 0;
    }
 }


 /*  PrintStack function Description:
 * - This function takes a reference to the stack
 * - Prints all stack's data starting from the top
 *   Return:
 * - returns -1 if the stack is full
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */

 int8_t printStack(ST_stack_t *stack)
 {
     if(-1 == stack->top) // empty
     {
         return -2;
     }
     else
     {
         printf("Stack elemenets are:\n");
         for(int i=stack->top; i> -1; i--)
         {
             printf("Elements[%d] = %c\n", i, stack->elements[i]);
         }
         if (9 == stack->top) // full
         {
             return -1;
         }
         else
         {
              return 0;
         }
     }
 }


/*   getStackTop function Description:
 * - This function takes a reference to the stack
 * - Stores its top data into a variable
 *   Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */

int8_t getStackTop(ST_stack_t *stack, uint8_t *topData)
 {
     if (-1 == stack->top)
     {
         printf("Stack is empty \n");
         return -2;
     }
     else
     {
         *topData = stack->elements[stack->top];
        // *topData = stack->top;
         return 0;
     }
 }

/*   isFull function Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is full or not
 *   Return:
 * - returns -1 if the stack is full
 * - 0 otherwise
 */

int8_t isFull(ST_stack_t *stack)
{
    if(9 == stack->top)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}



/*   isEmpty function Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is empty or not
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t isEmpty(ST_stack_t *stack)
{
    if(-1 == stack->top)
    {
        return -2;
    }
    else
    {
        return 0;
    }
}
