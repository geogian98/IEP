#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

MODULE_DESCRIPTION("Modul Kernel");
MODULE_AUTHOR("George");
MODULE_LICENSE("GPL");


static int initializare(void){
	pr_debug("Hai noroc! \n");
	return 0;
}

static void iesire(void){
	pr_debug("Hai salut! \n");
}
module_init(initializare);
module_exit(iesire);
		
