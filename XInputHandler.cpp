// C/C++ Standard Headers
#include <iostream>
// Win32
#include <Windows.h>
#include <Xinput.h>

#pragma comment(lib, "XInput.lib") 

int main()
{
    DWORD dwResult;
    for (DWORD i = 0; i < XUSER_MAX_COUNT; i++)
    {
        XINPUT_STATE state;
        ZeroMemory(&state, sizeof(XINPUT_STATE));
        // Simply get the state of the controller from XInput.
        dwResult = XInputGetState(i, &state);

        if (dwResult == ERROR_SUCCESS)
        {
            // Controller is connected
            std::cout << "Your controller is connected" << std::endl;
        }
        else
        {
            // Controller is not connected
            std::cout << "Your controller is not connected" << std::endl;
        }
    }
}
