
struct FIFO{
    int data;
    struct FIFO *next;
};
void push(struct FIFO **tail, int x);
void view(struct FIFO *head);
void sum15(struct FIFO *head);
struct FIFO* pop(int x, struct FIFO *head);
void find5(struct FIFO *head);