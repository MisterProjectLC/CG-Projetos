#include <vector>
#include "keyframe.h"
#include "Atividade02/src/vec3.h"


#pragma once
class Movable
{
public:
	void move(vec3 transform) {
		_center += transform;
		on_move();
	}

	void add_keyframe(shared_ptr<Keyframe> k) {
		keyframes.push_back(k);
	}

	void set_time(double time) {
		if (keyframes.size() == 0)
			return;

		while (keyframe_index < keyframes.size() and keyframes[keyframe_index]->time < time) {
			keyframe_index++;
		}

		if (keyframe_index >= keyframes.size()) {
			_center = keyframes[keyframes.size()-1]->pos;
		}
		else {
			_center = _center.lerp(keyframes[keyframe_index]->pos, keyframes[keyframe_index - 1]->pos, 
				(time - keyframes[keyframe_index-1]->time)/ (keyframes[keyframe_index]->time - keyframes[keyframe_index-1]->time));
		}
		on_move();
	}

	point3 get_center() {
		return _center;
	}

	Movable() {
		_center = point3(0, 0, 0);
		keyframes = vector<shared_ptr<Keyframe>>();
	}

protected:
	point3 _center = point3(0, 0, 0);

	virtual void on_move() { };

private:
	int keyframe_index = 1;
	vector<shared_ptr<Keyframe>> keyframes = vector<shared_ptr<Keyframe>>();
};

