CC = riscv64-unknown-elf-gcc
INCLUDE = -I./include
CFLAGS = -mcmodel=medany -march=rv32ima_zicsr -mabi=ilp32 -g -Wall -w
BUILD = -nostdlib -fno-builtin
GDB = riscv64-unknown-elf-gdb
SOURCE = src/

DIR = ./bin/
CHECKDIR := $(shell if ! $(DIR); \
			then mkdir -p $(DIR); fi)

OBJ = \
$(SOURCE)start.s \
$(SOURCE)mem.s \
$(SOURCE)lib.c \
$(SOURCE)alloc.c \
$(SOURCE)os.c 

QEMU = qemu-system-riscv32
QFLAGS = -nographic -smp 4 -machine virt -bios none
QFLAGS += -drive if=none,format=raw,file=$(DIR)hdd.dsk,id=x0
QFLAGS += -device virtio-blk-device,drive=x0,bus=virtio-mmio-bus.0

OBJDUMP = riscv64-unknown-elf-objdump

make: $(DIR)os.elf $(DIR)hdd.dsk

all: clean $(DIR)os.elf $(DIR)hdd.dsk qemu

test: clean $(DIR)os.elf qemu

$(DIR)os.elf: $(OBJ)
	$(CHECKDIR)$(CC) $(INCLUDE) $(BUILD) $(CFLAGS) -T os.ld -o $(DIR)os.elf $^

$(DIR)hdd.dsk:
	dd if=/dev/urandom of=$(DIR)hdd.dsk bs=1M count=32

qemu: $(TARGET) $(DIR)hdd.dsk
	@qemu-system-riscv32 -M ? | grep virt >/dev/null || exit
	@echo "Press Ctrl-A and then X to exit QEMU"
	$(QEMU) $(QFLAGS) -kernel $(DIR)os.elf

clean:
	rm -f $(DIR)*.elf
	rm -f $(DIR)hdd.dsk
	rm -f *.gch

.PHONY : debug
debug: clean os.elf hdd.dsk
	@echo "Press Ctrl-C and then input 'quit' to exit GDB and QEMU"
	@echo "-------------------------------------------------------"
	@${QEMU} ${QFLAGS} -kernel $(DIR)os.elf -s -S &
	@${GDB} $(DIR)os.elf -q -x ./gdbinit