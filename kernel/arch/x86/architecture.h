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
#ifndef ARCH_H
#define ARCH_H

#include <runtime/types.h>

#include <process.h>


/** Processor architecture class **/
class Architecture
{
	public:
		/** architecture class functions **/
		void	init();			/* start the processor interface */
		void	reboot();		/* reboot the computer */
		void	shutdown();		/* shutdown the computer */
		char*	detect();		/* detect the type of processor */
		void	install_irq(int_handler h);	/* install a interruption handler */
		void	addProcess(Process* p);		/* add a process to the scheduler */
		void	enable_interrupt();		/* enable the interruption */
		void	disable_interrupt();	/* disable the interruption */
		int 	createProc(process_st* info,char* file,int argc,char** argv);	/* initialise a process */
		void	setParam(u32 ret,u32 ret1,u32 ret2, u32 ret3,u32 ret4);		/* set the syscall arguments */
		u32		getArg(u32 n);		/* get a syscall argument */
		void	setRet(u32 ret);	/* set the return value of syscall */
		void 	initProc();			/* initialise the list of processus */
		void	destroy_process(Process* pp);	/* destroy a processus */
		void	destroy_all_zombie();
		void	change_process_father(Process* p,Process* pere);
		int		fork(process_st* info,process_st* father);	/* fork a process */
		
		
		/** architecture public class attributes */
		Process*	pcurrent;		/* the current processus */
		Process*	plist;			/* the chain list of processus */
		
		
	private:
		/** architecture private attributes **/
		u32			ret_reg[5];
		Process* 	firstProc;
		
};

/** standart starting architecture interface **/
extern Architecture arch;

#endif
