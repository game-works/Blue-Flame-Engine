#include <emscripten.h>
#include "../../Core/BF/Application/Window.h"
#include "../../Core/BF/Graphics/API/Context.h"
#include "../../Core/BF/Graphics/API/VertexBuffer.h"
#include "../../Core/BF/Graphics/API/Shader.h"
#include "../../Core/BF/Graphics/API/Texture2D.h"
#include "../../Core/BF/Math/Math.h"

struct Vertex
{
	BF::Math::Vector3 position;
	BF::Math::Vector4 color;
	BF::Math::Vector2 UV;
};

Vertex tri1Vertices[3];

BF::Graphics::API::Context *context;
BF::Graphics::API::VertexBuffer *buffer;
BF::Graphics::API::Texture2D *texture2D;

void one_iter()
{
	context->Clear(BF::Math::Vector4(1.0f, 0.0f, 1.0f, 1.0f));
	buffer->Bind();
	context->Draw(3);
	buffer->Unbind();
	context->SwapBuffers();
}

int main()
{
	BF::Application::Window window("", 0, 0, 0, 0, BF::Application::WindowStyle::Fullscreen);
	context = new BF::Graphics::API::Context(&window, BF::Graphics::API::RenderAPI::OpenGL);
	BF::Graphics::API::Shader shader(context);
	buffer = new BF::Graphics::API::VertexBuffer(context, &shader);
	BF::Graphics::API::BufferLayout bufferLayout;
	texture2D = new BF::Graphics::API::Texture2D(context);

	tri1Vertices[0].position = BF::Math::Vector3(1.0f, -1.0f, 0.0f);
	tri1Vertices[0].color = BF::Math::Vector4(1.0f, 0.0f, 0.0f, 1.0f);
	tri1Vertices[0].UV = BF::Math::Vector2(2.0f, 2.0f);

	tri1Vertices[1].position = BF::Math::Vector3(-1.0f, -1.0f, 0.0f);
	tri1Vertices[1].color = BF::Math::Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	tri1Vertices[1].UV = BF::Math::Vector2(2.0f, 0.0f);

	tri1Vertices[2].position = BF::Math::Vector3(-1.0f, 1.0f, 0.0f);
	tri1Vertices[2].color = BF::Math::Vector4(0.0f, 0.0f, 1.0f, 1.0f);
	tri1Vertices[2].UV = BF::Math::Vector2(0.0f, 2.0f);

	texture2D->Load("./Sandbox/test.png");

	shader.Load("./Sandbox/VertexShader.glsl", "./Sandbox/FragmentShader.glsl");

	shader.Bind();
	buffer->Create(tri1Vertices, sizeof(tri1Vertices));

	bufferLayout.Push(0, "POSITION", BF::Graphics::API::DataType::Float3, sizeof(Vertex), 0);
	bufferLayout.Push(1, "COLOR", BF::Graphics::API::DataType::Float4, sizeof(Vertex), 3 * sizeof(float));
	bufferLayout.Push(2, "TEXCOORD", BF::Graphics::API::DataType::Float2, sizeof(Vertex), (3 * sizeof(float)) + (4 * sizeof(float)));

	context->SetPrimitiveType(BF::Graphics::API::PrimitiveType::TriangleList);

	buffer->SetLayout(&bufferLayout);

	emscripten_set_main_loop(one_iter, 0, 1);

	return 0;
}