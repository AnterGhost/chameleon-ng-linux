#pragma once

#define INVALID_EHANDLE_INDEX 0xFFFFFFFF

typedef unsigned long CBaseHandle;

class IHandleEntity {
	public:
		virtual ~IHandleEntity() {};
};

class IClientUnknown: public IHandleEntity {
	public:
		virtual ~IClientUnknown() {};
};

class IClientThinkable {
	public:
		virtual ~IClientThinkable() {};
};

class IClientRenderable {
	public:
		virtual ~IClientRenderable() {};
};

class IClientNetworkable {
	public:
		virtual ~IClientNetworkable() {};

		inline ClientClass* GetClientClass() {
			return GetVirtualFunction<ClientClass*(*)(IClientNetworkable*)>(this, 2)(this);
		}
		
		inline int GetIndex() {
			return GetVirtualFunction<int(*)(IClientNetworkable*)>(this, 9)(this);
		}
};

class IClientEntity: public IClientUnknown, public IClientRenderable, public IClientNetworkable, public IClientThinkable {
	public:
		virtual ~IClientEntity() {};
};