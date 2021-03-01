#include "strategies/ShooterStrategy.h"

ShooterManualStrategy::ShooterManualStrategy(std::string name, Shooter &shooter, Controllers &contGroup) : Strategy(name), _shooter(shooter), _contGroup(contGroup) {
	Requires(&shooter);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);

}

void ShooterManualStrategy::OnUpdate(double dt) {
	
}