#path for .h files
INCLUDE = -I include
INCLUDE += -I st7735
INCLUDE += -I snake

SOURCE = main.cpp startup.cpp
SOURCE += lib/rcc.c
SOURCE += lib/gpio.c
SOURCE += lib/delay.c
SOURCE += lib/spi.c
SOURCE += st7735/st7735.c
SOURCE += snake/snake.cpp

LINKER = linker_script.ld

FLAGS = -Os -mcpu=cortex-m3 -mthumb -ffunction-sections -fdata-sections -lc -lm -mfloat-abi=soft -lstdc++ -lsupc++ --specs=nosys.specs -static
FLAGS += --specs=nano.specs -Wl,--gc-sections -Wl,--start-group -Wl,--end-group -fno-exceptions
	
all: build upload clean 
	
build:
	@arm-none-eabi-g++ $(FLAGS) $(INCLUDE) $(SOURCE) -T $(LINKER) -o firm.elf
	@arm-none-eabi-objcopy -O binary firm.elf firm.bin

dump:
	arm-none-eabi-objdump -h -S firm.elf > dissasembly.list

upload:
	STM32_Programmer_CLI -c port=SWD freq=3900 ap=0 -e all -w firm.bin 0x08000000 -v -rst --start

clean:
	-del *.o
	-del *.elf
	-del *.bin
	-del *.list
