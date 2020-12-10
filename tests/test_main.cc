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
      game::visualizer::Sprite sprite(glm::vec2(200, 30), glm::vec2(0,3), 25);

      REQUIRE(!sprite.CheckBorderCollision());
      REQUIRE(sprite.GetPosition() == glm::vec2(200 , 30));
      REQUIRE(sprite.GetVelocity() == glm::vec2(0,3));
    }

    SECTION("Aligned Collision") { // The sprite just touches the border
      game::visualizer::Sprite sprite(glm::vec2(200, 25), glm::vec2(0,3), 25);
      sprite.MoveUp();
      REQUIRE(sprite.CheckBorderCollision());
      REQUIRE(sprite.GetPosition() == glm::vec2(200, 25));
      REQUIRE(sprite.GetVelocity() == glm::vec2(0,0));
    }

    SECTION("Overlapping Collision") {
      game::visualizer::Sprite sprite(glm::vec2(200, 15), glm::vec2(0,3), 25);
      sprite.MoveUp();
      REQUIRE(sprite.CheckBorderCollision());
      REQUIRE(sprite.GetPosition() == glm::vec2(200, 25));
      REQUIRE(sprite.GetVelocity() == glm::vec2(0,0));
    }
  }

  SECTION("Collide with Bottom Pipe") {
    SECTION("No Collision") {
      game::visualizer::Sprite sprite(glm::vec2(200, 600), glm::vec2(0,3), 25);

      REQUIRE(!sprite.CheckBorderCollision());
      REQUIRE(sprite.GetPosition() == glm::vec2(200, 600));
      REQUIRE(sprite.GetVelocity() == glm::vec2(0, 3));
    }

    SECTION("Aligned Collision") { // The sprite just touches the border
      game::visualizer::Sprite sprite(glm::vec2(200, 622), glm::vec2(0,3), 25);
      REQUIRE(sprite.CheckBorderCollision());
      REQUIRE(sprite.GetPosition() == glm::vec2(200, 625));
      REQUIRE(sprite.GetVelocity() == glm::vec2(0, 0));
    }

    SECTION("Overlapping Collision") {
      game::visualizer::Sprite sprite(glm::vec2(200, 640), glm::vec2(0,3), 25);
      REQUIRE(sprite.CheckBorderCollision());
      REQUIRE(sprite.GetPosition() == glm::vec2(200, 625));
      REQUIRE(sprite.GetVelocity() == glm::vec2(0, 0));
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
      REQUIRE(sprite.GetPosition() == glm::vec2(250, 250));
      REQUIRE(sprite.GetVelocity() == glm::vec2(0, 3));
    }

    SECTION("Inside the pipe resulting in no collision") {
      game::visualizer::Sprite sprite(glm::vec2(280, 330), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(!sprite.CheckPipeCollision());
      REQUIRE(sprite.GetPosition() == glm::vec2(280, 330));
      REQUIRE(sprite.GetVelocity() == glm::vec2(0, 3));
    }

    SECTION("Aligned Collision") {
      game::visualizer::Sprite sprite(glm::vec2(274, 250), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(sprite.CheckPipeCollision());
      REQUIRE(sprite.GetPosition() == glm::vec2(275, 250));
      REQUIRE(sprite.GetVelocity() == glm::vec2(0, 0));
    }

    SECTION("Overlap Collision") {
      game::visualizer::Sprite sprite(glm::vec2(290, 250), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(sprite.CheckPipeCollision());
      REQUIRE(sprite.GetPosition() == glm::vec2(275, 250));
      REQUIRE(sprite.GetVelocity() == glm::vec2(0, 0));
    }
  }

  SECTION("Bottom Pipe") {
    SECTION("Not Colliding") {
      game::visualizer::Sprite sprite(glm::vec2(250, 580), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(!sprite.CheckPipeCollision());
      REQUIRE(sprite.GetPosition() == glm::vec2(250, 580));
      REQUIRE(sprite.GetVelocity() == glm::vec2(0, 3));
    }

    SECTION("Inside the pipe resulting in no collision") {
      game::visualizer::Sprite sprite(glm::vec2(280, 490), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(!sprite.CheckPipeCollision());
      REQUIRE(sprite.GetPosition() == glm::vec2(280, 490));
      REQUIRE(sprite.GetVelocity() == glm::vec2(0, 3));
    }

    SECTION("Aligned Colliding") {
      game::visualizer::Sprite sprite(glm::vec2(274, 580), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(sprite.CheckPipeCollision());
      REQUIRE(sprite.GetPosition() == glm::vec2(275, 580));
      REQUIRE(sprite.GetVelocity() == glm::vec2(0, 0));
    }

    SECTION("Overlap Colliding") {
      game::visualizer::Sprite sprite(glm::vec2(290, 580), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(sprite.CheckPipeCollision());
      REQUIRE(sprite.GetPosition() == glm::vec2(275, 580));
      REQUIRE(sprite.GetVelocity() == glm::vec2(0, 0));
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
      REQUIRE(sprite.GetPosition() == glm::vec2(330, 330));
      REQUIRE(sprite.GetVelocity() == glm::vec2(0, 3));
    }
  }

  SECTION("Aligned Collision") {
    game::visualizer::Sprite sprite(glm::vec2(330, 325), glm::vec2(0, 3), 25);
    sprite.MoveUp();
    game::visualizer::Pipe pipe(300, 1);
    sprite.SetPipe(pipe);
    pipe.SetPipePosition(300, 375);
    REQUIRE(sprite.CheckPipeCollision());
    REQUIRE(sprite.GetPosition() == glm::vec2(330, 325));
    REQUIRE(sprite.GetVelocity() == glm::vec2(0, 0));
  }

  SECTION("Overlap Collision") {
    game::visualizer::Sprite sprite(glm::vec2(330, 310), glm::vec2(0, 3), 25);
    sprite.MoveUp();
    game::visualizer::Pipe pipe(300, 1);
    sprite.SetPipe(pipe);
    pipe.SetPipePosition(300, 375);
    REQUIRE(sprite.CheckPipeCollision());
    REQUIRE(sprite.GetPosition() == glm::vec2(330, 325));
    REQUIRE(sprite.GetVelocity() == glm::vec2(0, 0));
  }

  SECTION("Bottom Pipe") {
    SECTION("No Collision") {
      game::visualizer::Sprite sprite(glm::vec2(340, 400), glm::vec2(0, 3), 25);
      game::visualizer::Pipe pipe(300, 1);
      sprite.SetPipe(pipe);
      pipe.SetPipePosition(300, 375);
      REQUIRE(!sprite.CheckPipeCollision());
      REQUIRE(sprite.GetPosition() == glm::vec2(340, 400));
      REQUIRE(sprite.GetVelocity() == glm::vec2(0, 3));
    }
  }

  SECTION("Aligned Collision") {
    game::visualizer::Sprite sprite(glm::vec2(340, 499), glm::vec2(0, 3), 25);
    game::visualizer::Pipe pipe(300, 1);
    sprite.SetPipe(pipe);
    pipe.SetPipePosition(300, 375);
    REQUIRE(sprite.CheckPipeCollision());
    REQUIRE(sprite.GetPosition() == glm::vec2(340, 500));
    REQUIRE(sprite.GetVelocity() == glm::vec2(0, 0));
  }

  SECTION("Overlap Collision") {
    game::visualizer::Sprite sprite(glm::vec2(340, 510), glm::vec2(0, 3), 25);
    game::visualizer::Pipe pipe(300, 1);
    sprite.SetPipe(pipe);
    pipe.SetPipePosition(300, 375);
    REQUIRE(sprite.CheckPipeCollision());
    REQUIRE(sprite.GetPosition() == glm::vec2(340, 500));
    REQUIRE(sprite.GetVelocity() == glm::vec2(0, 0));
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

TEST_CASE("Test Relative Lerp") {
  SECTION("Valid Lerp value") {
    game::visualizer::Sprite sprite(glm::vec2(300, 300), glm::vec2(0, 3), 25);
    // MoveUp() invokes RelativeLerp() and it turns on isLerpActive
    sprite.MoveUp();
    glm::vec2 lerp = sprite.GetLerp();
    REQUIRE(lerp == glm::vec2(0, 6));
  }
}

