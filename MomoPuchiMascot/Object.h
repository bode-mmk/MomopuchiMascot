#pragma once
#include <gdiplus.h>
#include <string>
#include <utility>
#include <memory>
#include <boost/geometry/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/filesystem.hpp>
#include "Part.h"

class Object {

public:
	Object() noexcept = default;
	//それぞれのパーツをセットする
	void set_back_hair(Part&& pt) {
		back_hair_ = std::move(pt);
	}
	void set_face(Part&& pt) {
		face_ = std::move(pt);
	}
	void set_front_hair(Part&& pt) {
		front_hair_ = std::move(pt);
	}
	void set_head_set(Part&& pt) {
		head_set_ = std::move(pt);
	}
	void set_eyes(Part&& pt) {
		eyes_ = std::move(pt);
	}
	void set_left_arm(Part&& pt) {
		left_arm_ = std::move(pt);
	}
	void set_left_hand(Part&& pt) {
		left_hand_ = std::move(pt);
	}
	void set_right_arm(Part&& pt) {
		right_arm_ = std::move(pt);
	}
	void set_right_hand(Part&& pt) {
		right_hand_ = std::move(pt);
	}
	void set_left_leg(Part&& pt) {
		left_leg_ = std::move(pt);
	}
	void set_left_foot(Part&& pt) {
		left_foot_ = std::move(pt);
	}
	void set_right_leg(Part&& pt) {
		right_leg_ = std::move(pt);
	}
	void set_right_foot(Part&& pt) {
		right_foot_ = std::move(pt);
	}
	void set_body(Part&& pt) {
		body_ = std::move(pt);
	}
	void draw_parts(Gdiplus::Graphics& graphics) {
		draw_part(back_hair_, graphics);
		draw_part(face_, graphics);
		draw_part(front_hair_, graphics);
		draw_part(head_set_, graphics);
		draw_part(eyes_, graphics);
		draw_part(left_arm_, graphics);
		draw_part(left_hand_, graphics);
		draw_part(right_arm_, graphics);
		draw_part(right_hand_, graphics);
		draw_part(left_leg_, graphics);
		draw_part(left_foot_, graphics);
		draw_part(right_leg_, graphics);
		draw_part(right_foot_, graphics);
		draw_part(body_, graphics);
	}
protected:
	void draw_part(const Part& part, Gdiplus::Graphics& graphics) {
		graphics.DrawImage(part.get_image(), part.get_rect());
	}
private:
	//後ろ髪
	Part back_hair_;
	//顔
	Part face_;
	//前髪
	Part front_hair_;
	//髪飾り
	Part head_set_;
	//目
	Part eyes_;
	//左腕
	Part left_arm_;
	//左手
	Part left_hand_;
	//右腕
	Part right_arm_;
	//右手
	Part right_hand_;
	//左脚
	Part left_leg_;
	//左足
	Part left_foot_;
	//右脚
	Part right_leg_;
	//右足
	Part right_foot_;
	//身体
	Part body_;
};