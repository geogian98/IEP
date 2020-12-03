obj-m = tema9.o

KDIR = /usr/lib/modules/`uname -r`/build/

default:
	make -C $(KDIR) M=`pwd`
clean:
	rm -rf *o
