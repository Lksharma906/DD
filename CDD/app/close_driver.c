#include "header.h"

void* close_driver(void* arg){
#ifdef DBG
    printf("BEGIN: %s %s\n",__FILE__,__func__);
#endif
   
    pthread_t thread_id;
    void* thread_result;
    File *file = (File*)arg;

    t_ppties[opr_read].t_id = &thread_id;
    t_ppties[opr_read].t_result = thread_result;
    t_ppties[opr_read].func = func_arr[opr_read];
    t_ppties[opr_read].arg = arg;

    t_ppties[opr_read].myopttype = opr_read;
    thread_creater(&t_ppties[opr_read]);

    close(file->fd);
#ifdef DBG
    printf("BEGIN: %s %s\n",__FILE__,__func__);
#endif
    pthread_exit((void*)arg);
}
