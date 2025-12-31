#include <GLFW/glfw3.h>

int main() {
    GLFWwindow* window;

    // Initialize GLFW Library
    if (!glfwInit()) {
        return -1;
    }

    // Actually make the window
    window = glfwCreateWindow(1280, 720, "Renderer Window", NULL, NULL);

    // Verify window creation and terminate GLFW if error
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Create OpenGL context for window
    glfwMakeContextCurrent(window);

    // Actual draw/refresh body to fill in later
    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}