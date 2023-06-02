#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/dma-mapping.h>

MODULE_LICENSE("GPL");

//static struct dma_alloc_handle *dma_handle;
//static char *dma_buffer;
//static dma_addr_t dma_addr;

static int __init dma_alloc_init(void)
{
//    int ret;
//
//    /* Allocate DMA-safe memory */
//    dma_buffer = dma_alloc_coherent(NULL, PAGE_SIZE, &dma_addr, GFP_KERNEL);
//    if (!dma_buffer) {
//        printk(KERN_ERR "Failed to allocate DMA buffer\n");
//        return -ENOMEM;
//    }

    printk(KERN_INFO "Buffer allocated well\n");
    /* Use the DMA buffer here */

    return 0;
}

static void __exit dma_alloc_exit(void)
{
    /* Free the DMA-safe memory */
    printk(KERN_INFO "Good bye\n");
    //dma_free_coherent(NULL, PAGE_SIZE, dma_buffer, dma_addr);
}

module_init(dma_alloc_init);
module_exit(dma_alloc_exit);