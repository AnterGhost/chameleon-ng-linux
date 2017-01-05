#pragma once

#include <dlfcn.h>
#include <string>

typedef void* (*InstantiateInterfaceFn) ();

class InterfaceReg {
	public:
		InstantiateInterfaceFn m_CreateFn;
		const char* m_pName;
		InterfaceReg* m_pNext;
};

inline const InterfaceReg* GetInterfaces(const char* library) {
	// Open a handle to the requested shared library.
	void* handle = dlopen(library, RTLD_NOLOAD | RTLD_NOW);

	// Get the address of the "s_pInterfaceRegs" symbol.
	void* interfaces_sym = dlsym(handle, "s_pInterfaceRegs");

	// Cast the symbol to the global interface linked list.
	InterfaceReg* interfaces = *reinterpret_cast<InterfaceReg**>(interfaces_sym);

	// Close our handle.
	dlclose(handle);

	// Return the list of interfaces.
	return interfaces;
}

template <typename T> inline T* GetInterface(const char* library, const char* partial_version) {
	for (const InterfaceReg* current = GetInterfaces(library); current; current = current->m_pNext) {
		if (std::string(current->m_pName).find(partial_version) != std::string::npos) {
			return reinterpret_cast<T*>(current->m_CreateFn());
		}
	}

	return nullptr;
}