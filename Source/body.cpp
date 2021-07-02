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
#include "body.h"

Body::Body( int health, D3DXVECTOR3& pos, GameObject& owner )
: m_health( health ),
  m_owner( &owner ),
  m_speed( 0.0f ),
  m_radius( 1.0f )
{
	m_pos = pos;

	m_dir.x = 1.0f;
	m_dir.y = 0.0f;
	m_dir.z = 0.0f;
}

Body::~Body( void )
{

}


