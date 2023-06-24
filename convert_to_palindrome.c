#include<stdio.h>
#include<stdlib.h>
#define size 50
typedef struct node
{
    struct node* next;
    char letter;
}node;

node* insert_at_beginning(char, node*);
void insert_at_end(char, node*);
node* delete_at_beginning(node*);
node* delete_letter(char, node*);
int is_empty(node*);
int present(char, node*);
void print_list(node*);
int list_size(node*);

int main()
{
    char x = 'a';
    int i = 0, u = 0, r = 0;
    char* name = (char*) malloc(size*sizeof(char));
    node* unrepeated = NULL, *repeated = NULL, *palindrome = NULL;
    printf("Enter your name: ");
    scanf("%s",name);

    //First segregate repeated and unrepeated letters:
    x = name[i];
    while (x != '\0')
    {
        if(present(x,repeated))
        repeated = insert_at_beginning(x,repeated);
        else if(present(x,unrepeated))//O(n)
        {
            repeated = insert_at_beginning(x,repeated);
            repeated = insert_at_beginning(x,repeated);
            unrepeated = delete_letter(x,unrepeated);
        }
        else
        {
            unrepeated = insert_at_beginning(x,unrepeated);
        }
        i++;
        x = name[i];
    } 
    u = list_size(unrepeated);
    r = list_size(repeated);
    printf("repeated=");
    print_list(repeated);
    printf("unrepeated=");
    print_list(unrepeated);
    printf("No. of repeated: %d\nNo. of unrepeated: %d\n",r,u);
    printf("name_length =i=%d\n",i);
    x = unrepeated->letter;
    unrepeated = delete_at_beginning(unrepeated);
    palindrome = insert_at_beginning(x,palindrome);
    while(unrepeated != NULL)
    {
        x = unrepeated->letter;
        unrepeated = delete_at_beginning(unrepeated);
        palindrome = insert_at_beginning(x,palindrome);
        insert_at_end(x,palindrome);
    }
    while(repeated != NULL)
    {
        x = repeated->letter;
        repeated = delete_at_beginning(repeated);
        repeated = delete_letter(x,repeated);
        palindrome = insert_at_beginning(x,palindrome);
        insert_at_end(x,palindrome);
    }
    printf("The name after converting it to the palindromic form: ");
    print_list(palindrome);
    printf("The number of letters in the palindrome: %d\n",list_size(palindrome));
    return 0;
}

node* insert_at_beginning(char x, node* head)
{
    if(head == NULL)
    {
        head = (node*) malloc(sizeof(node));
        head->letter = x;
        head->next = NULL;
        return head;
    }
    node* temp = head;
    head = (node*) malloc(sizeof(node));
    head->letter = x;
    head->next = temp;
    return head;
}
node* delete_at_beginning(node* head)
{
    if(head == NULL)
    return head;
    node* temp = head;
    head = head->next;
    free(temp);
    return head;
}
node* delete_letter(char x, node* head)
{
    node* temp1 = head, *temp2 = NULL;
    if(head == NULL)
    return head;
    if(head->letter == x)
    {
        head = delete_at_beginning(head);
        return head;
    }
    if(temp1->next == NULL)
        return head;
    while(temp1->next->letter != x)
    {
        temp1 = temp1->next;
        if(temp1->next == NULL)
            return head;
    }
    temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    return head;
}
int is_empty(node* head)
{
    if(head == NULL)
    return 1;
    else return 0;
}
int present(char x, node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        if(temp->letter == x)
        return 1;
        temp = temp->next;
    }
    return 0;
}
void print_list(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        printf("%c",temp->letter);
        temp = temp->next;
    }
    printf("\n");
    return;
}
void insert_at_end(char x, node* head)
{
    node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = (node*) malloc(sizeof(node));
    temp->next->letter = x;
    temp->next->next = NULL;
    return;
}
int list_size(node* head)
{
    int count = 0;
    while(head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}
   