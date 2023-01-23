#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>

#include "logging.h"
#include "window.h"

#define VERSION "0.0.0-dev"

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if ((key    == GLFW_KEY_ESCAPE ||
		 key    == GLFW_KEY_Q) && 
		 action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

int main(void) {
	printf(
"--------------------------------------------------------------------------------\n"
"------------------------------- CCraft "VERSION" -------------------------------\n"
"--------------------------------------------------------------------------------\n");

#ifdef CCRAFT_DEBUG /* Testing alignment */
	CCraft_info("Test CCraft info message");
	CCraft_debug("Test CCraft debug message");
	CCraft_warn("Test CCraft warn message");
	CCraft_error("Test CCraft error message");
	GLFW_error_callback(-1, "Test GLFW error message - faked callback");
	GLAD_error("Test GLAD error message");
#endif

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
	GLFWwindow *window = glfwCreateWindow(640, 480, "CCraft - Minecraft compatible clone written in C99.", NULL, NULL);
	if (!window) {
		GLFW_error_callback(0, "Window creation failed.");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);

	/* Setup callbacks */
	glfwSetErrorCallback(GLFW_error_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);

	/* GLAD fetches and loads supported OpenGL functions */
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		CCraft_error("Failed to initalize GLAD.");
		return 1;
	}

	/* Set window size */
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	/* Render loop */
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	/* Cleanup */
	glfwDestroyWindow(window);
	glfwTerminate();
    return 0;
}
