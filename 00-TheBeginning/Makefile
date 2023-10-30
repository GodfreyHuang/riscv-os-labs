CC = riscv64-unknown-elf-gcc
CFLAG= -march=rv32ima_zicsr -mabi=ilp32 -T
#CFLAG = -nostdlib -fno-builtin -march=rv32ima -mabi=ilp32
BUILD = -nostdlib -fno-builtin

OUT = os
#OUT = os.elf
LDS = os.ld

QEMU = qemu-system-riscv32
QFLAG = -nographic -smp 4 -machine virt -bios none -kernel

FILES := boot.s main.c
DIR = ./bin/
CHECKDIR := $(shell if ! $(DIR); \
			then mkdir -p $(DIR); fi)

all: $(FILES)
	$(CHECKDIR)$(CC) $(CFLAG) $(LDS) \
	-o $(DIR)$(OUT) $(BUILD) $(FILES)

qemu: $(DIR)$(OUT)
	@qemu-system-riscv32 -M ? | grep virt >/dev/null || exit
	@echo "Press Ctrl-A and then X to exit QEMU"
	$(QEMU) $(QFLAG) $(DIR)$(OUT)

.PHONY: clean
clean:
	rm -f $(DIR)os
	rm -f $(DIR)*.o
	rm -f $(DIR)*.out
	rm -f $(DIR)*.elf
	rm -f *.gch