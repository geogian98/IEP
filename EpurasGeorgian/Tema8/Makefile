obj-m = tema8.o

K = $(shell uname -r)

makeall:
	make -C /usr/lib/modules/$(K)/build M=$(PWD) modules

clean:
	make -C /usr/lib/modules/$(K)/build M=$(PWD) clean
