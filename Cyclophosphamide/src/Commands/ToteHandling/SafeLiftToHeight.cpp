#include "SafeLiftToHeight.h"
#include "../CanCollecterino/Arms/MoveWrist.h"
#include "../CanCollecterino/Craaaw/CraaawActuate.h"
#include "LiftToHeight.h"

SafeLiftToHeight::SafeLiftToHeight(double destination)
{
	AddSequential(new MoveWrist(MoveWrist::open));
	AddSequential(new LiftToHeight(destination));
}