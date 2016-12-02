#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodeLL
{
    int index;
    char name[20];
    int price;
    struct nodeLL* next;
}Item;

// Start of stack

typedef struct nodeS
{
    int size;
    int capasity;
    Item** items;
}stack;

void additem(Item* ptr, char* name, int price);
void printitem(Item* ptr);
void printitem2(Item* s);
void order (Item* ptr);
Item* finditem(Item* ptr, int x);
void deleteitem(Item* ptr, int index);
int price(Item* ptr, int q);

stack* creatstack(int capasity)
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->items=(Item**)malloc(sizeof(s->items)*capasity);
    s->size=0;
    s->capasity=capasity;
    return s;
}

void push(stack* s, Item* ptr)
{
    if (s->size==s->capasity)
    {
        printf("\nStack is Full");
    }
    s->items[s->size]= ptr;
    s->size++;

}


void top(stack* s)
{
    if (s->size==0)
    {
        printf("\nStack is empty");
    }
    printitem2(s->items[s->size-1]);
}

void pop(stack* s)
{
    if (s->size==0)
    {
        printf("\nStack is empty");
    }
    s->size--;
}

//End of stack

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
    printf("What do you want to do?\nTo view all item, Press 1.\nTo Add a new item, press 2.\nTo delete an item press 3\nTo order press 4");
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
                printf("Input the item index number: ");
                scanf("%d",&idx);
                deleteitem(start,idx);
                break;
            case 4:
                order(start);


        }
    }
}

void additem(Item* ptr, char name[], int price)
{
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=(Item*)malloc(sizeof(Item));
    ptr=ptr->next;
    ptr->index=i;
    i++;
    strcpy(ptr->name,name);
    ptr->price=price;
    ptr->next=NULL;
}

void printitem(Item* ptr)
{
    if (ptr==NULL)
    {
        //printf("\nNothing!");
        return;
    }
    printf("\n\n");
    printf("Item number: %d\n",ptr->index);
    printf("Item name: ");
    puts(ptr->name);
    printf("Item Price: %d\n",ptr->price);
    printitem(ptr->next);
}

void printitem2(Item* ptr)
{
    if (ptr==NULL)
    {
        printf("\nNothing!");
        return;
    }
    printf("\n\n");
    printf("Item number: %d\n",ptr->index);
    printf("Item name: ");
    puts(ptr->name);
}

void order (Item* ptr)
{
    char c;
    int itemnumber, quantity,total;
    total=0;
    Item* temp;
    stack* s=creatstack(5);

    printf("\nEnter 'y' to ordern and 'n' to finish order");
    while(c!='n')
    {
        printf("\nEnter Item index number: ");
        scanf("%d",&itemnumber );
        temp=finditem(ptr,itemnumber);
        push(s,temp);
        printf("\nEnter Item quantity: ");
        scanf("%d",&quantity);
        total=total+price(temp, quantity);
        getchar();
        printf("\nEnter your decission: ");
        scanf("%c",&c );
    }
    while (s->size!=0)
    {
        top(s);
        pop(s);
    }
    printf("\nTotal Price: %d",total);
}

Item* finditem(Item* ptr, int x)
{
    while(ptr!=NULL)
    {
        if(ptr->index==x)
        {
            return ptr;
        }
        else
        {
            ptr=ptr->next;
        }
    }
    printf("\nNot foud!");
}
void deleteitem(Item* ptr, int index)
{
    Item* temp;
    while (ptr->next!=NULL && (ptr->next)->index!=index)
    {
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=temp->next;
    free(temp);

}

int price(Item* ptr, int q)
{
    int cprice=0;
    cprice=ptr->price*q;
    return cprice;
}
