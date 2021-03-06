/* Copyright Steve Rabin, 2010. 
 * All rights reserved worldwide.
 *
 * This software is provided "as is" without express or implied
 * warranties. You may freely copy and compile this source into
 * applications you distribute provided that the copyright text
 * below is included in the resulting source code, for example:
 * "Portions Copyright Steve Rabin, 2010"
 */

#pragma once

#include "statemch.h"


class UnitTest2c : public StateMachine
{
public:

	UnitTest2c( GameObject & object )
		: StateMachine( object ) {}
	~UnitTest2c( void ) {}


private:

	virtual bool States( State_Machine_Event event, MSG_Object * msg, int state, int substate );

	//Put state variables here

};
