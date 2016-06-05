/*****************************************************************************************
* Desc: Tutorial 02 IND_Surface
*****************************************************************************************/

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"

/*
==================
Main
TASks:

CHECK- да смените картинката на фона - background - на играта(можете да ползвате ресурсите в другия архив.)
CHECK- на мястото на звездата горе в дясно да поставите 3 сърчица, които да служат като health-bar. Може да са 3 отделни елемента или една обща червена лента.
- при натискането на клавиш от клавиатурата, да се премества позицията на единия герой. W –нагоре, A-наляво, S-надолу, D- надясно.
- При достигане до края на екрана, героят да не може да продължи (ще проверите за колизии).
- При колизия с края на екрана, намалете по едно сърчице от живота на героя





==================
*/
int IndieLib()
{
	
	// ----- IndieLib intialization -----

	CIndieLib *mI = CIndieLib::instance();
	if (!mI->init()) return 0;

	
	// ----- Surface loading -----

	// Loading Background
	IND_Surface *mSurfaceBack = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceBack, "../SpaceGame/resources/skyyy.png", IND_OPAQUE, IND_32)) return 0;

	// Loading sprite of a star/heart1
	IND_Surface *mSurfaceStar = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceStar, "../SpaceGame/resources/h.png", IND_ALPHA, IND_32)) return 0;

	//heart 2

	IND_Surface *mSurfaceHeart = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceHeart, "../SpaceGame/resources/h.png", IND_ALPHA, IND_32)) return 0;


	//TEST

	IND_Surface *mSurfaceCat = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceCat, "../SpaceGame/resources/cats.png", IND_ALPHA, IND_32)) return 0;

	// ----- Animations loading -----

	// Characters animations, we apply a color key of (0, 48, 152)
	IND_Animation *mAnimationCharacter1 = IND_Animation::newAnimation();
	if (!mI->_animationManager->addToSurface(mAnimationCharacter1, "../SpaceGame/resources/animations/character1.xml", IND_ALPHA, IND_32, 0, 48, 152)) return 0;

	// Characters animations, we apply a color key of (0, 48, 152)
	//IND_Animation *mAnimationCharacter2 = IND_Animation::newAnimation();
	//if (!mI->_animationManager->addToSurface(mAnimationCharacter2, "../SpaceGame/resources/animations/character2.xml", IND_ALPHA, IND_32, 0, 48, 152)) return 0;

	// Dust animation, we apply a color key of (255, 0, 255)
	IND_Animation *mAnimationDust = IND_Animation::newAnimation();
	if (!mI->_animationManager->addToSurface(mAnimationDust, "../SpaceGame/resources/animations/dust.xml", IND_ALPHA, IND_16, 255, 0, 255)) return 0;

	// ----- Set the surface and animations into 2d entities -----

	// Creating 2d entity for the background
	IND_Entity2d *mBack = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mBack);					// Entity adding
	mBack->setSurface(mSurfaceBack);					// Set the surface into the entity

	//heart
	IND_Entity2d *star = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(star);
	star->setSurface(mSurfaceStar);

	//heart2
	IND_Entity2d *heart = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(heart);
	heart->setSurface(mSurfaceStar);
	//heart 2.1
	IND_Entity2d *heart1 = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(heart1);
	heart1->setSurface(mSurfaceHeart);
	////////////////////tEST
	IND_Entity2d *cat = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(cat);
	cat->setSurface(mSurfaceCat);

	// Character 1
	IND_Entity2d *mPlayer1 = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mPlayer1);					// Entity adding
	mPlayer1->setAnimation(mAnimationCharacter1);				// Set the animation into the entity

	// Character 2
	//IND_Entity2d *mPlayer2 = IND_Entity2d::newEntity2d();
	//mI->_entity2dManager->add(mPlayer2);					// Entity adding
	//mPlayer2->setAnimation(mAnimationCharacter2);				// Set the animation into the entity

	// Dust explosion
	IND_Entity2d *mDust = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mDust);					// Entity adding
	mDust->setAnimation(mAnimationDust);					// Set the animation into the entity

	// ----- Changing the attributes of the 2d entities -----

	// Player 1
	mPlayer1->setSequence(0);						// Choose sequence
	mPlayer1->setPosition(100, 350, 0);
	mPlayer1->setMirrorX(1);						// Horizontal mirroring

	// Dust explosion
	mDust->setPosition(100, 420, 0);
	
	

	// Player 2
	/*mPlayer2->setSequence(0);	*/					// Choose sequence
	cat->setPosition(550, 450, 0);
/*	mPlayer2->setNumReplays(3);	*/					// The animation will be displayed 3 times


	//star = hearts
	star->setPosition(100, 0, 30); //outer
	heart->setPosition(0, 0, 40); //inner
	heart1->setPosition(50,0,70); //middle
	// ----- Main Loop -----


	float mAngle = 0;
	float mPosX = 100;
	float mPosY = 350;
	int mSpeed = 200;
	float mDelta; // double

	
	while (!mI->_input->onKeyPress(IND_ESCAPE) && !mI->_input->quit())
	{

		mI->_input->update();
		mPlayer1->setPosition((float)mPosX, (float)mPosY,1);
		mDelta = mI->_render->getFrameTime() / 1000.0f;
		if ((mI->_input->isKeyPressed(IND_W)))
		{
		
			mPosY -= mSpeed * mDelta;
		}
		if ((mI->_input->isKeyPressed(IND_A)))
		{
			
			mPosX -= mSpeed * mDelta;
		}
		if ((mI->_input->isKeyPressed(IND_S)))
		{
			
			mPosY += mSpeed * mDelta;
		}
		if ((mI->_input->isKeyPressed(IND_D)))
		{
			mPosX += mSpeed * mDelta;
		
		
		}
		

		// Toogle full screen when pressing "space"
		//if (mI->_input->onKeyPress(IND_SPACE)) mI->_render->toggleFullScreen();
		mI->_render->beginScene();
		mI->_entity2dManager->renderEntities2d();
		mI->_render->endScene();
		mI->_render->showFpsInWindowTitle();
	
	}

	// ----- Free -----

	mI->end();

	return 0;
}