# (Very) Basic Operating System in C++

This code was written several years ago as one of my first projects when I was in High School so it's normal if some parts of the code looks like "crap".

## Features :

	* Code in C++
	* x86 32bits
	* Boot with Grub
	* Kind of modular system for drivers (I was in High school so it's not really great)
	* Kind of UNIX style (again: It's not great)
	* Multitasking
	* ELF executable in userland
	* Modules (accessible in userland using /dev/...) :
		* IDE disks
		* DOS partitions
		* Clock
		* EXT2 (read only)
		* Boch VBE


## To build the kernel :

You will need : gcc, make, binutils (not cygwin)
It was tested on : Ubuntu (i386).
Just type :

	make all
	
## To emulate the operatingsystem :

You will need : qemu and somes unix utils like grub
	
## To build an application :

You will need : gcc, make, binutils (not cygwin)
It was tested on : Ubuntu (i386).
