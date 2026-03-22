
#include "Violet.h"
#include <iostream>

#define Vi Violet
static void inputTest();
static void debugGui(Vi::Window& window, Vi::Camera& camera);
static void controlCamera(Vi::Camera& camera);

int main() {
	Vi::Window window = Vi::Window("Render3D", 1920, 1080);
	Vi::Camera camera;

	Vi::Mesh mesh("default", GL_TRIANGLES);
	mesh.vertices.push_back({ Vi::Vec3f(-0.5, 0.5, 0.0), Vi::Color::random() });
	mesh.vertices.push_back({ Vi::Vec3f(-0.5,-0.5, 0.0), Vi::Color::random() });
	mesh.vertices.push_back({ Vi::Vec3f( 0.5, 0.0, 0.0), Vi::Color::random() });

	while (window.isOpen()) {
		window.pollEvents();
		window.clear(Violet::Color(0.2, 0.2, 0.4));

		inputTest();
		controlCamera(camera);
		debugGui(window, camera);

		window.draw(mesh, camera);
		window.display();
	}

	return 0;
}

static void inputTest() {
	Vi::Mouse& mouse = Vi::Mouse::getMouse();
	Vi::Keyboard& keyboard = Vi::Keyboard::getKeyboard();

	if (mouse.clicked(GLFW_MOUSE_BUTTON_LEFT, GLFW_PRESS))
		std::cout << "Left Mouse Button Pressed\n";
	if (mouse.clicked(GLFW_MOUSE_BUTTON_LEFT, GLFW_RELEASE))
		std::cout << "Left Mouse Button Released\n";
	if (mouse.clicked(GLFW_MOUSE_BUTTON_RIGHT, GLFW_PRESS))
		std::cout << "Right Mouse Button Pressed\n";
	if (mouse.clicked(GLFW_MOUSE_BUTTON_RIGHT, GLFW_RELEASE))
		std::cout << "Right Mouse Button Released\n";
	if (mouse.clicked(GLFW_MOUSE_BUTTON_MIDDLE, GLFW_PRESS))
		std::cout << "Middle Mouse Button Pressed\n";
	if (mouse.clicked(GLFW_MOUSE_BUTTON_MIDDLE, GLFW_RELEASE))
		std::cout << "Middle Mouse Button Released\n";

	double scroll = mouse.scroll();
	if (scroll > 0.0)
		std::cout << "Scrolled Up: scroll = " << scroll << "\n";
	if (scroll < 0.0)
		std::cout << "Scrolled Down: scroll = " << scroll << "\n";

	if (keyboard.pressing(GLFW_KEY_SPACE)) {
		Vi::Vec2d pos = mouse.position();
		std::cout << "Cursor Position: x = " << pos.x << " y = " << pos.y << "\n";
	}
	if (keyboard.pressing(GLFW_KEY_LEFT_SHIFT)) {
		Vi::Vec2d vel = mouse.velocity();
		if ((vel.x != 0.0) || (vel.y != 0.0))
			std::cout << "Cursor Velocity: x = " << vel.x << " y = " << vel.y << "\n";
	}

	if (keyboard.pressed(GLFW_KEY_W, GLFW_PRESS))
		std::cout << "W key Pressed\n";
	if (keyboard.pressed(GLFW_KEY_W, GLFW_RELEASE))
		std::cout << "W key Released\n";
	if (keyboard.pressing(GLFW_KEY_A))
		std::cout << "A Button Being Held Down\n";
}

static void debugGui(Vi::Window& window, Vi::Camera& camera) {
	Vi::Vec2i screen_size = window.size();
	ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
	ImGui::SetNextWindowSize(ImVec2(500, screen_size.y), ImGuiCond_Always);
	ImGui::Begin(
		"stats for nerds",
		nullptr,
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoTitleBar
	);
	ImGui::Text("Camera Position");
	ImGui::Text("x: %f", camera.position.x);
	ImGui::Text("y: %f", camera.position.y);
	ImGui::Text("z: %f", camera.position.z);
	ImGui::End();
}

static void controlCamera(Vi::Camera& camera) {
	constexpr double speed = 0.001;
	Vi::Mouse& mouse = Vi::Mouse::getMouse();

	if (mouse.pressing(GLFW_MOUSE_BUTTON_LEFT)) {
		Vi::Vec3d up = Vi::Vec3d(0.0, 1.0, 0.0);
		Vi::Quaternion rot_up = Vi::Math::rotationQuaternion(up, (double)mouse.velocity().x * -speed);
		camera.orientation = rot_up * camera.orientation;
		Vi::Vec3d right = camera.rightDirection();
		Vi::Quaternion rot_right = Vi::Math::rotationQuaternion(right, (double)mouse.velocity().y * -speed);
		camera.orientation = rot_right * camera.orientation;
	}

	camera.position = camera.forwardDirection() * 2.0;
}

