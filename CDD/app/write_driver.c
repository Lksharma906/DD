#include "header.h"

void* write_driver(void* arg){
#ifdef DBG
    printf("BEGIN: %s %s\n",__FILE__,__func__);
#endif

    pthread_t thread_id;
    void* thread_result;
    File *file = (File*)arg;
    
    t_ppties[opr_open].t_id = &thread_id;
    t_ppties[opr_open].t_result = thread_result;
    t_ppties[opr_open].func = func_arr[opr_open];
    t_ppties[opr_open].arg = arg;
    t_ppties[opr_open].myopttype = opr_open;
    thread_creater(&t_ppties[opr_open]);

    int ret = write(file->fd,"Hello Driver\n",strlen("Hello Driver\n"));
    if(ret == -1)
    {
        printf("Write Failed \n");
    }
    else
        printf("Wrote some bytes\n");
#ifdef DBG
    printf("BEGIN: %s %s\n",__FILE__,__func__);
#endif
    pthread_exit((void*)arg); 
}
