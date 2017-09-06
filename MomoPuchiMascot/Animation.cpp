#include "stdafx.h"
#include "Animation.h"
#include "Object.h"

bool Animation::next_frame(Object* obj) {
	// animation折り返し地点 (大体1秒 1sec / 16fps = 60f
	constexpr unsigned int animation_half_point = 60;

	// 上下の振れ幅
	constexpr unsigned int ocsillation_height = 30;

	// 1 frame毎に加減算される座標値
	constexpr double ocsillation_delta = static_cast<double>(ocsillation_height) / static_cast<double>(animation_half_point);

	// 現在のframeから実座標値を計算
	double position = animation_state_counter_ * ocsillation_delta;

	// 四捨五入値
	int rounded_position = static_cast<int>(position + 0.5);

	// 取り敢えず顔だけ動かしてみる
	obj->get_face()->set_left_up({ 0, rounded_position });

	// 加算
	animation_state_counter_++;

	// 一定値を越えるとリターン
	if (animation_state_counter_ > animation_half_point) {
		animation_state_counter_ = 0;
	}

	return true;
}