#ifndef OPENGL_INFO_H
#define OPENGL_INFO_H

namespace Rendering
{
    struct WindowInfo
    {
        std::string name;
        int width, height;
        int position_x, position_y;
        bool isReshapeable;

        WindowInfo(std::string name,
                   int width, int height,
                   int x, int y,
                   bool reshapeable) :
            name(name),
            width(width), height(height),
            position_x(x), position_y(y),
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
