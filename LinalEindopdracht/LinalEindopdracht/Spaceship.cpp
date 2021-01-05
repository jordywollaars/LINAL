#include "Spaceship.hpp"

#include "Matrix.hpp"
#include "Vector3.hpp"
#include "Projectile.hpp"

Spaceship::Spaceship(InputHandler& inputHandler, Scene& scene) : BoundingBox(this->getVertices()), inputHandler{ inputHandler }, scene{scene}
{
	this->setShipRenderObject();

	//Matrix<double> toOrigin = Matrix<double>::getTranslationMatrix(this->getPivot().x, this->getPivot().y, this->getPivot().z);
	//Matrix<double> upscaleMatrix = Matrix<double>::getScalingMatrix(4, 4, 4);
	//Matrix<double> back = Matrix<double>::getTranslationMatrix(-this->getPivot().x, -this->getPivot().y, -this->getPivot().z);
	//this->transformVertices(toOrigin* upscaleMatrix* back);
}

void Spaceship::shoot(double relativeSpeed)
{
	this->scene.add(new Projectile(this->getPivot(), this->getLocalAxis(), this->scene, relativeSpeed));
}

void Spaceship::update(double deltaTime)
{
	double currentSpeed = 0;

	//Movement
	if (inputHandler.keyHold(sf::Keyboard::Key::LShift))
	{
		Matrix<double> translationMatrixForward = Matrix<double>::getTranslationMatrix(-this->getLocalZAxis().x * moveSpeed * deltaTime, -this->getLocalZAxis().y * moveSpeed * deltaTime, -this->getLocalZAxis().z * moveSpeed * deltaTime);
		this->transformObject(translationMatrixForward);

		currentSpeed = moveSpeed;
	}

	//Rotating
	if (inputHandler.keyHold(sf::Keyboard::Key::Q))
	{
		Matrix<double> m = Matrix<double>::rotationMatrix(this->getLocalZAxis(), this->getPivot(), rotationSpeed * deltaTime);

		this->transformObject(m);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::E))
	{
		Matrix<double> m = Matrix<double>::rotationMatrix(this->getLocalZAxis(), this->getPivot(), -rotationSpeed * deltaTime);

		this->transformObject(m);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::W))
	{
		Matrix<double> m = Matrix<double>::rotationMatrix(this->getLocalXAxis(), this->getPivot(), rotationSpeed * deltaTime);

		this->transformObject(m);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::S))
	{
		Matrix<double> m = Matrix<double>::rotationMatrix(this->getLocalXAxis(), this->getPivot(), -rotationSpeed * deltaTime);

		this->transformObject(m);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::A))
	{
		Matrix<double> m = Matrix<double>::rotationMatrix(this->getLocalYAxis(), this->getPivot(), -rotationSpeed * deltaTime);

		this->transformObject(m);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::D))
	{
		Matrix<double> m = Matrix<double>::rotationMatrix(this->getLocalYAxis(), this->getPivot(), rotationSpeed * deltaTime);

		this->transformObject(m);
	}

	//Shooting
	if (inputHandler.keyDown(sf::Keyboard::Key::Space))
	{
		shoot(currentSpeed);
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
