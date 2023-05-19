# LINUX_DRIVER_MODULES


### Structure
    - 01_kernelspace_driver
        This folder contains many small drivers.
    - ALLOC_FREE
        When the driver is loaded a loop that allocate buffers with dma_alloc_coherent and disallocated after. That operation is break after 1000 allocations. 
    