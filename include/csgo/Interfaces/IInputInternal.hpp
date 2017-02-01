#pragma once

class IInputInternal {
	public:
		void SetKeyCodeState(ButtonCode_t code, bool is_down) {
			return GetVirtualFunction<void(*)(IInputInternal*, ButtonCode_t, bool)>(this, 92)(this, code, is_down);
		}
};

extern IInputInternal* inputinternal;