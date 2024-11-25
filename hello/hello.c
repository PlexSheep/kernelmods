#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>
#include <linux/sched.h>

MODULE_DESCRIPTION("My kernel module");
MODULE_AUTHOR("Me");
MODULE_LICENSE("GPL");

void check_tasks(void) { 
	struct task_struct *task;
	for_each_process (task){
		printk(KERN_INFO "Name=%s PID=%d\n", task->comm,task->pid);
	}

	return; 
}

static int dummy_init(void) {
	printk(KERN_INFO "Starting...\n");

	check_tasks();

	return 0;
}

static void dummy_exit(void) { pr_info("Stopping...\n"); }

module_init(dummy_init);
module_exit(dummy_exit);
