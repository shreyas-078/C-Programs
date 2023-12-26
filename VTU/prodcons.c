#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0;

int wait_func(int);
int signal_func(int);
void producer();
void consumer();

int main() {
    int n;
    printf("\n1.Producer\n2.Consumer\n3.Exit");
    while (1) {
        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n) {
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("Buffer is full!!");
                break;
            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("Buffer is empty!!");
                break;
            default:
                exit(0);
        }
    }
    return 0;
}

int wait_func(int s) {
    return (--s);
}

int signal_func(int s) {
    return (++s);
}

void producer() {
    mutex = wait_func(mutex);
    empty = wait_func(empty);
    x++;
    printf("\nProducer produces the item %d", x);
    full = signal_func(full);
    mutex = signal_func(mutex);
}

void consumer() {
    mutex = wait_func(mutex);
    full = wait_func(full);
    printf("\nConsumer consumes item %d", x--);
    empty = signal_func(empty);
    mutex = signal_func(mutex);
}
