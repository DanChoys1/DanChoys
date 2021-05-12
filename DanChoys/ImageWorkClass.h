#pragma once

using namespace System::Drawing;

ref class ImageWork {
	Bitmap^ _resultingImage = nullptr;
	Bitmap^ _mainImage = nullptr;
	Bitmap^ _watermark = nullptr;
	Bitmap^ _originalWatermark = nullptr;
	int _alpha = 255;
	int _x = 0;
	int _y = 0;

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

	Bitmap^ getOriginalWatermark(void);

	int getHeightOriginalWatermark(void);

	int getWidthOriginalWatermark(void);
	
	Bitmap^ getResultingImage(void);

	int getHeightResultingImage(void);

	int getWidthResultingImage(void);

};