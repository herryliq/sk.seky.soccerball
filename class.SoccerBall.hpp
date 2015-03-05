#pragma once
#include "class.App.hpp"
#include "log4cpp.h"
#include "entities.hpp"
#include "class.VideoRecord.hpp"
#include <opencv2/video/background_segm.hpp>

/**
* Trieda reprezentuje hlavny projekt Carlos a jeho halvny algoritmus, ktory spaja ostatne moduly
*/
class SoccerBall : public App
{
private:
	log4cpp::Category* log;
	static const bool m_fullscreen = false;
	static const int m_lockFPS = 60;
	VideoRecord* record;
	Mat fgMaskMOG; //fg mask generated by MOG method
	Mat fgMaskMOG2; //fg mask fg mask generated by MOG2 method
	Ptr<BackgroundSubtractor> pMOG; //MOG Background subtractor
	Ptr<BackgroundSubtractor> pMOG2; //MOG2 Background subtractor

	// Metoda na spracovanie snimku
	void spracujJedenSnimok(Image* image);

	// Metoda pre ziskanie snimku
	void nacitajDalsiuSnimku();

protected:
	// Inicializacia Carlosu
	virtual void Init();

	// Run() metoda je vola v cykle dokedy bezi apliakcia
	virtual bool Run();
	virtual int getLockFPS();

public:

	SoccerBall();
	~SoccerBall();
};
