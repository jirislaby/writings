KDIR ?= /lib/modules/$(shell uname -r)/build

obj-m := hello.o

all:
	$(MAKE) -C $(KDIR) M=$(CURDIR)

clean:
	$(MAKE) -C $(KDIR) M=$(CURDIR) clean
