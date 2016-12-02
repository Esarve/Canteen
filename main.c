#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Linked List to store item names and prices.

typedef struct nodeLL
{
    int index;
    char name[20];
    int price;
    struct nodeLL* next;
}Item;

// Start of stack for Items

typedef struct nodeS
{
    int size;
    int capasity;
    Item** items;
}stack;

// Functions
void additem(Item* ptr, char* name, int price);
void printitem(Item* ptr);
void printitem2(Item* s);
void order (Item* ptr);
Item* finditem(Item* ptr, int x);
void deleteitem(Item* ptr, int index);
int price(Item* ptr, int q);
// End

stack* creatstack(int capasity)
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->items=(Item**)malloc(sizeof(s->items)*capasity); // To store the pointers of Linked List
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
    s->items[s->size]= ptr; //Storing the pointer of the node
    s->size++;

}


void top(stack* s)
{
    if (s->size==0)
    {
        printf("\nStack is empty");
    }
    printitem2(s->items[s->size-1]); // Calling print function and sending the pointer stored in "items" as argument
}

void pop(stack* s)
{
    if (s->size==0)
    {
        printf("\nStack is empty");
    }
    s->size--;
}

//End of stack for items

int i,n;
i=1;
n=0;

int main()
{
    Item* start;
    start=(Item*)malloc(sizeof(Item));
    Item* temp=start;
    temp->next=NULL;
    // Adding default items
    char *input;
    input="Coke";
    additem(start,input, 20);
    input="Cake";
    additem(start,input, 10);
    //end
    printf("---------- Welcom to DIU Canteen----------\n");
    while (1)
    {
        int x,price,idx;
        char arr[50];
        printf("\n------------------------------------------\n");
        printf("\tWhat do you want to do?\n\tTo view all item, Press 1.\n\tTo Add a new item, press 2.\n\tTo delete an item press 3\n\tTo order press 4\n");
        printf("\n------------------------------------------");
        printf("\nEnter Your choice: ");
        scanf("%d",&x);
        printf("\n-----------------------------------------\n");
        switch(x)
        {
            case 1:
                printitem(start->next); //Calling the print function for Linked List
                break;
            case 2:
                getchar();
                printf("\nInput the item name: ");
                gets(arr);
                printf("\nInput the item price: ");
                scanf("%d",&price);
                additem(start,arr,price); //Calling a function to add an item with its price
                break;
            case 3:
                printf("Input the item index number: ");
                scanf("%d",&idx);
                deleteitem(start,idx); //Deleting an item.
                break;
            case 4:
                order(start); // Calling function to order items
        }
    }
}

void additem(Item* ptr, char name[], int price)
{
    // Finding the last node of the Linked List
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=(Item*)malloc(sizeof(Item));
    ptr=ptr->next;
    ptr->index=i;
    i++;
    strcpy(ptr->name,name); // Assigning the Item name passed from main function
    ptr->price=price; // Assigning the Item price passed  from main function
    ptr->next=NULL;
}

void printitem(Item* ptr) // To print items
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

void printitem2(Item* ptr) // To print items on the stack
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
    stack* s=creatstack(5); // Creating stack

    printf("\nEnter 'y' to ordern and 'n' to finish order");
    while(c!='n')
    {
        printf("\nEnter Item index number: ");
        scanf("%d",&itemnumber );
        temp=finditem(ptr,itemnumber); // fA function to find the desired item and return the node's address
        push(s,temp); // Pushing onto stack
        printf("\nEnter Item quantity: ");
        scanf("%d",&quantity);
        total=total+price(temp, quantity); // Calculating the total price
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

Item* finditem(Item* ptr, int x) // A function to find the necessery node of the Linked List
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
