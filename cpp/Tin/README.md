Tin
===

A C++ game library.

###General Project setup instructions on Windows:

Download the [MinGW Compilers](http://sourceforge.net/projects/mingw/files/)<br/>
Download the [SDL 2.0.3](https://www.libsdl.org/download-2.0.php) (or later) for MinGW compiler<br/>
Download the latest [Boost Lib](http://sourceforge.net/projects/boost/files/boost-binaries/) version<br/>
Download the latest [CMake](http://www.cmake.org/cmake/resources/software.html) version (3.0 or later)<br/><br/>
After extracting/installing the above packages, create 2 environment variables.<br/>
Assuming that you've extracted the SDL library under C:\, you should create the below environment variable<br/>
**SDL2**=C:\SDL2-2.0.3\i686-w64-mingw32<br/>
Assuming that you've extracted the Boost library under C:\, you should create the below environment variable<br/>
**BOOST_ROOT**=C:\boost_1_55_0<br/><br/>
And create the below variable if it wasn't created by the installation packages.<br/>
**MINGW_HOME**=C:\MinGW<br/>
Add the below values at the end of your PATH variable, it is also important for code assistance in Netbeans.<br/>
**%MINGW_HOME%**\bin;**%MINGW_HOME%**\msys\1.0\bin
###Instructions specific to Netbeans project setup:

If don't have Netbeans already, please [download](https://netbeans.org/downloads/) the latest version.<br/>
You can download the version which is only for C/C++, it's up to you.<br/>
After installing Netbeans, open it and go to *Tools* **>** *Options* **>** *C/C++* and then click **Add...**<br/>
In the screen that will be shown, select **C:\MinGW\bin** (or wherever you've installed your MinGW) as **base directory** and click **OK**.<br/>
After that, you should see that most of the fields were filled for you. If there are still missing fields, just fill them to look like the below image.

![Netbeans configuration](https://raw.githubusercontent.com/TinTeam/Tin/feature/project_structure/docs/readme/netbeans_config.png)

####Creating the Betbeans project

Go to *File* **>** *Create project* and then select **C/C++ Project project with Existing Sources**, select the directory where the repository is and then click **OK**.<br/>
Now you should be able to compile the project.
