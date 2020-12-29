#include "Spaceship.hpp"

#include "Matrix.hpp"
#include "Vector3.hpp"
#include "Projectile.hpp"

Spaceship::Spaceship(InputHandler& inputHandler, Scene& scene) : inputHandler{ inputHandler }, scene{scene}
{
	this->setShipRenderObject();
}

void Spaceship::update()
{
	//Shooting
	if (inputHandler.keyDown(sf::Keyboard::Key::Space))
	{
		scene.add(new Projectile(this->getPivot(), this->getLocalAxis()));
	}

	//Movement
	if (inputHandler.keyHold(sf::Keyboard::Key::LShift))
	{
		Matrix<double> translationMatrixForward = Matrix<double>::getTranslationMatrix(-this->getLocalZAxis().x, -this->getLocalZAxis().y, -this->getLocalZAxis().z);
		this->transformObject(translationMatrixForward);
	}

	//Rotating
	if (inputHandler.keyHold(sf::Keyboard::Key::Q))
	{
		Vector3<double> localZAxis = this->getLocalZAxis();
		localZAxis.normalize();

		// translatiematrix naar de oorsprong
		Matrix<double> to = Matrix<double>::getTranslationMatrix(this->getPivot().x, this->getPivot().y, this->getPivot().z);
		// rotatiematrix om de y-as naar het xy-vlak
		Matrix<double> m1 = Matrix<double>::getRotationMatrixM1(localZAxis);
		// rotatiematrix om de z-as naar de x-as
		Matrix<double> m2 = Matrix<double>::getRotationMatrixM2(localZAxis);
		// rotatie om de x-as
		Matrix<double> m3 = Matrix<double>::getRotationMatrixX(-1);
		// rotatie om de z-as terug
		Matrix<double> m4 = Matrix<double>::getRotationMatrixM4(localZAxis);
		// rotatie om de y-as terug
		Matrix<double> m5 = Matrix<double>::getRotationMatrixM5(localZAxis);
		// translatiematrix "terug"
		Matrix<double> back = Matrix<double>::getTranslationMatrix(-this->getPivot().x, -this->getPivot().y, -this->getPivot().z);
		// vermenigvuldig alle matrices
		Matrix<double> m = to * m1 * m2 * m3 * m4 * m5 * back;

		this->transformObject(m);
		//renderObject->rotateLocalAxis(m1 * m2 * m3 * m4 * m5);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::E))
	{
		Vector3<double> localZAxis = this->getLocalZAxis();
		localZAxis.normalize();

		// translatiematrix naar de oorsprong
		Matrix<double> to = Matrix<double>::getTranslationMatrix(this->getPivot().x, this->getPivot().y, this->getPivot().z);
		// rotatiematrix om de y-as naar het xy-vlak
		Matrix<double> m1 = Matrix<double>::getRotationMatrixM1(localZAxis);
		// rotatiematrix om de z-as naar de x-as
		Matrix<double> m2 = Matrix<double>::getRotationMatrixM2(localZAxis);
		// rotatie om de x-as
		Matrix<double> m3 = Matrix<double>::getRotationMatrixX(1);
		// rotatie om de z-as terug
		Matrix<double> m4 = Matrix<double>::getRotationMatrixM4(localZAxis);
		// rotatie om de y-as terug
		Matrix<double> m5 = Matrix<double>::getRotationMatrixM5(localZAxis);
		// translatiematrix "terug"
		Matrix<double> back = Matrix<double>::getTranslationMatrix(-this->getPivot().x, -this->getPivot().y, -this->getPivot().z);
		// vermenigvuldig alle matrices
		Matrix<double> m = to * m1 * m2 * m3 * m4 * m5 * back;

		this->transformObject(m);
		//renderObject->rotateLocalAxis(m1 * m2 * m3 * m4 * m5);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::W))
	{
		Vector3<double> localXAxis = this->getLocalXAxis();
		localXAxis.normalize();

		// translatiematrix naar de oorsprong
		Matrix<double> to = Matrix<double>::getTranslationMatrix(this->getPivot().x, this->getPivot().y, this->getPivot().z);
		// rotatiematrix om de y-as naar het xy-vlak
		Matrix<double> m1 = Matrix<double>::getRotationMatrixM1(localXAxis);
		// rotatiematrix om de z-as naar de x-as
		Matrix<double> m2 = Matrix<double>::getRotationMatrixM2(localXAxis);
		// rotatie om de x-as
		Matrix<double> m3 = Matrix<double>::getRotationMatrixX(1);
		// rotatie om de z-as terug
		Matrix<double> m4 = Matrix<double>::getRotationMatrixM4(localXAxis);
		// rotatie om de y-as terug
		Matrix<double> m5 = Matrix<double>::getRotationMatrixM5(localXAxis);
		// translatiematrix "terug"
		Matrix<double> back = Matrix<double>::getTranslationMatrix(-this->getPivot().x, -this->getPivot().y, -this->getPivot().z);
		// vermenigvuldig alle matrices
		Matrix<double> m = to * m1 * m2 * m3 * m4 * m5 * back;

		this->transformObject(m);
		//renderObject->rotateLocalAxis(m1* m2* m3* m4* m5);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::S))
	{
		Vector3<double> localXAxis = this->getLocalXAxis();
		localXAxis.normalize();

		// translatiematrix naar de oorsprong
		Matrix<double> to = Matrix<double>::getTranslationMatrix(this->getPivot().x, this->getPivot().y, this->getPivot().z);
		// rotatiematrix om de y-as naar het xy-vlak
		Matrix<double> m1 = Matrix<double>::getRotationMatrixM1(localXAxis);
		// rotatiematrix om de z-as naar de x-as
		Matrix<double> m2 = Matrix<double>::getRotationMatrixM2(localXAxis);
		// rotatie om de x-as
		Matrix<double> m3 = Matrix<double>::getRotationMatrixX(-1);
		// rotatie om de z-as terug
		Matrix<double> m4 = Matrix<double>::getRotationMatrixM4(localXAxis);
		// rotatie om de y-as terug
		Matrix<double> m5 = Matrix<double>::getRotationMatrixM5(localXAxis);
		// translatiematrix "terug"
		Matrix<double> back = Matrix<double>::getTranslationMatrix(-this->getPivot().x, -this->getPivot().y, -this->getPivot().z);
		// vermenigvuldig alle matrices
		Matrix<double> m = to * m1 * m2 * m3 * m4 * m5 * back;

		this->transformObject(m);
		//renderObject->rotateLocalAxis(m1* m2* m3* m4* m5);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::A))
	{
		Vector3<double> localYAxis = this->getLocalYAxis();
		localYAxis.normalize();

		// translatiematrix naar de oorsprong
		Matrix<double> to = Matrix<double>::getTranslationMatrix(this->getPivot().x, this->getPivot().y, this->getPivot().z);
		// rotatiematrix om de y-as naar het xy-vlak
		Matrix<double> m1 = Matrix<double>::getRotationMatrixM1(localYAxis);
		// rotatiematrix om de z-as naar de x-as
		Matrix<double> m2 = Matrix<double>::getRotationMatrixM2(localYAxis);
		// rotatie om de x-as
		Matrix<double> m3 = Matrix<double>::getRotationMatrixX(1);
		// rotatie om de z-as terug
		Matrix<double> m4 = Matrix<double>::getRotationMatrixM4(localYAxis);
		// rotatie om de y-as terug
		Matrix<double> m5 = Matrix<double>::getRotationMatrixM5(localYAxis);
		// translatiematrix "terug"
		Matrix<double> back = Matrix<double>::getTranslationMatrix(-this->getPivot().x, -this->getPivot().y, -this->getPivot().z);
		// vermenigvuldig alle matrices
		Matrix<double> m = to * m1 * m2 * m3 * m4 * m5 * back;

		this->transformObject(m);
		//renderObject->rotateLocalAxis(m1* m2* m3* m4* m5);
	}
	if (inputHandler.keyHold(sf::Keyboard::Key::D))
	{
		Vector3<double> localYAxis = this->getLocalYAxis();
		localYAxis.normalize();

		// translatiematrix naar de oorsprong
		Matrix<double> to = Matrix<double>::getTranslationMatrix(this->getPivot().x, this->getPivot().y, this->getPivot().z);
		// rotatiematrix om de y-as naar het xy-vlak
		Matrix<double> m1 = Matrix<double>::getRotationMatrixM1(localYAxis);
		// rotatiematrix om de z-as naar de x-as
		Matrix<double> m2 = Matrix<double>::getRotationMatrixM2(localYAxis);
		// rotatie om de x-as
		Matrix<double> m3 = Matrix<double>::getRotationMatrixX(-1);
		// rotatie om de z-as terug
		Matrix<double> m4 = Matrix<double>::getRotationMatrixM4(localYAxis);
		// rotatie om de y-as terug
		Matrix<double> m5 = Matrix<double>::getRotationMatrixM5(localYAxis);
		// translatiematrix "terug"
		Matrix<double> back = Matrix<double>::getTranslationMatrix(-this->getPivot().x, -this->getPivot().y, -this->getPivot().z);
		// vermenigvuldig alle matrices
		Matrix<double> m = to * m1 * m2 * m3 * m4 * m5 * back;

		this->transformObject(m);
		//renderObject->rotateLocalAxis(m1* m2* m3* m4* m5);
	}
}
