#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

static void syscall_handler (struct intr_frame *);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  printf ("system call!\n");
	// switch (f) {
	// 	case SYS_HALT:
	// 		break;
	// 	case SYS_EXIT:
	// 		break; 
	// 	case SYS_EXEC: 
	// 		break; 
	// 	case SYS_WAIT: 
	// 		break; 
	// 	case SYS_CREATE: 
	// 		break; 
	// 	case SYS_REMOVE: 
	// 		break; 
	// 	case SYS_OPEN: 
	// 		break; 
	// 	case SYS_FILESIZE: 
	// 		break; 
	// 	case SYS_READ: 
	// 		break; 
	// 	case SYS_WRITE: 
	// 		break; 
	// 	case SYS_SEEK:
	// 		break; 
	// 	case SYS_TELL: 
	// 		break; 
	// 	case SYS_CLOSE: 
	// 		break; 
	// 	default: 
	// 		printf("Error: not a valid system call.");

	// }
  thread_exit ();
}

// void 
// halt (void) 
// {
// 	shutdown_power_off();
// }

// void
// exit (int status) 
// {
// 	process_exit ();
// }

// pid_t
// exec (const char *cmd_line)
// {
//     int pointer_ok = verify_pointer((void*) cmd_line); 
//     if (!pointer_ok) {
//     	// terminate calling process and claim resources
//     }
// 	return process_execute(cmd_line); 
// }

// int
// wait (pid_t pid)
// {

// }

// int 
// verify_pointer (const void* pointer)
// {
// 	struct thread* current = thread_current (); 
// 	uint32_t *pagedir = current->pagedir; 
// 	if (pointer == NULL || is_kernel_vaddr (pointer) || pagedir_get_page (pagedir, pointer) == NULL) {
// 		return 0; 
// 	} else {
// 		return 1; 
// 	}
// }