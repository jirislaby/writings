KDIR=/lib/modules/$(shell uname -r)/build
KBUILD=$(MAKE) -C $(KDIR) M=$(PWD)

obj-m := jezek.o

default: us
	$(KBUILD) modules

clean:
	$(KBUILD) clean
	rm -f us *.o

us: us.o

.PHONY: default clean
