#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 5
// creating structure
typedef struct que
{
    int REAR;
    int FRONT;
    int Q[MAX];
} QUEUE;
// creating create queue function
void create_LQ(QUEUE *q)
{
    q->REAR = -1;
    q->FRONT = -1;
}
// creating ADD fucntion
void ADD_LQ(QUEUE *q, int value)
{
    if (q->REAR == MAX - 1)
    {
        printf("\n Linear Queue is FULL");
        return;
    }
    if (q->REAR == -1)
    {
        q->REAR = q->FRONT = 0;
    }
    else
    {
        q->REAR = q->REAR + 1;
    }
    q->Q[q->REAR] = value;
}
// creating DELETE function
int DEL_LQ(QUEUE *q)
{
    int x;
    if (q->FRONT == -1)
    {
        printf("\n Linear Queue is EMPTY");
        return (-1);
    }
    x = q->Q[q->FRONT];
    if (q->REAR == q->FRONT)
    {
        q->REAR = q->FRONT = -1;
    }
    else
    {
        q->FRONT = q->FRONT + 1;
    }
    return (x);
}
// creating DISPLAY function
void display_LQ(QUEUE *q)
{
    int i;
    if (q->REAR == -1)
    {
        printf("\n Queue is EMPTY");
        return;
    }
    else
    {
        for (i = q->FRONT; i <= q->REAR; i++)
        {
            printf(" %d", q->Q[i]);
        }
    }
    printf("\n");
}
// creating main fucntion
main()
{
    printf("\nName - Aditya Raj");
    QUEUE q;
    int value, x, ch;
    create_LQ(&q);
    while (1)
    {
        printf("\n 1: ADD");
        printf("\n 2: DELETE");
        printf("\n 3: DISPLAY");
        printf("\n 4: EXIT");
        printf("\n 5: Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("\n Enter value: ");
            scanf("%d", &value);
            ADD_LQ(&q, value);
            break;
        }
        case 2:
        {
            x = DEL_LQ(&q);
            if (x != -1)
            {
                printf("\n Deleted item: %d", x);
            }
            break;
        }
        case 3:
        {
            display_LQ(&q);
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