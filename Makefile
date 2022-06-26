obj-m := test_drv.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
#	make -C /lib/modules/5.10.103-v7+/build M=$(shell pwd) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
#	make -C /lib/modules/5.10.103-v7+/build M=$(shell pwd) clean

