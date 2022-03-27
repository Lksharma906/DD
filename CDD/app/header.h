#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<pthread.h>


#ifndef DBG
#define DBG
#endif

#define STR_SIZE 10
#define FILE_NAME_SIZE 64
enum OPERATIONS{
   opr_close = 0,
   opr_read,
   opr_write,
   opr_open,
   opr_max
};

extern char opr_name[opr_max][STR_SIZE]; 
extern unsigned int operator_pos;

void* open_driver(void* arg);
void* write_driver(void* arg);
void* read_driver(void* arg);
void* close_driver(void* arg);


typedef void* (*t_func)(void*);

typedef struct THREAD_PROPERTIES
{
    pthread_t *t_id;
    void* t_result;
    t_func func;
    void* arg;
    int myopttype;
}T_PPTIES;

extern T_PPTIES t_ppties[4];

typedef struct FILE 
{
    char file_name[FILE_NAME_SIZE];
    int fd;
    int rdwr_flag;
}File;

extern File *file;

extern t_func func_arr[4];// = {close_driver,read_driver,write_driver,open_driver};
void thread_creater(void *thread_properties);
void* nested_driver_access(void* arg);
