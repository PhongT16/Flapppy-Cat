#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <core/rename_this_file.h>
#include "visualizer/jetpack_cat.h"
#include "visualizer/pipe.h"
#include "visualizer/sprite.h"
#include <iostream>

TEST_CASE("Border Collision") {
  //int window_size = 650;
  SECTION("Collide with Top Pipe") {
    SECTION("No Collision") {
      game::visualizer::Sprite sprite(glm::vec2(0, 30), glm::vec2(0,3), 25);

      REQUIRE(!sprite.CheckBorderCollision());
    }

    SECTION("Aligned Collision") { // The sprite just touches the border
      game::visualizer::Sprite sprite(glm::vec2(0, 22), glm::vec2(0,3), 25);
      REQUIRE(sprite.CheckBorderCollision());
    }

    SECTION("Overlapping Collision") {
      game::visualizer::Sprite sprite(glm::vec2(0, 15), glm::vec2(0,3), 25);
      REQUIRE(sprite.CheckBorderCollision());
    }
  }

  SECTION("Collide with Bottom Pipe") {
    SECTION("No Collision") {
      game::visualizer::Sprite sprite(glm::vec2(0, 600), glm::vec2(0,3), 25);

      REQUIRE(!sprite.CheckBorderCollision());
    }

    SECTION("Aligned Collision") { // The sprite just touches the border
      game::visualizer::Sprite sprite(glm::vec2(0, 622), glm::vec2(0,3), 25);
      REQUIRE(sprite.CheckBorderCollision());
    }

    SECTION("Overlapping Collision") {
      game::visualizer::Sprite sprite(glm::vec2(0, 640), glm::vec2(0,3), 25);
      REQUIRE(sprite.CheckBorderCollision());
    }
  }
}

TEST_CASE("Side Pipe Collision") {
  SECTION("Top Pipe") {
    SECTION("No Collision") {
      game::visualizer::Sprite sprite(glm::vec2(250, 250), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(!sprite.CheckPipeCollision());
    }

    SECTION("Inside the pipe resulting in no collision") {
      game::visualizer::Sprite sprite(glm::vec2(280, 330), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(!sprite.CheckPipeCollision());
    }

    SECTION("Aligned Collision") {
      game::visualizer::Sprite sprite(glm::vec2(274, 250), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(sprite.CheckPipeCollision());
    }

    SECTION("Overlap Collision") {
      game::visualizer::Sprite sprite(glm::vec2(290, 250), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(sprite.CheckPipeCollision());
    }
  }

  SECTION("Bottom Pipe") {
    SECTION("Not Colliding") {
      game::visualizer::Sprite sprite(glm::vec2(250, 580), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(!sprite.CheckPipeCollision());
    }

    SECTION("Inside the pipe resulting in no collision") {
      game::visualizer::Sprite sprite(glm::vec2(280, 490), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(!sprite.CheckPipeCollision());
    }

    SECTION("Aligned Colliding") {
      game::visualizer::Sprite sprite(glm::vec2(274, 580), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(sprite.CheckPipeCollision());
    }

    SECTION("Overlap Colliding") {
      game::visualizer::Sprite sprite(glm::vec2(290, 580), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(sprite.CheckPipeCollision());
    }
  }
}

TEST_CASE("Internal Pipe Collision") {
  SECTION("Top Pipe") {
    SECTION("No Collision") {
      game::visualizer::Sprite sprite(glm::vec2(330, 330), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(!sprite.CheckPipeCollision());
    }
  }

  SECTION("Aligned Collision") {
    game::visualizer::Sprite sprite(glm::vec2(330, 325), glm::vec2(0, 3), 25);
    game::visualizer::Pipe pipe(300, 1);
    sprite.SetPipe(pipe);
    pipe.SetPipePosition(300, 375);
    REQUIRE(sprite.CheckPipeCollision());
  }

  SECTION("Overlap Collision") {
    game::visualizer::Sprite sprite(glm::vec2(330, 310), glm::vec2(0, 3), 25);
    game::visualizer::Pipe pipe(300, 1);
    sprite.SetPipe(pipe);
    pipe.SetPipePosition(300, 375);
    REQUIRE(sprite.CheckPipeCollision());
  }

  SECTION("Bottom Pipe") {
    SECTION("No Collision") {
      game::visualizer::Sprite sprite(glm::vec2(340, 400), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(!sprite.CheckPipeCollision());
    }
  }

  SECTION("Aligned Collision") {
    game::visualizer::Sprite sprite(glm::vec2(340, 495), glm::vec2(0, 3), 25);
    game::visualizer::Pipe pipe(300, 1);
    sprite.SetPipe(pipe);
    pipe.SetPipePosition(300, 375);
    REQUIRE(sprite.CheckPipeCollision());
  }

  SECTION("Overlap Collision") {
    game::visualizer::Sprite sprite(glm::vec2(340, 510), glm::vec2(0, 3), 25);
    game::visualizer::Pipe pipe(300, 1);
    sprite.SetPipe(pipe);
    pipe.SetPipePosition(300, 375);
    REQUIRE(sprite.CheckPipeCollision());
  }
}

TEST_CASE("HasPassedPipe function") {
  SECTION("Hasn't Entered Pipe - Not passed") {
    game::visualizer::Sprite sprite(glm::vec2(340, 260), glm::vec2(0, 3), 25);
    game::visualizer::Pipe pipe(300, 1);
    pipe.SetPipePosition(300, 375);
    REQUIRE(!sprite.HasPassedPipe(pipe));
  }

  SECTION("Entered Pipe - Not passed") {
    game::visualizer::Sprite sprite(glm::vec2(340, 320), glm::vec2(0, 3), 25);
    game::visualizer::Pipe pipe(300, 1);
    pipe.SetPipePosition(300, 375);
    REQUIRE(!sprite.HasPassedPipe(pipe));

  }

  SECTION("Passed Pipe - passed") {
    game::visualizer::Sprite sprite(glm::vec2(401, 400), glm::vec2(0, 3), 25);
    game::visualizer::Pipe pipe(300, 1);
    pipe.SetPipePosition(300, 375);
    REQUIRE(sprite.HasPassedPipe(pipe));
  }
}

