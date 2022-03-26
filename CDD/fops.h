#include "header.h"
#include "declarations.h"
struct file_operations fops = {
	open:		myDeviceOpen,
	release:	myDeviceClose,
	read:		myDeviceRead,
	write:		myDeviceWrite	
};
