#include"Queue.h"
#include"Mystack.h"

MyStack* myStackCreate() {
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    Queue q1, q2;
    st->q1 = &q1;
    st->q2 = &q2;
    QueueInit(st->q1);//QueueInit(&(st->q1));
    QueueInit(st->q2);
    return st;
}

void myStackPush(MyStack* obj, int x) {
    if (!QueueEmpty(obj->q1)) {
        QueuePush(obj->q1, x);
    }
    else {
        QueuePush(obj->q2, x);
    }
}

int myStackPop(MyStack* obj) {
    int top = 0;
    if (!QueueEmpty(obj->q1)) {
        while (QueueSize(obj->q1) > 1) {
            QueuePush(obj->q2, QueueFront(obj->q1));
            QueuePop(obj->q1);
        }
        top = QueueFront(obj->q1);
        QueuePop(obj->q1);
    }
    else {
        while (QueueSize(obj->q2) > 1) {
            QueuePush(obj->q1, QueueFront(obj->q2));
            QueuePop(obj->q2);
        }
        top = QueueFront(obj->q2);
        QueuePop(obj->q2);
    }
    return top;
}

int myStackTop(MyStack* obj) {
    if (!QueueEmpty(obj->q1)) {
        return QueueBack(obj->q1);
    }
    else {
        return QueueBack(obj->q2);
    }
}

bool myStackEmpty(MyStack* obj) {
    // if( QueueEmpty(obj->q1) && QueueEmpty(obj->q2)){
    //     return true;
    // }else{
    //     return false;
    // }
    return QueueEmpty(obj->q1) && QueueEmpty(obj->q2);
}

void myStackFree(MyStack* obj) {
    QueueDestroy(obj->q1);
    QueueDestroy(obj->q2);
    free(obj);
}