#/bin/bash/
fdisk -l -u ./c.img
losetup -o 2048 /dev/loop1 ./c.img

#mkdosfs -F 12 -c /dev/loop1
mke2fs /dev/loop1
mount  /dev/loop1 /mnt/
cp -R bootdisk/* /mnt/
umount /mnt/
grub --device-map=/dev/null << EOF
device (hd0) ./c.img
geometry (hd0) 20 16 63
root (hd0,0)
setup (hd0)
quit
EOF

losetup -d /dev/loop1
