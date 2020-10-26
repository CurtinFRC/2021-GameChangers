# 2021-Current
Our Robot Code for 2021 using multi-project gradle with WML, CJ-Vision &amp; Wayfinder Libraries

## Installing Code
#### 1. Download latest WPILib from releases [https://github.com/wpilibsuite/allwpilib/releases]
  - This isn't technically needed to build/deploy to the robot. But does provide useful tools to use.

#### 2. run `git clone ${link} --recursive` when cloning (clones code with submodules)

#### 3. Build Code `./gradlew build` Successful if installed correctly
  - On windows use `gradlew build`. 
  - For linux and macOS you might need to run `sudo chmod +x gradlew` to be able to use the command

## Developing
  - Code for robot goes in `4788/src/main`

  - Code for coprocessor goes in `Coproc/src/main`


## Documentation

#### @TODO (Put your docs/info on what your code does. e.g)

  - Drivebase
```
Uses XboxControllers on USB ports 0 and 1. Control Left and Right power via tankdrive with a maxspeed of 80% etc.... 
```
