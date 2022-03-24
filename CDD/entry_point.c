#include"header.h"
dev_t devno;
unsigned baseminor;
unsigned basemajor;
int nod;
int devSize;
module_param(nod,int,S_IRUGO);
module_param(devSize,int,S_IRUGO);
static int __init entry_point(void){
    int ret;
    if(nod<1 && nod>255)
        nod = NOD;
    baseminor = BASEMINOR;
    ret = alloc_chrdev_region(&devno, baseminor, nod, "DD");
    if(ret == -1)
    {
        pr_err("alloc_chrdev_region failed\n");
    }
    basemajor = MAJOR(devno);
    pr_info("Major No of allocated device is %d \n",basemajor);

    pr_info("Hello Kernel\n");
    return 0;
}

module_init(entry_point);
