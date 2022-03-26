#ifndef _DECLARATIONS_H_
#define _DECLARATIONS_H_

#include"header.h"

//File Operation Declarions to be handled by driver.
extern int myDeviceOpen(struct inode * node, struct file *f);
extern int myDeviceClose(struct inode * node, struct file *f);
extern ssize_t myDeviceRead(struct file * f, char __user * u, size_t size,loff_t *loff);
extern ssize_t myDeviceWrite(struct file * f,const char __user * u, size_t size,loff_t *loff);


#endif
