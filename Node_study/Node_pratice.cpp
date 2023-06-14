#include<stdio.h>
#include<stdlib.h>
    typedef struct Node
    {
        int age;
        char name[10],id[10],sex[10];
        /* data */
        struct Node *next=NULL;
        /*point*/
    }listnode, *linklist;
linklist listnode_create (){
    linklist x;
    //访问结构体的几种方法
    // (*指针变量名).成员名
    // 指针变量名->成员名
    x->next=NULL;
    return x;
}
bool is_emptylist (linklist x){
    if(x->next==NULL)
    return true;
    return false;
}
int list_lenth (linklist head){
    sum=0;
    while(head->next){
        head = head->next;
        sum++;
    }
    return sum;
}
void list_delete (linklist *x){
    (*x)->next=(*x)->next->next;
}//好像有点问题 这个删除的是x的下一个链节  
int main()
{
    //链表功能函数的实现
    linklist listnode_create ();
    bool is_emptylist (linklist x);
    int list_lenth (linklist head);
    void list_delete (linklist *x);
}