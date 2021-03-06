
#ifndef __ASM_XEN_DRIVER_UTIL_H__
#define __ASM_XEN_DRIVER_UTIL_H__

#include <linux/vmalloc.h>
#include <linux/device.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,23)
/* Allocate/destroy a 'vmalloc' VM area. */
extern struct vm_struct *alloc_vm_area(unsigned long size);
extern void free_vm_area(struct vm_struct *area);
#endif

extern struct class *get_xen_class(void);

#endif /* __ASM_XEN_DRIVER_UTIL_H__ */
