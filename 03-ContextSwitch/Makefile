CC = riscv64-unknown-elf-gcc
CFLAG= -march=rv32ima_zicsr -mabi=ilp32 -T
BUILD = -I./include -nostdlib -fno-builtin
SOURCE = src/

FILES = \
$(SOURCE)boot.s \
$(SOURCE)os_api.c \
$(SOURCE)swtch.s \
$(SOURCE)main.c

OUT = os.elf
LDS = os.ld

QEMU = qemu-system-riscv32
QFLAG = -nographic -smp 4 -machine virt -bios none -kernel

DIR = ./bin/
CHECKDIR := $(shell if ! $(DIR); \
			then mkdir -p $(DIR); fi)

all: $(OUT) qemu

$(OUT): $(FILES)
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