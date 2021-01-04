#include "Projectile.hpp"
#include "Target.hpp"

#include "Spaceship.hpp"

Projectile::Projectile(Vector3<double> position, std::vector<Vector3<double>> localAxis, Scene& scene) : BoundingBox(this->getVertices()), scene{ scene }
{
	this->setSphereRenderObject(0);

	this->transformObject(Matrix<double>::getTranslationMatrix(position.x, position.y, position.z));
	this->localAxis = localAxis;
}

void Projectile::update(double deltaTime)
{
	Matrix<double> translationMatrixForward = Matrix<double>::getTranslationMatrix(-this->getLocalZAxis().x * speed * deltaTime, -this->getLocalZAxis().y * speed * deltaTime, -this->getLocalZAxis().z * speed * deltaTime);
	this->transformObject(translationMatrixForward);

	lifeTimeInSeconds -= deltaTime;
	if (lifeTimeInSeconds <= 0)
	{
		scene.queueForDestruction(this);
	}
}

void Projectile::onCollision(BoundingBox* other)
{
	if (lifeTimeInSeconds > 0)
	{
		if (dynamic_cast<Spaceship*>(other) || dynamic_cast<Projectile*>(other))
		{
			return;
		}

		GameObject* go = dynamic_cast<Target*>(other);

		if (go)
		{
			scene.queueForDestruction(go);
		}

		scene.queueForDestruction(this);
	}
}
