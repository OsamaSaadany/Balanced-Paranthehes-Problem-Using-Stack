#include "stack.h"
int8_t isBalancedParanthethes(uint8_t *expression);

int main()
{
    /* Testing the stack */
    /*1. Create an empty stack */
    ST_stack_t s1;
    createEmptyStack(&s1);
    /*2. Push 5 different characters to the stack */
    push(&s1, 'L');
    push(&s1, 'M');
    push(&s1, 'N');
    push(&s1, 'O');
    push(&s1, 'P');
    /*3. Print all stack data */
    printStack(&s1);
    /*4. Pop one character from the stack */
    uint8_t temp;
    pop(&s1, &temp);
    /* 5. Print the stack's top */
    getStackTop(&s1, &temp);
    printf("stack top = %c\n", temp);
    /*6. Print all stack data */
    printStack(&s1);
   /* 7. Push another 7 different characters to the stack */
    push(&s1, 'Q');
    push(&s1, 'R');
    push(&s1, 'S');
    push(&s1, 'T');
    push(&s1, 'U');
    push(&s1, 'V');
    push(&s1, 'W');
    /* 8. Print the stack's top */
    getStackTop(&s1, &temp);
    printf("stack top = %c\n", temp);
    /* 9. Print all stack data */
    printStack(&s1);
    /* 10. Pop 4 characters from the stack */
    pop(&s1, &temp);
    pop(&s1, &temp);
    pop(&s1, &temp);
    pop(&s1, &temp);
    /* 11. Print the stack's top */
    getStackTop(&s1, &temp);
    printf("stack top = %c\n", temp);
    /* 12. Print all stack data */
    printStack(&s1);
    /* 13. Pop 7 more times from the stack */
    pop(&s1, &temp);
    pop(&s1, &temp);
    pop(&s1, &temp);
    pop(&s1, &temp);
    pop(&s1, &temp);
    pop(&s1, &temp);
    pop(&s1, &temp);
    /* 14. Print the stack's top */
    getStackTop(&s1, &temp);
    printf("stack top = %c\n", temp);
    /* 15. Print all stack data */
    printStack(&s1);
    printf("\n\n");

    // Testing the isBalanced Paranthethes function
    uint8_t * testcases[10] = {"{(2+3)}", "{{((2+3)}", "[(2+3)]","{(2+3)/((3+3)*(15-10))}","(2+3)/((3+3)*(15-10)))",
                                "{{{2+3)/((3+3)*(15-10)))", "{(2+3(/((3+3)*(15-10))}","{(2+3)/((3+3(*)15-10))}",
                                "})2+3)/((3+3)*(15-10))}", "{(2+3)/(<3+3>*(15-10))}" };

    uint8_t j = 0;
    int8_t result;
    while(j<10)
    {
        result = isBalancedParanthethes(testcases[j]);
        printf("Expression %d  result = ", j);
        if (result == 0)
        {
            printf("Balanced\n");
        }
        else if (result == -1)
        {
            printf("Unbalanced\n");
        }
        j++;
    }
    return 0;
}

 /* isBalancedParanthethes function Description:
 * - This function takes an expression array max 10 characters
 * - Checks if the parentheses are balanced or not
 * - Checks the following parentheses types {, }, (, ) only
 * Return:
 * - returns -2 if the neither of paranthethes is used
 * - returns -1 if the parentheses are not balanced
 * - returns 0 if the parentheses are balanced
 */

int8_t isBalancedParanthethes(uint8_t *expression)
{
    int status = -2;

    if (sizeof(*expression) == 0)
    {
        return status;
    }
    else
    {
         // temporary stack creation
        ST_stack_t temp_stack;
        createEmptyStack(&temp_stack);

        for(uint8_t i; expression[i] != '\0'; i++)
        {
            // check for parentheses
            if(expression[i] == '{' || expression[i] == '(')
            {
                push(&temp_stack, expression[i]);
                status = -1;// there is parentheses but not balanced
            }
            if(expression[i] == '}' || expression[i] ==')')
            {
                int8_t stackStatus;
                uint8_t temp;
                stackStatus = pop(&temp_stack, &temp);
                if((stackStatus != -2) && (((temp+1) == expression[i])||((temp+2) == expression[i])))
                {
                    status = 0;
                }
                else
                {
                    status = -1;
                }

            }
        }
    }
return status;
}
