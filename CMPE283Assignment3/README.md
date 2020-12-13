# CMPE283-3

### CMPE283 Assignment-3  
Your assignment is to modify the CPUID emulation code in KVM to report back additional information when special CPUID leaf nodes are requested.  
•	For CPUID leaf node %eax=0x4FFFFFFE:  
o	Return the number of exits for the exit number provided (on input) in %ecx  
	This value should be returned in %eax  
For leaf nodes 0x4FFFFFFE, if %ecx (on input) contains a value not defined by the SDM, return 0 in all %eax, %ebx, %ecx registers and return 0xFFFFFFFF in %edx. For exit types not enabled in KVM, return 0s in all four registers  

At a high level, you will need to perform the following:  
•	Start with your assignment 2 environment  
•	Modify the kernel code with the assignment functionality:  
o	Determine where to place the measurement code (for exit counts)  
o	Create new CPUID leaf 0x4FFFFFFE  
	Report back information as described above  
o	Create a user-mode program that performs various CPUID instructions required to test your assignment  
	Pro tip: This can be achieved on ubuntu by installing the ‘cpuid’ package  
	Run this user mode program in the inner VM  
	There is no need to insmod anything like assignment 1 did  
o	Verify proper output  

#### Q1:I did the assignment by myself

#### Q2:Steps: 
1. Start with the assignment 2 environment   
2. install cpuid package in inner vm    
> sudo apt-get install cpuid  
![cpuid](https://user-images.githubusercontent.com/33148410/102020770-2b5a6100-3d30-11eb-9255-a62286e0cbf7.jpg)  
3. Edit 'linux/arch/x86/kvm/vmx/vmx.c' and 'linux/arch/x86/kvm/cpuid.c' files.  
In cpuid.c, create a new CPUID leaf 0x4FFFFFFE, inside the leaf, if exit type is not defined in SDM, returns 0 for eax,ebx,ecx, returns 0xFFFFFFFF for edx. If exit type is not enabled in KVM,  returns 0 in all eax-edx. Else, return exit number to eax.  
4. Rebuild the code by running:  
> make && make modules && make modules_install && make install (it takes shorter time, about 5-10 minutes)  
5. Open virt-manager by running:  
> sudo virt-manager  
6. Enter the guest vm1, and test functionality, compile and verify results:  
> gcc test-3.c -o test-3  
./test-3 1  
![exits](https://user-images.githubusercontent.com/33148410/102020772-2c8b8e00-3d30-11eb-9a81-24d2d3d60125.jpg)  

#### Q3:Comment on the frequency of exits:
- does the number of exits increase at a stable rate?  
No it doesn't.  
- Or are there more exits performed during certain VM operations?  
Yes, there are more exits performed during some VM operations such as I/O operations.  
- Approximately how many exits does a full VM boot entail?  
About 13 exits.  
- Of the exit types defined in the SDM, which are the most frequent? Least?  
Most frequent exit type is external interrupt.  
The least frequent exit types are many, such as  
