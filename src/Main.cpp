//Assignment 02: Trandformations, viewing and projection

#include "fun.h"

int width = 640, height=640;
// #define DIVISIONS 100
// #define PI 3.14
void createCircle(unsigned int &program, unsigned int &circle_VAO, float x, float y, float r, int num_segments);

int main(int, char**)
{
    // Setup window
    GLFWwindow *window = setupWindow(width, height);
    ImGuiIO& io = ImGui::GetIO(); // Create IO object

    ImVec4 clearColor = ImVec4(0.0f, 0.0f, 0.0f, 1.00f);

    unsigned int shaderProgram = createProgram("./shaders/vshader.vs", "./shaders/fshader.fs");
    glUseProgram(shaderProgram);

    setupModelTransformation(shaderProgram);
    setupViewTransformation(shaderProgram);
    setupProjectionTransformation(shaderProgram, width , height);
    
    // int vVertex_attrib = glGetAttribLocation(shaderProgram, "vVertex");
    // if(vVertex_attrib == -1) {
    //     std::cout << "Could not bind location: vVertex\n" ;
    //     exit(0);
    // }else{
    //     std::cout << "vVertex found at location " << vVertex_attrib << std::endl;
    // }

  	// static const GLfloat vertices[] = {
    //     0.5f,  0.5f,    // triangle 1 : begin
    //     -0.5f,  0.5f, 
    //     0.5f, -0.5f,    // triangle 1 : end
    //     -0.5f, -0.5f,   //2 begin
    //     0.5f, -0.5f,  
    //     -0.5f,  0.5f,   //2 end
    // };
    
    glUseProgram(shaderProgram);
    GLuint scene_VAO;
    glGenVertexArrays(1, &scene_VAO);
    glBindVertexArray(scene_VAO);
///////////////////////////////////////
        // glUseProgram(program);
    //Bind shader variables
    int num_segments= 1000, x=40, y = 2, r = 10;
    int vVertex_attrib = glGetAttribLocation(shaderProgram, "vVertex");
    if(vVertex_attrib == -1) {
        fprintf(stderr, "Could not bind location: vVertex\n");
        exit(0);
    }
    GLfloat circle_vertices[num_segments+1][2];
    for (int i = 0; i < num_segments+1; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle
        circle_vertices[i][0] = x + r*cosf(theta);
        circle_vertices[i][1] = y + r*sinf(theta);
    }

    // GLfloat cube_colors[] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1}; //Unique face colors

    //Generate VAO object
    glGenVertexArrays(1, &scene_VAO);
    glBindVertexArray(scene_VAO);

    //Create VBOs for the VAO
    //Position information (data + format)
    int nVertices = num_segments*3; //(num faces) * (1 triangles each) * (3 vertices each)
    GLfloat *expanded_vertices = new GLfloat[nVertices*2];
    for(int i=0; i<num_segments; i++) {
        expanded_vertices[i*2] = circle_vertices[i][0];
        expanded_vertices[i*2+1] = circle_vertices[i][1];
        expanded_vertices[i*2+2] = x;
        expanded_vertices[i*2+3] = y;
        expanded_vertices[i*2+4] = circle_vertices[i+1][0];
        expanded_vertices[i*2+5] = circle_vertices[i+1][1];
    }
    // delete []circle_vertices;

    GLuint vertex_VBO;
    glGenBuffers(1, &vertex_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_VBO);
    glBufferData(GL_ARRAY_BUFFER, nVertices*2*sizeof(GLfloat), expanded_vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(vVertex_attrib);
    glVertexAttribPointer(vVertex_attrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    // createCircle(shaderProgram, scene_VAO, 400, 400, 10, 1000);

    // GLuint vertex_VBO;
    // glGenBuffers(1, &vertex_VBO);
    // glBindBuffer(GL_ARRAY_BUFFER, vertex_VBO);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(expanded_vertices), expanded_vertices, GL_STATIC_DRAW); //else tri_points
    // glEnableVertexAttribArray(static_cast<uint>(vVertex_attrib));
    // glVertexAttribPointer(static_cast<uint>(vVertex_attrib), 2, GL_FLOAT, GL_FALSE, 0, nullptr);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

//    float angle = 0.0f;
//    GLfloat matrix[] = {
//     1.0f, 0.0f, 0.0f, 0.0f, // first column
//     0.0f, 1.0f, 0.0f, 0.0f, // second column
//     0.0f, 0.0f, 1.0f, 0.0f,// third column
//      0.0f, 0.0f, 0.0f, 1.0f
//     };

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        glUseProgram(shaderProgram);
        showOptionsDialog(shaderProgram);

        if (io.KeyCtrl){
            std::cout << "ctrl pressed" << std::endl;
        }
        int key = 'A';
        if(io.KeysDown[key] && io.KeyShift){
            std::cout << "a " << std::endl;
        }

        if( ImGui::IsKeyPressed('O')) {
            std::cout << "o" << std::endl;
        }

        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Information");                          
            ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        glBindVertexArray(scene_VAO); 
        glDrawArrays(GL_TRIANGLES, 0, 3003); //tri_points);//else tri_points   

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);

    }

    // Cleanup
    cleanup(window);

    return 0;
}

