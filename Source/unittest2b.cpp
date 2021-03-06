/* Copyright Steve Rabin, 2010. 
 * All rights reserved worldwide.
 *
 * This software is provided "as is" without express or implied
 * warranties. You may freely copy and compile this source into
 * applications you distribute provided that the copyright text
 * below is included in the resulting source code, for example:
 * "Portions Copyright Steve Rabin, 2010"
 */

#include "DXUT.h"
#include "unittest2b.h"
#include "unittest2c.h"
#include "body.h"


//Add new states here
enum StateName {
	STATE_Initialize,	//Note: the first enum is the starting state
	STATE_Chain1,
	STATE_Chain2,
	STATE_Chain3,
	STATE_Chain4,
	STATE_Chain5,
	STATE_Chain6,
	STATE_Chain7,
	STATE_Chain8,
	STATE_Chain9,
	STATE_Chain10,
	STATE_Success
};

//Add new substates here
enum SubstateName {
	SUBSTATE_Inside1,
	SUBSTATE_Inside2
};

//unittest2 covers:
//1. PushStateMachine
//2. PopStateMachine
//3. QueueStateMachine
//4. RequeueStateMachine

bool UnitTest2b::States( State_Machine_Event event, MSG_Object * msg, int state, int substate )
{
BeginStateMachine

	//Global message responses
	
	///////////////////////////////////////////////////////////////
	DeclareState( STATE_Initialize )

		OnEnter
			if( m_owner->GetBody().GetHealth() == 100 )
			{
				OutputDebugString( L"UnitTest2b Success\n" );
				PopStateMachine();
			}
			else
			{
				ChangeStateDelayed( 1.0f, STATE_Chain1 );
			}


	///////////////////////////////////////////////////////////////
	DeclareState( STATE_Chain1 )
		
		OnEnter
			StateMachine* mch = new UnitTest2c( *m_owner );
			QueueStateMachine( *mch );	//Put this new one between UnitTest2a and UnitTest2b
			ChangeStateDelayed( 1.0f, STATE_Chain2 );


	///////////////////////////////////////////////////////////////
	DeclareState( STATE_Chain2 )

		OnEnter
			RequeueStateMachine();		//Put this current one between UnitTest2a and UnitTest2c


EndStateMachine
}
