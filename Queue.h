#ifndef QUEUE_H
#define QUEUE_H
#include <QDebug>
struct SItem
{
    int x;
    SItem* next;
};

class Queue
{
public:
    Queue() {}

    ~Queue()
    {
        SItem *temp = Head;
         getEl=0;
        while (temp!=nullptr)
        {
            temp =Head->next;
            delete Head;
            Head = temp;
        }

    }

    void push(int count)
    {
        SItem *temp = new SItem;
        temp->x=count;
        temp->next = nullptr;

        if(Head!=nullptr)
        {
            Tail->next = temp;
            Tail = temp;
        }
        else
            Head = Tail =temp;
        getEl++;
    }
    void pop()
    {
        if (Head!=nullptr)
        {
            SItem *temp = Head;
            qDebug()<<"Number "<<Head->x<<" delete"<<'\n';
            Head = Head->next;
            delete temp;
        }
        getEl--;
    }
    void clear()
    {
        qDebug()<<"Список очищен !";
    }
    bool isEmpty(bool flag);
    int size()
    {
        return getEl;
    }
    void Print()
    {
        SItem *temp = Head;
        while (temp!=nullptr)
        {
            qDebug()<<temp->x<<" ";
            temp=temp->next;
        }
        qDebug()<<'\n';
    }
private:
    SItem *Head, *Tail = nullptr;
    int *P;
    int getEl=0;

};

#endif // QUEUE_H
