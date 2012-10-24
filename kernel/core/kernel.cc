/**
 *	Koala Operating System
 *	Copyright (C) 2010 - 2011 Samy Pessé
 *	
 *	This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundatn 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/
#include <os.h>
#include <boot.h>


static char* init_argv[2]={"init","-i"};

/* charge les modules de depart */
static void load_modules(multiboot_info* mbi){
	
	if (mbi->mods_count>0){
		u32 initrd_location = *((u32*)mbi->mods_addr);
		u32 initrd_end = *(u32*)(mbi->mods_addr+4);
		u32	initrd_size=initrd_end-initrd_location;
		io.print(" >load module:  location=%x, size=%d \n",initrd_location,initrd_end-initrd_location);
		int i=0;
		unsigned int adress;
	
		for (i=0;i<(initrd_size/4072)+1;i++){	
				adress=(initrd_location+i*4096);
				vmm.kmap(adress,adress);
		}
		execv_module(initrd_location,1,init_argv);
	}
}


/* le main du noyau */
extern "C" void kmain(multiboot_info* mbi){
	io.clear();
	io.print("%s - %s -- %s %s \n",	KERNEL_NAME,
									KERNEL_VERSION,
									KERNEL_DATE,
									KERNEL_TIME);
	
	io.print("%s \n",KERNEL_LICENCE);
	arch.init();
	
	io.print("Loading Virtual Memory Management \n");
	vmm.init(mbi->high_mem);
	
	io.print("Loading FileSystem Management \n");
	fsm.init();
	
	io.print("Loading syscalls interface \n");
	syscall.init();
	
	io.print("Loading system \n");
	sys.init();
	
	io.print("Loading modules \n");
	modm.init();
	modm.initLink();


	modm.install("hda0","module.dospartition",0,"/dev/hda");
	modm.install("hda1","module.dospartition",1,"/dev/hda");
	modm.install("hda2","module.dospartition",2,"/dev/hda");
	modm.install("hda3","module.dospartition",3,"/dev/hda");
	modm.mount("/dev/hda0","boot","module.ext2",NO_FLAG);

	arch.initProc();
	
	io.print("Loading binary modules \n");
	load_modules(mbi);
	
	fsm.link("/mnt/boot/bin/","/bin/");

	
	io.print("\n");
	io.print("  ==== System is ready (%s - %s) ==== \n",KERNEL_DATE,KERNEL_TIME);
	arch.enable_interrupt();
	for (;;);
	arch.shutdown();
}

