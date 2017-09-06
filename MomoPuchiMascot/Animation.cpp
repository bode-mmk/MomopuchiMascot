#include "stdafx.h"
#include "Animation.h"
#include "Object.h"

bool Animation::next_frame(Object* obj) {
	// animation�܂�Ԃ��n�_ (���1�b 1sec / 16fps = 60f
	constexpr unsigned int animation_half_point = 60;

	// �㉺�̐U�ꕝ
	constexpr unsigned int ocsillation_height = 30;

	// 1 frame���ɉ����Z�������W�l
	constexpr double ocsillation_delta = static_cast<double>(ocsillation_height) / static_cast<double>(animation_half_point);

	// ���݂�frame��������W�l���v�Z
	double position = animation_state_counter_ * ocsillation_delta;

	// �l�̌ܓ��l
	int rounded_position = static_cast<int>(position + 0.5);

	// ��芸�����炾���������Ă݂�
	obj->get_face()->set_left_up({ 0, rounded_position });

	// ���Z
	animation_state_counter_++;

	// ���l���z����ƃ��^�[��
	if (animation_state_counter_ > animation_half_point) {
		animation_state_counter_ = 0;
	}

	return true;
}