#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int index;
    char* name;
    int price;
    struct node* next;
}Item;

void additem(Item* ptr, char* name, int price);
void printitem(Item* ptr);
int i,n;
i=1;
n=0;

int main()
{
    Item* start;
    start=(Item*)malloc(sizeof(Item));
    Item* temp=start;
    temp->next=NULL;
    char *input;
    input="Coke";
    additem(start,input, 20);
    input="Cake";
    additem(start,input, 10);
    printf("What do you want to do?\nTo view all item, Press 1.\nTo Add a new item, press 2.\nTo delete an item press 3\n");
    while (1)
    {
        int x,price,idx;
        char arr[50];
        printf("\nEnter Your choice: ");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
                printitem(start->next);
                break;
            case 2:
                getchar();
                printf("Input the item name: ");
                gets(arr);
                printf("Input the item price: ");
                scanf("%d",&price);
                additem(start,arr,price);
                break;
            case 3:
                while (1)
                {
                    printf("Input the item index name: ");
                    scanf("%d",&idx);
                    finditem(start->next);
                }
                break;
        }
    }
}

void additem(Item* ptr, char* name, int price)
{
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=(Item*)malloc(sizeof(Item));
    ptr=ptr->next;
    ptr->index=i;
    i++;
    ptr->name= name;
    ptr->price=price;
    ptr->next=NULL;
}

void printitem(Item* ptr)
{
    if (ptr==NULL)
    {
        return;
    }
    printf("\n\n");
    printf("Item number: %d\n",ptr->index);
    printf("Item name: ");
    puts(ptr->name);
    printf("Item Price: %d\n",ptr->price);
    printitem(ptr->next);
}

void finditem(Item* ptr, int x)
{
    while(ptr!=NULL)
    {
        if(ptr->index==x)
        {
            printf("\nItem selected! Item name: ");
            puts(ptr->name);
            printf("\nItem Price: %d",ptr->price);
            n=n+(ptr->price);
            printf("\nTotal Price: %d ",n);
        }
    }
}
