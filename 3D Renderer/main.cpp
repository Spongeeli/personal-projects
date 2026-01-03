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
    // Found out that Wayland compositor system scaling bugs this out, will have to look into framebuffer
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

    // Current testing code (default triangle)
    std::cout << glGetString(GL_VERSION) << std::endl;

    const GLfloat triangleData[9] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    };

    GLuint bufferID;
    glGenBuffers(1, &bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangleData), triangleData, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (const void *) 0);
    
    // Actual draw/refresh body to fill in later
    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}