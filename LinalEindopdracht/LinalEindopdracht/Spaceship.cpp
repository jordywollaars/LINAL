#include "Spaceship.hpp"

#include "Matrix.hpp"
#include "Vector3.hpp"
#include "Projectile.hpp"

Spaceship::Spaceship(InputHandler& inputHandler, Scene& scene, Camera& camera) : BoundingBox(this->getVertices()), inputHandler{ inputHandler }, scene{ scene }, camera{ camera }
{
	this->setShipRenderObject();
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
	if (inputHandler.keyHold(sf::Keyboard::Key::Q)) //Roll left
	{
		Matrix<double> m = Matrix<double>::rotationMatrix(this->getLocalZAxis(), this->getPivot(), rotationSpeed * deltaTime);

		this->transformObject(m);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::E)) //Roll right
	{
		Matrix<double> m = Matrix<double>::rotationMatrix(this->getLocalZAxis(), this->getPivot(), -rotationSpeed * deltaTime);

		this->transformObject(m);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::W)) //Rotate forward
	{
		Matrix<double> m = Matrix<double>::rotationMatrix(this->getLocalXAxis(), this->getPivot(), -rotationSpeed * deltaTime);

		this->transformObject(m);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::S)) //Rotate Backward
	{
		Matrix<double> m = Matrix<double>::rotationMatrix(this->getLocalXAxis(), this->getPivot(), rotationSpeed * deltaTime);

		this->transformObject(m);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::A)) //Rotate sideways left
	{
		Matrix<double> m = Matrix<double>::rotationMatrix(this->getLocalYAxis(), this->getPivot(), rotationSpeed * deltaTime);

		this->transformObject(m);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::D)) //Rotate sideways right
	{
		Matrix<double> m = Matrix<double>::rotationMatrix(this->getLocalYAxis(), this->getPivot(), -rotationSpeed * deltaTime);

		this->transformObject(m);
	}

	//Shooting
	if (inputHandler.keyDown(sf::Keyboard::Key::Space))
	{
		shoot(currentSpeed);
	}

	//Toggle camera look at
	if (inputHandler.keyDown(sf::Keyboard::Key::L))
	{
		this->lookAt = !this->lookAt;
	}

	if (this->lookAt)
	{
		camera.setLookAtPosition(this->getPivot());
	}
}

void Spaceship::onCollision(BoundingBox* other)
{
	GameObject* go = dynamic_cast<Projectile*>(other);

	if (!go)
	{
		scene.queueForDestruction(this);
	}
}
