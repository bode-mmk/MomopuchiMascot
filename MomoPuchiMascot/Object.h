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
	//���ꂼ��̃p�[�c���Z�b�g����
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
	//��딯
	Part back_hair_;
	//��
	Part face_;
	//�O��
	Part front_hair_;
	//������
	Part head_set_;
	//��
	Part eyes_;
	//���r
	Part left_arm_;
	//����
	Part left_hand_;
	//�E�r
	Part right_arm_;
	//�E��
	Part right_hand_;
	//���r
	Part left_leg_;
	//����
	Part left_foot_;
	//�E�r
	Part right_leg_;
	//�E��
	Part right_foot_;
	//�g��
	Part body_;
};