#include "strategies/IntakeStrategy.h"

// IntakeActuation::IntakeActuation(std::string name, Intake &intake, Controllers &contGroup) : Strategy(name), _intake(intake), _contGroup(contGroup) {
//   Requires(&intake);
//   SetCanBeInterrupted(true);
//   SetCanBeReused(true);
// }

// void IntakeActuation::OnUpdate(double dt) {
// 	// double powerIn = fabs(_contGroup.Get(ControlMap::Intake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Intake) : 0;
// 	// double powerOut = fabs(_contGroup.Get(ControlMap::Outake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Outake) : 0;
  
//   //maybe move these variables later 
//   bool forwardsPower = false;
//   bool backwardsPower = false;

  
  
//   if (_contGroup.Get(ControlMap::Intake)) {
//     forwardsPower = true;
//   } else {
//     forwardsPower = false;
//   }

//   if (_contGroup.Get(ControlMap::Outake)) {
//     backwardsPower = true;
//   } else {
//     backwardsPower = false;
//   }

//   //toggle button 
//   if (_contGroup.Get(ControlMap::Down)) {
//     if (forwardsPower == true) {
//       _intake.setIntake(IntakeStates::ADEPLOYED, ControlMap::IntakeSpeed);
//       // std::Cout << 
//     } else if (backwardsPower == true) {
//       _intake.setIntake(IntakeStates::ADEPLOYED, -ControlMap::IntakeSpeed);
//     } else {
//       _intake.setIntake(IntakeStates::ADEPLOYED, 0);
//     }
//   } else {
//     _intake.setIntake(IntakeStates::ASTOWED, 0);
//   }
// }



IntakeStill::IntakeStill(std::string name, Intake &intake, Controllers &contGroup) : Strategy(name), _intake(intake), _contGroup(contGroup) {
  Requires(&intake);
  SetCanBeInterrupted(true);
  SetCanBeReused(true);
}

void IntakeStill::OnUpdate(double dt) {
  // if (_contGroup.Get(ControlMap::Intake)) {
  //   _intake.setintake(IntakeStates::MSPINFORWARD, ControlMap::IntakeSpeed);
  // } else if (_contGroup.Get(ControlMap::Outake)) {
  //   _intake.setIntake(IntakeStates::MSPINBACKWARDS, ControlMap::IntakeSpeed);  
  // } else {
  //   _intake.setIntake(IntakeStates::MSTOP, 0);
  // }
}