# CMPE283
## Functionality:
- Read the VMX configuration MSRs to ascertain support capabilities/features
-- Entry / Exit / Procbased / Secondary Procbased / Pinbased controls
- For each group of controls above, interpret and output the values read from the MSR to the system via printk(..), including if the value can be set or cleared.


#### Q1:I did it by myself


#### Q2:steps
1. choose senario 2, and install Ubuntu 20.04LTS (dual-boot)
2. install 'make' and 'gcc' to set up the environment
>      sudo apt install make  
>      sudo apt install gcc
3. complete the cmpe283-1.c by looking into sdm volumn 3 section 24
4. open the terminal in corresponding directory, build the module by running: 
>      make
5. insert the module into kernel by running:
>      sudo insmod ./cmpe283-1.ko    
6. show the kernel log which represents VMX features:
>      dmesg                         
6. if you change cmpe283-1.c and recompile, you need to remove the module first, and insert the new module:
>      sudo rmmod cmpe283-1
>      sudo insmod ./cmpe283-1.ko

       
## Screenshots:
![1](https://user-images.githubusercontent.com/33148410/96801733-24ad0e80-13bd-11eb-9f0e-e698a40d82d8.png)

![2](https://user-images.githubusercontent.com/33148410/96801742-2971c280-13bd-11eb-984f-a4d2f3604a14.png)

![3](https://user-images.githubusercontent.com/33148410/96801747-2bd41c80-13bd-11eb-91de-d0ecb742334c.png)
