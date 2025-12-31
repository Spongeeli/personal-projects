#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main() {
    GLFWwindow* window;

    // Initialize GLFW Library
    if (!glfwInit()) {
        return -1;
    }

    // Actually make the window
    window = glfwCreateWindow(1280, 720, "Renderer Window", nullptr, nullptr);

    // Verify window creation and terminate GLFW if error
    if (!window) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        glfwTerminate();
        return -1;
    }

    // Create OpenGL context for window
    glfwMakeContextCurrent(window);

    // Initalize GLEW Library
    glewExperimental = true;
    GLenum glewErr = glewInit();
    if (glewErr != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW: %s\n", glewGetErrorString(glewErr));
        glfwTerminate();
        return -1;
    }

    // Actual draw/refresh body to fill in later
    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}