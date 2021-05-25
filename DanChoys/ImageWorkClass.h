#pragma once

using namespace System;
using namespace System::Drawing;

public ref class ImageWork {
	Bitmap^ _resultingImage = nullptr;
	Bitmap^ _mainImage = nullptr;
	String^ _mainImagePath = nullptr;
	Bitmap^ _watermark = nullptr;
	String^ _watermarkImagePath = nullptr;
	array<bool, 2>^ _transparencyPixel = nullptr;
	int _alpha = 255;
	int _x = 0;
	int _y = 0;
	int _newWidthWatermark = 0;
	int _newHeightWatermark = 0;

public:
	ImageWork(Image^ mainImage, String^ mainImagePath, Image^ watermark, String^ watermarkImagePath);

	void changePositionWatermark(int x, int y);

	void changeTransparencyWatermark(int transparency);

	void changeSizeWatermark(int newSize);

	String^ getMainImagePath(void);

	int getHeightMainImage(void);

	int getWidthMainImage(void);

	Bitmap^ getWatermark(void);

	String^ getWatermarkImagePath(void);

	int getHeightWatermark(void);

	int getWidthWatermark(void);
	
	Bitmap^ getResultingImage(void);
};