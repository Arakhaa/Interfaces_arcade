/*
** EPITECH PROJECT, 2018
** Igraphique
** File description:
** none
*/

#ifndef IGRAPHIC_HPP_
	#define IGRAPHIC_HPP_
	#include <string>
	#include <utility>

	namespace gfx {
		enum eventHandler
		{
			NONE,
			UP,
			DOWN,
			RIGHT,
			LEFT,
			LEFT_CLICK,
			RIGHT_CLICK,
			PAUSE,
			RESTART,
			MENU,
			ACTION,
			NEXT_GAME,
			PREV_GAME,
			NEXT_LIB,
			PREV_LIB,
			QUIT
		};

		using idSprite_t = size_t;
		using idSound_t = size_t;

		class IGraphic
		{
		public:
			virtual ~IGraphic();
			virtual eventHandler pollEvent() = 0;
			virtual idSprite_t createSprite(std::string const &filename,
				std::pair<float, float> const &origin,
				std::pair <float, float> const &clipping) = 0;
			virtual bool drawSprite(idSprite_t,
				std::pair<float, float> &position) = 0;
			virtual bool setSprite(idSprite_t,
				std::pair<float, float> &origin,
				std::pair<float, float> &clipping) = 0;
			virtual bool draw() = 0;
			virtual bool destroySprite(idSprite_t) = 0;
			virtual bool clear() = 0;

			virtual idSound_t createSound(char *, int) = 0;
			virtual bool playSound(idSound_t) const = 0;
			virtual bool pauseSound(idSound_t) const = 0;
			virtual bool destroySound(idSound_t) = 0;
		};

		IGraphic *initGfx();
		void destroyGfx(gfx::IGraphic *);
	}
#endif