void createCircle(unsigned int &program, unsigned int &circle_VAO, float x, float y, float r, int num_segments) {
    glUseProgram(program);
    //Bind shader variables
    int vVertex_attrib = glGetAttribLocation(program, "vVertex");
    if(vVertex_attrib == -1) {
        fprintf(stderr, "Could not bind location: vVertex\n");
        exit(0);
    }
    int vColor_attrib = glGetAttribLocation(program, "vColor");
    if(vColor_attrib == -1) {
        fprintf(stderr, "Could not bind location: vColor\n");
        exit(0);
    }
    GLfloat circle_vertices[num_segments+1][2];
    for (int i = 0; i < num_segments+1; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle
        circle_vertices[i][0] = x + r*cosf(theta);
        circle_vertices[i][1] = y + r*sinf(theta);
    }

    // GLfloat cube_colors[] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1}; //Unique face colors

    //Generate VAO object
    glGenVertexArrays(1, &circle_VAO);
    glBindVertexArray(circle_VAO);

    //Create VBOs for the VAO
    //Position information (data + format)
    int nVertices = num_segments*3; //(num faces) * (1 triangles each) * (3 vertices each)
    GLfloat *expanded_vertices = new GLfloat[nVertices*2];
    for(int i=0; i<num_segments; i++) {
        expanded_vertices[i*2] = circle_vertices[i][0];
        expanded_vertices[i*2+1] = circle_vertices[i][1];
        expanded_vertices[i*2+2] = x;
        expanded_vertices[i*2+3] = y;
        expanded_vertices[i*2+4] = circle_vertices[i+1][0];
        expanded_vertices[i*2+5] = circle_vertices[i+1][1];
    }
    // delete []circle_vertices;

    GLuint vertex_VBO;
    glGenBuffers(1, &vertex_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_VBO);
    glBufferData(GL_ARRAY_BUFFER, nVertices*2*sizeof(GLfloat), expanded_vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(vVertex_attrib);
    glVertexAttribPointer(vVertex_attrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
    delete []expanded_vertices;

    // //Color - one for each face
    // GLfloat *expanded_colors = new GLfloat[nVertices*3];
    // for(int i=0; i<nVertices; i++) {
    //     int color_index = i / 6;
    //     expanded_colors[i*3] = cube_colors[color_index*3];
    //     expanded_colors[i*3+1] = cube_colors[color_index*3+1];
    //     expanded_colors[i*3+2] = cube_colors[color_index*3+2];
    // }
    // GLuint color_VBO;
    // glGenBuffers(1, &color_VBO);
    // glBindBuffer(GL_ARRAY_BUFFER, color_VBO);
    // glBufferData(GL_ARRAY_BUFFER, nVertices*3*sizeof(GLfloat), expanded_colors, GL_STATIC_DRAW);
    // glEnableVertexAttribArray(vColor_attrib);
    // glVertexAttribPointer(vColor_attrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
    // delete []expanded_colors;

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0); //Unbind the VAO to disable changes outside this function.
}