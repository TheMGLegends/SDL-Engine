#pragma once

#include <SDL.h>

#include <functional>
#include <unordered_map>

/// @brief Enum class used in conjunction with keybind data to specify when the action should be executed
enum class KeyState
{
	None = 0,

	GetKey,
	GetKeyDown,
	GetKeyUp
};

/// @brief Struct that holds data for keybindings
struct KeybindData
{
	std::function<void()> action;
	KeyState keyState;

	KeybindData(std::function<void()> _action, KeyState _keyState) : action(_action), keyState(_keyState) {}
};

/// @brief Class that handles input-related operations
class InputHandler
{
// INFO: Generic Members & Methods for Input Handling
private:
	static const Uint8* KEYBOARD_STATE;
	static Uint8* previousKeyboardState;
	static int keyLength;
	static SDL_Event inputEvent;

public:
	inline static bool GetKey(SDL_Keycode keyCode) { return KEYBOARD_STATE[keyCode]; }
	inline static bool GetKeyDown(SDL_Keycode keyCode) { return KEYBOARD_STATE[keyCode] && !previousKeyboardState[keyCode]; }
	inline static bool GetKeyUp(SDL_Keycode keyCode) { return !KEYBOARD_STATE[keyCode] && previousKeyboardState[keyCode]; }


// INFO: Keybinding Members & Methods Extension
private:
	static std::unordered_map<SDL_Keycode, KeybindData> keyBindings;

public:
	static inline void BindKeyAction(SDL_Keycode keyCode, KeybindData keybindData) { keyBindings[keyCode] = keybindData; }
	static inline void ClearKeyBindings() { keyBindings.clear(); }
	static inline void ClearKeyBinding(SDL_Keycode keyCode) { keyBindings.erase(keyCode); }

// INFO: Primary Methods
public:
	static void Initialize();
	static void HandleInput();
	static void Clean();
	static void ClearBindings();

private:
	InputHandler() = delete;
	~InputHandler() = delete;
	InputHandler(const InputHandler&) = delete;
	InputHandler& operator=(const InputHandler&) = delete;
};

