#pragma once

class Renderer {
	private:
		bool active = false;
	public:
		bool IsActive();
		void SetActive(bool);
};

extern Renderer renderer;