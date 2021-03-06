#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node* next;
    int   data;
};

struct Node* g_head = NULL;

int add_head(int newdata)
{
    struct Node* p = malloc(sizeof(struct Node));
    if (!p)
    {
        return -1;
    }
    p->data = newdata;
    p->next = g_head;
    g_head = p;
    return 0;
}

int add_tail(int newdata)
{
    struct Node* p = malloc(sizeof(struct Node));
    if (!p)
    {
        return -1;
    }

    p->data = newdata;
    p->next = NULL;
    if (g_head == NULL)
    {
        g_head = p;
        return 1;
    }
    
    struct Node* m = g_head;
    while(m->next != NULL)
    {
        m = m->next;
    }
    m->next = p;
    return 0;
}

int delete_data(int data)
{
    struct Node* p = g_head;
    struct Node* p1 = NULL;
    if (p == NULL)
    {
        return -1;
    }
    
    if (p->data == data)
    {
        g_head = p->next;
        free(p);
        return 0;
    }
    
    while(p->next != NULL)
    {
        if (p->data == data)
        {
            p1->next = p->next;
            free(p);
            return 0;
        }
        p1 = p;
        p = p->next;
    }
    return 1;
}

int modify_data(int old_data, int new_data)
{
    struct Node* p = g_head;
    while(p != NULL)
    {
        if (p->data == old_data)
        {
            p->data = new_data;
            return 0;
        }
        p = p->next;
    }
    return 1;
}

void print_data(void)
{
    struct Node* p = g_head;
    
    while (p != NULL)
    {
        printf("%p Node: %d\r\n", p, p->data);
        p = p->next;
    }
}

int main(char argc, char* argv[])
{
    add_head(99);
    add_tail(101);

    print_data();

    add_head(98);
    print_data();
    delete_data(99);
    print_data();
    return 0;
}