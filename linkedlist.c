#include <stdio.h>
#include <stdlib.h>
struct linkedlist
{
    int data;
    struct linkedlist *next_ptr;
} *first, *temp, *newnode, *temp1;
void *create(int num);
void display(struct linkedlist *header);
void *insertfirst(struct linkedlist *temp);
void insertend(struct linkedlist *header);
void *insertmiddle(struct linkedlist *header);
void *deletefirst(struct linkedlist *header);
void deleteend(struct linkedlist *header);
void deletemiddle(struct linkedlist *header);
int displayrev(struct linkedlist *header);
int count(struct linkedlist *header);

int d;

int main()
{
    printf("Enter the no. of elements\n");
    int num_ele;
    scanf("%d", &num_ele);
    first = create(num_ele);
    display(first);
    do
    {
        printf("choose any \n\t1. insertfirst\n\t2. insertend\n\t3. insertmiddle\n\t4. deletefirst\n\t5. deletelast\n\t6. deletemiddle\n\t7. display\n\t8. display in reverse\n\t9. to count the nodes");
        scanf("%d", &d);
        fflush(stdin);

        switch (d)
        {
        case 1:
            printf("insertion in the first = \n");
            first = insertfirst(first);
            break;
        case 2:
            printf("after insertion in the end = \n");
            insertend(first);
            break;
        case 3:
            printf("Insertion in the middle\n");
            insertmiddle(first);
            break;
        case 4:
            printf("Deletion in the beginning\n");
            first = deletefirst(first);
            break;
        case 5:
            printf("Deletion in the end\n");
            deleteend(first);
            break;
        case 6:
            printf("Deletion in middle\n");
            deletemiddle(first);
            break;
        case 7:
            display(first);
            break;
        case 8:
            displayrev(first);
            break;
        case 9:
            printf(" The no. of nodes in the list = %d\n", count(first));
            break;
        default:
            printf("Invalid input\n");
        }
        printf("Do you want to continue... if yes enter 'y'\n");
        fflush(stdin);
    } while (getchar() == 'y');
}
void *create(int num)
{
    first = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    temp = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    printf("Enter the data of first node \n");
    scanf("%d", &d);
    if (first == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }
    first->data = d;
    first->next_ptr = NULL;
    temp = first; // temp stores the address of first
    for (int i = 2; i <= num; i++)
    {
        newnode = (struct linkedlist *)malloc(sizeof(struct linkedlist)); // dynamically creates a memory in a new address
        if (newnode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }
        printf("Enter the data of node = %d\n", i);
        scanf("%d", &d);
        newnode->data = d;
        newnode->next_ptr = NULL;

        temp->next_ptr = newnode; // now temp next points to the address of newnode
        temp = temp->next_ptr;    // temp now points to nextpointer
    }
    return (first);
}

void display(struct linkedlist *temp)
{
    int i = 1;
    do
    {
        printf("Data in node %d = %d\n", i, temp->data);
        temp = temp->next_ptr;
        i++;
    } while (temp != NULL);
}

int count(struct linkedlist *header)
{
    int n = 0;
    temp = header;
    do
    {
        n++;
        temp = temp->next_ptr;
    } while (temp != NULL);
    return (n);
}

void *insertfirst(struct linkedlist *header)
{
    temp1 = (struct linkedlist *)malloc(sizeof(struct linkedlist)); // dynamically new node is created

    printf("Enter the new data in new node = ");
    scanf("%d", &d);
    temp1->data = d;          // storing data in the new node
    temp1->next_ptr = header; // linking the new node with the header
    return (temp1);
}

void insertend(struct linkedlist *header)
{
    temp = header;
    do
    {
        temp = temp->next_ptr;
    } while (temp->next_ptr != NULL);
    newnode = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    if (temp->next_ptr == NULL)
        temp->next_ptr = newnode; // removing the null and linking the new node
    printf("Enter the last element in the new node = ");
    scanf("%d", &d);
    temp = newnode;
    newnode->data = d;
    newnode->next_ptr = NULL;
}

void *insertmiddle(struct linkedlist *header)
{
    newnode = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    printf("\nEnter the position where you want to insert new data = ");
    int pos;
    scanf("%d", &pos);
    printf("Enter the new data to be inserted = ");
    scanf("%d", &d);
    if (newnode == NULL)
    {
        printf("NOT created \n");
        exit(0);
    }
    newnode->data = d;
    temp = header;
    d = 1;
    do
    {
        if (d == (pos - 1))
        {
            temp1 = temp->next_ptr;
            d++;
            printf("d=%d\n", d);
            continue;
        }
        if (d == pos)
        {
            temp->next_ptr = newnode;
            newnode->next_ptr = temp1;
            temp = newnode->next_ptr;
        }

        temp = temp->next_ptr;
        d++;
    } while (temp->next_ptr != NULL);
}

void *deletefirst(struct linkedlist *header)
{
    return (header->next_ptr);
}

void deleteend(struct linkedlist *header)
{
    temp = header;
    while (temp->next_ptr != NULL)
    {
        temp = temp->next_ptr;
        temp1 = temp->next_ptr;
        if (temp1->next_ptr == NULL)
            break;
    }
    temp->next_ptr = NULL;
}

void deletemiddle(struct linkedlist *header)
{

    newnode = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    printf("\nEnter the position where you want to delete = ");
    int pos;
    scanf("%d", &pos);

    temp = header;
    d = 1;
    int flag = 0;
    do
    {
        if (d == (pos - 1) && flag != 1)
        {
            temp1 = temp;
            temp = temp->next_ptr;
            d++;
            flag = 1;
            continue;
        }
        if (d == (pos) && flag != 2)
        {
            newnode = temp;
            newnode = newnode->next_ptr;
            temp1->next_ptr = newnode;
            flag = 2;
            break;
        }
        temp = temp->next_ptr;
        d++;
    } while (temp->next_ptr != NULL);
}

int displayrev(struct linkedlist *header)
{
    static int count = 1;
    if (header->next_ptr == NULL)
    {
        printf("data in node %d = %d\n", count, header->data);
        return (0);
    }
    else
    {
        count++;
        displayrev(header->next_ptr);
    }
    printf("data in node %d = %d\n", --count, header->data);
}