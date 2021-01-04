#include "Spaceship.hpp"

#include "Matrix.hpp"
#include "Vector3.hpp"
#include "Projectile.hpp"

Spaceship::Spaceship(InputHandler& inputHandler, Scene& scene) : BoundingBox(this->getVertices()), inputHandler{ inputHandler }, scene{scene}
{
	this->setSphereRenderObject(0);

	Matrix<double> toOrigin = Matrix<double>::getTranslationMatrix(this->getPivot().x, this->getPivot().y, this->getPivot().z);
	Matrix<double> upscaleMatrix = Matrix<double>::getScalingMatrix(4, 4, 4);
	Matrix<double> back = Matrix<double>::getTranslationMatrix(-this->getPivot().x, -this->getPivot().y, -this->getPivot().z);
	this->transformVertices(toOrigin* upscaleMatrix* back);
}

void Spaceship::shoot()
{
	this->scene.add(new Projectile(this->getPivot(), this->getLocalAxis(), this->scene));
}

void Spaceship::update(double deltaTime)
{
	//Shooting
	if (inputHandler.keyDown(sf::Keyboard::Key::Space))
	{
		shoot();
	}

	//Movement
	if (inputHandler.keyHold(sf::Keyboard::Key::LShift))
	{
		Matrix<double> translationMatrixForward = Matrix<double>::getTranslationMatrix(-this->getLocalZAxis().x * moveSpeed * deltaTime, -this->getLocalZAxis().y * moveSpeed * deltaTime, -this->getLocalZAxis().z * moveSpeed * deltaTime);
		this->transformObject(translationMatrixForward);
	}

	//Rotating
	if (inputHandler.keyHold(sf::Keyboard::Key::Q))
	{
		Matrix<double> m = this->rotationMatrix(this->getLocalZAxis(), this->getPivot(), 1 * rotationSpeed * deltaTime);

		this->transformObject(m);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::E))
	{
		Matrix<double> m = this->rotationMatrix(this->getLocalZAxis(), this->getPivot(), -1 * rotationSpeed * deltaTime);

		this->transformObject(m);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::W))
	{
		Matrix<double> m = this->rotationMatrix(this->getLocalXAxis(), this->getPivot(), 1 * rotationSpeed * deltaTime);

		this->transformObject(m);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::S))
	{
		Matrix<double> m = this->rotationMatrix(this->getLocalXAxis(), this->getPivot(), -1 * rotationSpeed * deltaTime);

		this->transformObject(m);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::A))
	{
		Matrix<double> m = this->rotationMatrix(this->getLocalYAxis(), this->getPivot(), 1 * rotationSpeed * deltaTime);

		this->transformObject(m);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::D))
	{
		Matrix<double> m = this->rotationMatrix(this->getLocalYAxis(), this->getPivot(), -1 * rotationSpeed * deltaTime);

		this->transformObject(m);
	}
}

void Spaceship::onCollision(BoundingBox* other)
{
	GameObject* go = dynamic_cast<Projectile*>(other);

	if (other != this && !go)
	{
		scene.queueForDestruction(this);
	}
}

Matrix<double> Spaceship::rotationMatrix(Vector3<double> rotationAxis, Vector3<double> centre, double degrees)
{
	Matrix<double> to = Matrix<double>::getTranslationMatrix(centre.x, centre.y, centre.z);
	Matrix<double> m1 = Matrix<double>::getRotationMatrixM1(rotationAxis);
	Matrix<double> m2 = Matrix<double>::getRotationMatrixM2(rotationAxis);
	Matrix<double> m3 = Matrix<double>::getRotationMatrixX(degrees);
	Matrix<double> m4 = Matrix<double>::getRotationMatrixM4(rotationAxis);
	Matrix<double> m5 = Matrix<double>::getRotationMatrixM5(rotationAxis);
	Matrix<double> back = Matrix<double>::getTranslationMatrix(-centre.x, -centre.y, -centre.z);

	Matrix<double> m = (((((to * m1) * m2) * m3) * m4) * m5) * back;

	return m;
}
