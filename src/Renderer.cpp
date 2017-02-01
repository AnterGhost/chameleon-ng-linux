#include "Renderer.hpp"

bool Renderer::IsActive() {
	// Whether the GUI is accepting input and should be drawn.
	return this->active;
}

void Renderer::SetActive(bool active) {
	this->active = active;
}