#include"header.h"
#include"declarations.h"


ssize_t myDeviceWrite(struct file * f,const char __user * u, size_t size, loff_t *loff)
{
	#ifdef KCDEBUG
	pr_info("BEGIN: %s %s \n",__FILE__,__func__);
	#endif
	
	#ifdef KCDEBUG
	pr_info("END: %s %s \n",__FILE__,__func__);
	#endif
	return 0;

}
