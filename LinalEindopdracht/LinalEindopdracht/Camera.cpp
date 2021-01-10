#include "Camera.hpp"

Camera::Camera(Vector3<double> eyePosition, Vector3<double> lookAtPosition, Scene& scene, InputHandler& inputHandler) : scene{ scene }, inputHandler{ inputHandler }
{
	this->near = 0.1;
	this->far = 1000.0;
	this->fovy = 90.0;
	this->scale = near * std::tan(fovy * 0.5);

	this->eyePosition = eyePosition;
	this->lookAtPosition = lookAtPosition;

	this->direction = eyePosition - lookAtPosition;
	this->direction.normalize();
	this->right = Vector3<double>::crossProduct(this->up, this->direction);
	this->right.normalize();
	this->up = Vector3<double>::crossProduct(this->direction, this->right);
	this->up.normalize();
}

Matrix<double> Camera::getInverse()
{
	Matrix<double> inverse = Matrix<double>(4, 4);

	inverse(0, 0) = this->right.x;
	inverse(0, 1) = this->right.y;
	inverse(0, 2) = this->right.z;

	inverse(1, 0) = this->up.x;
	inverse(1, 1) = this->up.y;
	inverse(1, 2) = this->up.z;

	inverse(2, 0) = this->direction.x;
	inverse(2, 1) = this->direction.y;
	inverse(2, 2) = this->direction.z;

	inverse(3, 3) = 1;

	return inverse;
}

Matrix<double> Camera::originTranslate()
{
	Matrix<double> matrix = Matrix<double>(4, 4);

	matrix(0, 0) = 1;
	matrix(1, 1) = 1;
	matrix(2, 2) = 1;
	matrix(3, 3) = 1;

	matrix(0, 3) = -this->eyePosition.x;
	matrix(1, 3) = -this->eyePosition.y;
	matrix(2, 3) = -this->eyePosition.z;

	return matrix;
}

void Camera::drawLine(Vector3<double> begin, Vector3<double> end, Matrix<double> pm, Matrix<double> m, sf::Color color, sf::RenderWindow& window)
{
	const double canvastWidth = window.getView().getSize().x;
	const double canvastHeight = window.getView().getSize().y;

	begin = begin.viewTransform(m);
	end = end.viewTransform(m);

	begin = begin.viewTransform(pm);
	end = end.viewTransform(pm);

	if (begin.w > 0 && end.w >0)
	{
		sf::Vertex edgeLine[]{
				{
					sf::Vector2f(canvastWidth / 2 + (int)(begin.x / begin.w * canvastWidth / 2),
								 canvastHeight / 2 - (int)(begin.y / begin.w * canvastHeight / 2)),
					color
				},
				{
					sf::Vector2f(canvastWidth / 2 + (int)(end.x / end.w * canvastWidth / 2),
								 canvastHeight / 2 - (int)(end.y / end.w * canvastHeight / 2)),
					color
				}
		};
		window.draw(edgeLine, 2, sf::Lines);
	}
}

void Camera::draw(sf::RenderWindow& window)
{
	const double canvastWidth = window.getView().getSize().x;
	const double canvastHeight = window.getView().getSize().y;

	Matrix<double> pm = Matrix<double>(4, 4);
	pm(0, 0) = scale;
	pm(1, 1) = scale;
	pm(2, 2) = -far / (far - near);
	pm(2, 3) = -1;
	pm(3, 2) = (-far * near) / (far - near);

	Vector3<double> begin;
	Vector3<double> end;

	Matrix<double> inverse = this->getInverse();
	Matrix<double> origin = this->originTranslate();

	Matrix<double> m = inverse * origin;

	std::vector<sf::Color> colors{
		sf::Color{255,0,0,255},
		sf::Color{0,255,0,255},
		sf::Color{0,0,255,255}
	};
	for (auto renderObject : this->scene.getRenderObjects())
	{
		for (int i = 0; i < renderObject->getEdges().size(); i++) {
			drawLine(renderObject->getEdges()[i].getStart(),
				renderObject->getEdges()[i].getEnd(),
				pm,
				m,
				{ 255,255,255,255 },
				window);

		}

		for (int i = 1; i < 4; i++)
		{
			drawLine(renderObject->getLocalAxis()[0],
				renderObject->getLocalAxis()[i],
				pm,
				m,
				colors[i - 1],
				window);
		}
	}
}

