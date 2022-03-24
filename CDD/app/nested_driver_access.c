#include"header.h"

char opr_name[opr_max][STR_SIZE] = {
    "close",
    "read",
    "write",
    "open"
};

void print_oprname(int opr_no){
    printf("%s\n",opr_name[opr_no]);
}

void thread_creater(void *thread_properties)
{
    
    T_PPTIES *t_pptr = (T_PPTIES*)thread_properties;
#ifdef DBG
    printf("BEGIN:%s %s \t",__FILE__,__func__);
    print_oprname(t_pptr->myopttype);
#endif
    
    int ret = 0;
    ret = pthread_create(t_pptr->t_id, NULL, t_pptr->func, t_pptr->arg);
    if(ret == -1)
    {
        perror("pthread_create:");
        exit(EXIT_FAILURE);
    }

    ret = pthread_join(*(t_pptr->t_id),t_pptr->t_result);
    if(ret == -1)
    {
        perror("pthread_join:");
        exit(EXIT_FAILURE);
    }
#ifdef DBG
    printf("END:%s %s \t",__FILE__,__func__);
    print_oprname(t_pptr->myopttype);
#endif
}


void* nested_driver_access(void* arg)
{
    #ifdef DBG
    printf("BEGIN: %s %s\n",__FILE__,__func__);
    #endif 
    File *file = (FILE*)arg;
    printf("file name received = %s\n",file->file_name);
    int ret = 0;
    
    pthread_t thread_id;
    void* thread_result;
    
    t_ppties[opr_close].t_id = &thread_id;
    t_ppties[opr_close].t_result = thread_result;
    t_ppties[opr_close].func = func_arr[opr_close];
    t_ppties[opr_close].arg = (void*)file;
    t_ppties[opr_close].myopttype = opr_close;
    thread_creater(&t_ppties[opr_close]);

    #ifdef DBG
    printf("END: %s %s\n",__FILE__,__func__);
    #endif 
    
    return arg;
}
