# Python 1.5 extension for NVDA controller
 It gives possibility to call
[NVDA controller](https://github.com/nvaccess/nvda/tree/master/extras/controllerClient)
functions from `Severance: Blade of Darkness` game scripts.
# Using NVDA python extension
 Copy `nvda.dll` and `nvdaControllerClient32.dll` to `<game-path>/Bin` directory.
You can call it from python scripts in the following way:
```
import nvda

nvda.SpeakText("Some text")
```
# Downloading
 You can download `nvda.dll` from
[appveyor build artifacts](https://ci.appveyor.com/project/smartblade/bldnvda/build/artifacts).
`nvdaControllerClient32.dll` can be found at
[NVDA site](http://www.nvda-project.org/nvdaControllerClient/nvdaControllerClient_20100219.7z)
