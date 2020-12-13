# CMPE283-4  

### CMPE283 Assignment-4  
1.	Run your assignment 3 code and boot a test VM using that code.  
2.	Once the VM has booted, record total exit count information (total count for each type of exit handled by KVM). You should do this via a sequence of queries of CPUID leaf function 0x4FFFFFFE.  
3.	Shutdown your test (inner) VM.  
4.	Remove the ‘kvm-intel’ module from your running kernel:  
o	rmmod kvm-intel  
5.	Reload the kvm-intel module with the parameter ept=0 (this will disable nested paging and force KVM to use shadow paging instead)  
o	The module you want is usually found in /lib/modules/XXX/kernel/arch/x86/kvm , where XXX is the version of the kernel you build for assignment 3 – don’t make a mistake and use the one that came with the stock Linux installation.  
o	insmod /lib/modules/XXX/kernel/arch/x86/kvm/kvm-intel.ko ept=0  
6.	Boot the same test VM again, and capture the same output as you did in step 2.  
7.	Answer the questions below.  

#### Q1:I did the assignment by myself

#### Q2:Steps: 
1. Include a sample of your print of exit count output from dmesg from “with ept” and “without ept”.    
2. Clone the source code  
> 

#### Q3:
- What did you learn from the count of exits? Was the count what you expected? If not, why not?  

- What changed between the two runs (ept vs no-ept)？  


