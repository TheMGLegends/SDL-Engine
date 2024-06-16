#include "InputHandler.h"

#include <cstring>

// INFO: Generic Members for Input Handling
const Uint8* InputHandler::KEYBOARD_STATE = nullptr;
Uint8* InputHandler::previousKeyboardState = nullptr;
int InputHandler::keyLength = 0;
SDL_Event InputHandler::inputEvent{};

// INFO: Keybinding Members Extension
std::unordered_map<SDL_Keycode, KeybindData> InputHandler::keyBindings{};

void InputHandler::Initialize()
{
	// INFO: Get the state of the keyboard
	KEYBOARD_STATE = SDL_GetKeyboardState(&keyLength);

	// INFO: Initialise the previous keyboard state with the size of keyLength
	previousKeyboardState = new Uint8[keyLength];

	// INFO: Copy the contents of KEYBOARD_STATE into previousKeyboardState
	std::memcpy(previousKeyboardState, KEYBOARD_STATE, keyLength);
}

void InputHandler::HandleInput()
{
	// INFO: Copy the contents of KEYBOARD_STATE into previousKeyboardState
	// so that events current and previous events can be compared
	std::memcpy(previousKeyboardState, KEYBOARD_STATE, keyLength);

	// INFO: Keybinding Extension (Supports GetKey, GetKeyDown, GetKeyUp)
	for (auto& keyBinding : keyBindings)
	{
		switch (keyBinding.second.keyState)
		{
		case KeyState::GetKey:
			if (GetKey(keyBinding.first))
			{
				keyBinding.second.action();
			}
			break;
		case KeyState::GetKeyDown:
			if (GetKeyDown(keyBinding.first))
			{
				keyBinding.second.action();
			}
			break;
		case KeyState::GetKeyUp:
			if (GetKeyUp(keyBinding.first))
			{
				keyBinding.second.action();
			}
			break;
		case KeyState::None:
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
	keyBindings.clear();

	// INFO: Clear all mouse bindings
}
