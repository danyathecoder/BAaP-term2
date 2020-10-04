struct QUEUE{
    int data;
    struct QUEUE *next;
};

struct DEQUE{
    int data;
    struct DEQUE *next;
    struct DEQUE *prev;
};

struct QUEUE* push(struct QUEUE *tail, int x);
struct QUEUE* pop(struct QUEUE *head);
void view(struct QUEUE *head);
void push_d(struct DEQUE **head, struct DEQUE **tail, int x);
void pop_d(struct DEQUE **head, struct DEQUE **tail);
void view_d(struct DEQUE *tail);