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

WIP

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

	//WALL THINGS
	IND_Surface *mSurfaceGreen = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceGreen, "../SpaceGame/resources/green.png", IND_ALPHA, IND_32)) return 0;
	
	IND_Surface *mSurfaceGreen1 = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceGreen1, "../SpaceGame/resources/green.png", IND_ALPHA, IND_32)) return 0;
	// Loading sprite of a star/heart1
	IND_Surface *mSurfaceStar = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceStar, "../SpaceGame/resources/h.png", IND_ALPHA, IND_32)) return 0;

	//heart 2
	IND_Surface *mSurfaceHeart = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceHeart, "../SpaceGame/resources/h.png", IND_ALPHA, IND_32)) return 0;
	
	//TEST
	IND_Surface *mSurfaceCat = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceCat, "../SpaceGame/resources/cats.png", IND_ALPHA, IND_32)) return 0;

	//GAME OVER
	IND_Surface *mSurfaceGame = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceGame, "../SpaceGame/resources/gameover.png", IND_ALPHA, IND_32)) return 0;
	

	//TITLE
	IND_Surface *mSneak = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSneak, "../SpaceGame/resources/sneak1.png", IND_ALPHA, IND_32)) return 0;

	//subtitle
	IND_Surface *mSub = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSub, "../SpaceGame/resources/dont.png", IND_ALPHA, IND_32)) return 0;

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

	//////////////////////////////////////////////////WALL
	IND_Entity2d *green = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(green);
	green->setSurface(mSurfaceGreen);

	IND_Entity2d *green1 = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(green1);
	green1->setSurface(mSurfaceGreen1);

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
	//game over
	
	IND_Entity2d *gamecat = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(gamecat);
	gamecat->setSurface(mSurfaceGame);

	//title
	
	IND_Entity2d *sneako = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(sneako);
	sneako->setSurface(mSneak);

	//sub mSub
	IND_Entity2d *sub = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(sub);
	sub->setSurface(mSub);
	// Character 1
	IND_Entity2d *mPlayer1 = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mPlayer1);					// Entity adding
	mPlayer1->setAnimation(mAnimationCharacter1);				// Set the animation into the entity

	// Character 2
	//IND_Entity2d *mPlayer2 = IND_Entity2d::newEntity2d();
	//mI->_entity2dManager->add(mPlayer2);					// Entity adding
	//mPlayer2->setAnimation(mAnimationCharacter2);				// Set the animation into the entity

	// Dust explosion
	//IND_Entity2d *mDust = IND_Entity2d::newEntity2d();
	//mI->_entity2dManager->add(mDust);					// Entity adding
	//mDust->setAnimation(mAnimationDust);					// Set the animation into the entity

	// ----- Changing the attributes of the 2d entities -----   false alarm
	mBack->setPosition(0, 0, -10000000); //liololololddddd

	//green
	green->setPosition(0, 275, 5000);
	green->setBoundingRectangle("green", 5, -328, 10, 800);

	green1->setPosition(471, 275, 5000);
	green1->setBoundingRectangle("green1", 310, -250, 10, 800); 
	

	//star = hearts
	star->setPosition(100, 0, 30); //outer
	heart->setPosition(0, 0, 40); //inner
	heart1->setPosition(50, 0, 70); //middle

	cat->setPosition(550, 450, 4);
	cat->setBoundingCircle("cat", 50, 50, 55); 

	// Player 1
	mPlayer1->setSequence(0);						// Choose sequence
//	mPlayer1->setPosition(100, 350, 5000);
	mPlayer1->setMirrorX(1);						// Horizontal mirroring
	//mPlayer1->setBoundingRectangle("player", 300, 20, 5, 475);
	// Dust explosion
	//mDust->setPosition(40, 410, 0);
	
	// Player 2
	/*mPlayer2->setSequence(0);	*/					// Choose sequence
	/*mPlayer2->setNumReplays(3);	*/				// The animation will be displayed 3 times


	// ----- Main Loop -----
	gamecat->setPosition(300, 100, 30);
	gamecat->setShow(false);
	sneako->setPosition(250, 50, 30);
	sub->setPosition(350, 210, 30);
	float mAngle = 0;
	float mPosX = 100;
	float mPosY = 440;
	int mSpeed = 200;
	float mDelta; // double
	float mWidth = mPlayer1->getRegionWidth() / 2;
	float mHeight = mPlayer1->getRegionHeight() / 2;
	mPlayer1->setHotSpot(0.5f, 0.5f);

	
	while (!mI->_input->onKeyPress(IND_ESCAPE) && !mI->_input->quit())
	{

		mI->_input->update();
		mPlayer1->setPosition((float)mPosX, (float)mPosY,1);
		mDelta = mI->_render->getFrameTime() / 1000.0f;

		if (mPosX + mWidth >= mI->_window->getWidth()-25) mPosX = mI->_window->getWidth()-25;
		if (mPosX - mWidth< 50) mPosX = 50;
		if (mPosY + mHeight >= mI->_window->getHeight()-100) mPosY = mI->_window->getHeight()-100;
		if (mPosY - mHeight < 100) mPosY = 100; 
	if (mI->_entity2dManager->isCollision(mPlayer1, "player1", green, "green")){
		star->setShow(false);
	
		}
	if (mI->_entity2dManager->isCollision(mPlayer1, "player1", green1, "green1")){
		heart->setShow(false);
		gamecat->setShow(true);
		mPlayer1->setShow(false);
		cat->setShow(false);
		sneako->setShow(false);
		heart1->setShow(false);
		star->setShow(false);
		sub->setShow(false);
	}
	if (mI->_entity2dManager->isCollision(mPlayer1, "player1", cat, "cat")){
		heart1->setShow(false);
		

	}
	
	/*if (heart1->isShow && heart->isShow = false && star->isShow = false){
		mI->_render->endScene();
	}*/

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
		mI->_render->clearViewPort(0, 0, 0); 
		mI->_entity2dManager->renderEntities2d();
		//mI->_render->showFpsInWindowTitle();
		//mI->_entity2dManager->renderCollisionAreas(255, 0, 0, 255);
		mI->_render->endScene();
	}

	// ----- Free -----

	mI->end();

	return 0;
}