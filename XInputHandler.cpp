// C/C++ Standard Headers
#include <iostream>
// Win32
#include <Windows.h>
#include <Xinput.h>

#pragma comment(lib, "XInput.lib") 

class XboxController {
private:
    // To store the current state of the controller 
    XINPUT_STATE controllerState;
    int controllerIndex;
public:
    inline XboxController() noexcept {
        controllerIndex = 0;
        XInputGetState(controllerIndex, &controllerState);
    }

    // INPUT
    bool checkButtonPressed(WORD button) {
        return (controllerState.Gamepad.wButtons & button) != 0;
    }
    void getState() {
        ZeroMemory(&controllerState, sizeof(XINPUT_STATE));
        XInputGetState(controllerIndex, &controllerState);
    }
};

int main()
{
    XboxController x1;
    bool isFinished = false;
    while (!isFinished) {
        x1.getState();
        if (x1.checkButtonPressed(XINPUT_GAMEPAD_A)) {
            std::cout << "A IS PRESSED" << std::endl;
            std::cout << "------------" << std::endl;
        }
        else if (x1.checkButtonPressed(XINPUT_GAMEPAD_B)) {
            std::cout << "B PRESSED, EXITING." << std::endl;
            isFinished = true;
        }
    }
}
