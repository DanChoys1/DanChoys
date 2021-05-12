#include <cmath>

#include "ImageWorkClass.h"

ImageWork::ImageWork(Image^ mainImage, Image^ watermark) {
	_mainImage = gcnew Bitmap(mainImage);
		
	const bool isMainImageBigger = (mainImage->Width >= watermark->Width) && (mainImage->Height >= watermark->Height);
	double imageRatio = mainImage->Width / static_cast<double>(watermark->Width);

	if (isMainImageBigger) {

		_watermark = gcnew Bitmap(watermark);

	} else if ((watermark->Height * imageRatio) <= mainImage->Height) {

		int newWidth = mainImage->Width;
		int newHeight = static_cast<int>(watermark->Height * imageRatio);

		if ((newWidth != 0) && (newHeight != 0)) {
			_watermark = gcnew Bitmap(watermark, newWidth, newHeight);
		}

	} else {
		imageRatio = mainImage->Height / static_cast<double>(watermark->Height);

		int newHeight = mainImage->Height;
		int newWidth = static_cast<int>(watermark->Width * imageRatio);

		if ((newWidth != 0) && (newHeight != 0)) {
			_watermark = gcnew Bitmap(watermark, newWidth, newHeight);
		}

	}

	if (_watermark != nullptr) {
		_originalWatermark = gcnew Bitmap(_watermark);

		_resultingImage = gcnew Bitmap(_mainImage);
		Graphics^ imageGraphics = Graphics::FromImage(_resultingImage);

		imageGraphics->DrawImage(_resultingImage, 0, 0);
		imageGraphics->DrawImage(_watermark, 0, 0);
	}
}

void ImageWork::changePositionWatermark(int x, int y) {
	_x = x;
	_y = y;
	_resultingImage = gcnew Bitmap(_mainImage);
	Graphics^ imageGraphics = Graphics::FromImage(_resultingImage);

	imageGraphics->DrawImage(_resultingImage, 0, 0);
	imageGraphics->DrawImage(_watermark, _x, _y);

}

void ImageWork::changeTransparencyWatermark(int transparency) {
	_alpha = abs(transparency);

	for (int x = 0; x < _watermark->Width; x++) {

		for (int y = 0; y < _watermark->Height; y++) {

			Color watermarkPixel = _watermark->GetPixel(x, y);
			watermarkPixel = Color::FromArgb(_alpha, watermarkPixel);
			_watermark->SetPixel(x, y, watermarkPixel);

		}

	}

	changePositionWatermark(_x, _y);
}

void ImageWork::changeSizeWatermark(int newSize) {
	int width = 0;
	int height = 0;
	double imageRatio = _mainImage->Width / static_cast<double>(_originalWatermark->Width);

	if ((_originalWatermark->Height * imageRatio) < _mainImage->Height) {

		width = static_cast<int>(_mainImage->Width * (newSize * 0.01));
		height = static_cast<int>((_originalWatermark->Height * imageRatio) * (newSize * 0.01));

		while ((width == 0) || (height == 0)) {
			newSize++;
			width = static_cast<int>(_mainImage->Width * (newSize * 0.01));
			height = static_cast<int>((_originalWatermark->Height * imageRatio) * (newSize * 0.01));
		}

	} else {

		imageRatio = _mainImage->Height / static_cast<double>(_originalWatermark->Height);
		height = static_cast<int>(_mainImage->Height * (newSize * 0.01));
		width = static_cast<int>((_originalWatermark->Width * imageRatio) * (newSize * 0.01));
		
		while ((width == 0) || (height == 0)) {
			newSize++;
			height = static_cast<int>(_mainImage->Height * (newSize * 0.01));
			width = static_cast<int>((_originalWatermark->Width * imageRatio) * (newSize * 0.01));
		}

	}

	_watermark = gcnew Bitmap(_originalWatermark, width, height);

	changeTransparencyWatermark(_alpha);	
}

Bitmap^ ImageWork::getMainImage(void) {
	return _mainImage;
}

int ImageWork::getHeightMainImage(void) {
	return _mainImage->Height;
}

int ImageWork::getWidthMainImage(void) {
	return _mainImage->Width;
}

Bitmap^ ImageWork::getWatermark(void) {
	return _watermark;
}

int ImageWork::getHeightWatermark(void) {
	return _watermark->Height;
}

int ImageWork::getWidthWatermark(void) {
	return _watermark->Width;
}

Bitmap^ ImageWork::getOriginalWatermark(void) {
	return _originalWatermark;
}

int ImageWork::getHeightOriginalWatermark(void) {
	return _originalWatermark->Height;
}

int ImageWork::getWidthOriginalWatermark(void) {
	return _originalWatermark->Width;
}
	
Bitmap^ ImageWork::getResultingImage(void) {
	return _resultingImage;
}

int ImageWork::getHeightResultingImage(void) {
	return _resultingImage->Height;
}

int ImageWork::getWidthResultingImage(void) {
	return _resultingImage->Width;
}
