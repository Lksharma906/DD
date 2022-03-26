#include"header.h"

dev_t devno;
Device_t *device;

unsigned baseminor;
unsigned basemajor;
int nod;
int devSize;
int noReg;
int regSize;

module_param(nod,int,S_IRUGO);
module_param(devSize,int,S_IRUGO);
module_param(noReg,int,S_IRUGO);
module_param(regSize,int,S_IRUGO);

static int __init entry_point(void){
    int ret = 0;
    int i = 0;// For Looping through devices.
    if(nod<1 && nod>255)
        nod = NOD;
    baseminor = BASEMINOR;
    ret = alloc_chrdev_region(&devno, baseminor, nod, "DD");
    if(ret == -1)
    {
        pr_err("alloc_chrdev_region failed\n");
	goto OUT;
    }
    basemajor = MAJOR(devno);
    baseminor = MINOR(devno);
    pr_info("Major No of allocated device is %d, %d \n",basemajor,baseminor);

    device =  (Device_t*)kmalloc(sizeof(Device_t)*nod,GFP_KERNEL);
    if(!device)
    {
	    pr_err("kmalloc failed\n");
	    goto OUT;
    }
    for(i =0; i<nod; i++)
    {
	//Need to do individual memory allocation.
		
    }

    return 0;

OUT:
    pr_err("Failed to do some important job \n");
    return -1;
}

module_init(entry_point);
