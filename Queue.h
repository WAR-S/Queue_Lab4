#ifndef QUEUE_H
#define QUEUE_H
#include <QDebug>
template <typename T>
class Queue
{
    struct SItem
    {
        T x;
        SItem* next;
    };

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

    void push(T count)
    {
        SItem *temp = new  SItem;
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
        SItem* temp = nullptr;
        Head = temp;
        getEl=0;

    }

        T isEmpty(T flag);
        T size()
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
