//
// Created by 37157 on 2021/4/28.
//

#include "Queue.h"
#include <iostream>


using namespace std;

void InitQueue(SqQueue &D) {
    D.front = 0;
    D.rear = 0;
}

bool QueueEmpty(SqQueue D) {
    return D.front == D.rear;
}

/**
 * 入队
 * @param D
 * @param x 入队元素
 * @return
 */
bool EnQueue(SqQueue &D, ElemType x) {
    if (D.rear == Maxsize) {
        cout << "Queue is Full!" << endl;//并不是真正意义上的满
        return false;
    }
    D.data[D.rear++] = x;
    return true;
}

void print_Queue(SqQueue &D) {
    if (!QueueEmpty(D)) {
        for (int i = D.front; i < D.rear; i++) {
            cout << D.data[i] << " ";
        }
        cout << endl;
    }
}

/**
 * 出队
 * @param D
 * @param x 用于接收出队元素
 * @return
 */
bool DeQueue(SqQueue &D, ElemType &x) {
    if (QueueEmpty(D)) {
        cout << "Queue is Empty!" << endl;
        return false;
    } else {
        x = D.data[D.front++];
        return true;
    }
}

bool LoopQueueEmpty(SqQueue D) {
    return D.front == D.rear % Maxsize;
}

bool EnLoopQueue(SqQueue &D, ElemType x) {
    if ((D.rear + 1) % Maxsize == D.front) {
        cout << "LoopQueue if full!" << endl;
        return false;
    } else {
        D.data[D.rear] = x;
        D.rear = (D.rear + 1) % Maxsize;
        return true;
    }
}

bool DeLoopQueue(SqQueue &D, ElemType &x) {
    if (LoopQueueEmpty(D)) {
        cout << "LoopQueue is empty!" << endl;
        return false;
    } else {
        x = D.data[D.front];
        D.front = (D.front + 1) % Maxsize;
        return true;
    }
}

void print_LoopQueue(SqQueue &D) {//这个函数可能有问题？？
    for (int i = D.front; i < D.rear; i++) {
        cout << D.data[i % Maxsize] << " ";
    }
    cout << endl;
}

int LoopQueueLength(SqQueue D) {
    return (D.rear + Maxsize - D.front) % Maxsize;
}

void InitLinkQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode *) malloc(sizeof(LinkNode));
    Q.front->next = nullptr;
}

bool LinkQueueEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

void EnLinkQueue(LinkQueue &Q, ElemType x) {
    auto *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = nullptr;
    Q.rear->next = s;
    Q.rear = s;
}

void DeLinkQueue(LinkQueue &Q, ElemType &x) {
    if (LinkQueueEmpty(Q)) {
        cout << "LinkQueue is empty!" << endl;
        return;
    }
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) {
        Q.rear = Q.front;//如果原队列中只有一个结点，删除后变空
    }
    free(p);
}

