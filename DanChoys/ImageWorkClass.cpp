#include <cmath>

#include "ImageWorkClass.h"

ImageWork::ImageWork(Image^ mainImage, String^ mainImagePath, Image^ watermark, String^ watermarkImagePath) {
	_mainImage = gcnew Bitmap(mainImage);

	_mainImagePath = mainImagePath;
	_watermarkImagePath = watermarkImagePath;

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
		_newWidthWatermark = _watermark->Width;
		_newHeightWatermark = _watermark->Height;

		_transparencyPixel = gcnew array<bool, 2>(_watermark->Width, _watermark->Height);

		for (int x = 0; x < _watermark->Width; x++) {
			for (int y = 0; y < _watermark->Height; y++) {
				Color watermarkPixel = _watermark->GetPixel(x, y);

				if (watermarkPixel.A == 0) {
					_transparencyPixel[x, y] = true;
				} else {
					_transparencyPixel[x, y] = false;
				}

			}
		}

		changePositionWatermark(0, 0);
	}
}

void ImageWork::changePositionWatermark(int x, int y) {
	_x = x;
	_y = y;
	_resultingImage = gcnew Bitmap(_mainImage);
	Graphics^ imageGraphics = Graphics::FromImage(_resultingImage);

	imageGraphics->DrawImage(_resultingImage, 0, 0);
	imageGraphics->DrawImage(_watermark, _x, _y, _newWidthWatermark, _newHeightWatermark);
}

void ImageWork::changeTransparencyWatermark(int transparency) {
	_alpha = abs(transparency);

	for (int x = 0; x < _watermark->Width; x++) {
		for (int y = 0; y < _watermark->Height; y++) {

			if (!_transparencyPixel[x, y]) {
				Color watermarkPixel = _watermark->GetPixel(x, y);
				watermarkPixel = Color::FromArgb(_alpha, watermarkPixel);
				_watermark->SetPixel(x, y, watermarkPixel);
			}

		}
	}

	changePositionWatermark(_x, _y);
}

void ImageWork::changeSizeWatermark(int newSize) {
	double imageRatio = _mainImage->Width / static_cast<double>(_watermark->Width);
	const double percentageRatio = 0.01;

	if ((_watermark->Height * imageRatio) < _mainImage->Height) {
		_newWidthWatermark = static_cast<int>(_mainImage->Width * (newSize * percentageRatio));
		_newHeightWatermark = static_cast<int>((_watermark->Height * imageRatio) * (newSize * percentageRatio));

		while ((_newWidthWatermark == 0) || (_newHeightWatermark == 0)) {
			newSize++;
			_newWidthWatermark = static_cast<int>(_mainImage->Width * (newSize * percentageRatio));
			_newHeightWatermark = static_cast<int>((_watermark->Height * imageRatio) * (newSize * percentageRatio));
		}

	} else {
		imageRatio = _mainImage->Height / static_cast<double>(_watermark->Height);
		_newHeightWatermark = static_cast<int>(_mainImage->Height * (newSize * percentageRatio));
		_newWidthWatermark = static_cast<int>((_watermark->Width * imageRatio) * (newSize * percentageRatio));
		
		while ((_newWidthWatermark == 0) || (_newHeightWatermark == 0)) {
			newSize++;
			_newHeightWatermark = static_cast<int>(_mainImage->Height * (newSize * percentageRatio));
			_newWidthWatermark = static_cast<int>((_watermark->Width * imageRatio) * (newSize * percentageRatio));
		}

	}

	changePositionWatermark(_x, _y);
}

String^ ImageWork::getMainImagePath(void) {
	return _mainImagePath;
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

String^ ImageWork::getWatermarkImagePath(void) {
	return _watermarkImagePath;
}

int ImageWork::getHeightWatermark(void) {
	return _newHeightWatermark;
}

int ImageWork::getWidthWatermark(void) {
	return _newWidthWatermark;
}
	
Bitmap^ ImageWork::getResultingImage(void) {
	return _resultingImage;
}