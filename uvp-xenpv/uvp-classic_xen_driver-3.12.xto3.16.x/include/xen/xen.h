#ifndef _XEN_XEN_H
#define _XEN_XEN_H

enum xen_domain_type {
	XEN_NATIVE,		/* running on bare hardware    */
	XEN_PV_DOMAIN,		/* running in a PV domain      */
	XEN_HVM_DOMAIN,		/* running in a Xen hvm domain */
};

#if defined(CONFIG_PARAVIRT_XEN)
extern enum xen_domain_type xen_domain_type;
#elif defined(CONFIG_XEN)
#define xen_domain_type		XEN_PV_DOMAIN
#else
#define xen_domain_type		XEN_NATIVE
#endif

#define xen_domain()		(xen_domain_type != XEN_NATIVE)
#define xen_pv_domain()		(xen_domain() &&			\
				 xen_domain_type == XEN_PV_DOMAIN)
#define xen_hvm_domain()	(xen_domain() &&			\
				 xen_domain_type == XEN_HVM_DOMAIN)

#ifdef CONFIG_XEN_DOM0
#include <xen/interface/xen.h>
#include <asm/xen/hypervisor.h>

#define xen_initial_domain()	(xen_domain() && \
				 xen_start_info && xen_start_info->flags & SIF_INITDOMAIN)
#elif defined(CONFIG_XEN)
#define xen_initial_domain()	is_initial_xendomain()
#define xen_has_pv_devices()	is_running_on_xen()
#else  /* !CONFIG_XEN_DOM0 */
#define xen_initial_domain()	(0)
#endif	/* CONFIG_XEN_DOM0 */

#endif	/* _XEN_XEN_H */
