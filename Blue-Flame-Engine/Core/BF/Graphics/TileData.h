#pragma once
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		struct BFE_API TileData
		{
			int textureID;
			BF::Math::Rectangle rectangle;
			BF::Math::Rectangle scissorRectangle;
		};
	}
}