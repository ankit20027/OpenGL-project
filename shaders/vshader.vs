#version 330
layout (location = 0)in vec2 vVertex;

uniform mat4 vModel;
uniform mat4 vView;
uniform mat4 vProjection;
uniform vec3 vColor;

// float spec_exp = 4.0;

out vec4 fragColor;


void main(){

    gl_Position = vProjection * vView * vModel * vec4(vVertex, 0.0, 1.0);
    fragColor =vec4(vColor,1.0f);
	
}
