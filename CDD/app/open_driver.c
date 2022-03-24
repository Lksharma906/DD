#include "header.h"

void* open_driver(void* arg){
#ifdef DBG
    printf("BEGIN: %s %s\n",__FILE__,__func__);
#endif
   
    File *file = (File*)arg;
    file->fd = open(file->file_name,O_RDWR|O_CREAT,0666);
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
