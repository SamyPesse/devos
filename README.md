# (Very) Basic Operating System in C++

[![Code Now](https://friendco.de/widgets/image/codenow?url=https%3A%2F%2Fgithub.com%2FSamyPesse%2Fdevos.git&file=&style=vertical&private=true&create=false&prepare=true)](https://friendco.de/widgets/url/codenow?url=https%3A%2F%2Fgithub.com%2FSamyPesse%2Fdevos.git&file=&style=vertical&private=true&create=false&prepare=true)

This code was written several years ago as one of my first projects when I was in High School so it's normal if some parts of the code looks like "crap".

But some parts of the code are usefull to learn how to create a bootable operating system with memory pagination, multitasking, virtual memory, EXT2, ...


[![Screen](https://raw.github.com/SamyPesse/devos/master/screens/1.png)](https://raw.github.com/SamyPesse/devos/master/screens/1.png)

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
	* Userland :
		* API Posix
		* LibC
		* "Can" run a shell or some excutables like Lua, ...


## Build & Run using Vagrant (for OS X and Linux users)

Make sure you have both Vagrant installed and this repo cloned (and an open terminal in it's folder)

Then run the following commands (ignore comment lines sarting with ```#```):

```bash
# Starts Vagrant VM
# This will start an ubuntu machine and install build-essential, make, Qemu ...
vagrant up

# SSH into machine
vagrant ssh

# Once SSHed
cd /vagrant

# Build kernel, userland ...
make all

# Run emulation
make emulate
```

## Progress
  - Compiles :white_check_mark:
  - Builds Image :white_check_mark:
  - Boots :x:
