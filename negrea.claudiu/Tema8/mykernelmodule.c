#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

MODULE_DESCRIPTION("My kernel module");
MODULE_AUTHOR("Me");
MODULE_LICENSE("GPL");


static int my_init(void){
	pr_debug("Bonjour! \n");
	return 0;
}

static void my_exit(void){
	pr_debug("Au revoir! \n");
}
module_init(my_init);
module_exit(my_exit);

		
	
