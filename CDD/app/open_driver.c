#include "header.h"

void* open_driver(void* arg){
#ifdef DBG
    printf("BEGIN: %s %s\n",__FILE__,__func__);
#endif
   
    File *file = (File*)arg;
    if(file->rdwr_flag == 1)// Write only Mode
        file->fd = open(file->file_name,O_WRONLY);
    if(file->rdwr_flag == 2)// Read only Mode
        file->fd = open(file->file_name,O_RDONLY);
    
    if(file->fd == -1)
    {
        perror("Open File Failed:");
        exit(EXIT_FAILURE);
    }

#ifdef DBG
    printf("BEGIN: %s %s\n",__FILE__,__func__);
#endif
    pthread_exit((void*)arg);
}
