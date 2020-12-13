# CMPE283-2

### CMPE283 Assignment-2
Your assignment is to modify the CPUID emulation code in KVM to report back additional information when a special CPUID “leaf function” is called.  
• For CPUID leaf function %eax=0x4FFFFFFF:  
◦ Return the total number of exits (all types) in %eax  
◦ Return the high 32 bits of the total time spent processing all exits in %ebx  
◦ Return the low 32 bits of the total time spent processing all exits in %ecx  
▪ %ebx and %ecx return values are measured in processor cycles  

At a high level, you will need to perform the following:  
• Configure a Linux machine, either VM based or on real hardware. You may use any Linux  
distribution you wish, but it must support the KVM hypervisor.  
• Download and build the Linux kernel source code (see below)  
• Modify the kernel code with the assignment functionality:  
◦ Determine where to place the measurement code  
◦ Create new CPUID leaf 0x4FFFFFFF  
▪ Report back information as described above  
• Create (or otherwise locate) a user-mode program that performs various CPUID instructions  
required to test your assignment  
• Verify proper output  

#### Q1:I did the assignment by myself

#### Q2:Steps: 
1. Fork the https://github.com/torvalds/linux repository.  
2. Clone the source code  
> git clone https://github.com/emilyfoxhu/linux.git  
3. Open the terminal in corresponding directory 
4. Build the new kernel using following steps: 
> sudo bash  
apt-get install build-essential kernel-package fakeroot libncurses5-dev libssl-dev ccache bison flex libelf-dev  
uname -r  
![1](https://user-images.githubusercontent.com/33148410/98290847-1cc5a080-1f5f-11eb-9048-3aa1d42647b7.jpg)  
cp /boot/config-5.4.0-52-generic ./.config   (replace your version obtained from the previous step here)  
make oldconfig   (default for everything by holding down enter)  
make -j4  
make modules  
make modules_install  
make install  
reboot  (enter the new kernel, you can use 'uname -r' to check the version)  
![2](https://user-images.githubusercontent.com/33148410/98290852-1df6cd80-1f5f-11eb-9fbf-558fbfe53005.jpg)  
![3](https://user-images.githubusercontent.com/33148410/98290857-1f27fa80-1f5f-11eb-9920-c7b6d5cff98d.jpg)  
5. Edit 'linux/arch/x86/kvm/vmx/vmx.c' and 'linux/arch/x86/kvm/cpuid.c' files.  
6. Rebuild the code by running:  
> make && make modules && make modules_install && make install   (it takes shorter time, about 5-10 minutes)  
7. Check if kvm is there(no):  
> cat /proc/cpuinfo | more  
![4](https://user-images.githubusercontent.com/33148410/98290861-20f1be00-1f5f-11eb-82f6-a5fffd44dabd.jpg)  
8. Install KVM and Virt-manager by running:  
> sudo apt install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils virt-manager  
9. Open virt-manager by running:  
> sudo virt-manager  
10. Create a nested vm using ubuntu-20.04.1-desktop-amd64.iso on desktop. You can see vm added by running:  
> sudo virsh -c qemu:///system list  
![5](https://user-images.githubusercontent.com/33148410/98290866-22bb8180-1f5f-11eb-9706-27f1b997fef6.jpg)  
![6](https://user-images.githubusercontent.com/33148410/98290889-26e79f00-1f5f-11eb-99bf-75c195698f9e.jpg)  
11. Enter the guest vm1 you just installed, and test functionality, compile and verify results:   
> gcc test.c  
./a.out  
![77](https://user-images.githubusercontent.com/33148410/98300350-08d56b00-1f6e-11eb-8269-ef9198eda68a.jpg)  
![8](https://user-images.githubusercontent.com/33148410/98299432-90ba7580-1f6c-11eb-935a-27a2a8f98307.jpg)  
12. Reboot the guest vm and run test again:  
![9](https://user-images.githubusercontent.com/33148410/98299439-91eba280-1f6c-11eb-830c-bb6a2baf8ad6.jpg)  

#### Q3:Comment on the frequency of exits:
- Does the number of exits increase at a stable rate?  
No, it doesn't.  
- Or are there more exits performed during certain VM operations?  
Yes, there are more exits performed during some VM operations such as I/O operations.  
- Approximately how many exits does a full VM boot entail?  
About 1,031,093 exits.  

