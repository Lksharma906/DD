#include"header.h"

static void __exit exit_point(void) {

    unregister_chrdev_region(devno, nod);
    pr_info("Exiting from kernel\n");
}

module_exit(exit_point);