void print_LinkQueue(LinkQueue &Q) {
    LinkNode *p = Q.front->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void EnLoopQueue1(SqQueue &Q, ElemType x) {
    if (Q.front == Q.rear && Q.tag == 1) {
        cout << "LoopQueue is full!" << endl;
        return;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % Maxsize;
    Q.tag = 1;//可能队满
}

void DeLoopQueue1(SqQueue &Q, ElemType &x) {
    if (Q.front == Q.rear && Q.tag == 0) {
        cout << "LoopQueue is empty!" << endl;
        return;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % Maxsize;
    Q.tag = 1;//可能队空
}

void invert(SqQueue &Q) {
    SqStack S;
    InitStack(S);
    ElemType x;
    while (!QueueEmpty(Q)) {//出队并压栈
        DeQueue(Q, x);
        Push(S, x);
    }
    while (!StackEmpty(S)) {//出栈并入队
        Pop(S, x);
        EnQueue(Q, x);
    }
}

bool EnQueue_Stack(SqStack &S1, SqStack &S2, ElemType e) {
    if (!StackOverflow(S1)) {
        Push(S1, e);
        return true;
    }
    if (StackOverflow(S1) && !StackEmpty(S2)) {
        cout << "The Stack_Queue is full!" << endl;
        return false;
    }
    if (StackOverflow(S1) && StackEmpty(S2)) {
        ElemType x;
        while (!StackEmpty(S1)) {
            Pop(S1, x);
            Push(S2, x);
        }
    }
    Push(S1, e);
    return true;
}

bool DeQueue_Stack(SqStack &S1, SqStack &S2, ElemType &x) {
    if (!StackEmpty(S2)) {
        Pop(S2, x);
        return true;
    } else if (StackEmpty(S1)) {
        cout << "The Stack_Queue is empty!" << endl;
        return false;
    } else {
        while (!StackEmpty(S1)) {
            Pop(S1, x);
            Push(S2, x);
        }
        Pop(S2, x);
        return true;
    }
}

bool Stack_Queue_Empty(SqStack S1, SqStack S2) {
    return StackEmpty(S1) && StackEmpty(S2);
}

void test_Stack_Queue() {
    ElemType A[] = {1, 3, 5, 7, 9};
    int n = sizeof(A) / sizeof(A[0]);
    SqStack S1, S2;
    InitStack(S1);
    InitStack(S2);
    for (int i = 0; i < n; i++) {
        EnQueue_Stack(S1, S2, A[i]);
    }
    ElemType e;
    while (!Stack_Queue_Empty(S1, S2)) {
        DeQueue_Stack(S1, S2, e);
        cout << e << " ";
    }
    cout << endl;
}

void InitLoopLinkQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode *) malloc(sizeof(LinkNode));
    Q.front->next = Q.rear;//构成环
}

bool LoopLinkQueue_Empty(LinkQueue Q) {
    return Q.front == Q.rear;
}

bool LoopLinkQueue_Full(LinkQueue Q) {
    return Q.front == Q.rear->next;
}

bool En_LoopLinkQueue(LinkQueue &Q, ElemType e) {
    if (LoopLinkQueue_Full(Q)) {//队满，则在rear后面插入一个新结点s
        auto s = (LinkNode *) malloc(sizeof(LinkNode));
        s->data = e;
        s->next = Q.rear->next;
        Q.rear->next = s;
        Q.rear = s;
        return true;
    } else {
        Q.rear->next->data = e;//将入队元素保存在rear中
        Q.rear = Q.rear->next;
    }
    return true;
}

bool De_LoopLinkQueue(LinkQueue &Q, ElemType &e) {
    if (LoopLinkQueue_Empty(Q)) {//队空
        return false;
    }
    e = Q.front->next->data;
    Q.front = Q.front->next;
    return true;
}

void test_LoopLinkQueue() {
    LinkQueue a;
    InitLoopLinkQueue(a);
    ElemType A[] = {1, 2, 4, 7, 9};
    int n = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < n; i++) {
        En_LoopLinkQueue(a, A[i]);
    }
    print_LoopLinkQueue(a);
    ElemType e;
    De_LoopLinkQueue(a, e);
    cout << e << endl;
    print_LoopLinkQueue(a);
    En_LoopLinkQueue(a, 399);
    En_LoopLinkQueue(a, 3999);
    print_LoopLinkQueue(a);
}

