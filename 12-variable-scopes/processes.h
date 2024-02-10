#ifndef PROCESSES_H
#define PROCESSES_H

struct Process{
    long ID;
    char name[30];
};

extern struct Process processes[5];

extern int processescount;

int nextprocessid();

struct Process createnewprocess();

struct Process stopprocess();

#endif