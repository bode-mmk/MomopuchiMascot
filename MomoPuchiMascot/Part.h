#pragma once

#include <gdiplus.h>
#include <boost/geometry/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/filesystem.hpp>

class Part {
public:
	Part() noexcept = default;

	Part(const boost::filesystem::path& path,
		const boost::geometry::model::d2::point_xy<int>& left_up,
		const int& width,
		const int& height) :
		img_(new Gdiplus::Image(path.c_str())),
		left_up_(left_up),
		width_(width),
		height_(height) {}

	Part(const Part& rhs) :
		img_(rhs.img_->Clone()),
		left_up_(rhs.left_up_),
		width_(rhs.width_),
		height_(rhs.height_)
	{}

	~Part() noexcept = default;

	auto get_left_up() const {
		return left_up_;
	}

	void set_left_up(const boost::geometry::model::d2::point_xy<int>& pt) {
		left_up_.x(pt.x());
		left_up_.y(pt.y());
	}

	boost::geometry::model::d2::point_xy<int>
		get_right_down() {
		return { left_up_.x() + width_, left_up_.y() + height_ };
	}
	auto get_image() const {
		return img_;
	}
	Gdiplus::Rect
		get_rect() const {
		return { left_up_.x(), left_up_.y(), left_up_.x() + width_, left_up_.y() + height_ };
	}

private:
	Gdiplus::Image* img_;
	boost::geometry::model::d2::point_xy<int> left_up_;
	int width_;
	int height_;
};