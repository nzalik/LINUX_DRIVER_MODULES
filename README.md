# LINUX_DRIVER_MODULES


### Structure
    - 01_kernelspace_driver
        This folder contains many small drivers.
    - ALLOC_FREE
        When the driver is loaded a loop that allocate buffers with dma_alloc_coherent and disallocated after. That operation is break after 1000 allocations. 
    
    
### In case of 

If you have this error "insmod: ERROR: could not insert module module_name: Invalid module format"
when loading the module driver, you can follow the instructions mentionned here : 
https://stackoverflow.com/questions/71746914/linux-kernel-module-development-module-x86-modules-skipping-invalid-relocatio 

The objective is to update and upgrade system packets and reinstall linux headers as follows :
- sudo apt update && sudo apt upgrade
- sudo apt remove --purge linux-headers-*
- sudo apt autoremove && sudo apt autoclean
- sudo apt install linux-headers-generic
    
