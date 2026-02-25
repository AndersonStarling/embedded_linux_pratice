obj-m += character.o
PWD := $(shell pwd)

USER_SRC := character_test.c
USER_APP := character_test

all:
	$(MAKE) -C $(KDIR) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) M=$(PWD) clean

app:
	$(CC) -o $(USER_APP) $(USER_SRC)



