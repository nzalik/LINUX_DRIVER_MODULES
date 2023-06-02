




                Steps to take the usb element to contact
                1. lsusb
                2. lsusb -s 1:8 -v (The usb element with his coordonnées)
                3. use address of idVendor and idProduct



                Steps to compile the hello linux driver

                1. make
                2. sudo insmod dma_buffer_allocation.ko (Compile)
                3. sudo dmesg | grep dma_buffer_allocation (search our driver)
                4. sudo rmmod dma_buffer_allocation