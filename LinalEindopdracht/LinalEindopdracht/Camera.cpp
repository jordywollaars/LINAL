#include "Camera.hpp"

Camera::Camera(Vector3<double> eyePosition, Vector3<double> lookAtPosition, Scene& scene, InputHandler& inputHandler) : scene{ scene }, inputHandler{ inputHandler }
{
	this->eyePosition = eyePosition;
	this->lookAtPosition = lookAtPosition;

	this->direction = eyePosition - lookAtPosition;
	this->direction.normalize();
	this->right = Vector3<double>::normal(this->up, this->direction);
	this->right.normalize();
	this->up = Vector3<double>::normal(this->direction, this->right);
	this->up.normalize();

	this->direction.print();
	this->right.print();
	this->up.print();

	/*Matrix<double> inverse = this->getInverse();
	Matrix<double> origin = this->originTranslate();

	Matrix<double> m = origin * inverse;

	m.print();

	for (auto renderObject : scene.getRenderObjects())
	{
		renderObject->transformObject(m);
	}*/
}

Matrix<double> Camera::getInverse()
{
	Matrix<double> inverse = Matrix<double>(4, 4);

	inverse(0, 0) = this->right.x;
	inverse(1, 0) = this->right.y;
	inverse(2, 0) = this->right.z;

	inverse(0, 1) = this->up.x;
	inverse(1, 1) = this->up.y;
	inverse(2, 1) = this->up.z;

	inverse(0, 2) = this->direction.x;
	inverse(1, 2) = this->direction.y;
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

void Camera::draw(sf::RenderWindow& window)
{
	const double canvastWidth = 800;
	const double canvastHeight = 600;

	// middelpunt scherm
	int nulpuntCanvasX = canvastWidth / 2;
	int nulpuntCanvasY = canvastHeight / 2;

	Matrix<double> pm = Matrix<double>(4, 4);
	pm(0, 0) = scale;
	pm(1, 1) = scale;
	pm(2, 2) = -far / (far - near);
	pm(2, 3) = -1;
	pm(3, 2) = -(far * near) / (far - near);

	Vector3<double> begin;
	Vector3<double> end;

	Matrix<double> inverse = this->getInverse();
	Matrix<double> origin = this->originTranslate();

	Matrix<double> m = origin * inverse;

	for (auto renderObject : this->scene.getRenderObjects())
	{
		for (int i = 0; i < renderObject->getEdges().size(); i++) {
			begin = renderObject->getEdges()[i].getStart().projectTransform(m);
			end = renderObject->getEdges()[i].getEnd().projectTransform(m);

			begin = begin.getPerspectiveCoordinate(pm);
			end = end.getPerspectiveCoordinate(pm);

			if ((begin.w > 0) && (end.w > 0)) {
				sf::Vertex edgeLine[]{
					{
						sf::Vector2f(nulpuntCanvasX + (int)(begin.x / begin.w * canvastWidth / begin.w),
									 nulpuntCanvasY - (int)(begin.y / begin.w * canvastHeight / begin.w)),
						{255,255,255,255}
					},
					{
						sf::Vector2f(nulpuntCanvasX + (int)(end.x / end.w * canvastWidth / end.w),
									 nulpuntCanvasY - (int)(end.y / end.w * canvastHeight / end.w)),
						{255,255,255,255}
					}
				};
				window.draw(edgeLine, 2, sf::Lines);
			}
		}
	}

	std::vector<sf::Color> colors{
		sf::Color{255,0,0,255},
		sf::Color{0,255,0,255},
		sf::Color{0,0,255,255}
	};
	for (auto renderObject : this->scene.getRenderObjects())
	{
		for (int i = 1; i < 4; i++)
		{
			begin = renderObject->getLocalAxis()[0].projectTransform(m);
			end = renderObject->getLocalAxis()[i].projectTransform(m);

			begin = begin.getPerspectiveCoordinate(pm);
			end = end.getPerspectiveCoordinate(pm);

			if ((begin.w > 0) && (end.w > 0)) {
				sf::Vertex edgeLine[]{
					{
						sf::Vector2f(nulpuntCanvasX + (int)(begin.x / begin.w * canvastWidth / begin.w),
									 nulpuntCanvasY - (int)(begin.y / begin.w * canvastHeight / begin.w)),
						colors[i - 1]
					},
					{
						sf::Vector2f(nulpuntCanvasX + (int)(end.x / end.w * canvastWidth / end.w),
									 nulpuntCanvasY - (int)(end.y / end.w * canvastHeight / end.w)),
						colors[i - 1]
					}
				};
				window.draw(edgeLine, 2, sf::Lines);
			}
		}
	}
}

void Camera::transformPosition(Matrix<double> m)
{
	eyePosition.transform(m);
	lookAtPosition.transform(m);

	this->direction = eyePosition - lookAtPosition;
	this->direction.normalize();
	this->right = Vector3<double>::normal(this->up, this->direction);
	this->right.normalize();
	this->up = Vector3<double>::normal(this->direction, this->right);
	this->up.normalize();
}

void Camera::transformLookAt(Matrix<double> m)
{
	//eyePosition.transform(m);
	lookAtPosition.transform(m);

	this->direction = eyePosition - lookAtPosition;
	this->direction.normalize();
	this->right = Vector3<double>::normal(this->up, this->direction);
	this->right.normalize();
	this->up = Vector3<double>::normal(this->direction, this->right);
	this->up.normalize();
}

void Camera::setLookAtPosition(Vector3<double> lookAt)
{
	this->lookAtPosition = lookAt;
}

void Camera::update(double deltaTime)
{
	if (inputHandler.keyHold(sf::Keyboard::Key::Up))
	{
		Matrix<double> translationMatrix = Matrix<double>::getTranslationMatrix(-this->up.x * moveSpeed * deltaTime, -this->up.y * moveSpeed * deltaTime, -this->up.z * moveSpeed * deltaTime);
		this->transformPosition(translationMatrix);
	}

	if (inputHandler.keyHold(sf::Keyboard::Key::Down))
	{
		Matrix<double> translationMatrix = Matrix<double>::getTranslationMatrix(this->up.x * moveSpeed * deltaTime, this->up.y * moveSpeed * deltaTime, this->up.z * moveSpeed * deltaTime);
		this->transformPosition(translationMatrix);
	}

	if (inputHandler.keyHold(sf::Keyboard::Key::Left))
	{
		Matrix<double> translationMatrix = Matrix<double>::getTranslationMatrix(this->right.x * moveSpeed * deltaTime, this->right.y * moveSpeed * deltaTime, this->right.z * moveSpeed * deltaTime);
		this->transformPosition(translationMatrix);
	}

	if (inputHandler.keyHold(sf::Keyboard::Key::Right))
	{
		Matrix<double> translationMatrix = Matrix<double>::getTranslationMatrix(-this->right.x * moveSpeed * deltaTime, -this->right.y * moveSpeed * deltaTime, -this->right.z * moveSpeed * deltaTime);
		this->transformPosition(translationMatrix);
	}

	if (inputHandler.keyHold(sf::Keyboard::Key::PageUp))
	{
		Matrix<double> translationMatrix = Matrix<double>::getTranslationMatrix(-this->direction.x * moveSpeed * deltaTime, -this->direction.y * moveSpeed * deltaTime, -this->direction.z * moveSpeed * deltaTime);
		this->transformPosition(translationMatrix);
	}

	if (inputHandler.keyHold(sf::Keyboard::Key::PageDown))
	{
		Matrix<double> translationMatrix = Matrix<double>::getTranslationMatrix(this->direction.x * moveSpeed * deltaTime, this->direction.y * moveSpeed * deltaTime, this->direction.z * moveSpeed * deltaTime);
		this->transformPosition(translationMatrix);
	}
}
