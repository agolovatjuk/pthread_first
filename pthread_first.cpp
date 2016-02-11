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
    cout << "I'm alive" <<endl;
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

    FILE *f = fopen(fname, "w");
    fprintf(f, "%u", pid);
    cout << pid << endl;        
    fclose(f);
    
    pth = pthread_create(&thread, NULL, helloW, NULL);
    pthread_join(thread, 0);
    
    cout<<pth<<endl;
    
    return 0;
}

