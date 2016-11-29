#include "DXShader.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				using namespace BF::IO;

				DXShader::DXShader(const DXContext* context) :
					context(context), VS(nullptr), PS(nullptr), hr(0), VSData(nullptr), PSData(nullptr), VSsize(0), PSsize(0)
				{
				}

				DXShader::~DXShader()
				{
				}

				void DXShader::Load(const std::string& vertexShaderFilePath, const std::string& pixelShaderFilePath)
				{
					VSData = FileLoader::LoadBinaryFile(vertexShaderFilePath, &VSsize);
					PSData = FileLoader::LoadBinaryFile(pixelShaderFilePath, &PSsize);
					
					if (FAILED(hr = context->GetDevice()->CreateVertexShader(VSData, VSsize, 0, &VS)))
					{
						std::cout << hr << std::endl;
					}

					if (FAILED(hr = context->GetDevice()->CreatePixelShader(PSData, PSsize, 0, &PS)))
					{
						std::cout << hr << std::endl;
					}
				}

				void DXShader::Bind() const
				{
					context->GetContext()->VSSetShader(VS, 0, 0);
					context->GetContext()->PSSetShader(PS, 0, 0);
				}

				void DXShader::CleanUp() const
				{
					VS->Release();
					PS->Release();
				}
			}
		}
	}
}