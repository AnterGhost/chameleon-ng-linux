#pragma once

class CBaseClientState {
	public:
		void ForceFullUpdate() {
			// m_nDeltaTick: 0x1FC
			*reinterpret_cast<int*>(uintptr_t(this) + 0x1FC) = -1;
		};
};

typedef CBaseClientState* (*GetLocalClient_t) (unsigned int);

extern CBaseClientState* clientstate;