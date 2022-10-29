#pragma once

namespace ZOM
{
	struct ZOM_API cameraMovement {
		int dolly_front;   // move front
		int dolly_back;    // move back
		int truck_left;    // move left
		int truck_right;   // move right
		int tilt_up;       // tilt up
		int tilt_down;     // tilt down
		int pedestal_up;   // vertically up
		int pedestal_down; // vertically down
		int pan_left;      // move on spot left
		int pan_right;     //move on spot right
		int roll_left;     // rolls on the left side
		int roll_right;    // rolls on the right side

		cameraMovement()
			: dolly_front(0),
			dolly_back(0),
			truck_left(0),
			truck_right(0),
			tilt_up(0),
			tilt_down(0),
			pedestal_up(0),
			pedestal_down(0),
			pan_left(0),
			pan_right(0),
			roll_left(0),
			roll_right(0) {}

	};
}