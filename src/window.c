#include "window.h"

#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
}

void window_init() {
	/* Initialize GLFW */
	if (!glfwInit()) {
		CCraft_error("Initialization failed.");
	}

	/* Enforce minimum OpenGL version */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	/* Set OpenGL profile (core/compatibility) */
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__ /* MacOS need forward compatibility explicitly enabled */
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	/* Initialize window, exit if fail */
	*window = glfwCreateWindow(640, 480, "CCraft - Minecraft compatible clone written in C99.", NULL, NULL);
	if (!window) {
		GLFW_error_callback(0, "Window creation failed.");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);
}
