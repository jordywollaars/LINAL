#include "Target.hpp"

void Target::update()
{
	counter++;

	if (counter > counterTarget)
	{
		counter = 0;
		shrink = !shrink;
	}

	//Scaling
	if (!shrink)
	{
		Matrix<double> toOrigin = Matrix<double>::getTranslationMatrix(this->getPivot().x, this->getPivot().y, this->getPivot().z);
		Matrix<double> upscaleMatrix = Matrix<double>::getScalingMatrix(1.01, 1.01, 1.01);
		Matrix<double> back = Matrix<double>::getTranslationMatrix(-this->getPivot().x, -this->getPivot().y, -this->getPivot().z);
		this->transformObject(toOrigin * upscaleMatrix * back);
	}
	else
	{
		Matrix<double> toOrigin = Matrix<double>::getTranslationMatrix(this->getPivot().x, this->getPivot().y, this->getPivot().z);
		Matrix<double> upscaleMatrix = Matrix<double>::getScalingMatrix(.99, .99, .99);
		Matrix<double> back = Matrix<double>::getTranslationMatrix(-this->getPivot().x, -this->getPivot().y, -this->getPivot().z);
		this->transformObject(toOrigin * upscaleMatrix * back);
	}
}
