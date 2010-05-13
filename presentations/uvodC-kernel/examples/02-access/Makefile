KDIR=/lib/modules/$(shell uname -r)/build
KBUILD=$(MAKE) -C $(KDIR) M=$(PWD)

obj-m := code.o

default: us
	$(KBUILD) modules

clean:
	$(KBUILD) clean

us: us.o

.PHONY: default clean
