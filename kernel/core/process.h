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
#ifndef PROC_H
#define PROC_H

#include <core/file.h>
#include <runtime/list.h>
#include <archprocess.h>	/* definition de process_st */

#include <core/signal.h>

#include <runtime/buffer.h>

#include <api/dev/proc.h>

#define ZOMBIE	PROC_STATE_ZOMBIE
#define CHILD	PROC_STATE_RUN

struct openfile
{
	u32				mode;	/* Mode d'ouverture */
	u32				ptr;	/* Pointeur de lecture/ecriture */
	File*			fp;		/* Fichier ouvert */
};

class Process : public File
{
	public:
		Process(char* n);
		~Process();
		
		u32		open(u32 flag);
		u32		close();
		u32		read(u32 pos,u8* buffer,u32 size);
		u32		write(u32 pos,u8* buffer,u32 size);
		u32		ioctl(u32 id,u8* buffer);
		u32		remove();
		void	scan();
		
		
		u32		create(char* file, int argc, char **argv);
		void	sendSignal(int sig);
		u32		wait();
		
		u32 	addFile(File* fp,u32 m);
		File*	getFile(u32 fd);
		void	deleteFile(u32 fd);
		openfile*	getFileInfo(u32 fd);
		
		void	exit();
		int		fork();
		
		
		void	setState(u8 st);
		u8		getState();
		void	setFile(u32 fd,File* fp,u32 ptr, u32 mode);
		void	setPid(u32 st);
		u32		getPid();
		
		void			setPNext(Process* p);
		
		Process* 		schedule();
		Process*		getPNext();
		Process*		getPParent();
		process_st* 	getPInfo();
		void			setPParent(Process*p);
		
		void			reset_pinfo();
		
		process_st		info;
		
		File*	getCurrentDir();
		void	setCurrentDir(File* f);
		
	protected:
		static u32	proc_pid;
		
		u32 		pid;
		u8			state;
		Process*	pparent;
		Process*	pnext;
		openfile	openfp[CONFIG_MAX_FILE];
		proc_info	ppinfo;
		File*		cdir;
		
		Buffer*		ipc;
		
		static char*	default_tty;

};


#endif
