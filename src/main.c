#include <stdio.h>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#define VERSION "0.0.0-dev"

void GLFW_error_callback(int error, const char* description) {
	fprintf(stderr, "GLFW error %d: %s\n", code, description);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void CCraft_error(const char* description) {
	fprintf(stderr, "Error: %s\n", description);
}

int main(void) {
	printf(
"--------------------------------------------------------------------------------\n"
"------------------------------- CCraft "VERSION" -------------------------------\n"
"--------------------------------------------------------------------------------\n");

	/* Initialize GLFW */
	if (!glfwInit()) {
		CCraft_error(stderr, "Initialization failed.");
	}

	/* Setup callbacks */
	glfwSetErrorCallback(GLFW_error_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	/*  */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	GLFWwindow* window = glfwCreateWindow(640, 480, "CCraft - Minecraft compatible clone written in C99.", NULL, NULL);
	if (!window) {
		GLFW_error_callback(0, "Window or OpenGL context creation failed.");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader(GLADloadproc)glfwGetProcAddress) {
		CCraft_error("Failed to initalize GLAD");
		return 1;
	}
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	while (!glfwWindowShouldClose(window)) {
		
	}
	glfwDestroyWindow(window);
	glfwTerminate();
    return 0;
}
