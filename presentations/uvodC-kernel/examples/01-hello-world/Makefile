KDIR=/lib/modules/$(shell uname -r)/build
KBUILD=$(MAKE) -C $(KDIR) M=$(PWD)

obj-m := krtek.o

default: us krtek.ko

krtek.ko: krtek.c
	$(KBUILD) modules

clean:
	$(KBUILD) clean
	rm -f us *.o

us: us.o krtek.ko

.PHONY: default clean
