#include"header.h"
#include"declarations.h"

static void __exit exit_point(void) {
	
    int i = 0;
    for(i = 0; i < nod; i++)     
    	cdev_del(&device[i].mydev);
    kfree(device);	
    unregister_chrdev_region(devno, nod);
    pr_info("Exiting from kernel\n");
}

module_exit(exit_point);
