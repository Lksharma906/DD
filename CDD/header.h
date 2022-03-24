#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/moduleparam.h>

#ifndef BASEMINOR
#define BASEMINOR 1
#endif

#ifndef NOD
#define NOD 1
#endif

extern dev_t devno;
extern unsigned baseminor;
extern unsigned basemajor;
extern int  nod;



MODULE_LICENSE("DUAL GPL/MIT");
MODULE_AUTHOR("LOKESH SHARMA");
MODULE_DESCRIPTION("A basic kernel module");

