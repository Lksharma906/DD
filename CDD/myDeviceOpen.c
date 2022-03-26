#include"header.h"
#include"declarations.h"


int myDeviceOpen(struct inode *node, struct file * f)
{
	#ifdef KCDEBUG
	pr_info("BEGIN: %s %s \n",__FILE__,__func__);
	#endif
	
	#ifdef KCDEBUG
	pr_info("END: %s %s \n",__FILE__,__func__);
	#endif
	return 0;
}
