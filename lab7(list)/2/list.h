struct FIFO{
    int data;
    struct FIFO *next;
    struct FIFO *prev;
};

void push(struct FIFO **head, struct FIFO **tail, int x);
void view(struct FIFO *head);
void shell(int *head, int n);