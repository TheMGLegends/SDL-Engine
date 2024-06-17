#include "InputHandler.h"

#include <cstring>

// INFO: Generic Members for Keyboard Input Handling
const Uint8* InputHandler::KEYBOARD_STATE = nullptr;
Uint8* InputHandler::previousKeyboardState = nullptr;
int InputHandler::keyLength = 0;
SDL_Event InputHandler::inputEvent{};

// INFO: Keybinding Members Extension
std::unordered_map<SDL_Keycode, BindData> InputHandler::keyBindingsLib{};

// INFO: Generic Members for Mouse Input Handling
Mouse InputHandler::mouse{};
Uint32 InputHandler::MOUSE_STATE = 0;
Uint32 InputHandler::previousMouseState = 0;

// INFO: Button binding Members Extension
std::unordered_map<Uint32, BindData> InputHandler::mouseButtonBindingsLib{};

void InputHandler::Initialize()
{
	// INFO: Get the state of the keyboard
	KEYBOARD_STATE = SDL_GetKeyboardState(&keyLength);

	// INFO: Initialise the previous keyboard state with the size of keyLength
	previousKeyboardState = new Uint8[keyLength];

	// INFO: Copy the contents of KEYBOARD_STATE into previousKeyboardState
	std::memcpy(previousKeyboardState, KEYBOARD_STATE, keyLength);

	// INFO: Get the current state of the mouse
	MOUSE_STATE = SDL_GetMouseState(&mouse.mouseInfo.x, &mouse.mouseInfo.y);

	// INFO: Set the contents of the previous mouse state to the current mouse state
	previousMouseState = MOUSE_STATE;
}

void InputHandler::HandleInput()
{
	// INFO: Copy the contents of KEYBOARD_STATE into previousKeyboardState
	// so that events current and previous events can be compared
	std::memcpy(previousKeyboardState, KEYBOARD_STATE, keyLength);

	// INFO: Set the contents of the previous mouse state to the current mouse state
	previousMouseState = MOUSE_STATE;

	// INFO: Get the current state of the mouse
	MOUSE_STATE = SDL_GetMouseState(&mouse.mouseInfo.x, &mouse.mouseInfo.y);

	// INFO: Keybinding Extension (Supports GetKey, GetKeyDown, GetKeyUp)
	for (auto& keyBinding : keyBindingsLib)
	{
		switch (keyBinding.second.buttonState)
		{
		case ButtonState::Held:
			if (GetKey(keyBinding.first))
			{
				keyBinding.second.action();
			}
			break;
		case ButtonState::Pressed:
			if (GetKeyDown(keyBinding.first))
			{
				keyBinding.second.action();
			}
			break;
		case ButtonState::Released:
			if (GetKeyUp(keyBinding.first))
			{
				keyBinding.second.action();
			}
			break;
		case ButtonState::None:
		default:
			break;
		}
	}

	// INFO: Mouse Button Binding Extension (Supports GetMouseButton, GetMouseButtonDown, GetMouseButtonUp)
	for (auto& mouseButtonBinding : mouseButtonBindingsLib)
	{
		switch (mouseButtonBinding.second.buttonState)
		{
		case ButtonState::Held:
			if (GetMouseButton(mouseButtonBinding.first))
			{
				mouseButtonBinding.second.action();
			}
			break;
		case ButtonState::Pressed:
			if (GetMouseButtonDown(mouseButtonBinding.first))
			{
				mouseButtonBinding.second.action();
			}
			break;
		case ButtonState::Released:
			if (GetMouseButtonUp(mouseButtonBinding.first))
			{
				mouseButtonBinding.second.action();
			}
			break;
		case ButtonState::None:
		default:
			break;
		}
	}

	// INFO: Generic polling of events for basic functionality e.g. (Closing the window)
	while (SDL_PollEvent(&inputEvent))
	{
		switch (inputEvent.type)
		{
		case SDL_QUIT:
			// Quit the game
			break;
		default:
			break;
		}
	}
}

void InputHandler::Clean()
{
	// INFO: Clean up the contents of the previous keyboard state
	if (previousKeyboardState != nullptr)
	{
		delete[] previousKeyboardState;
		previousKeyboardState = nullptr;
	}
}

void InputHandler::ClearBindings()
{
	// INFO: Clear all key bindings
	keyBindingsLib.clear();

	// INFO: Clear all mouse bindings
    mouseButtonBindingsLib.clear();
}