void Camera::transformPosition(Matrix<double> m)
{
	eyePosition.transform(m);
	lookAtPosition.transform(m);
}

void Camera::setLookAtPosition(Vector3<double> lookAt)
{
	if (this->lookAtPosition.x != lookAt.x ||
		this->lookAtPosition.y != lookAt.y ||
		this->lookAtPosition.z != lookAt.z)
	{
		this->lookAtPosition = lookAt;
	}
}

void Camera::update(double deltaTime)
{
	this->direction = eyePosition - lookAtPosition;
	this->direction.normalize();
	this->right = Vector3<double>::crossProduct(this->up, this->direction);
	this->right.normalize();
	this->up = Vector3<double>::crossProduct(this->direction, this->right);
	this->up.normalize();

	if (inputHandler.keyHold(sf::Keyboard::Key::Up))
	{
		Matrix<double> translationMatrix = Matrix<double>::getTranslationMatrix(this->up.x * moveSpeed * deltaTime, this->up.y * moveSpeed * deltaTime, this->up.z * moveSpeed * deltaTime);
		this->transformPosition(translationMatrix);
	}

	if (inputHandler.keyHold(sf::Keyboard::Key::Down))
	{
		Matrix<double> translationMatrix = Matrix<double>::getTranslationMatrix(-this->up.x * moveSpeed * deltaTime, -this->up.y * moveSpeed * deltaTime, -this->up.z * moveSpeed * deltaTime);
		this->transformPosition(translationMatrix);
	}

	if (inputHandler.keyHold(sf::Keyboard::Key::Left))
	{
		Matrix<double> translationMatrix = Matrix<double>::getTranslationMatrix(-this->right.x * moveSpeed * deltaTime, -this->right.y * moveSpeed * deltaTime, -this->right.z * moveSpeed * deltaTime);
		this->transformPosition(translationMatrix);
	}

	if (inputHandler.keyHold(sf::Keyboard::Key::Right))
	{
		Matrix<double> translationMatrix = Matrix<double>::getTranslationMatrix(this->right.x * moveSpeed * deltaTime, this->right.y * moveSpeed * deltaTime, this->right.z * moveSpeed * deltaTime);
		this->transformPosition(translationMatrix);
	}

	if (inputHandler.keyHold(sf::Keyboard::Key::PageUp))
	{
		Matrix<double> translationMatrix = Matrix<double>::getTranslationMatrix(this->direction.x * moveSpeed * deltaTime, this->direction.y * moveSpeed * deltaTime, this->direction.z * moveSpeed * deltaTime);
		this->transformPosition(translationMatrix);
	}

	if (inputHandler.keyHold(sf::Keyboard::Key::PageDown))
	{
		Matrix<double> translationMatrix = Matrix<double>::getTranslationMatrix(-this->direction.x * moveSpeed * deltaTime, -this->direction.y * moveSpeed * deltaTime, -this->direction.z * moveSpeed * deltaTime);
		this->transformPosition(translationMatrix);
	}

	if (inputHandler.keyHold(sf::Keyboard::Key::Period))
	{

		Matrix<double> rotation = Matrix<double>::rotationMatrix(this->up, this->lookAtPosition, 1 * 25 * deltaTime);
		eyePosition.transform(rotation);
	}

	if (inputHandler.keyHold(sf::Keyboard::Key::Comma))
	{

		Matrix<double> rotation = Matrix<double>::rotationMatrix(Vector3<double>(-this->up.x, -this->up.y, -this->up.z), this->lookAtPosition, 1 * 25 * deltaTime);
		eyePosition.transform(rotation);
	}
}
