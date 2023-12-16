#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 5
typedef struct STK
{
    int TOP;
    int A[MAX];
} STACK;
//  creating create function
void create_stack(STACK *s)
{
    s->TOP = -1;
}
//  creating PUSH functiuon
void PUSH(STACK *s, int value)
{
    if (s->TOP == MAX - 1)
    {
        printf("\n Stack is FULL");
    }
    else
    {
        s->TOP = s->TOP + 1;
        s->A[s->TOP] = value;
    }
}
// creating POP function
int POP(STACK *s)
{
    int x;
    if (s->TOP == -1)
    {
        printf("\n Stack is Empty");
        return (-1);
    }
    else
    {
        x = s->A[s->TOP];
        s->TOP = s->TOP - 1;
        return (x);
    }
}
// creating Display functin
void display(STACK *s)
{
    int i;
    for (i = 0; i <= s->TOP; i++)
        printf(" %d", s->A[i]);
    printf("\n");
}
// creating main function
main()
{
    printf("\n Name - Aditya Raj");
    STACK s;
    int value, x, ch;
    create_stack(&s);
    while (1)
    {
        printf("\n 1: PUSH");
        printf("\n 2: POP");
        printf("\n 3: DISPLAY");
        printf("\n 4: EXIT");
        printf("\n 5: Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("\n Enter value: ");
            scanf("%d", &value);
            PUSH(&s, value);
            break;
        }
        case 2:
        {
            x = POP(&s);
            if (x != -1)
            {
                printf("\n Deleted item : %d", x);
            }
            break;
        }
        case 3:
        {
            display(&s);
            break;
        }
        case 4:
        {
            exit(0);
        }
        }
        getch();
    }
}