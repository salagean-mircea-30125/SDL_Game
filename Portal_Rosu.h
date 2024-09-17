#pragma once
#include "Portal.h"
#include <stdlib.h>
#include "Global.h"

class Portal_Rosu: public Portal
{
public:
	void portal_apar() override;
	void check() override;
	static float pozx;
	static float pozy;
	static float centru_x_rosu;
	static float centru_y_rosu;
	static float colt_dr_jos_x;
	static float colt_dr_jos_y;
};

