struct task{
    int name;
    int complexity;
    int priority;
};
struct FILO{
    struct task data;
    struct FILO *next;
};
struct FIFO{
    struct task data;
    struct FIFO *next;
};
struct FIFO *push_q(struct FIFO *tail, struct task x);
struct FILO *push_s(struct FILO *head, struct task x);
void view(struct FIFO *head);
void view_s(struct FILO *head);
struct FIFO* pop_q(struct FIFO *head);
struct task generator();
