# /bin/bash/
qemu-i386 -m 1024 -s -hda ./c.img  -vga vmware -serial /dev/tty  -redir tcp:2323::23
#-net nic,vlan=1,model=ne2k_pci

