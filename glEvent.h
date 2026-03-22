
#pragma once

namespace Violet {

	class glMouseEvent;
	class glScrollEvent;
	class glKeyboardEvent;

	class glMouseEvent {
	public:
		int button;
		int action;
		int mods;
	};

	class glScrollEvent {
	public:
		double xoffset;
		double yoffset;
	};

	class glKeyboardEvent {
	public:
		int key;
		int scancode;
		int action;
		int mods;
	};
}

