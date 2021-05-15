#pragma once

using namespace System::Drawing;

ref class ImageWork {
	Bitmap^ _resultingImage = nullptr;
	Bitmap^ _mainImage = nullptr;
	Bitmap^ _watermark = nullptr;
	array<bool, 2>^ _transparencyPixel = nullptr;
	int _alpha = 255;
	int _x = 0;
	int _y = 0;
	int _newWidthWatermark = 0;
	int _newHeightWatermark = 0;

public:
	ImageWork(Image^ mainImage, Image^ watermark);

	void changePositionWatermark(int x, int y);

	void changeTransparencyWatermark(int transparency);

	void changeSizeWatermark(int newSize);

	Bitmap^ getMainImage(void);

	int getHeightMainImage(void);

	int getWidthMainImage(void);

	Bitmap^ getWatermark(void);

	int getHeightWatermark(void);

	int getWidthWatermark(void);
	
	Bitmap^ getResultingImage(void);

	int getHeightResultingImage(void);

	int getWidthResultingImage(void);
};