export PATH := /opt/devkitpro/devkitARM/bin/:/opt/devkitpro/tools/bin/:$(PATH)

RM=rm
EMU=VisualBoyAdvance

CPPFLAGS=-mthumb-interwork -mthumb -O2 -nostdinc++ -fno-strict-aliasing -Wall -Wextra
LDFLAGS=-mthumb-interwork -mthumb -specs=gba.specs 

all: fixed.gba

fixed.gba: main.gba
	cp $< $@
	gbafix $@

main.gba: main.elf
	arm-none-eabi-objcopy -v -O binary $< $@

main.elf: main.o
	arm-none-eabi-g++ $< $(LDFLAGS) -o $@

main.o: main.cpp
	arm-none-eabi-g++ -c $< $(CPPFLAGS) -o $@

.PHONY: clean run

clean:
	$(RM) fixed.gba main.gba main.elf main.o

run: fixed.gba
	$(EMU) fixed.gba
