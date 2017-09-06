#pragma once

class Object;

class Animation {
public:
	Animation() :
		animation_state_counter_(0)
	{};
	~Animation() noexcept = default;

	// animation
	bool next_frame(Object* obj);

private:
	unsigned int animation_state_counter_;
};