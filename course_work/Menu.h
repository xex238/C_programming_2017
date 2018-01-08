#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"
#include "Music.h"
using namespace sf;
#ifndef Menu_
#define Menu_

class Menu
{
public:
	Menu() = default;

	Menu(const String& main, const String& left, const String& settings, const String& rectangle, const String& string_for_restart_level);

	~Menu() = default;

	void Menu_MouseButtonReleased_left(RenderWindow& window);

	void Menu_MouseButtonPressed_left(const RenderWindow& window);

	void Menu_MouseButtonEvent(RenderWindow& window, const Event& event);

	void Work_with_settings(const Event& event, Musics& my_music);

	void Return_to_main_menu(const Event& event);

	void Update_pos(const RenderWindow& window);

	void Restart_level(const Event& event, Player& car, Map&  map_1, Musics& my_music);

	Text Return_text();

	String Return_screen_text();

	Sprite Return_sounds_enable_list_sprite();

	Sprite Return_main_sprite();

	Sprite Return_left_sprite();

	Sprite Return_settings_sprite();

	Sprite Return_rectangle_sprite();

	Sprite Return_restart_level_sprite();

	bool Return_enable_rectangle_sprite();
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
	bool enable_rectangle_sprite = false;

	Texture sounds_enable_list_texture; // <- Текстурка значка включенного/выключенного звука
	Sprite sounds_enable_list_sprite;
	bool sounds_enable = true; // <- Включен или выключен звук

	Event event;

	Vector2i pixel_pos; // <- Координаты мыши в пикселях
	Vector2f pos; // <- Координаты мыши

	Font font;  // <- Шрифт для текста
	Text text = Text("", font, 20); // <- Сам текст

	String screen_text; // <- Для выбора загрузки

	float sound_bufer_volume{ 0 }; // <- Для хранения громкости звука

	int text_int_real[3]{ 1, 0, 0 }; // <- Массив для перевода значений из типа int в тип char*
};

#endif // !menu