#!/bin/sh
echo "Creating ISO"
rm -f iso/ghost_x86.iso
cp bin/kernel.bin iso/boot/kernel.bin
genisoimage -q -no-emul-boot -boot-load-size 4 -boot-info-table -R -b boot/grub/stage2_eltorito  -o ./iso/ghost_x86.iso --exclude=.git ./iso
rm -rf iso/boot/kernel.bin
