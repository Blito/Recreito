#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL2/SDL_keycode.h>

namespace Core
{

    typedef SDL_Keycode Keycode;
    /**
     * @brief The InputManager class is responsible for registering input events from
     * the user. Other classes should query the InputManager for input status and updates.
     */
    class InputManager
    {
    public:
        InputManager();

        /**
         * @brief update Updates input status.
         */
        void update(float millis);

        bool isQuit() const { return shouldQuit; }

    protected:
        bool shouldQuit = false;
    };

} // end Core

#endif // INPUTMANAGER_H
