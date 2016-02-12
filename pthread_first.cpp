/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   pthread_first.cpp
 * Author: golo
 *
 * Created on 10 февраля 2016 г., 23:44
 */

/*
 Напишите многопоточную программу (POSIX Threads).
Должен быть как минимум:
    Один поток, ожидающий pthread_join.
Текст программы должен находиться в файле /home/box/main.cpp
PID запущенного процесса должен быть сохранен в файле /home/box/main.pid
 */
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <pthread.h>

using namespace std;

void *helloW(void *args){

    char **c = (char **) args;

    cout << "I'm alive" <<endl;
    cout << "My 1 arg:" << c[0] << endl;
    cout << "My 2 arg:" << c[1] << endl;
    return 0;
}

/*
 *
 */
int main(int argc, char** argv) {

    pthread_t thread;
    int pth;
    pid_t pid = getpid();
    char fname[] = "main.pid";
    char **args;

    args[0] = (char *) "Test thread";
    args[1] = (char *) "Test thread2";

    FILE *f = fopen(fname, "w");
    fprintf(f, "%u", pid);
    cout << pid << endl;
    fclose(f);

    pth = pthread_create(&thread, NULL, helloW, args);
    pthread_join(thread, 0);

    cout<<pth<<endl;

    return 0;
}

