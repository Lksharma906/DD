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
    
    nested_driver_access((void*)file);
}



