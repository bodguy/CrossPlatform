#version 430 core

layout (local_size_x = 3) in;

layout (std430, binding = 0) readOnly buffer buffer_InPos {
	vec2 InPos[];
};

layout (std430, binding = 0) writeOnly buffer buffer_OutPos {
	vec2 OutPos[];
};

void main() {
	OutPos[gl_GlobalInvocationID.x] = InPos[gl_GlobalInvocationID.x];
}
