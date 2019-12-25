//
// Created by yiran feng on 2019/12/24.
//

#ifndef VOLO__GAME_H_
#define VOLO__GAME_H_
#include <SDL.h>
#include <string>
#include <iostream>
namespace iiran {
class Game {
 public:
  Game(const std::string &title, int32_t width, int32_t height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
	  throw std::runtime_error("initialize error: " + std::string(SDL_GetError()));
	}
	uint32_t flags{};
	if (fullscreen) {
	  flags |= SDL_WINDOW_FULLSCREEN;
	}
	m_window = SDL_CreateWindow(title.c_str(),
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								width,
								height,
								flags);
	if (m_window == nullptr) {
	  throw std::runtime_error("create window error: " + std::string(SDL_GetError()));
	}
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	if (m_renderer == nullptr) {
	  throw std::runtime_error("create renderer error: " + std::string(SDL_GetError()));
	}
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

	m_running = true;
  }

  ~Game() {
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
  }
  [[nodiscard]] bool is_running() const { return m_running; }

  void handle_events() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	  case SDL_QUIT: m_running = false;
		break;
	  default: std::cout << "unknown event" << std::endl;
		break;
	}
  }
  void update() {};
  void render() {
	SDL_RenderClear(m_renderer);
	SDL_RenderPresent(m_renderer);
  }

 private:
  SDL_Window *m_window{nullptr};
  SDL_Renderer *m_renderer{nullptr};
  bool m_running{false};
};
}
#endif //VOLO__GAME_H_
