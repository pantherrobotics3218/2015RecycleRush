#ifndef CraaawActuate_H
#define CraaawActuate_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class CraaawActuate: public CommandBase
{
private:
	DoubleSolenoid::Value value;

public:
	CraaawActuate(DoubleSolenoid::Value value);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
