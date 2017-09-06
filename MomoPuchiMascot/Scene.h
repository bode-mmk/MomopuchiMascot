#pragma once
#include "Animation.h"
#include "Object.h"
#include <gdiplus.h>
#include <boost/filesystem.hpp>

class Scene {
public:
	// ctor
	Scene() noexcept = default;

	//dtor
	~Scene() noexcept = default;

	//registeration object
	void registeration_object(const boost::filesystem::path& folder_path);

	//paint object
	void paint(Gdiplus::Graphics& graphics);
private:
	Animation animation_;
	Object object_;
};