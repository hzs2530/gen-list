/*
  * A general list
  * 2018-10-08
  * zhongsheng
 */
#ifndef _GEN_LIST_H
#define _GEN_LIST_H

#define LIST_STA_OK              1
#define LIST_STA_MEM_ERR        -1
#define LIST_STA_LIST_NULL      -2
#define LIST_STA_MATCH_ERR      -3
#define LIST_STA_CALLBACK_NULL  -4


typedef struct node_list 
{
    void *data;
    struct node_list *prev;
    struct node_list *next;
}NodeList;

typedef struct 
{
    NodeList *head;
    int data_len;
    int (*matchNode)(void *node_data, void *user_data);
    void (*printNode)(void *data);
}GenList;

int add_list_head(GenList *list, void *data);

int add_list_tail(GenList *list, void *data);

int del_list_head(GenList *list);

int del_list_tail(GenList *list);

int del_list_data(GenList *list, void *data);

void del_list_all(GenList *list);

void* get_list_data_head(GenList list);

void* get_list_data_tail(GenList list);

int print_list(GenList *list);

int gen_list_init(GenList *list, int dataLen);

#endif
