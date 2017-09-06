#include "stdafx.h"
#include "Scene.h"

void Scene::registeration_object(const boost::filesystem::path& folder_path) {
	object_.set_back_hair({ folder_path / boost::filesystem::path("\\back_hair.png"),{ 0,0 }, 242, 238 });
	object_.set_face({ folder_path / boost::filesystem::path("\\face.png"),{ 0,0 }, 242, 238 });
	object_.set_front_hair({ folder_path / boost::filesystem::path("\\front_hair.png"),{ 0,0 }, 242, 238 });
	object_.set_head_set({ folder_path / boost::filesystem::path("\\head_set.png"),{ 0,0 }, 242, 238 });
	object_.set_eyes({ folder_path / boost::filesystem::path("\\eyes.png"),{ 0,0 }, 242, 238 });
	object_.set_left_arm({ folder_path / boost::filesystem::path("\\left_arm.png"),{ 0,0 }, 242, 238 });
	object_.set_left_hand({ folder_path / boost::filesystem::path("\\left_hand.png"),{ 0,0 }, 242, 238 });
	object_.set_right_arm({ folder_path / boost::filesystem::path("\\right_arm.png"),{ 0,0 }, 242, 238 });
	object_.set_right_hand({ folder_path / boost::filesystem::path("\\right_hand.png"),{ 0,0 }, 242, 238 });
	object_.set_left_leg({ folder_path / boost::filesystem::path("\\left_leg.png"),{ 0,0 }, 242, 238 });
	object_.set_left_foot({ folder_path / boost::filesystem::path("\\left_foot.png"),{ 0,0 }, 242, 238 });
	object_.set_right_leg({ folder_path / boost::filesystem::path("\\right_leg.png"),{ 0,0 }, 242, 238 });
	object_.set_right_foot({ folder_path / boost::filesystem::path("\\right_foot.png"),{ 0,0 }, 242, 238 });
	object_.set_body({ folder_path / boost::filesystem::path("\\body.png"),{ 0,0 }, 242, 238 });
}

void Scene::paint(Gdiplus::Graphics& graphics) {
	object_.draw_parts(graphics);
}
