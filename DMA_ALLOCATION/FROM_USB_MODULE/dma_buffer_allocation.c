#include <linux/module.h>
#include <linux/init.h>
#include <linux/usb.h>
//#include <linux/dma-mapping.h>

/* Meta Information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Johannes 4 GNU/Linux");
MODULE_DESCRIPTION("A driver for my Atmega32U4 USB device");

#define VENDOR_ID 0x2717
#define PRODUCT_ID 0xff48

//static struct dma_alloc_handle *dma_handle;
//static char *dma_buffer;
//static dma_addr_t dma_addr;

static struct usb_device_id usb_dev_table [] = {
	{ USB_DEVICE(VENDOR_ID, PRODUCT_ID) },
	{},
};
MODULE_DEVICE_TABLE(usb, usb_dev_table);

static int my_usb_probe(struct usb_interface *intf, const struct usb_device_id *id) {
	printk("my_usb_devdrv - Probe Function\n");
	return 0;
}

static void my_usb_disconnect(struct usb_interface *intf) {
	printk("my_usb_devdrv - Disconnect Function\n");
}

static struct usb_driver my_usb_driver = {
	.name = "my_usb_devdrv",
	.id_table = usb_dev_table,
	.probe = my_usb_probe,
	.disconnect = my_usb_disconnect,
};

/**
 * @brief This function is called, when the module is loaded into the kernel
 */
static int __init my_init(void) {
	int result;
	printk("my_usb_devdrv - Init Function\n");
	result = usb_register(&my_usb_driver);
//    dma_buffer = dma_alloc_coherent(NULL, PAGE_SIZE, &dma_addr, GFP_KERNEL);
//    if (!dma_buffer) {
//        printk(KERN_ERR "Failed to allocate DMA buffer\n");
//        return -ENOMEM;
//    }
	if(result) {
		printk("my_usb_devdrv - Error during register!\n");
		return -result;
	}

	return 0;
}

/**
 * @brief This function is called, when the module is removed from the kernel
 */
static void __exit my_exit(void) {
	printk("my_usb_devdrv - Exit Function\n");
    //dma_free_coherent(NULL, PAGE_SIZE, dma_buffer, dma_addr);
	usb_deregister(&my_usb_driver);
}

module_init(my_init);
module_exit(my_exit);


