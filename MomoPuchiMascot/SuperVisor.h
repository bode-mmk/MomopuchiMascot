#pragma once
#include <memory>
#include <vector>

class Scene;

class SuperVisor {

public:
	// Constructor
	SuperVisor() noexcept = default;

	// Destructor
	~SuperVisor() noexcept = default;

	// Non-Copyable 
	SuperVisor(const SuperVisor&) = delete;

	// Non-Movable
	SuperVisor(SuperVisor&&) = delete;

	// paint_all
	bool paint_all(Gdiplus::Graphics&);

	// regsteration scene
	bool registeration_scene(std::shared_ptr<Scene>&&);

private:
	std::vector<std::shared_ptr<Scene>> scene_;
};