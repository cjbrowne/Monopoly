/*
 * release.cpp
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 *
 *  Release (SDL) version of the entrypoint
 */
#include <SDL/SDL.h>
#include "RuleFile.h"
#include "Rules.h"
#include "SDLGame.h"

int main(int argc, char** argv)
{
    SDLGame monopoly;
    monopoly.start();

    return 0;
}

