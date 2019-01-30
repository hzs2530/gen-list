#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gen_list.h"

struct Type
{
    int id;
    char data[17];
    int num;
};

void show_node(void *node_data)
{
    struct Type *data = (struct Type*)(node_data);
    printf("id:%d,num:%d,data:%s\n",data->id,data->num,data->data);
}

int match_by_id(void *node_data, void *user_data)
{
    int id = *(int*)user_data;
    struct Type *node_data_t = (struct Type*)(node_data);
    if(id == node_data_t->id)
        return 1;
    return 0;
}

/***********************************/


int main()
{
    int ret;
    GenList list;
    ret = gen_list_init(&list,sizeof(struct Type));
    list.printNode = show_node;
    list.matchNode = match_by_id;

/*
    float fd = 1.0;
    ret = add_list_tail(&list, &fd);
    fd = 2.0;
    ret = add_list_tail(&list, &fd);
    fd = 3.0;
    ret = add_list_tail(&list, &fd);
    fd = 4.0;
    ret = add_list_tail(&list, &fd);
    ret = print_list(&list);
 */  
/*
    struct Type d = {12,"hello",43};
    ret = add_list_head(&list, &d);
    printf("ret = %d\n",ret);

    ret = print_list(&list);
    printf("ret = %d\n",ret);

    d.id = 12;
    ret = del_list_data(&list,&(d.id));
    printf("ret = %d\n",ret);

    ret = del_list_head(&list);
    printf("ret = %d\n",ret);
    ret = del_list_tail(&list);
    printf("ret = %d\n",ret);
    ret = print_list(&list);
    printf("ret = %d\n",ret);
    */
    printf("Add nodes to head\n");
    struct Type d = {12,"hello",1};
    ret = add_list_head(&list, &d);
    d.id = 13;strcpy(d.data,"I");d.num=2;
    ret = add_list_head(&list, &d);
    d.id = 14;strcpy(d.data,"AM");d.num=3;
    ret = add_list_head(&list, &d);
    d.id = 15;strcpy(d.data,"H");d.num=4;
    ret = add_list_head(&list, &d);
    d.id = 13;strcpy(d.data,"ZS");d.num=5;
    ret = add_list_head(&list, &d);
    print_list(&list);


    printf("Add nodes to tail\n");
    d.id = 90;strcpy(d.data,"WHO");d.num=6;
    ret = add_list_tail(&list, &d);
    d.id = 80;strcpy(d.data,"ARE");d.num=7;
    ret = add_list_tail(&list, &d);
    d.id = 70;strcpy(d.data,"YOU");d.num=8;
    ret = add_list_tail(&list, &d);
    d.id = 60;strcpy(d.data,"?");d.num=9;
    ret = add_list_tail(&list, &d);
    ret = print_list(&list);

    printf("Delete nodes from head.\n");
    ret = del_list_head(&list);
    ret = print_list(&list);
    printf("Delete nodes from tail.\n");
    ret = del_list_tail(&list);
    ret = print_list(&list);

    d.id = 14;
    printf("Delete node by id\n");
    ret = del_list_data(&list,&(d.id));
    ret = print_list(&list);
    
    printf("Get a node from List head\n");
    d = *(struct Type*)get_list_data_head(list);
    printf("***id:%d,num:%d,data:%s\n",d.id,d.num,d.data);

    printf("Get a node from List tail\n");
    d = *(struct Type*)get_list_data_tail(list);
    printf("***id:%d,num:%d,data:%s\n",d.id,d.num,d.data);
    return 0;
}
