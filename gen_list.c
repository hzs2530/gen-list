/*
  * A general list
  * 2018-10-08
  * zhongsheng
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gen_list.h"

int add_list_head(GenList *list, void *data)
{
    NodeList *head,*p;
    head = list->head;
    p = head->next;
    
    NodeList *new = (NodeList*)malloc(sizeof(NodeList));
    if(new)
    {
        new->data = malloc(list->data_len);
        if(!new->data)
            return LIST_STA_MEM_ERR;

        memcpy(new->data,data,list->data_len);
        head->next = new;
        new->prev = head;
        new->next = p;
        p->prev = new;
    }
    return LIST_STA_OK;
}

int add_list_tail(GenList *list, void *data)
{
    NodeList *head,*p;
    head = list->head;
    p = head->prev;

    NodeList *new = (NodeList*)malloc(sizeof(NodeList));
    if(new)
    {
        new->data = malloc(list->data_len);
        if(!new->data)
            return LIST_STA_MEM_ERR;
        memcpy(new->data,data,list->data_len);
        p->next = new;
        new->prev = p;
        new->next = head;
        head->prev = new;
    }
    return LIST_STA_OK;
}


int del_list_head(GenList *list)
{
    NodeList *head,*p;
    head = list->head;
    p = head->next;

    if(p == head)
        return LIST_STA_LIST_NULL;

    p->prev->next = p->next;
    p->next->prev = p->prev;
    p->prev = NULL;
    p->next = NULL;
    free(p);
    p = NULL;

    return LIST_STA_OK;
}

int del_list_tail(GenList *list)
{
    NodeList *head,*p;
    head = list->head;
    p = head->prev;

    if(p == head)
        return LIST_STA_LIST_NULL;

    p->prev->next = p->next;
    p->next->prev = p->prev;
    p->prev = NULL;
    p->next = NULL;
    free(p);
    p = NULL;

    return LIST_STA_OK;
}


int del_list_data(GenList *list, void *data)
{
    NodeList *head,*p;
    head = list->head;
    p = head->next;
    int match = 0;
    if(NULL == list->matchNode)
    {
        printf("function matchNode is null.\n");
        return LIST_STA_CALLBACK_NULL;
    }

    while(p != head)
    {
        if(list->matchNode(p->data,data))
        {
            match = 1;
            break;
        }
        p = p->next;
    }
    if(match)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->prev = NULL;
        p->next = NULL;
        free(p);
        p = NULL;
    }
    else
    {
        printf("data not found.\n");
        return LIST_STA_MATCH_ERR;
    }
    return LIST_STA_OK;
}

void* get_list_data_head(GenList list)
{
    return (list.head->next->data);
}

void* get_list_data_tail(GenList list)
{
    return (list.head->prev->data);
}

int print_list(GenList *list)
{
    NodeList *head,*p;
    head = list->head;
    p = head;
    if(NULL == list->printNode)
    {
        printf("function printNode is null.\n");
        return LIST_STA_CALLBACK_NULL;
    }
    while(p->next != head)
    {
        list->printNode(p->next->data);
        p = p->next;
    }
    return LIST_STA_OK;
}
/*
int show_from_tail(GenList *list)
{
    NodeList *head,*p;
    head = list->head;
    p = head;
    if(NULL == list->printNode)
    {
        printf("function printNode is null.\n");
        return LIST_STA_CALLBACK_NULL;
    }
    while(p->prev != head)
    {
        list->printNode(p->prev);
        p = p->prev;
    }
    return LIST_STA_OK;
}
*/

int gen_list_init(GenList *list, int dataLen)
{

    NodeList *head = (NodeList*)malloc(sizeof(NodeList));
    if(!head)
        return LIST_STA_MEM_ERR;

    list->head = head;
    list->head->prev = list->head->next = head;
    list->data_len = dataLen;
    list->matchNode = NULL;
    list->printNode = NULL;

    return LIST_STA_OK;
}


