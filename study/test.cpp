#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;

int main() {
    int pid = fork();
    int status; // 자식 프로세스의 종료 상태를 저장하기 위한 변수

    if (pid > 0) {
        cout << "parent: child = " << pid << endl;
        pid = wait(&status); // 자식 프로세스의 종료를 기다리고 종료 상태를 수집합니다.
        cout << "child is done" << endl;
    } else if (pid == 0) {
        cout << "child is exiting." << endl;
        exit(status); // 자식 프로세스는 여기서 종료 상태를 반환합니다.
    } else {
        cout << "fork error..." << endl;
    }

    return 0;
}

