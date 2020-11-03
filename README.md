### CMPE283 Assignment-2

#### Q1:I did the assignment by myself

#### Q2:Steps: 
1. Fork the https://github.com/torvalds/linux repository.  
2. Clone the source code  
> git clone https://github.com/emilyfoxhu/linux.git  
3. Open the terminal in corresponding directory 
4. Build the kernel using following steps: 
> sudo bash  
apt-get install build-essential kernel-package fakeroot libncurses5-dev libssl-dev ccache bison flex libelf-dev  
uname -a  
cp /boot/config-5.4.0-52-generic ./.config   (replace your version obtained from the previous step here)  
make oldconfig   (default for everything by holding down enter)  
make && make modules && make modules_install && make install   (take a long time for the first time)  
reboot  (enter the new kernel, you can use uname -a to check the version)  
5. Edit linux/arch/x86/kvm/vmx.c and cpuid.c files.  
6. Rebuild the code by running:  
> make && make modules && make modules_install && make install   (it takes shorter time)  
7. Install virt-manager by running:  
> sudo apt-install virt-manager  
8. Test functionality  
> compile and run ./test

#### Q3:Comment on the frequency of exits:
- Does the number of exits increase at a stable rate?  
No, it doesn't.  
- Or are there more exits performed during certain VM operations?  
Yes, there are more exits performed during some VM operations.  
- Approximately how many exits does a full VM boot entail?  
About 2720000(change) exits.  
