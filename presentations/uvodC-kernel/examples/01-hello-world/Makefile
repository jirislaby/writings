KDIR=/lib/modules/$(shell uname -r)/build
KBUILD=$(MAKE) -C $(KDIR) M=$(PWD)

obj-m := code.o

default:
	$(KBUILD) modules

clean:
	$(KBUILD) clean

.PHONY: default clean
