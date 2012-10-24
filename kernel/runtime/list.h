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
 
#ifndef __LIST__
#define __LIST__


	struct list_head {
		struct list_head *next, *prev;
	};

	#define LIST_HEAD_INIT(name) { &(name), &(name) }

	#define LIST_HEAD(name) \
		struct list_head name = LIST_HEAD_INIT(name)

	static inline void INIT_LIST_HEAD(struct list_head *list)
	{
		list->next = list;
		list->prev = list;
	}

	static inline void list_add(struct list_head *neww, struct list_head *head)
	{
		neww->next = head->next;
		neww->prev = head;
		(head->next)->prev = neww;
		head->next = neww;
	}

	static inline void list_del(struct list_head *p)
	{
		(p->next)->prev = p->prev;
		(p->prev)->next = p->next;
		p->next = 0;
		p->prev = 0;
	}

	static inline int list_empty(const struct list_head *head)
	{
		return head->next == head;
	}

	#define list_entry(ptr, type, member) \
		(type*) ((char*) ptr - (char*) &((type*)0)->member)

	#define list_first_entry(head, type, member) \
		list_entry((head)->next, type, member)

	#define list_for_each(p, head) \
		for (p = (head)->next; p != (head); p = p->next) 

	#define list_for_each_safe(p, n, head) \
		for (p = (head)->next, n = p->next; p != (head); p = n, n = n->next) 

	#define list_for_each_entry(p, head, member)				\
		for (p = list_entry((head)->next, typeof(*p), member);		\
			 &p->member != (head);					\
			 p = list_entry(p->member.next, typeof(*p), member))	\


#endif	/* __LIST__ */
