#include <SFML/Graphics.hpp>
#include "Car.h"

#ifndef Menu_
#define Menu_

class Menu
{
public:
	Menu();
	~Menu() = default;

	void Menu_MouseButtonReleased_left(RenderWindow& window, const Vector2f& pos);
	void Menu_MouseButtonPressed_left(const RenderWindow& window, const Vector2f& pos);
	void Menu_MouseButtonEvent(RenderWindow& window, const Event& event, const Vector2f& pos);
	void Work_with_settings(const Event& event, Musics& my_music, const Vector2f& pos);
	void Return_to_main_menu(const Event& event, const Vector2f& pos, Car& car, Level& level, Musics& my_music);
	void Restart_level(const Event& event, Car& car, Musics& my_music, const Vector2f& pos);
	void Set_screen_text(const String& screen_text_);
	void Set_play_game_over_music(const bool& boolean);

	bool Return_enable_rectangle_sprite();

	Text Return_text();

	String Return_screen_text();

	Sprite Return_sounds_enable_list_sprite();
	Sprite Return_main_sprite();
	Sprite Return_left_sprite();
	Sprite Return_settings_sprite();
	Sprite Return_rectangle_sprite();
	Sprite Return_restart_level_sprite();
	Sprite Return_level_screen_sprite();
private:
	Texture restart_level_texture; // <- Для кнопки перезагрузки уровня
	Sprite restart_level_sprite;

	Texture main_texture; // <- Для главного меню
	Sprite main_sprite;

	Texture left_texture; // <- Для кнопки "назад"
	Sprite left_sprite;

	Texture settings_texture; // <- Для настроек
	Sprite settings_sprite;

	Texture rectangle_texture; // <- Для подсветки, когда нажата клавиша
	Sprite rectangle_sprite;
	bool enable_rectangle_sprite{ false };

	Texture sounds_enable_list_texture; // <- Текстурка значка включенного/выключенного звука
	Sprite sounds_enable_list_sprite;
	bool sounds_enable = { true }; // <- Включен или выключен звук

	Texture level_screen_texture;
	Sprite level_screen_sprite;

	Font font;  // <- Шрифт для текста
	Text text = Text("", font, 20); // <- Сам текст

	String screen_text; // <- Для выбора загрузки

	float sound_bufer_volume{ 0 }; // <- Для хранения громкости звука

	bool play_game_over_music{ false }; // Играет ли победная музыка
};

#endif // !menu
