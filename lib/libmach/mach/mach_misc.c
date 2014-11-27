#include <sys/cdefs.h>
#include <sys/types.h>
#include <sys/errno.h>

#include <mach/mach.h>
#include <mach/boolean.h>
#include <mach/mach_traps.h>
#include <mach/mach_init.h>
#include <mach/mach_types.h>
#include <mach/message.h>
#include <mach/mach_port.h>
#include <mach/mach_vm.h>
#include <stdbool.h>

kern_return_t
mach_port_allocate(mach_port_name_t target, mach_port_right_t right,
				   mach_port_name_t *name)
{

	return (_kernelrpc_mach_port_allocate_trap(target, right, name));
}

kern_return_t
mach_port_deallocate(mach_port_name_t target, mach_port_name_t name)
{

	return (_kernelrpc_mach_port_deallocate_trap(target, name));
}

kern_return_t
mach_port_extract_right(mach_port_name_t target __unused,
						mach_port_name_t name __unused,
						mach_msg_type_name_t msgt_name __unused,
						mach_port_name_t *poly __unused,
						mach_msg_type_name_t *polyPoly __unused)
{

	/* no syscall for this - needs to go through the normal RPC glue */
	return (ENOSYS);
}

kern_return_t
mach_port_insert_right(mach_port_name_t target, mach_port_name_t name,
					   mach_port_name_t poly, mach_msg_type_name_t polyPoly)
{

	return (_kernelrpc_mach_port_insert_right_trap(target, name, poly, polyPoly));
}

kern_return_t
mach_port_mod_refs(mach_port_name_t target, mach_port_name_t name,
					   mach_port_right_t right, mach_port_delta_t delta)
{

	return (_kernelrpc_mach_port_mod_refs_trap(target, name, right, delta));
}

mach_port_t
mach_host_self(void)
{

	return (host_self_trap());
}

kern_return_t
mach_vm_allocate(mach_port_name_t target, vm_address_t *addr, vm_size_t size, int flags)
{

	return (_kernelrpc_mach_vm_allocate_trap(target, addr, size, flags));
}

kern_return_t
mach_vm_deallocate(mach_port_name_t target, vm_address_t addr, vm_size_t size)
{

	return (_kernelrpc_mach_vm_deallocate_trap(target, addr, size));
}


kern_return_t
mach_vm_map(mach_vm_map_t target, mach_vm_address_t *address, mach_vm_offset_t mask,
			mach_vm_size_t size, int flags, mem_entry_name_port_t object __unused,
			memory_object_offset_t offset __unused, boolean_t copy __unused,
			vm_prot_t cur_protection, vm_prot_t max_protection __unused,
			vm_inherit_t inheritance __unused)
{

	return (_kernelrpc_mach_vm_map_trap(target, address, size, mask, flags, cur_protection));
}

kern_return_t
mach_port_move_member(mach_port_name_t target, mach_port_name_t member, mach_port_name_t after)
{

	return (_kernelrpc_mach_port_move_member_trap(target, member, after));
}
