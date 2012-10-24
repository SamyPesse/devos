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
#ifndef KERNEL_H
#define KERNEL_H

#include <runtime/alloc.h>
#include <runtime/libc.h>
#include <runtime/string.h>


#include <core/file.h>
#include <core/filesystem.h>
#include <core/elf_loader.h>
#include <core/syscalls.h>
#include <core/env.h>
#include <core/user.h>
#include <core/modulelink.h>
#include <core/device.h>
#include <core/socket.h>
#include <core/system.h>


#include <module.h>


#include <io.h>
#include <architecture.h>
#include <vmm.h>
#include <process.h>

#endif
