#pragma once

#include "Mouse.h"

#include <SDL.h>

#include <functional>
#include <unordered_map>

/// @brief Enum class used in conjunction with BindData to specify when the action should be executed
enum class ButtonState
{
	None = 0,

	Held,
	Pressed,
	Released
};

/// @brief Struct that holds data for binding a key/button to an action along with the triggering state of the key/button
struct BindData
{
	std::function<void()> action;
	ButtonState buttonState;

	BindData(std::function<void()> _action, ButtonState _buttonState) : action(_action), buttonState(_buttonState) {}
};

/// @brief Class that handles input-related operations
class InputHandler
{

#pragma region GenericKeyboardInput
// INFO: Generic Members & Methods for Keyboard Input Handling
private:
	static const Uint8* KEYBOARD_STATE;
	static Uint8* previousKeyboardState;
	static int keyLength;
	static SDL_Event inputEvent;

public:
	static inline bool GetKey(SDL_Keycode keyCode) { return KEYBOARD_STATE[keyCode]; }
	static inline bool GetKeyDown(SDL_Keycode keyCode) { return KEYBOARD_STATE[keyCode] && !previousKeyboardState[keyCode]; }
	static inline bool GetKeyUp(SDL_Keycode keyCode) { return !KEYBOARD_STATE[keyCode] && previousKeyboardState[keyCode]; }
#pragma endregion

#pragma region KeybindingExtension
// INFO: Keybinding Members & Methods Extension (Keyboard)
private:
	static std::unordered_map<SDL_Keycode, BindData> keyBindings;

public:
	static inline void BindKeyAction(SDL_Keycode keyCode, BindData bindData) { keyBindings[keyCode] = bindData; }
	static inline void ClearKeyBindings() { keyBindings.clear(); }
	static inline void ClearKeyBinding(SDL_Keycode keyCode) { keyBindings.erase(keyCode); }
#pragma endregion

#pragma region GenericMouseInput
// INFO: Generic Members & Methods for Mouse Input Handling
private:
	static Mouse mouse;
	static Uint32 MOUSE_STATE;
	static Uint32 previousMouseState;

public:
	static inline bool GetMouseButton(Uint32 mouseButtonFlags) { return MOUSE_STATE & mouseButtonFlags; }
	static inline bool GetMouseButtonDown(Uint32 mouseButtonFlags) { return (MOUSE_STATE & mouseButtonFlags) && !(previousMouseState & mouseButtonFlags); }
	static inline bool GetMouseButtonUp(Uint32 mouseButtonFlags) { return !(MOUSE_STATE & mouseButtonFlags) && (previousMouseState & mouseButtonFlags); }
#pragma endregion

#pragma region ButtonBindingExtension
// INFO: Button binding Members & Methods Extension (Mouse)
private:
	static std::unordered_map<Uint32, BindData> mouseButtonBindings;

public:
	static inline void BindMouseButtonAction(Uint32 mouseButtonFlags, BindData bindData) { mouseButtonBindings[mouseButtonFlags] = bindData; }
	static inline void ClearMouseButtonBindings() { mouseButtonBindings.clear(); }
	static inline void ClearMouseButtonBinding(Uint32 mouseButtonFlags) { mouseButtonBindings.erase(mouseButtonFlags); }
	static inline Mouse GetMouse() { return mouse; }
#pragma endregion

#pragma region GenericMethods
// INFO: Primary Methods
public:
	static void Initialize();
	static void HandleInput();
	static void Clean();
	static void ClearBindings();
#pragma endregion

private:
	InputHandler() = delete;
	~InputHandler() = delete;
	InputHandler(const InputHandler&) = delete;
	InputHandler& operator=(const InputHandler&) = delete;
};

