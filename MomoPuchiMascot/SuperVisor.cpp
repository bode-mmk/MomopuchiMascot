#include "stdafx.h"
#include "SuperVisor.h"
#include "Scene.h"

bool SuperVisor::paint_all(Gdiplus::Graphics& graphics) {
	for (auto&& s : scene_) {
		s->paint(graphics);
	}
	return true;
}

bool SuperVisor::registeration_scene(std::shared_ptr<Scene>&& scene) {
	scene_.push_back(std::move(scene));
	return true;
}

