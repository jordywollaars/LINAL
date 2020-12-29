#include "Projectile.hpp"

Projectile::Projectile(Vector3<double> position, std::vector<Vector3<double>> localAxis)
{
	this->setSphereRenderObject(0);

	this->transformObject(Matrix<double>::getTranslationMatrix(position.x, position.y, position.z));
	this->localAxis = localAxis;
}

void Projectile::update()
{
	Matrix<double> translationMatrixForward = Matrix<double>::getTranslationMatrix(-this->getLocalZAxis().x, -this->getLocalZAxis().y, -this->getLocalZAxis().z);
	this->transformObject(translationMatrixForward);
}
