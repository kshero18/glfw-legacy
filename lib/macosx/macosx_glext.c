//========================================================================
// GLFW - An OpenGL framework
// File:     platform.h
// Platform: Mac OS X
// Version:  2.4
// Date:     2002.12.31
// Author:   Marcus Geelnard (marcus.geelnard@home.se)
//           Keith Bauer (onesadcookie@hotmail.com)
// WWW:      http://hem.passagen.se/opengl/glfw/
//------------------------------------------------------------------------
// Copyright (c) 2002 Marcus Geelnard
//
// GLFW is provided "as-is", without any express or implied warranty,
// without even the implied warranty of fitness for a particular purpose.
// In no event will the author be held liable for any damage araising from
// the use of GLFW.
//
// Permission is granted to anyone to use GLFW for any purpose, including
// commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. You must not claim that you wrote GLFW.
// 2. If you modify any parts of GLFW, it must be clearly stated which
//    modifications have been made, and that those modifications are not
//    the work of the author of GLFW.
// 3. If you use GLFW in a product, an acknowledgment in the product
//    documentation would be appreciated, but is not required.
// 4. This notice may not be removed or altered from any source
//    distribution of GLFW.
//
// Marcus Geelnard
// marcus.geelnard@home.se
//========================================================================

#include "internal.h"

int    _glfwPlatformExtensionSupported( const char *extension )
{
    // There are no AGL, CGL or NSGL extensions.
    return GL_FALSE;
}

void * _glfwPlatformGetProcAddress( const char *procname )
{
    CFStringRef symbolName = CFStringCreateWithCString( kCFAllocatorDefault,
                                                        procname,
                                                        kCFStringEncodingASCII );
    
    void *symbol = CFBundleGetFunctionPointerForName( _glfwLibs.OpenGLFramework,
                                                      symbolName );

    CFRelease( symbolName );

    return symbol;
}
