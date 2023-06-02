#include <linux/dma-mapping.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yannick");
MODULE_DESCRIPTION("A driver for allocating DMA buffer and free it");

static int my_allocator_probe(struct platform_device *pdev) {
    printk("my_allocator - Probe Function\n");
    return 0;
}

static void my_allocator_disconnect(struct platform_device *pdev) {
    printk("my_allocator - Disconnect Function\n");
}

/*
static struct file_operations my_allocator = {
        .name = "my_allocator",
        .probe = my_allocator_probe,
        .remove = my_allocator_disconnect,
};
*/

static int __init alloc_init(void)
{
    int ret;
    void *buffer;
    dma_addr_t dma_addr;
    size_t size = 1024; // size of buffer in bytes
    int count = 0;

    while(1) {

        /* Allocate DMA-safe memory */
        buffer = dma_alloc_coherent(NULL, size, &dma_addr, GFP_KERNEL);
        if (!buffer) {
            printk(KERN_ERR "Failed to allocate DMA buffer\n");
            return 1;
        }

        printk(KERN_INFO "Buffer allocated well\n");

        /* Free the DMA-safe memory */
        dma_free_coherent(NULL, size, buffer, dma_addr);

        break;

//        if (count == 1000) {
//            break; // exit the loop after 100 iterations
//        }
    }
    return 0;
}

static void __exit alloc_exit(void)
{
    printk(KERN_INFO "Good bye\n");
}

module_init(alloc_init);
module_exit(alloc_exit);


