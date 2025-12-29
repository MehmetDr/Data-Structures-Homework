#include <stdio.h>

void hanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        printf("Disk 1: %c -> %c\n", source, target);
        return;
    }
    hanoi(n - 1, source, target, auxiliary);
    printf("Disk %d: %c -> %c\n", n, source, target);
    hanoi(n - 1, auxiliary, source, target);
}

int main() {
    int n = 3; // Disk sayýsý
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
