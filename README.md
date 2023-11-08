# riscv-os-labs
The labs of learning how to write a os with RISC-V architecture.  
The programs can run in Linux and MacOS.  

Make sure the device is already installed riscv library and qemu. To get riscv library, please follow the guideline of [riscv-gnu-toolchain](https://github.com/riscv-collab/riscv-gnu-toolchain).  

Add the appropriate directory to $PATH is required, You will need to update your shell's rc file (e.g. ~/.bashrc) :  
```
# Using Linux:
$ vim ~/.bashrc
$ export PATH=$PATH:/opt/riscv/bin  

# Using MacOS:
$ PATH=$PATH:/usr/local/opt/riscv-gnu-toolchain/bin
```

To install qemu, please using the instruction below:  
```
# Using Ubuntu:
$ sudo apt-get install 

# Using Fedora:
$ sudo dnf install qemu

# Using MacOS (with homebrew):
$ brew install qemu
```
