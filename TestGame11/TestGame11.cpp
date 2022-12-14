#include <iostream>
#include "Game.h"
#include<time.h>
#include<iostream>

int main()
{
    // Init Game engine
    Game game;

    float LOW_LIMIT = 0.0167f;          // Keep At/Below 60fps
    float HIGH_LIMIT = 0.1f;            // Keep At/Above 10fps

    float lastTime = std::time(nullptr);

    // Game loop
    while (game.running()) {

        float currentTime = std::time(nullptr);
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        if (deltaTime < LOW_LIMIT)
            deltaTime = LOW_LIMIT;
        else if (deltaTime > HIGH_LIMIT)
            deltaTime = HIGH_LIMIT;

        lastTime = currentTime;


        
        // Update
        game.update(deltaTime);

        // Render
        game.render();
    }

    // End of application
    return 0;
}