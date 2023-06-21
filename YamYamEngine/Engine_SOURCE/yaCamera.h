#pragma once
#include "yaComponent.h"
#include "yaGraphics.h"

namespace ya
{
	class Camera : public Component
	{
	public:
		Camera();
		~Camera();

	private:
		static Matrix mView;
		static Matrix mProjection;
	};
}
