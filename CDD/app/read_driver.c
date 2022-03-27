#include "header.h"

void* read_driver(void* arg){
#ifdef DBG
    printf("BEGIN: %s %s\n",__FILE__,__func__);
#endif
   
    pthread_t thread_id;
    void* thread_result;
    File *file = (File*)arg;
    char c[100];// = (char *) calloc(100, sizeof(char));

    if(file->rdwr_flag == 1)// Write into Device
    {
        // If file is opened in write mode then do write only.
        t_ppties[opr_write].t_id = &thread_id;
        t_ppties[opr_write].t_result = thread_result;
        t_ppties[opr_write].func = func_arr[opr_write];
        t_ppties[opr_write].arg = arg;
        t_ppties[opr_write].myopttype = opr_write;

        thread_creater(&t_ppties[opr_write]);

        printf("Write only mode no read is required \n");
    }
    else if(file->rdwr_flag == 2) //Read from device.
    {
        printf("Read only mode open file and read \n");
        t_ppties[opr_open].t_id = &thread_id;
        t_ppties[opr_open].t_result = thread_result;
        t_ppties[opr_open].func = func_arr[opr_open];
        t_ppties[opr_open].arg = arg;
        t_ppties[opr_open].myopttype = opr_open;
        thread_creater(&t_ppties[opr_open]);

        int ret = read(file->fd, &c, 100); 
        if(ret == 1)
        {
            printf("Read failed\n");
        }
        else
        {
            c[ret] = '\0';
            printf("No of Bytes read = %d\n",ret);
            printf("read data = %s \n",c);
        }

    }
    else{
        printf("INVALID MODE: %s %s \n",__FILE__,__func__);
    }

#ifdef DBG
    printf("BEGIN: %s %s\n",__FILE__,__func__);
#endif
    pthread_exit((void*)arg);
}
