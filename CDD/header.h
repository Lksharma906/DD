#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/moduleparam.h>
#include<linux/slab.h>  //For Kmalloc

#ifndef BASEMINOR
#define BASEMINOR 1
#endif

#ifndef NOD
#define NOD 1
#endif

extern dev_t devno;
extern unsigned baseminor;
extern unsigned basemajor;
extern int nod;
extern int devSize;
extern int regSize;
extern int noReg;

typedef struct Qset 
{
	struct Qset *next;
} Qset_t;

typedef struct Dev
{
	/* Struct cdev* is the way to access hardware lying for cdev. 
	 * For accessing it from our driver we are using it here.
	 * */
	struct cdev* mydev;
        Qset_t* qset;	
} Device_t;

extern Device_t * device;



MODULE_LICENSE("DUAL GPL/MIT");
MODULE_AUTHOR("LOKESH SHARMA");
MODULE_DESCRIPTION("A basic kernel module");

