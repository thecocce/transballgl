#ifdef _WIN32
#include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "string.h"

#ifdef __APPLE__
#include "OpenGL/gl.h"
#include "OpenGL/glu.h"
#else
#include "GL/glew.h"
#include "GL/gl.h"
#include "GL/glu.h"
#endif
#include "SDL.h"

#include "Symbol.h"
#include "BB2D.h"
#include "auxiliar.h"
#include "GLTile.h"
#include "BB2D.h"
#include "sound.h"
#include "keyboardstate.h"
#include "randomc.h"
#include "VirtualController.h"

#include "GLTManager.h"
#include "SFXManager.h"
#include "TGLobject.h"
#include "TGLobject_pipevscreen.h"
#include "TGLmap.h"

#include "debug.h"




TGLobject_pipevscreen::TGLobject_pipevscreen(float x,float y,int ao) : TGLobject(x,y,ao)
{
} /* TGLobject_pipevscreen::TGLobject_pipevscreen */ 


TGLobject_pipevscreen::~TGLobject_pipevscreen()
{
} /* TGLobject_pipevscreen::~TGLobject_pipevscreen */ 


void TGLobject_pipevscreen::draw(glm::mat4 transform, class GLTManager *GLTM)
{
	int local_cycle=((m_animation_offset+m_cycle)%120)/8;
	if (local_cycle==0) m_last_tile=GLTM->get("graphics/objects/pipe-vertical-screen1.png");
	if (local_cycle==1) m_last_tile=GLTM->get("graphics/objects/pipe-vertical-screen2.png");
	if (local_cycle==2) m_last_tile=GLTM->get("graphics/objects/pipe-vertical-screen1.png");
	if (local_cycle==3) m_last_tile=GLTM->get("graphics/objects/pipe-vertical-screen2.png");
	if (local_cycle==4) m_last_tile=GLTM->get("graphics/objects/pipe-vertical-screen1.png");
	if (local_cycle==5) m_last_tile=GLTM->get("graphics/objects/pipe-vertical-screen2.png");
	if (local_cycle==6) m_last_tile=GLTM->get("graphics/objects/pipe-vertical-screen1.png");
	if (local_cycle==7) m_last_tile=GLTM->get("graphics/objects/pipe-vertical-screen2.png");
	if (local_cycle==8) m_last_tile=GLTM->get("graphics/objects/pipe-vertical-screen3.png");
	if (local_cycle==9) m_last_tile=GLTM->get("graphics/objects/pipe-vertical-screen4.png");
	if (local_cycle==10) m_last_tile=GLTM->get("graphics/objects/pipe-vertical-screen5.png");
	if (local_cycle==11) m_last_tile=GLTM->get("graphics/objects/pipe-vertical-screen6.png");
	if (local_cycle==12) m_last_tile=GLTM->get("graphics/objects/pipe-vertical-screen7.png");
	if (local_cycle==13) m_last_tile=GLTM->get("graphics/objects/pipe-vertical-screen8.png");
	if (local_cycle==14) m_last_tile=GLTM->get("graphics/objects/pipe-vertical-screen9.png");
    if (m_last_tile!=0) {
        glm::mat4 transform2 = glm::translate(transform, glm::vec3(m_x, m_y, 0));
        if (m_angle!=0) transform2 = glm::rotate(transform2, float(m_angle*M_PI/180), glm::vec3(0, 0, 1));
        if (m_scale!=1) transform2 = glm::scale(transform2, glm::vec3(m_scale, m_scale, m_scale));
        m_last_tile->draw(transform2);
    }
} /* TGLobject_pipevscreen::draw */


bool TGLobject_pipevscreen::is_a(Symbol *c)
{
	if (c->cmp("TGLobject_pipevscreen")) return true;
	return TGLobject::is_a(c);
} /* TGLobject_pipevscreen::is_a */ 


bool TGLobject_pipevscreen::is_a(char *c)
{
	bool retval;
	Symbol *s=new Symbol(c);

	retval=is_a(s);

	delete s;

	return retval;
} /* TGLobject_pipevscreen::is_a */ 


const char *TGLobject_pipevscreen::get_class(void)
{
	return "TGLobject_pipevscreen";
} /* TGLobject_pipevscreen:get_class */ 

