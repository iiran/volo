#include <iostream>
#include <memory>
#include <thread>
#include "Game.h"

int main(int argc, char **argv) {
  const int32_t window_width = 600;
  const int32_t window_height = 480;
  const std::string window_name{"volo"};

  auto game = std::make_unique<iiran::Game>(window_name, window_width, window_height, false);

  while (game->is_running()) {
	game->handle_events();
	game->update();
	game->render();
  }
  return 0;
}
