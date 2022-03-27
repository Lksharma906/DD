#include"header.h"
unsigned int operator_pos;
File *file;
t_func func_arr[opr_max] = {
                    &close_driver,   //0     //OPR_CLOSE
                    &read_driver,    //1     //OPR_READ
                    &write_driver,   //2     //OPR_WRITE
                    &open_driver     //2     //OPR_OPEN
};

T_PPTIES t_ppties[opr_max];

int main(int argc, char* argv[])
{
    if(argc<2 || argc > 2)
    {
        perror("No or Multiple arguments not suppported:");
        exit(EXIT_FAILURE);
    }
    file = (FILE*)malloc(sizeof(FILE));
    strcpy(file->file_name, argv[1]);

    while(1){
        /*1*/printf("%s: Begin \n",__func__);
        /*2*/printf("%s: MAIN MENU \n",__func__);
        /*3*/printf("%s: 1: WRITE INTO DEVICE \n",__func__);
        /*4*/printf("%s: 2: READ FROM DEVICE  \n",__func__);
        /*7*/printf("%s: 0: EXIT PROGRAM \n",__func__);
        /*8*/printf("%s: Please Enter your choice: \n",__func__);	
    
        scanf("%d",&file->rdwr_flag);	
        if(file->rdwr_flag == 0)
            exit(0);
        nested_driver_access((void*)file);
    }
}



