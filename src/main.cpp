//Assignment 02: Trandformations, viewing and projection

#include "utils.h"

int width=1280, height=720;

int main(int, char**)
{
    // Setup window
    GLFWwindow *window = setupWindow(width, height);
    ImGuiIO& io = ImGui::GetIO(); // Create IO object

    ImVec4 clearColor = ImVec4(0.0f, 0.0f, 0.0f, 1.00f);

    // unsigned int shaderProgram = createProgram("./shaders/vshader.vs", "./shaders/fshader.fs");
    // glUseProgram(shaderProgram);



    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // glUseProgram(shaderProgram);
        showOptionsDialog();
        showSceneWindow();

        // if (io.KeyCtrl){
        //     std::cout << "ctrl pressed" << std::endl;
        // }
        // int key = 'A';
        // if(io.KeysDown[key] && io.KeyShift){
        //     std::cout << "a " << std::endl;
        // }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        // glBindVertexArray(sphere_VAO); 

        // glDrawArrays(GL_TRIANGLES, 0, 36); //tri_points);//else tri_points   

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);

    }

    // Cleanup
    cleanup(window);

    return 0;
}

