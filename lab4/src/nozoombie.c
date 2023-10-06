#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
pid_t pid1 = getpid();
    pid_t ppid = getppid();	

    printf("PID текущего процесса: %d\n", pid1);
    printf("PID родительского процесса: %d\n", ppid);


    if (pid == 0) {
        // Дочерний процесс
        printf("Дочерний процесс завершен\n");
        exit(0);
    } else if (pid > 0) {
        // Родительский процесс
        printf("Родительский процесс ожидает завершения дочернего процесса\n");
        wait(NULL);
        printf("Родительский процесс завершен\n");
    } else {
        // Ошибка при создании процесса
        printf("Ошибка при создании процесса\n");
        exit(1);
    }

    return 0;
}
