//============================================================================
// Name        : Opengl_Eclipse.cpp
// Author      : lxd
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//const variables
const GLuint WIDTH = 800, HEIGHT = 600;
const GLchar* WINDOW_TITLE = "LearnOpenGL";

using namespace std;

// 窗口变化的Callback
void framebuffer_size_changed(GLFWwindow* window, int width, int height);
// 按键事件的响应函数
void processKeyEvent(GLFWwindow* window);

int main() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //开启兼容模式
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    GLFWwindow * window = glfwCreateWindow(WIDTH, HEIGHT, WINDOW_TITLE, nullptr, nullptr);
    if (window == nullptr) {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    } else {
        cout << "Window Create Success!!!" << endl;
        glfwMakeContextCurrent(window); //非常重要，没有这句就绘制不出效果了
        glfwSetFramebufferSizeCallback(window, framebuffer_size_changed);
    }

    //OpenGL绘制区域
    glViewport(0, 0, WIDTH / 2, HEIGHT / 2);

    while (!glfwWindowShouldClose(window)) {
        // 检查key事件
        processKeyEvent(window);

        // rendering
        glClearColor(1.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    cout << "glfwTerminate" << endl;
    glfwTerminate();
	return 0;
}

void framebuffer_size_changed(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width / 2, height / 2);
}

void processKeyEvent(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
