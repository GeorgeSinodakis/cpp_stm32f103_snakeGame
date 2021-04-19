# Snake Game

## What you need to build and upload the project to the stm32f103c8t6:

1. Download the following programs

    * [GNU Arm Embedded Toolchain][gnu arm]
    * [STM32CubeProgrammer][programmer]
    * [Make][makelink]

2. Create environmental variables for the executables:
    
    * arm-none-eabi-g++.exe
    * arm-none-eabi-objcopy.exe
    * arm-none-eabi-objdump.exe
    * STM32_Programmer_CLI.exe
    * make.exe

3. Change your directory to the project path

4. Execute the following
    
    ```shell
    make Makefile
    ```

[gnu arm]: https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads
[programmer]: https://www.st.com/en/development-tools/stm32cubeprog.html
[makelink]: http://gnuwin32.sourceforge.net/packages/make.htm
