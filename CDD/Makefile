INSTALL_DIR=modules
ifneq (${KERNELRELEASE},)
	obj-m:=DD.o

DD-objs := entry_point.o exit_point.o myDeviceOpen.o myDeviceClose.o myDeviceRead.o myDeviceWrite.o 

else
#	KERNELDIR ?= /lib/modules/5.14.8/build
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	@rm -rf ${INSTALL_DIR}
	@mkdir ${INSTALL_DIR}
	@mv -f *.o *.ko *.mod.c .*.cmd ${INSTALL_DIR}
clean:
	rm Module.symvers
	rm modules.order
	rm -rf ${INSTALL_DIR}
	rm *.mod
endif
