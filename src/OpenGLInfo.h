#ifndef OPENGL_INFO_H
#define OPENGL_INFO_H

#include <string>

namespace Rendering
{
    struct WindowInfo
    {
        std::string title;
        int width, height;
        int x, y;
        bool isReshapeable;

        WindowInfo(std::string name,
                   int width, int height,
                   int x, int y,
                   bool reshapeable) :
            title(name),
            width(width), height(height),
            x(x), y(y),
            isReshapeable(reshapeable)
        {}
    };

    struct ContextInfo
    {
        int major_version, minor_version;
        bool core;

        ContextInfo(int major, int minor, bool core) :
            major_version(major), minor_version(minor), core(core)
        {}
    };

    struct FramebufferInfo
    {
       unsigned int flags;
       bool msaa;

    };

} // end OpenGL

#endif // OPENGL_INFO_H