void print_LoopLinkQueue(LinkQueue &Q) {
    LinkNode *p = Q.front->next;
    while (p != Q.rear->next) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void test() {
    cout << "Please input expression:" << endl;
    string exp;
    getline(cin, exp);
    while (!check(exp)) {
        cout << "The expression is incorrect! Please input again!" << endl;
        getline(cin, exp);
    }
    vector<string> mid_exp = format_input(exp);
    vector<string> post_exp = to_post_exp(mid_exp);
    cout << "The Postfix expression is:";
    for (auto &i:post_exp) {
        cout << i << " ";
    }
    cout << endl;
    cout << solve(post_exp) << endl;
}

bool check(string &exp) {
    my_stack<char> S = my_stack<char>();
    int i = 0;
    while (exp[i] != '\0') {
        char e, c = exp[i];
        switch (c) {
            //左括号入栈
            case '(':
                Push(S, c);
                break;
            case '[':
                Push(S, c);
                break;
            case '{':
                Push(S, c);
                break;
                //遇到右括号，检查栈顶
            case ')':
                Pop(S, e);
                if (e != '(') return false;
                break;
            case ']':
                Pop(S, e);
                if (e != '[') return false;
                break;
            case '}':
                Pop(S, e);
                if (e != '{') return false;
                break;
            default:
                break;
        }
        i++;
    }
    if (!StackEmpty(S)) {
        cout << "Brackets do not match!" << endl;
        return false;
    } else {
        cout << "Brackets do match!" << endl;
        return true;
    }
}

template<typename T>
bool Push(my_stack<T> &S, T x) {
    if (S.top == Maxsize - 1) return false;
    S.data[++S.top] = x;
    return true;
}

template<typename T>
bool Pop(my_stack<T> &S, T &x) {
    if (S.top == -1) return false;
    x = S.data[S.top--];
    return true;
}

template<typename T>
bool StackEmpty(my_stack<T> S) {
    return S.top == -1;
}

template<typename T>
bool GetTop(my_stack<T> &S, T &x) {
    if (S.top == -1) return false;
    x = S.data[S.top];
    return true;
}

int priority(char op) {
    int priority = 0;
    switch (op) {
        case '#':
            priority = 0;
            break;
        case '(':
            priority = 1;
            break;
        case ')':
            priority = 1;
            break;
        case '+':
            priority = 4;
            break;
        case '-':
            priority = 4;
            break;
        case '*':
            priority = 5;
            break;
        case '/':
            priority = 5;
            break;
        default:
            cout << "The operator is illegal!" << endl;
            priority = 0;
            break;
    }
    return priority;
}

std::vector<std::string> format_input(std::string exp) {
    vector<string> mid_exp;
    vector<string> num;
    string path(R"(\d*\.?\d+)");//匹配double类型
    regex r(path);
    for (sregex_token_iterator it(exp.begin(), exp.end(), r), end_it; it != end_it; ++it) {//匹配所有的数值
        num.push_back(it->str());
    }
    int temp = 0, j = 0, k = 0;
    for (char x : exp) {
        if (isdigit(x) || x == '.') {
            temp = 1;
            if (k == exp.length() - 1 && x == exp[exp.length() - 1]) {
                mid_exp.push_back(num[j]);
            }
            k++;
            continue;
        } else {
            k++;
            if (temp == 1) {
                mid_exp.push_back(num[j]);
                j++;
                temp = 0;
            }
            string c;
            c.push_back(x);
            mid_exp.push_back(c);
        }
    }
    return mid_exp;
}

std::vector<std::string> to_post_exp(std::vector<std::string> &mid_exp) {
    string path(R"(\d*\.?\d+)");//匹配double类型
    regex r(path);
    vector<string> post_exp;//存放后缀表达式
    my_stack<char> stack = my_stack<char>();//栈
    Push(stack, '#');
    smatch re;
    for (auto each : mid_exp) {
        if (regex_match(each, re, r)) {//是运算数
            post_exp.push_back(each);
        } else {
            char top, op = each[0];
            if (op == '(' || op == ')') {//是括号
                if (op == '(') Push(stack, op);
                else {
                    Pop(stack, top);
                    while (top != '(') {
                        string string1;
                        string1.push_back(top);
                        post_exp.push_back(string1);
                        Pop(stack, top);
                    }
                }
            } else {//是运算符
                GetTop(stack, top);
                if (priority(op) > priority(top)) {
                    Push(stack, op);
                } else {
                    while (priority(op) <= priority(top)) {
                        Pop(stack, top);
                        string string2;
                        string2.push_back(top);
                        post_exp.push_back(string2);
                        GetTop(stack, top);
                    }
                    Push(stack, op);
                }
            }
        }
    }
    char ee;
    while (!StackEmpty(stack)) {
        Pop(stack, ee);
        string string3;
        string3.push_back(ee);
        post_exp.push_back(string3);
    }
    return post_exp;
}

double solve(std::vector<std::string> &post_exp) {
    my_stack<string> num = my_stack<string>();//存放数值
    string path(R"(\d*\.?\d+)");//匹配double类型
    regex r(path);
    smatch re;
    for (int i = 0; i < post_exp.size() - 1; i++) {
        string each(post_exp[i]);
        if (regex_match(each, re, r)) {
            Push(num, each);
        } else {
            string n1, n2;
            Pop(num, n1);
            Pop(num, n2);
            double num1 = atof(n1.c_str());
            double num2 = atof(n2.c_str());
            double result = 0;
            char opp = each[0];
            switch (opp) {
                case '+': {
                    result = num2 + num1;
                    break;
                }
                case '-': {
                    result = num2 - num1;
                    break;
                }
                case '*': {
                    result = num2 * num1;
                    break;
                }
                case '/': {
                    result = num2 / num1;
                    break;
                }
                default:
                    break;
            }
            Push(num, to_string(result));
        }
    }
    string gad;
    GetTop(num, gad);
    return atof(gad.c_str());
}

char *Train_Arrange(char *train) {
    int n = strlen(train);//获取长度
    char *p = new char[n];
    char c;
    my_stack<char> stack = my_stack<char>();
    int i = 0;
    for (int j = 0; j < n; j++) {
        if (train[j] == 'H') {
            Push(stack, train[j]);
        } else {
            p[i++] = train[j];
        }
    }
    while (!StackEmpty(stack)) {
        Pop(stack, c);
        p[i++] = c;
    }
    return p;
}

double P(int n, double x) {
    my_stack<double> stack = my_stack<double>();
    double n0 = 1, n1 = 2 * x;
    if (n == 0) return n0;
    if (n == 1) return n1;
    Push(stack, n0);
    Push(stack, n1);
    int temp = 2;
    while (temp <= n) {
        double n_1, n_2;
        Pop(stack, n_1);
        Pop(stack, n_2);
        Push(stack, n_1);
        double pn = 2 * x * n_1 - 2 * (temp - 1) * n_2;//进行运算
        Push(stack, pn);
        temp++;
    }
    GetTop(stack, n0);
    return n0;
}
